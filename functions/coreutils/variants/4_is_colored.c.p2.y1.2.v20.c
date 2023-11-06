is_colored (enum indicator_no type)
{
  struct color_indicator_t indicator = color_indicator[type];

  if(indicator.len==0)
    return 0;
  else if(STRNCMP_LIT (indicator.string, "0") == 0 || STRNCMP_LIT (indicator.string, "00") == 0)
    return 0;
  else
    return 1;
}