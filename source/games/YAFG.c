
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
    float YAFGx=200;
    float YAFGy=30;
    float YAFGvelx=0;
    float YAFGvely=0;

    srand(1);
    float YAFGenemies[10][3]={
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
    
        C2D_DrawCircleSolid(YAFGx, YAFGy, 0, 30, 
            YAOL);
        C2D_DrawCircleSolid(YAFGx, YAFGy, 0, 25, 
            YAGreen);
        bool hit = false;
        for(int i = 0; i<10;i++){
            
            YAFGenemies[i][0]+=YAFGenemies[i][2];
            C2D_DrawRectSolid(YAFGenemies[i][1]*90-25, YAFGenemies[i][0],0, 90, 35, YAOL);
            if(!hit){
                if((YAFGx-30)<YAFGenemies[i][1]*90-25+90&&(YAFGx-30)>YAFGenemies[i][1]*90-25&&(YAFGy)>YAFGenemies[i][0]&&(YAFGy)<YAFGenemies[i][0]+35) {YAFGvelx+=10;hit=true;}
                if((YAFGx+30)<YAFGenemies[i][1]*90-25+90&&(YAFGx+30)>YAFGenemies[i][1]*90-25&&(YAFGy)>YAFGenemies[i][0]&&(YAFGy)<YAFGenemies[i][0]+35) {YAFGvelx+=-10;hit=true;}
                if((YAFGx)<YAFGenemies[i][1]*90-25+90&&(YAFGx)>YAFGenemies[i][1]*90-25&&(YAFGy+30)>YAFGenemies[i][0]&&(YAFGy+30)<YAFGenemies[i][0]+35) {YAFGvely+=-30;hit=true;}
                if((YAFGx)<YAFGenemies[i][1]*90-25+90&&(YAFGx)>YAFGenemies[i][1]*90-25&&(YAFGy-30)>YAFGenemies[i][0]&&(YAFGy-30)<YAFGenemies[i][0]+35) {YAFGvely+=10;hit=true;}
            }
            if(YAFGenemies[i][0]>500) YAFGenemies[i][0]=-50 ;
    
        }
        C3D_FrameEnd(0);
        
    }
    void drawBottom(){
        int offset[2]={-40,-240};
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_SceneBegin(bottom);
        C2D_TargetClear(bottom, YABlue);
    
        C2D_DrawRectSolid(195+offset[0], 0,0, 10, 240, 
            YAOL);
        C2D_DrawRectSolid(105+offset[0], 0,0, 10, 240, 
            YAOL);
        C2D_DrawRectSolid(285+offset[0], 0,0, 10, 240, 
            YAOL);
    
    
        C2D_DrawCircleSolid(YAFGx+offset[0], YAFGy+offset[1], 0, 30, 
            YAOL);
        C2D_DrawCircleSolid(YAFGx+offset[0], YAFGy+offset[1], 0, 25, 
            YAGreen);
            
        for(int i = 0; i<10;i++){
    
            C2D_DrawRectSolid(YAFGenemies[i][1]*90-25+offset[0], YAFGenemies[i][0]+offset[1],0, 90, 35, YAOL);
    
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
        
        // u32 kHeld = hidKeysHeld();
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
        //      YAFGvely=YAFGvely-20;
        //  }
        if (kDown & KEY_A){
            YAFGvely=YAFGvely-30;
        }
        if (kDown & BIT(4)){
            YAFGvelx=YAFGvelx+10;
        }
        if (kDown & BIT(5)){
            YAFGvelx=YAFGvelx-10;
        }
        YAFGvelx*=.9;
        YAFGvely+=2;
        YAFGvely*=.9;
        YAFGx+=YAFGvelx;
        YAFGy+=YAFGvely;

        display();
        
    }

init();
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