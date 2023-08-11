is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  bool isEmpty = (len == 0);
  bool isZero = (len == 1 && STRNCMP_LIT (s, "0") == 0);
  bool isDoubleZero = (len == 2 && STRNCMP_LIT (s, "00") == 0);

  return ! (isEmpty || isZero || isDoubleZero);
}