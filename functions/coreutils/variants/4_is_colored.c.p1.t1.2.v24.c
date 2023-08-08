int is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);
    
  if(len == 0 || (len == 1 && *s == '0')
     || (len == 2 && strstr(s, "00") == s)){
        return 0;
    }
  return 1;
}