There's no provide Go equivalent for "STREQ" C macro,

You do range checking for strings in Go unlike in C,

Also In Go there's no null for strings unlike C, You check with empty value in Go

So the semantic equivalent might be something like this

go
func nextArg(args *string, str string) bool {
      if *args == "" {
         return false
     } else {
         r := *args == str
         if r {
            *args = str
         }
         return r
     }
}
