enum indicator_no type;
{
  const char *s = color_indicator[type].string;
  size_t len = strlen(s);
  if (len == 0)
  {
    return 0;
  }
  else if ((len == 1 && strcmp(s, "0") == 0) ||
           (len == 2 && strcmp(s, "00") == 0))
  {
    return 0;
  }
  return 1;
}