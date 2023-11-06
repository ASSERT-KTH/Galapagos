int is_colored (enum indicator_no type)
{
  column_indi col = color_indicator[type];
  
  if(col.len != 0 && !((col.len == 1 && strncmp(col.string, "0", 1) == 0) || (col.len == 2 && strncmp(col.string, "00", 2) == 0)))
  {
      return 1;
  }

  return 0;
}