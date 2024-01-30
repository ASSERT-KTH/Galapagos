Unfortunately, a direct translation of this function that maintains the original function signature isn't possible because Go and C are fundamentally different. For example, Go doesn't support enumerations in a similar way the C language does, but instead uses custom types with constant values. The code below is a conceptual equivalent, but assumes that an appropriate set up has been done (like declaring the "indicator_no" and "ColorIndicator" types and creating the "color_indicator" variable in accordance).

func isColored(t indicator_no) bool {
  length := len(color_indicator[t].string)
  str := color_indicator[t].string 

  if length == 0 || (length == 1 && str == "0") || 
    (length == 2 && str == "00"){
      return false 
  }

  return true
}