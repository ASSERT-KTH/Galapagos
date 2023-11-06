is_colored(enum indicator_no type)
{
  char const *str = color_indicator[type].string;
  size_t str_length = color_indicator[type].len;
  if(str_length == 0)
  {
    return false;
  }
  else
  {
    if(str_length == 1 && strcmp(str, "0") == 0)
    {
        return false;
    }
    else if(str_length == 2 && strcmp(str, "00") == 0)
    {
        return false;
    }
    else
    {
      return true;
    }
  }
}