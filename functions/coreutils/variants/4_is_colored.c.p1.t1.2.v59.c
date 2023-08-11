bool is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  bool returnValue = false;

  if(len ){
    if(len == 1){
        returnValue = STRNCMP_LIT (s, "0") != 0;
    }
    else if(len == 2){
        returnValue = STRNCMP_LIT (s, "00") != 0;
    }
    else{
        returnValue = true;
    }
  }

  return returnValue;
}