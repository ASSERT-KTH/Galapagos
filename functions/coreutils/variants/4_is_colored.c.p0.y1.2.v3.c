bool is_colored (enum indicator_no type)
{
  size_t length = color_indicator[type].len;
  char const *str = color_indicator[type].string;

  if (length == 0) {
    return false;  
  } else if (length == 1 && strncmp(str, "0", 1) == 0) { 
    return false;        
  } else if (length == 2 && strncmp(str, "00", 2) == 0) {
    return false;
  } else {
    return true;
  }  
}