Here is a different implementation of the aforementioned function:


is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  switch(color_indicator[type].len)
  {
    case 0:
      return false;
    case 1:
      return (strcmp(s, "0") != 0);
    case 2:
      return (strcmp(s, "00") != 0);
    default:
      return true;
  }
}


The above alternative implementation performs the same function as the initial one but rearranges the checks and uses a switch statement instead of conditional || operators. We have simplied the checks by replacing STRNCMP_LIT with strcmp because the length of comparison is already handled by the inspection of length before the comparison.