The C program variant is provided below:


is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  // Different approach to evaluating the return statement below
  if (len == 0) {
      return 0;
  }
  
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) {
      return 0;
  }
  
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) {
      return 0;
  }
  
  return 1;
}

The correctness and functionality of this function is equivalent to the original one, just organized in a different manner. The key idea is instead of running `-` operation inside a function block, the C program is simply written with multiple `if statements` connected to separate 'return 0' commands under same `length` condition limitation. When all these conditions fail then 'return 1' is evaluated in the last.