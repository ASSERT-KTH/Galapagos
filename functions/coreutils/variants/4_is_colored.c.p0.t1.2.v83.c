is_colored (enum indicator_no type)
{ 
  char const *s = color_indicator[type].string;
  
  //Assures that the string wasn't empty
  if (color_indicator[type].len != 0) 
  {
    size_t len = color_indicator[type].len;

    //Skips the single '0' and '00' cases
    if((len == 1 && strcmp(s, "0")) || (len == 2 && strcmp(s, "00")))
    {
        return true;
    }
  }  
  //Handles empty strings or numeric strings containing only zeros
  return false;
}