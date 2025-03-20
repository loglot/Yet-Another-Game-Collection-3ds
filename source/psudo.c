
// WARN: this code is untested, and will probably not build correctly

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
C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

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


void drawTop(){
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_SceneBegin(top);
	C2D_TargetClear(top, YABlue);
	C2D_DrawRectSolid(195, 0, 10, 240,0, 
		YAOL);
	C2D_DrawCircleSolid(x, y, 0, 30, 
		YAOL);
	C2D_DrawCircleSolid(x, y, 0, 25, 
		YAGreen);
	C3D_FrameEnd(0);
	
}
void drawBottom(){
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_SceneBegin(bottom);
	C2D_TargetClear(bottom, YABlue);
	C2D_DrawCircleSolid(x, y-240, 0, 30, 
		YAOL);
	C2D_DrawCircleSolid(x, y-240, 0, 25, 
		YAGreen);
	// printf("\x1b[1;1HYAFG REMASTERED 3DS EDITION");
	C3D_FrameEnd(0);
	
}
void display(){
	drawTop();
	drawBottom();
}
void init(){
	
}

void tick(){

	hidScanInput();

	// Respond to user input
	u32 kDown = hidKeysDown();
	
	u32 kHeld = hidKeysHeld();
	if (kHeld & KEY_A){
		x=x+10;
	}
	if (kHeld & KEY_Y){
		x=x-10;
	}
	if (kHeld & KEY_X){
		y=y-10;
	}
	if (kHeld & KEY_B){
		y=y+10;
	}
	// if (kDown & KEY_A){
	//      vely=vely-20;
	//  }
	if (kDown & BIT(6)){
		 velx=velx-20;
	 }
	if (kDown & BIT(5)){
		 velx=velx+20;
	 }

	display();
	
}
u32 kDownOld = 0, kHeldOld = 0, kUpOld = 0;
	// Main loop
	while (aptMainLoop())
	{
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break;
		tick();
	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
