Option 1:
In this version, we switch the discriminator against non colored situations to a more explicit series check of conditions. This could theoretically make the logic clear to other developers working at the code. Not forcing early return can sometimes ease readability at simple functions. 

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  // direct check for non color text
  if (len == 0 
      || (len == 1 && STRNCMP_LIT(s, "0") == 0)
      || (len == 2 && STRNCMP_LIT(s, "00") == 0))
  {
    //non colored
    return 0;
  }
  
  return 1;  // colored
}


Option 2:
This version is still maintaining the logical reasoning of the original, but more explicitly assigning boolean checks to variable results can enhance readability as well. Especially for the ones that are not 100% comfortable at logical operations within if statements.

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  int len_zero = (len == 0);
  
  int len_one_zero = (len == 1 && STRNCMP_LIT (s, "0") == 0);
  
  int len_two_zero = (len == 2 && STRNCMP_LIT (s, "00") == 0);
  
  // inverse nand gate shorthand
  return ! (len_zero || len_one_zero || len_two_zero);
}
