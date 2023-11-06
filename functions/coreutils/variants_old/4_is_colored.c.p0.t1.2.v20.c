bool is_colored (enum indicator_no type)
{
  size_t leng = color_indicator[type].len;
  char const *str = color_indicator[type].string;

  if (leng == 0)
    return false;
  
  if ((leng == 1 && strcmp(str, "0") == 0))
    return false;
  
  if((leng == 2 && strcmp(str, "00") == 0))
    return false;
  
  return true;
}