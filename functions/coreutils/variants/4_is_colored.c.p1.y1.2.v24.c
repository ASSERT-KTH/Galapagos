Variant 1:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if(len == 0){
    return 0;
  }   
  else if(len == 1 && STRNCMP_LIT (s, "0") == 0){
    return 0
  }
  else if(len == 2 && STRNCMP_LIT (s, "00") == 0){
    return 0;
  }
  else{
    return 1;
  }  
}

Variant 2:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  return !(len == 0)? ((len == 1 && STRNCMP_LIT (s, "0") != 0) || (len != 1)): ((len == 2 && STRNCMP_LIT (s, "00") == 0)?0:1);
}

Variant 3:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if(len == 0 || len == 1){
    return STRNCMP_LIT (s, "0") != 0;
  }   
    
  if(len == 2){
    return STRNCMP_LIT (s, "00") != 0;
  }
  
  return 1;
}

Variant 4:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  int result = 1;
  if(len == 0 || ((len == 1 || len == 2) && s[len-1] == '0')){
    result = 0;
  }
  return result;
}
