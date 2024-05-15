size_t LZ4F_getBlockSize(LZ4F_blockSizeID_t blockSizeID)
{
    static const size_t blockSizes[4] = { 64 KB, 256 KB, 1 MB, 4 MB };

    if (blockSizeID == 0) blockSizeID = LZ4F_BLOCKSIZEID_DEFAULT;
    if (blockSizeID < LZ4F_max64KB || blockSizeID > LZ4F_max4MB)
        RETURN_ERROR(maxBlockSize_invalid);
    {   int const blockSizeIdx = (int)blockSizeID - (int)LZ4F_max64KB;
        return blockSizes[blockSizeIdx];
}   }