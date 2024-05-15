_gcry_is_secure (const void *a)
{
  if (no_secure_memory)
    return 0;
  if (is_secure_func)
    return is_secure_func (a) ;
  return _gcry_private_is_secure (a);
}