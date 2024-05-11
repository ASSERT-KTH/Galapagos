wipememory (void *ptr, size_t len)
{
#if defined(HAVE_W32_SYSTEM) && defined(SecureZeroMemory)
  SecureZeroMemory (ptr, len);
#elif defined(HAVE_EXPLICIT_BZERO)
  explicit_bzero (ptr, len);
#else
  /* Prevent compiler from optimizing away the call to memset by accessing
     memset through volatile pointer. */
  static void *(*volatile memset_ptr)(void *, int, size_t) = (void *)memset;
  memset_ptr (ptr, 0, len);
#endif
}