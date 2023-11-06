is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  
  if (s == NULL || *s == '\0')
    return 0;

  if ((s[1] == '\0' && *s == '0') || 
      (s[1] == '0' && s[2] == '\0' && *s == '0'))
    return 0;

  return 1;
}