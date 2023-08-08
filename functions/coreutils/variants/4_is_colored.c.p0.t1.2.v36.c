is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  if (len == 0) {
    return false;
  } else if (len == 1) {
    return STRNCMP_LIT(s, "0");
  } else if (len == 2) {
    return STRNCMP_LIT(s, "00");
  } else {
    return true;
  }
}