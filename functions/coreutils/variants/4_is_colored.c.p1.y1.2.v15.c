Variant 1:

is_colored(enum indicator_no type) {
  if(type == 0 || type == 1 || type == 2) {
    char const *s = color_indicator[type].string;
    size_t len = color_indicator[type].len;
    
    if(len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0)) {
      return 0;
    } else {
      return 1;
    }
  }
  
  return 1;
}


Variant 2:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if (len == 0)
  {
      return 0;
  }
  else if (len == 1 && STRNCMP_LIT (s, "0") == 0)
  {
      return 0;
  }
  else if (len == 2 && STRNCMP_LIT (s, "00") == 0)
  {
      return 0;
  }
  else
  {
      return 1;
  }
}


Variant 3:

is_colored (enum indicator_no type) {
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  if (len != 0 && !(len == 1 && STRNCMP_LIT (s, "0") == 0) && !(len == 2 && STRNCMP_LIT (s, "00") == 0)) {
      return 1; 
  }

  return 0;
}


Variant 4:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  while(1) {
      if(len == 0) break; 
      if(len == 1 && STRNCMP_LIT (s, "0") == 0) break;
      if(len == 2 && STRNCMP_LIT (s, "00") == 0) break;
      
      return 1;
  }
  
  return 0;
}
