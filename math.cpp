#ifndef MATH_CPP
#define MATH_CPP

#include "math.h"

namespace Math {



inline s32
Clamp(s32 value, s32 min, s32 max)
{
    if(value >= max) {
        return max;
    }
    else if(value <= min) {
        return min;
    } else {
        return value;
    }
}

inline s32
SafeSubtract(s32 a, s32 b)
{
    if(a < S32MIN + b) {
        return S32MIN;
    }
    else if(a > S32MAX - b) {
        return S32MAX;
    } else {
        return a - b;
    }
}



}

#endif // MATH_CPP