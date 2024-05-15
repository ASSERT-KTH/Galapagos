static LZ4F_CDict* LZ4IO_createCDict(const LZ4IO_prefs_t* io_prefs)
{
    size_t dictionarySize;
    void* dictionaryBuffer;
    LZ4F_CDict* cdict;
    if (!io_prefs->useDictionary) return NULL;
    dictionaryBuffer = LZ4IO_createDict(&dictionarySize, io_prefs->dictionaryFilename);
    if (!dictionaryBuffer) END_PROCESS(29, "Dictionary error : could not create dictionary");
    cdict = LZ4F_createCDict(dictionaryBuffer, dictionarySize);
    free(dictionaryBuffer);
    return cdict;
}