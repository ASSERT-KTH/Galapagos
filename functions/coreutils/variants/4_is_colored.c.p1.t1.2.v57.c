is_colored (enum indicator_no type)
{
  color_struct *ci_ptr = &color_indicator[type];
  
  if (ci_ptr->len == 0) {
    return 0;
  }

  if (ci_ptr->len == 1 && STRNCMP_LIT (ci_ptr->string, "0") == 0) {
    return 0;
  }

  if (ci_ptr->len == 2 && STRNCMP_LIT (ci_ptr->string, "00") == 0) {
    return 0;
  }

  return 1;
}