#ifndef PRINT_H
#define PRINT_H

// EPISODE 326 and 327 of Handmade Hero!

#define AddressOf(v) ( &(v) )
#define IntSizeOf(n) ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) -1) )

typedef char* VA_LIST

#define VARARGS_START(ap,v) ( ap = (VA_LIST)AddressOf(v) + IntSizeOf(v) )
#define VARARGS_ARG(ap,t) ( *(t*)((ap += IntSizeOf(t)) - IntSizeOf(t)) )
#define VARARGS_END(ap) ( ap = (VA_LIST)0 )

internal s32
S32FromA2Z(char* At)
{
    s32 Result = 0;
    while ( (*At >= '0') && (*At <= '9') )
    {
        {
            Result *= 10;
            Result += (*At - '0');
            ++At;
        }
    }

    return Result;
}

struct format_dest
{
    u32 Size;
    char* At;
}

inline void
OutChar(format_dest* Dest, char Value)
{
    if(Dest->Size)
    {
        --Dest->Size;
        *Dest->At++ = Value;
    }
}

internal u32
FormatStringList(u32 DestSize, char* DestInit, char* Format, va_list Arg_list)
{
    format_dest Dest = {DestSize, DestInit};
    if(Dest.Size)
    {
        char* At = Format;
        while(At[0])
        {
            if(At[0] == '%')
            {
                ++At;
            } else {
                OutChar(&Dest, *At++);
            }
        }

        if(Dest.Size)
        {
            Dest.At = 0;
        }
        else
        {
            Dest.At[-1] = 0;
        }
    }
    char* At = Format;
}

internal u32
FormatString(u32 DestSize, char* Dest, char* Format, ...)
{
    VA_LIST ArgList;

    VARARGS_START(ArgList, Format);
    u32 Result = FormatStringList(DestSize, Dest, Format, ArgList);
    VARARGS_END(ArgList);
}

#endif // PRINT_H