int LZ4IO_compressFilename_Legacy(const char* input_filename,
                                  const char* output_filename,
                                  int compressionlevel,
                                  const LZ4IO_prefs_t* prefs)
{
    TIME_t const timeStart = TIME_getTime();
    clock_t const cpuStart = clock();
    unsigned long long processed = 0;
    int r = LZ4IO_compressLegacy_internal(&processed, input_filename, output_filename, compressionlevel, prefs);
    LZ4IO_finalTimeDisplay(timeStart, cpuStart, processed);
    return r;
}