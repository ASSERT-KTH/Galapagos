UTIL_STATIC U64 UTIL_getFileSize(const char* infilename)
{
    int r;
    struct UTIL_TYPE_stat statbuf;

    r = UTIL_stat(infilename, &statbuf);
    if (r || !UTIL_STAT_MODE_ISREG(statbuf.st_mode)) return 0;   /* No good... */
    return (U64)statbuf.st_size;
}