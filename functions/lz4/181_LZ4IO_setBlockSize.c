size_t LZ4IO_setBlockSize(LZ4IO_prefs_t* const prefs, size_t blockSize)
{
    static const size_t minBlockSize = 32;
    static const size_t maxBlockSize = 4 MB;
    unsigned bsid = 0;
    if (blockSize < minBlockSize) blockSize = minBlockSize;
    if (blockSize > maxBlockSize) blockSize = maxBlockSize;
    prefs->blockSize = blockSize;
    blockSize--;
    /* find which of { 64k, 256k, 1MB, 4MB } is closest to blockSize */
    while (blockSize >>= 2)
        bsid++;
    if (bsid < 7) bsid = 7;
    prefs->blockSizeId = (int)(bsid-3);
    return prefs->blockSize;
}