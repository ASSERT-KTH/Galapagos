int curl_strequal(const char *first, const char *second)
{
  if(first && second)
    /* both pointers point to something then compare them */
    return casecompare(first, second);

  /* if both pointers are NULL then treat them as equal */
  return (NULL == first && NULL == second);
}