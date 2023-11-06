is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  switch (color_indicator[type].len) {
    case 0: return 0;
    case 1: return strncmp(s, "0", 1) !=0 ;
    case 2: return strncmp(s, "00", 2) !=0;
    default: return 1;
  }
}