
// WARN: this code is untested, and will probably not build correctly


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "./general-utills/utillities.c"
#include "./games/YAFG.c"

#include <3ds.h>
#include <citro2d.h>


#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240


//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------

gfxInitDefault();
C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
C2D_Prepare();
C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
u32 YAGreen   = C2D_Color32(0xAF, 0xBF, 0xAF, 0xFF);
u32 UI  = C2D_Color32(0x00, 0x00, 0x00, 0x5F);
u32 YABlue  = C2D_Color32(0xA7, 0xC7, 0xD8, 0xFF);
// C2D_Text Text[2];
// C2D_Font font;
// C2D_TextBuf g_staticBuf;
 
	void textinit(){\
		YACTRText("PLAY!",120, 145,1);
		YACTRText("YET ANOTHER FLAPPY GAME",40, 55,.65f);

	}
	// Main loop
	
	// consoleInit(GFX_BOTTOM, NULL);
	// while (aptMainLoop())
	// {
	// 	u32 kDown = hidKeysDown();
	// 	if (kDown & KEY_START) break;
	// 	if (kDown & KEY_A) YAFG();
	// 	printf("\x1b[1;1HPress A to Start YAFG");
		
	// }
	void thistick(){

		u32 kDown = hidKeysDown();
		// if (kDown & KEY_START) break;
	}
	
	// consoleInit(GFX_BOTTOM, NULL);
	int time=0;

    void drawBottom(){
		
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(bottom);
        C2D_TargetClear(bottom, YABlue);
        C2D_DrawRectSolid(30, 30, 0, 260, 180, UI);
        C2D_DrawRectSolid(50, 130, 0, 220, 60, YAGreen);
		textinit();
        C3D_FrameEnd(0);
	}
    void drawTop(){
		
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(top);
        C2D_TargetClear(top, YABlue);
        C3D_FrameEnd(0);
	}
	void draw(){
		drawBottom();
		drawTop();
	}
	void tick(){

    	// hidScanInput();			
		touchPosition touch;
		hidTouchRead(&touch);

		u32 kDown = hidKeysDown();
		if (kDown & KEY_A||(touch.px>50&&touch.py>130&&touch.px<50+220&&touch.py<130+60)) {YAFG();}
	}
while (aptMainLoop())
{
    	hidScanInput();			
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
            break;
        tick();
		draw();
	// printf("\x1b[1;1HPress A to Start YAFG  ");
	// printf("\x1b[2;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
}

	// // Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
