static compressFunc_t LZ4F_selectCompression(LZ4F_blockMode_t blockMode, int level, LZ4F_BlockCompressMode_e  compressMode)
{
    if (compressMode == LZ4B_UNCOMPRESSED)
        return LZ4F_doNotCompressBlock;
    if (level < LZ4HC_CLEVEL_MIN) {
        if (blockMode == LZ4F_blockIndependent) return LZ4F_compressBlock;
        return LZ4F_compressBlock_continue;
    }
    if (blockMode == LZ4F_blockIndependent) return LZ4F_compressBlockHC;
    return LZ4F_compressBlockHC_continue;
}