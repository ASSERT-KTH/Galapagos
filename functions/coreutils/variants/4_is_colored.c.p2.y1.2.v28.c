int is_colored (enum indicator_no type)
{
  color val = color_indicator[type];
  size_t len = val.len;
  char const *s = val.string;

  int cond1 = len == 0;
  int cond2 = len == 1 && strlen(s) == 1 && s[0] == '0';
  int cond3 = len == 2 && strcmp(s, "00") == 0;

  return ! (cond1 || cond2 || cond3);
}