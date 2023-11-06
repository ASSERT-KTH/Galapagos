is_colored (enum indicator_no type)
{
  size_t length = color_indicator[type].len;
  char const *string = color_indicator[type].string;

  if (length == 0) // Check if length is zero
    return 0;
  else if (length == 1 && STRNCMP_LIT (string, "0") == 0) // Check if single zero
    return 0;
  else if (length == 2 && STRNCMP_LIT (string, "00") == 0) // Check if double zero
    return 0;
  else // If none of the above, must be colored
    return 1;
}