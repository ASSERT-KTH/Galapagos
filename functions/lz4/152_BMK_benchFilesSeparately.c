BMK_benchFilesSeparately(const char** fileNamesTable, unsigned nbFiles,
                   int cLevel, int cLevelLast,
                   const char* dictBuf, int dictSize)
{
    int benchError = 0;
    unsigned fileNb;
    if (cLevel > LZ4HC_CLEVEL_MAX) cLevel = LZ4HC_CLEVEL_MAX;
    if (cLevelLast > LZ4HC_CLEVEL_MAX) cLevelLast = LZ4HC_CLEVEL_MAX;
    if (cLevelLast < cLevel) cLevelLast = cLevel;

    for (fileNb=0; fileNb<nbFiles; fileNb++)
        benchError |= BMK_benchFileTable(fileNamesTable+fileNb, 1, cLevel, cLevelLast, dictBuf, dictSize);

    return benchError;
}