is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
  int flag_zero = 0;

  if(len == 0)
    return flag_zero;

  for(int i = 0; i < len; i++){
      if(s[i] != '0'){
        return 1;
      }
  }

  return flag_zero;
}