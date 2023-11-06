is_colored(enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  int bool_val;

  bool_val = ((len == 0)||(len == 1 && STRNCMP_LIT(s, "0") == 0)||(len == 2 && STRNCMP_LIT(s, "00") == 0));

  if (!bool_val)
    return 1;

  return 0;
}