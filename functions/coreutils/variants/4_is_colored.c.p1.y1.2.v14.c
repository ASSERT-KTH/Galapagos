1. Using Expressive If - Else Conditions:


is_colored(enum indicator_no type) 
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;

    if (len == 0) {
        return 0;
    } else if (len == 1 && STRNCMP_LIT (s, "0") == 0) {
        return 0;
    } else if (len == 2 && STRNCMP_LIT (s, "00") == 0) {
        return 0;
    } else {
        return 1;
    }
}


2. Using Bitwise Operations:


is_colored (enum indicator_no type) 
{    
 size_t len = color_indicator[type].len;
 char const *s = color_indicator[type].string;

 return ! ((len == 0)<<2
            | ((len == 1 & STRNCMP_LIT (s, "0") == 0)<<1)
            | (len == 2 & STRNCMP_LIT (s, "00") == 0));
}


3. With Ternary Conditional Operator:


 is_colored (enum indicator_no type) 
 {   
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;

  return (len == 0
           || (len == 1 && STRNCMP_LIT (s, "0") == 0)
           || (len == 2 && STRNCMP_LIT (s, "00")==0)) ? 0 : 1;
 }
 