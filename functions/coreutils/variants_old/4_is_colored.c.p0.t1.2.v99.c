is_colored (enum indicator_no type)
{
 size_t len = color_indicator[type].len;
 char const *s = color_indicator[type].string;
 bool isLenZeroOrOne = (len == 1);
 bool isLenZeroOrTwo = (len == 2);
 
 return ! (len == 0
           || (isLenZeroOrOne && STRNCMP_LIT (s, "0") == 0)
           || (isLenZeroOrTwo && STRNCMP_LIT (s, "00") == 0));
}