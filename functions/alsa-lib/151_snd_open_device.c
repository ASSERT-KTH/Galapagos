static inline int snd_open_device(const char *filename, int fmode)
{
	int fd;

#ifdef O_CLOEXEC
	fmode |= O_CLOEXEC;
#endif
	fd = open(filename, fmode);

/* open with resmgr */
#ifdef SUPPORT_RESMGR
	if (fd < 0) {
		if (errno == EAGAIN || errno == EBUSY)
			return fd;
		if (! access(filename, F_OK))
			fd = rsm_open_device(filename, fmode);
	}
#endif
#ifndef O_CLOEXEC
	if (fd >= 0)
		fcntl(fd, F_SETFD, FD_CLOEXEC);
#endif
	return fd;
}