creat (const char *filename, mode_t mode)
{
#if OPEN_TRAILING_SLASH_BUG
  /* Fail if the filename ends in a slash,
     as POSIX says such a filename must name a directory
     <https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap04.html#tag_04_13>:
       "A pathname that contains at least one non-<slash> character and that
        ends with one or more trailing <slash> characters shall not be resolved
        successfully unless the last pathname component before the trailing
        <slash> characters names an existing directory"
     creat() is defined as being equivalent to open() with flags
     O_CREAT | O_TRUNC | O_WRONLY.  Therefore:
     If the named file already exists as a directory, then creat() must fail
     with errno = EISDIR.
     If the named file does not exist or does not name a directory, then
     creat() must fail since creat() cannot create directories.  */
  {
    size_t len = strlen (filename);
    if (len > 0 && filename[len - 1] == '/')
      {
        errno = EISDIR;
        return -1;
      }
  }
#endif

#if defined _WIN32 && !defined __CYGWIN__
  /* Remap the 'x' bits to the 'r' bits.  */
  mode = (mode & ~0111) | ((mode & 0111) << 2);
#endif

  return orig_creat (filename, mode);
}