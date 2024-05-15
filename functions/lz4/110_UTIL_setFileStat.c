UTIL_STATIC int UTIL_setFileStat(const char *filename, stat_t *statbuf)
{
    int res = 0;

    if (!UTIL_isRegFile(filename))
        return -1;

    {
#if defined(_WIN32) || (PLATFORM_POSIX_VERSION < 200809L)
        struct utimbuf timebuf;
        timebuf.actime = time(NULL);
        timebuf.modtime = statbuf->st_mtime;
        res += utime(filename, &timebuf);  /* set access and modification times */
#else
        struct timespec timebuf[2];
        memset(timebuf, 0, sizeof(timebuf));
        timebuf[0].tv_nsec = UTIME_NOW;
        timebuf[1].tv_sec = statbuf->st_mtime;
        res += utimensat(AT_FDCWD, filename, timebuf, 0);  /* set access and modification times */
#endif
    }

#if !defined(_WIN32)
    res += chown(filename, statbuf->st_uid, statbuf->st_gid);  /* Copy ownership */
#endif

    res += chmod(filename, statbuf->st_mode & 07777);  /* Copy file permissions */

    errno = 0;
    return -res; /* number of errors is returned */
}