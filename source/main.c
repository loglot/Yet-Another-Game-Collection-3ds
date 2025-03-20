#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <3ds.h>

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------
	// Init libs
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	// Create colors
	u32 YAGreen   = C2D_Color32(0xAF, 0xBF, 0xAF, 0xFF);
	u32 YAOL   = C2D_Color32(0x33, 0x36, 0x3F, 0xFF);
	u32 YABlue  = C2D_Color32(0xA7, 0xC7, 0xD8, 0xFF);//#a7c7d8
    float x=200;
    float y=30;
    float velx=0;
    float vely=0;
    char keysNames[32][32] = {
		"KEY_A", "KEY_B", "KEY_SELECT", "KEY_START",
		"KEY_DRIGHT", "KEY_DLEFT", "KEY_DUP", "KEY_DDOWN",
		"KEY_R", "KEY_L", "KEY_X", "KEY_Y",
		"", "", "KEY_ZL", "KEY_ZR",
		"", "", "", "",
		"KEY_TOUCH", "", "", "",
		"KEY_CSTICK_RIGHT", "KEY_CSTICK_LEFT", "KEY_CSTICK_UP", "KEY_CSTICK_DOWN",
		"KEY_CPAD_RIGHT", "KEY_CPAD_LEFT", "KEY_CPAD_UP", "KEY_CPAD_DOWN"
	};


u32 kDownOld = 0, kHeldOld = 0, kUpOld = 0;
	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		// Respond to user input
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		printf("\x1b[1;1HYAFG REMASTERED 3DS EDITION");
		printf("\x1b[2;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
		printf("\x1b[3;1HGPU:     %6.2f%%\x1b[K", C3D_GetDrawingTime()*6.0f);
		printf("\x1b[4;1HCmdBuf:  %6.2f%%\x1b[K", C3D_GetCmdBufUsage()*100.0f);

		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_SceneBegin(top);
		C2D_TargetClear(top, YABlue);
        u32 kHeld = hidKeysHeld();
		// if (kHeld & KEY_A){
        //     x=x+1;
        // }
		// if (kHeld & KEY_Y){
        //     x=x-1;
        // }
		// if (kHeld & KEY_X){
        //     y=y-1;
        // }
		// if (kHeld & KEY_B){
        //     y=y+1;
        // }
        if (kDown & KEY_A){
             vely=vely-20;
         }
        if (kDown & BIT(6)){
             velx=velx-20;
         }
        if (kDown & BIT(5)){
             velx=velx+20;
         }
		circlePosition pos;
		hidCircleRead(&pos);
        // velx=velx+pos.dx/100;
        // vely=vely-pos.dy/100;
        velx=velx/1.1;
        vely=(vely+.1)/1.1;
        x=x+velx;
        y=y+vely;

		C2D_DrawCircleSolid(x, y, 0, 30, 
			YAOL);
		C2D_DrawCircleSolid(x, y, 0, 25, 
			YAGreen);


		//hidKeysHeld returns information about which buttons have are held down in this frame
		
		// //hidKeysUp returns information about which buttons have been just released
		// u32 kUp = hidKeysUp();
		// 	consoleClear();
		// 	int i;
		// 	for (i = 0; i < 32; i++)
		// 	{
		// 		if (kDown & BIT(i)) printf("%s down\n", keysNames[i]);
		// 		if (kHeld & BIT(i)) printf("%s held\n", keysNames[i]);
		// 		if (kUp & BIT(i)) printf("%s up\n", keysNames[i]);
		// 	}
		// kDownOld = kDown;
		// kHeldOld = kHeld;
		// kUpOld = kUp;
		C3D_FrameEnd(0);

	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}