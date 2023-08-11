is_colored (enum indicator_no type)
{
  size_t length = color_indicator[type].len;
  char const *str = color_indicator[type].string;
  if(length == 0){
    return false;
  }
  else if(length == 1 && STRNCMP_LIT (str, "0") == 0){
    return false;
  }
  else if(length == 2 && STRNCMP_LIT (str, "00") == 0){
    return false;
  }
  else{
    return true;
  }
}