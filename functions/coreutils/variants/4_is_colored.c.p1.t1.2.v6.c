is_colored (enum indicator_no type) 
{
  char const *s = color_indicator[type].string;

  if (strlen(s) == 0) {
    return 0;
  } 
  else if (strlen(s) == 1 && strncmp(s, "0", 1) == 0) {
    return 0;
  } 
  else if (strlen(s) == 2 && strncmp(s, "00", 2) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}