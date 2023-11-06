Variant 1:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  return !(len == 1 && STRNCMP_LIT (s, "0") == 0) && !(len == 2 && STRNCMP_LIT (s, "00") == 0) && len != 0;
}


Variant 2:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  bool islen0 = (len == 0); 
  bool islen1 = (len == 1 && STRNCMP_LIT (s, "0") == 0);
  bool islen2 = (len == 2 && STRNCMP_LIT (s, "00") == 0);

  return !(islen0 || islen1 || islen2);
}


Variant 3:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len == 0) return 0;
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) return 0;
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) return 0;
  
  return 1;
}


Variant 4:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  bool not_colored = (len == 0) || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0);

  return !(not_colored);
}


Variant 5:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  return len != 0 && !(len == 1 && STRNCMP_LIT (s, "0") == 0) && !(len == 2 && STRNCMP_LIT (s, "00") == 0);
}
