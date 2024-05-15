_gcry_random_bytes_secure (size_t nbytes, enum gcry_random_level level)
{
  void *buffer;

  /* Historical note (1.3.0--1.4.1): The buffer was only allocated
     in secure memory if the pool in random-csprng.c was also set to
     use secure memory.  */
  buffer = xmalloc_secure (nbytes);
  do_randomize (buffer, nbytes, level);
  return buffer;
}