#ifndef BMP_CPP
#define BMP_CPP

#pragma pack(push, 1)
struct bmp_header {
    u8 Chr[2];
    u32 Size;
    u16 Reserved[2];
    u32 StartingOffset;
    
    u32 biSize;
    s32 Width;
    s32 Height;
    u16 Planes;
    u16 BitsPerPixel;
    u32 Compression;
    u32 SizeOfBitmap;
    s32 HorRes;
    s32 VerRes;
    u32 ColorsUsed;
    u32 ColorsImportant;
};
#pragma pack(pop)

internal bmp_header
CreateBMPHeader(const image* Image) {
    
    bmp_header Header      = {0};
    Header.Chr[0]          = 'B';
    Header.Chr[1]          = 'M';
    Header.Size            = sizeof(Header) + Image->MemorySize;
    Header.StartingOffset  = sizeof(Header);
    Header.biSize          = sizeof(BITMAPINFOHEADER);
    Header.Width           = Image->Width;
    Header.Height          = Image->Height;
    Header.Planes          = 1;
    Header.BitsPerPixel    = (WORD)(Image->BytesPerPixel*8);
    Header.Compression     = BI_RGB;
    Header.HorRes          = 128; // ??
    Header.VerRes          = 128; // ??
    Header.ColorsUsed      = 0;
    Header.ColorsImportant = 0;

    return Header;
};

internal void
WriteEntireImageFile(const image* Image, LPCSTR Name)
{
    bmp_header Header = CreateBMPHeader(Image);

    HANDLE file = CreateFileA(Name, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    int BytesWritten = 0;
    WriteFile(file, (void*)(&Header), sizeof(Header), (LPDWORD)&BytesWritten, NULL);
    WriteFile(file, Image->Memory, Image->MemorySize, (LPDWORD)&BytesWritten, NULL);

    CloseHandle(file);
}

#endif // BMP_CPP