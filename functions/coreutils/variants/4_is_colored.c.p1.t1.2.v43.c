is_colored(enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len > 2 || len == 0)
    return 0;
  else 
    return strcmp(s, (len == 1) ? "0" : "00");
}