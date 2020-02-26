#ifndef MAIN_H
#define MAIN_H

struct image {
    u32 Width;
    u32 Height;
    u32 BytesPerPixel;
    u32 MemorySize;
    u32* Memory;
};

struct material {
    v3 Color;
};

struct plane {
    v3 Normal;
    f32 Distance;
    u32 MatIndex;
};

struct sphere {
    v3 Position;
    f32 Radius;
    u32 MatIndex;
};

struct world {
    u32 MaterialCount;
    material *Materials;

    plane Ground;
    
    u32 SphereCount;
    sphere *Spheres;
};

#endif // MAIN_H