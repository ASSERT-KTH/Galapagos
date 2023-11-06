is_colored(enum indicator_no type)
{
  size_t len = color_indicator[type].len;

  if (len == 0)
  {
    return false;
  }
  else if (len == 1 && color_indicator[type].string[0] == '0')
  {
    return false;
  }
  else if (len == 2 && color_indicator[type].string[0] == '0' 
                      && color_indicator[type].string[1] == '0')
  {
    return false;
  }
  else
  {
    return true;
  }
}