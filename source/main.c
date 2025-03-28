
// WARN: this code is untested, and will probably not build correctly


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
u32 YAOL   = C2D_Color32(0x33, 0x36, 0x3F, 0xFF);
u32 YAShadow   = C2D_Color32(0x33, 0x36, 0x3F, 0x5F);
float targetScale=.8;
int animation=-1;
float scale=0;
int index = 0;
int pos=0;

#include "./general-utills/utillities.c"
#include "./games/YAFG.c"
#include "./general-utills/previews.c"
int state=0;

// C2D_Text Text[2];
// C2D_Font font;
// C2D_TextBuf g_staticBuf;
 
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
        C2D_DrawRectSolid(30, 30+((scale-.8)*5)*300, 0, 260, 180, UI);
        C2D_DrawRectSolid(50, 130+((scale-.8)*5)*300, 0, 220, 60, YAGreen);
        C2D_DrawRectSolid(0-5-((scale-.8)*5)*60, 40-5, 0, 20+10, 160+10, YAOL);
        C2D_DrawRectSolid(300-5+((scale-.8)*5)*60, 40-5, 0, 20+10, 160+10, YAOL);
        C2D_DrawRectSolid(0-((scale-.8)*5)*60, 40, 0, 20, 160, YAGreen);
        C2D_DrawRectSolid(300+((scale-.8)*5)*60, 40, 0, 20, 160, YAGreen);
		YACTRText("PLAY!",120, 145+((scale-.8)*5)*300,1);
		YACTRText("YET ANOTHER FLAPPY GAME",40, 55+((scale-.8)*5)*300,.65f);
		YAFGPreviewBottom();
        C3D_FrameEnd(0);
	}
    void drawTop(){
		
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(top);
        C2D_TargetClear(top, YABlue);
        C2D_DrawRectSolid(0, 0, 0, 400, 240, UI);
		scaleX=scale;
		scaleY=scale;
		YAFGPreviewTop();
		scaleX=1;
		scaleY=1;
		scale= (scale*10+targetScale)/11;
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
		if (kDown & KEY_A||(touch.px>50&&touch.py>130&&touch.px<50+220&&touch.py<130+60)) {animation=0;}
		if (kDown & KEY_DLEFT  ||(touch.px<20&&touch.px>3))  {index--;}
		if (kDown & KEY_DRIGHT ||(touch.px>300)) {index++;}
		pos=((pos*7)+(index*300))/8;
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(top);
        if (kDown & KEY_B)  {C2D_TargetClear(top, YABlue);}
        C3D_FrameEnd(0);
		if(animation>=0){
			if(state==0){
				animation++;
				targetScale = 1;
				if(animation>40){
					animation=-1;
					YAFG();
					targetScale = .8;
				}
			} else if (state==1){

				animation++;
				targetScale = 0;
				if(animation>40){
					animation=-1;
					state=2;
					
				}
			}
		}
	}
while (aptMainLoop())
{
    	hidScanInput();			
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START){
			animation=0;
			state=1;
		}
		if(state==2) break;
		draw();
        tick();
	// printf("\x1b[1;1HPress A to Start YAFG  ");
	// printf("\x1b[2;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
}

	// // Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
