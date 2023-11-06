int is_colored(enum indicator_no type) {
  char const *string = color_indicator[type].string;
  size_t len = color_indicator[type].len;

  bool isLenZero = (len == 0);
  bool isLenOne = (len == 1 && STRNCMP_LIT (string, "0") == 0);
  bool isLenTwo = (len == 2 && STRNCMP_LIT (string, "00") == 0);

  return !(isLenZero || isLenOne || isLenTwo);
}