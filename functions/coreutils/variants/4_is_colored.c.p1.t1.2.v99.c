
is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  
  if (len == 0) {
    return 0;
  } else if (len == 1 && *s == '0') {
    return 0;
  } else if (len == 2 && *((char *)memchr(s, '0', 2)) == '0' && *s == s[1]) {
    return 0;
  } else {
    return 1;
  }
}
