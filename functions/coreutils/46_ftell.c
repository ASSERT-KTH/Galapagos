ftell (FILE *fp)
{
  /* Use the replacement ftello function with all its workarounds.  */
  off_t offset = ftello (fp);
  if (LONG_MIN <= offset && offset <= LONG_MAX)
    return /* (long) */ offset;
  else
    {
      errno = EOVERFLOW;
      return -1;
    }
}