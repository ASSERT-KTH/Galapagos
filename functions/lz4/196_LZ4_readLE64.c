static U64 LZ4_readLE64(const void* memPtr)
{
    if (LZ4_isLittleEndian()) {
        return LZ4_read64(memPtr);
    } else {
        const BYTE* p = (const BYTE*)memPtr;
        /* note: relies on the compiler to simplify this expression */
        return (U64)p[0] | ((U64)p[1]<<8) | ((U64)p[2]<<16) | ((U64)p[3]<<24)
            | ((U64)p[4]<<32) | ((U64)p[5]<<40) | ((U64)p[6]<<48) | ((U64)p[7]<<56);
    }
}