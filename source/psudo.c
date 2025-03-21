
// WARN: this code is untested, and will probably not build correctly

#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "./games/YAFG.c"

#include <3ds.h>


#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240


//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------

// gfxInitDefault();
// C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
// C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
// C2D_Prepare();
// C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
// C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
// u32 YAGreen   = C2D_Color32(0xAF, 0xBF, 0xAF, 0xFF);
// u32 YAOL   = C2D_Color32(0x33, 0x36, 0x3F, 0xFF);
// u32 YABlue  = C2D_Color32(0xA7, 0xC7, 0xD8, 0xFF);

	// Main loop
	while (aptMainLoop())
	{
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break;
		YAFG();
	}

	// // Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
