is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  bool condition_one = (len != 0);
  bool condition_two = ! (len == 1 && STRNCMP_LIT (s, "0") == 0);
  bool condition_three = ! (len == 2 && STRNCMP_LIT (s, "00") == 0);

  return (condition_one && condition_two && condition_three);
}