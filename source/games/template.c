
#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <3ds.h>
//---------------------------------------------------------------------------------
int YAFG() {

gfxInitDefault();
C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
C2D_Prepare();
C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
u32 YAGreen   = C2D_Color32(0xAF, 0xBF, 0xAF, 0xFF);
u32 YAOL   = C2D_Color32(0x33, 0x36, 0x3F, 0xFF);
u32 YABlue  = C2D_Color32(0xA7, 0xC7, 0xD8, 0xFF);
    float gamex=200;
    float gamey=30;
    float gamevelx=0;
    float gamevely=0;

    
    
    void drawTop(){
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(top);
        C2D_TargetClear(top, YABlue);
    
        C3D_FrameEnd(0);
        
    }
    void drawBottom(){
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(bottom);
        C2D_TargetClear(bottom, YABlue);
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
	u32 kHeld = hidKeysDown();

	display();
	
}

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
//---------------------------------------------------------------------------------