
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
    float x=200;
    float y=30;
    float velx=0;
    float vely=0;

    srand(1);
    float enemies[10][3]={
        {300,2,.5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5},
        {-rand()%600,rand()%5,.5+(rand()%20)/5}};
    
    
    void drawTop(){
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(top);
        C2D_TargetClear(top, YABlue);
    
        C2D_DrawRectSolid(195, 0,0, 10, 240, 
            YAOL);
        C2D_DrawRectSolid(105, 0,0, 10, 240, 
            YAOL);
        C2D_DrawRectSolid(285, 0,0, 10, 240, 
            YAOL);
        C2D_DrawRectSolid(15, 0,0, 10, 240, 
            YAOL);
        C2D_DrawRectSolid(375, 0,0, 10, 240, 
            YAOL);
    
        C2D_DrawCircleSolid(x, y, 0, 30, 
            YAOL);
        C2D_DrawCircleSolid(x, y, 0, 25, 
            YAGreen);
    
        for(int i = 0; i<10;i++){
            
            enemies[i][0]+=enemies[i][2];
            C2D_DrawRectSolid(enemies[i][1]*90-25, enemies[i][0],0, 90, 35, YAOL);
    
            if((x)<enemies[i][1]*90-25+90&&(x)>enemies[i][1]*90-25&&(y+30)>enemies[i][0]&&(y+30)<enemies[i][0]+35) vely+=-30;
            if((x)<enemies[i][1]*90-25+90&&(x)>enemies[i][1]*90-25&&(y-30)>enemies[i][0]&&(y-30)<enemies[i][0]+35) vely+=10;
            if((x-30)<enemies[i][1]*90-25+90&&(x-30)>enemies[i][1]*90-25&&(y)>enemies[i][0]&&(y)<enemies[i][0]+35) velx+=10;
            if((x+30)<enemies[i][1]*90-25+90&&(x+30)>enemies[i][1]*90-25&&(y)>enemies[i][0]&&(y)<enemies[i][0]+35) velx+=-10;
            if(enemies[i][0]>500) enemies[i][0]=-50 ;
    
        }
        C3D_FrameEnd(0);
        
    }
    void drawBottom(){
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(bottom);
        C2D_TargetClear(bottom, YABlue);
    
        C2D_DrawRectSolid(195-40, 0,0, 10, 240, 
            YAOL);
        C2D_DrawRectSolid(105-40, 0,0, 10, 240, 
            YAOL);
        C2D_DrawRectSolid(285-40, 0,0, 10, 240, 
            YAOL);
    
    
        C2D_DrawCircleSolid(x-40, y-240, 0, 30, 
            YAOL);
        C2D_DrawCircleSolid(x-40, y-240, 0, 25, 
            YAGreen);
            
        for(int i = 0; i<10;i++){
    
            C2D_DrawRectSolid(enemies[i][1]*90-25-40, enemies[i][0]-240,0, 90, 35, YAOL);
    
        }
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
	// if (kHeld & KEY_A){
	// 	x=x+10;
	// }
	// if (kHeld & KEY_Y){
	// 	x=x-10;
	// }
	// if (kHeld & KEY_X){
	// 	y=y-10;
	// }
	// if (kHeld & KEY_B){
	// 	y=y+10;
	// }
	// if (kDown & KEY_A){
	//      vely=vely-20;
	//  }
	if (kDown & KEY_A){
		vely=vely-30;
	}
	if (kDown & BIT(4)){
		 velx=velx+10;
	 }
	if (kDown & BIT(5)){
		 velx=velx-10;
	 }
	 velx*=.9;
	 vely+=2;
	 vely*=.9;
	 x+=velx;
	 y+=vely;

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