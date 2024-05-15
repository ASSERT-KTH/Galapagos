static U64 LZ4F_readLE64 (const void* src)
{
    const BYTE* const srcPtr = (const BYTE*)src;
    U64 value64 = srcPtr[0];
    value64 |= ((U64)srcPtr[1]<<8);
    value64 |= ((U64)srcPtr[2]<<16);
    value64 |= ((U64)srcPtr[3]<<24);
    value64 |= ((U64)srcPtr[4]<<32);
    value64 |= ((U64)srcPtr[5]<<40);
    value64 |= ((U64)srcPtr[6]<<48);
    value64 |= ((U64)srcPtr[7]<<56);
    return value64;
}