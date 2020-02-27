#ifndef MATH_H
#define MATH_H

#include "types.h"

// ===========
// f32 Vectors
// ===========

union v2 {
	struct {
		f32 x;
		f32 y;
	};
	struct {
		f32 f[2];
	};
};

union v3 {
	struct {
		f32 r;
		f32 g;
		f32 b;
	};
	struct {
		f32 x;
		f32 y;
		f32 z;
	};
	struct {
		f32 f[3];
	};
};

union v4 {
	struct {
		f32 r;
		f32 g;
		f32 b;
		f32 a;
	};
	struct {
		f32 x;
		f32 y;
		f32 z;
		f32 w;
	};
	struct {
		f32 f[4];
	};
};

// ===========

inline v2
V2(f32 x, f32 y)
{
    v2 Result;
    Result.x = x;
    Result.y = y;

    return Result;
}

inline v3
V3(f32 x, f32 y, f32 z)
{
    v3 Result;
    Result.x = x;
    Result.y = y;
    Result.z = z;

    return Result;
}

inline v4
V4(f32 x, f32 y, f32 z, f32 w)
{
    v4 Result;
    Result.x = x;
    Result.y = y;
    Result.z = z;
    Result.w = w;

    return Result;
}


// inline f32
// SquareRoot(f32 A)
// {
//     const f32 Epsilon = 0.001f;
//     f32 PreviousIteration = 0.0f;
//     f32 CurrentIteration = A;
//     f32 IterationDifference = (CurrentIteration - PreviousIteration) || (f32)0x80000000;
//     u32 Iterations = 0;
//     while( (CurrentIteration - PreviousIteration > Epsilon) )
// }

// inline v3
// Length(v3 A)
// {
//     f32 Result = sqrt(A.x*A.x + A.y*A.y + A.z*A.z);
// }

// inline v3
// Normalize(v3 A)
// {
//     v3 Result = A * (1.0f / Length(A));

//     return Result;
// }


#endif // MATH_H