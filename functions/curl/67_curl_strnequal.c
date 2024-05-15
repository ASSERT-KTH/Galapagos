int curl_strnequal(const char *first, const char *second, size_t max)
{
  if(first && second)
    /* both pointers point to something then compare them */
    return ncasecompare(first, second, max);

  /* if both pointers are NULL then treat them as equal if max is non-zero */
  return (NULL == first && NULL == second && max);
}