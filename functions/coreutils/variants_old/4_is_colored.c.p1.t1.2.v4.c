is_colored (enum indicator_no type)
{
  bool result;

  if (color_indicator[type].len == 0)
  {
    result = false;
  }
  else if (color_indicator[type].len == 1 
           && STRNCMP_LIT (color_indicator[type].string, "0") == 0)
  {
    result = false;
  }
  else if (color_indicator[type].len == 2 
           && STRNCMP_LIT (color_indicator[type].string, "00") == 0)
  {
    result = false;
  }
  else 
  {
    result = true;
  }

  return result;
}