UTIL_STATIC int UTIL_isDirectory(const char* infilename)
{
    stat_t statbuf;
    int r;
#if defined(_MSC_VER)
    r = _stat64(infilename, &statbuf);
    if (r) return 0;
    return (statbuf.st_mode & S_IFDIR);
#else
    r = stat(infilename, &statbuf);
    if (r) return 0;
    return (S_ISDIR(statbuf.st_mode));
#endif
}