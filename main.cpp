#include <windows.h>
#include "win32_crt.c"
#include "types.h"

#define IMG_WIDTH 80
#define IMG_HEIGHT 40
#define BYTESPERPIXEL 4

#include "math.cpp"
#include "main.h"
#include "bmp.cpp"


internal int
Main(HINSTANCE Instance) {
    
    image Image         = {0};
    Image.Width         = IMG_WIDTH;
    Image.Height        = IMG_HEIGHT;
    Image.BytesPerPixel = BYTESPERPIXEL;
    Image.MemorySize    = Image.Width*Image.Height*Image.BytesPerPixel;
    Image.Memory        = (u32*)VirtualAlloc(NULL, Image.MemorySize, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    
    
    
    world World = {0};

    material Materials[3] = {0};
    {
        Materials[0].Color = Math::V3(0.3f, 0.4f, 1.0f);

        Materials[1].Color = Math::V3(0.9f, 0.4f, 0.2f);
        Materials[2].Color = Math::V3(0.7f, 1.0f, 0.6f);
    }
    World.MaterialCount = ArrayCount(Materials);
    World.Materials     = Materials;

    World.Ground.Normal   = Math::V3(0.0f, 0.0f, 1.0f);
    World.Ground.Distance = 0.0f;
    World.Ground.MatIndex = 2;

    sphere Spheres[1] = {0};
    {
        Spheres[0].Position = Math::V3(0.0f, 0.0f, 0.0f);
        Spheres[0].Radius   = 1.0f;
        Spheres[0].MatIndex = 1;
    }
    World.SphereCount = ArrayCount(Spheres);
    World.Spheres = Spheres;

    u32* OutPixel = Image.Memory;
    for (u32 y=0;y<Image.Height;y++)
    {
        for (u32 x=0;x<Image.Width;x++)
        {
            *OutPixel = 0xFF0000FF;
            OutPixel = Image.Memory + y*Image.Width + x;
        }
    }

    WriteEntireImageFile(&Image, "img.bmp");

    return 0;
}

void
WinMainCRTStartup() 
{
	u32 result = Main(GetModuleHandle(NULL));
	ExitProcess(result);
}