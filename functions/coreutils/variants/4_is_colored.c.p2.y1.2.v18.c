is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string; 
        
  if (len == 1 && (s[0]=='0')) {
    return 0;
  }     
  else if (len == 2 && (s[0]=='0' && s[1]=='0')) {
    return 0;
  }
  else if (len == 0) {
    return 0;
  } 
  else {
    return 1;
  }
}