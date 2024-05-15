static U32 LZ4F_readLE32 (const void* src)
{
    const BYTE* const srcPtr = (const BYTE*)src;
    U32 value32 = srcPtr[0];
    value32 |= ((U32)srcPtr[1])<< 8;
    value32 |= ((U32)srcPtr[2])<<16;
    value32 |= ((U32)srcPtr[3])<<24;
    return value32;
}