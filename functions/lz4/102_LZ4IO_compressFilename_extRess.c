LZ4IO_compressFilename_extRess(unsigned long long* inStreamSize,
                               cRess_t ress,
                               const char* srcFileName, const char* dstFileName,
                               int compressionLevel,
                               const LZ4IO_prefs_t* const io_prefs)
{
#if LZ4IO_MULTITHREAD
    /* only employ multi-threading in the following scenarios: */
    if ( (io_prefs->nbWorkers != 1)
      && (io_prefs->blockIndependence == LZ4F_blockIndependent)  /* blocks must be independent */
      )
        return LZ4IO_compressFilename_extRess_MT(inStreamSize, ress, srcFileName, dstFileName, compressionLevel, io_prefs);
#endif
    /* Only single-thread available */
    return LZ4IO_compressFilename_extRess_ST(inStreamSize, ress, srcFileName, dstFileName, compressionLevel, io_prefs);

}