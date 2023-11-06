is_colored (enum indicator_no type)
{
  char* s = color_indicator[type].string;
  int len = 0; 
  while (s[len] != '\0') {
    len++;
  }
  
  return !(len == 0 || (len == 1 && s[0] == '0') || (len == 2 && s[0] == '0' && s[1] == '0'));
}