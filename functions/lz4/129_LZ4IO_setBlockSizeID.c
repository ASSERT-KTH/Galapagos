size_t LZ4IO_setBlockSizeID(LZ4IO_prefs_t* const prefs, unsigned bsid)
{
    static const size_t blockSizeTable[] = { 64 KB, 256 KB, 1 MB, 4 MB };
    static const unsigned minBlockSizeID = 4;
    static const unsigned maxBlockSizeID = 7;
    if ((bsid < minBlockSizeID) || (bsid > maxBlockSizeID)) return 0;
    prefs->blockSizeId = (int)bsid;
    prefs->blockSize = blockSizeTable[(unsigned)prefs->blockSizeId-minBlockSizeID];
    return prefs->blockSize;
}