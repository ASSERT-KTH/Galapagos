open_stream_nc (gnupg_fd_t fd, const char *mode)
{
  es_syshd_t syshd;

#ifdef HAVE_W32_SYSTEM
  syshd.type = ES_SYSHD_HANDLE;
  syshd.u.handle = fd;
#else
  syshd.type = ES_SYSHD_FD;
  syshd.u.fd = fd;
#endif

  return es_sysopen_nc (&syshd, mode);
}