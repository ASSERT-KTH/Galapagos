is_colored (enum indicator_no type)
{
  color_indicator_t color_i = color_indicator[type];
  if (!color_i.len)
    return 0;
  else if (color_i.len == 1)
    return STRNCMP_LIT(color_i.string, "0") ? 1 : 0;
  else if (color_i.len == 2)
    return STRNCMP_LIT(color_i.string, "00") ? 1 : 0;
  else
    return 1;
}