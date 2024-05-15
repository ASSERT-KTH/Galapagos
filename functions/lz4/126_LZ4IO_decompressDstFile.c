LZ4IO_decompressDstFile(unsigned long long* outGenSize,
                        dRess_t ress,
                        const char* input_filename,
                        const char* output_filename,
                        const LZ4IO_prefs_t* const prefs)
{
    int result;
    stat_t statbuf;
    int stat_result = 0;
    FILE* const foutput = LZ4IO_openDstFile(output_filename, prefs);
    if (foutput==NULL) return 1;   /* failure */

    if ( !LZ4IO_isStdin(input_filename)
      && UTIL_getFileStat(input_filename, &statbuf))
        stat_result = 1;

    ress.dstFile = foutput;
    result = LZ4IO_decompressSrcFile(outGenSize, ress, input_filename, output_filename, prefs);

    fclose(foutput);

    /* Copy owner, file permissions and modification time */
    if ( stat_result != 0
      && !LZ4IO_isStdout(output_filename)
      && !LZ4IO_isDevNull(output_filename)) {
        UTIL_setFileStat(output_filename, &statbuf);
        /* should return value be read ? or is silent fail good enough ? */
    }

    return result;
}