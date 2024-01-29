The "enum" feature doesn't exist in Go like it does in C. However, I will assume `type` is an integer, which is typically how many Go programmers represent things like enums. Likewise, the `color_indicator` would be a slice of struct, with "string" and "len" as fields. The enum color "indicator_no" would be considered as an integer index referencing elements in the colorIndicator slice, so let's assume `colorIndicator` as the equivalent representation and is previously defined in Go.

Here's how you might write the function "is_colored" in Go:

go
func is_colored(type_ int) bool {
  len := colorIndicator[type_].len
  s := colorIndicator[type_].string

  return !(len == 0 || (len == 1 && s == "0") || (len == 2 && s == "00"))
}
