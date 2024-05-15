static void LZ4IO_loadDDict(dRess_t* ress, const LZ4IO_prefs_t* const prefs)
{
    if (!prefs->useDictionary) {
        ress->dictBuffer = NULL;
        ress->dictBufferSize = 0;
        return;
    }

    ress->dictBuffer = LZ4IO_createDict(&ress->dictBufferSize, prefs->dictionaryFilename);
    if (!ress->dictBuffer) END_PROCESS(25, "Dictionary error : could not create dictionary");
}