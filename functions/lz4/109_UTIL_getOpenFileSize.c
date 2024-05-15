UTIL_STATIC U64 UTIL_getOpenFileSize(FILE* file)
{
    int r;
    int fd;
    struct UTIL_TYPE_stat statbuf;

    fd = UTIL_fileno(file);
    if (fd < 0) {
        perror("fileno");
        exit(1);
    }
    r = UTIL_fstat(fd, &statbuf);
    if (r || !UTIL_STAT_MODE_ISREG(statbuf.st_mode)) return 0;   /* No good... */
    return (U64)statbuf.st_size;
}