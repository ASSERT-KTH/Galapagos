is_colored(enum indicator_no type)
{
  int check_flag = 0;
  
  size_t len = color_indicator[type].len; 
  char const *s = color_indicator[type].string;

  if(len == 0)
  {
    check_flag = check_flag || true; 
  }
  else if(len == 1)
  {
    if(STRNCMP_LIT (s, "0") == 0) check_flag = check_flag || true;
  }
  else if(len == 2)
  {
    if(STRNCMP_LIT (s, "00") == 0) check_flag = check_flag || true; 
  }
  
  return !check_flag;
}