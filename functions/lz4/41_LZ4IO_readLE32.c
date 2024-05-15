static unsigned LZ4IO_readLE32 (const void* p)
{
    const unsigned char* const srcPtr = (const unsigned char*)p;
    unsigned value32 = srcPtr[0];
    value32 += (unsigned)srcPtr[1] <<  8;
    value32 += (unsigned)srcPtr[2] << 16;
    value32 += (unsigned)srcPtr[3] << 24;
    return value32;
}