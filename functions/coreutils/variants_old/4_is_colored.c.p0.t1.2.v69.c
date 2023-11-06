is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  return !(len == 0
        || strcmp(s,”0”) == 0
        || strcmp(s,”00”) == 0);
}