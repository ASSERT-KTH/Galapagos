is_colored (enum indicator_no type)
{
  size_t length = color_indicator[type].len;
  char const *sequence = color_indicator[type].string;
  int is_Not_Colored = (length == 0 || (length == 1 && STRNCMP_LIT (sequence, "0") == 0)
                        || (length == 2 && STRNCMP_LIT (sequence, "00") == 0));
  return !is_Not_Colored;
}