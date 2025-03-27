
#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <3ds.h>
//---------------------------------------------------------------------------------
int game() {

    float x=200;
    float y=30;
    float velx=0;
    float vely=0;

    
    
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