
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
#include <citro2d.h>

C2D_Text Text;
C2D_Font font;
C2D_TextBuf g_staticBuf;

void YACTRText(char input[100], float x, float y, float size){

		g_staticBuf  = C2D_TextBufNew(4096);
		font = C2D_FontLoadSystem(CFG_REGION_USA);
		C2D_TextFontParse(&Text, font, g_staticBuf, input);
		C2D_TextOptimize(&Text);
		C2D_DrawText(&Text, 0, x, y, 0.5f, size, size);
        C2D_TextBufDelete(g_staticBuf);
        C2D_FontFree(font);
}