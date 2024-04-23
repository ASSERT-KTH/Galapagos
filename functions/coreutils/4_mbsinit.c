mbsinit (const mbstate_t *ps)
{
# if defined _WIN32 && !defined __CYGWIN__
  /* Native Windows.  */
  /* MSVC defines 'mbstate_t' as an 8-byte struct; the first 4 bytes matter.
     On mingw, 'mbstate_t' is sometimes defined as 'int', sometimes defined as
     an 8-byte struct, of which the first 4 bytes matter.  */
  return ps == NULL || *(const unsigned int *)ps == 0;
# else
  /* Minix, HP-UX 11.00, Solaris 2.6, Interix, ...  */
  /* Maybe this definition works, maybe not...  */
  return ps == NULL || *(const char *)ps == 0;
# endif
}