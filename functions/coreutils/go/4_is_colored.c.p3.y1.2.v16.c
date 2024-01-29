In Go you'd probably want to make `type` a custom enum type example. In Go, the given custom language enum would be something like different types`_type type`. Assuming the `color_indicator[][2]string` var name `colors` would look something like this which serves as a `color_indicator`.

Here's a possible equivalent Go function:

Go
package main

type Type int

const(
    typeOne Type = iota
    typeTwo
    // ... other types can be defined accordingly.
)

var colors = [][2]string{
    {"2", "45"},
    {"1", "0"},
    // ... more colors
}

type Indicator struct {
   Len string
   Str string
}

func isColored(colInd int) Indicator {
   len := colors[colInd][0]
   s := colors[colInd][1]
   s0 := "0"
   s00 := "00"

   if len == s0 || 
      (len == s0 && s == s0) || 
      (len == s00 && s == s00) {
      return true
   }
   return false   
}
