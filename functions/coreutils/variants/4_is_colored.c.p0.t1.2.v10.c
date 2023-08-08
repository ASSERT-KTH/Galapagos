is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  if (len == 0) {
    return false;
  }
  char const *s = color_indicator[type].string;
  if ((len == 1 && strncmp(s, "0", len) == 0) || (len == 2 && strncmp(s, "00", len) == 0)) {
    return false;
  }
  return true;
}