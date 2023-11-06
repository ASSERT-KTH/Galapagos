is_colored (enum indicator_no type)
{
  const struct color_indicator *col_ind = &color_indicator[type];
  
  char const *s = col_ind->string; 
  size_t len = col_ind->len;
  
  int return_val = !(len == 0 || (len == 1 && STRNCMP_LIT(s, "0") == 0) || (len == 2 && STRNCMP_LIT(s, "00") == 0));
  
  return return_val;
}