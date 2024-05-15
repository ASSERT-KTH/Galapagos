LZ4IO_prefs_t* LZ4IO_defaultPreferences(void)
{
    LZ4IO_prefs_t* const prefs = (LZ4IO_prefs_t*)malloc(sizeof(*prefs));
    if (!prefs) END_PROCESS(11, "Can't even allocate LZ4IO preferences");
    prefs->passThrough = 0;
    prefs->overwrite = 1;
    prefs->testMode = 0;
    prefs->blockSizeId = LZ4IO_BLOCKSIZEID_DEFAULT;
    prefs->blockSize = 0;
    prefs->blockChecksum = 0;
    prefs->streamChecksum = 1;
    prefs->blockIndependence = 1;
    prefs->sparseFileSupport = 1;
    prefs->contentSizeFlag = 0;
    prefs->useDictionary = 0;
    prefs->favorDecSpeed = 0;
    prefs->dictionaryFilename = NULL;
    prefs->removeSrcFile = 0;
    prefs->nbWorkers = LZ4IO_defaultNbWorkers();
    return prefs;
}