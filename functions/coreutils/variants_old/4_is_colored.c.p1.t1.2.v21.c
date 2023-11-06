is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  
  if (len == 0)
    return 0;
  else if (len == 1 && strncmp(s, "0", len) == 0)
    return 0;
  else if (len == 2 && strncmp(s, "00", len) == 0)
    return 0;
  else
    return 1;
}