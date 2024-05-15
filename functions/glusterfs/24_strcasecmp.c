int strcasecmp(const char *s1, const char *s2)
{
  unsigned i;
  
  for (i = 0; s1[i] && s2[i]; i++)
    {
      unsigned char c1 = tolower( (unsigned char) s1[i]);
      unsigned char c2 = tolower( (unsigned char) s2[i]);

      if (c1 < c2)
	return -1;
      else if (c1 > c2)
	return 1;
    }

  return !s2[i] - !s1[i];	
}