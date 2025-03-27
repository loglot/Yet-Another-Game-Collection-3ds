
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
#include <citro2d.h>

C2D_Text Text;
C2D_Font font;
C2D_TextBuf g_staticBuf;
float scaleX = 1;
float scaleY = 1;

void YACTRText(char input[100], float x, float y, float size){

		g_staticBuf  = C2D_TextBufNew(4096);
		font = C2D_FontLoadSystem(CFG_REGION_USA);
		C2D_TextFontParse(&Text, font, g_staticBuf, input);
		C2D_TextOptimize(&Text);
		C2D_DrawText(&Text, 0, x, y, 0.5f, size, size);
        C2D_TextBufDelete(g_staticBuf);
        C2D_FontFree(font);
}
void DrawRect(int x, int y, int width, int height, u32 color, int depth){
	C2D_DrawRectSolid(x*scaleX, y*scaleY, depth, width*scaleX, height*scaleY, color);
}
void DrawCirc(int x, int y, int r, u32 color, int depth){
	C2D_DrawEllipseSolid((x-r)*scaleX, (y-r)*scaleY, 0, (r*2)*scaleX, (r*2)*scaleY, color);
}