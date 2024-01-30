The provided C code seems to have a few errors. There's an inconsistency between the argument provider in function is `str` but `args` used in implementation, besides the function is not well defined and missing some key information like its return type. I will assume intended function behaves like this: it scans null-terminated string (array of characters) and checks for matches with provided `str`. If match is found, it points to next argument / character. 

This function might work completely different in the context of a broader code, however. Still, here is a similar idea translated as a Go function.

go
package main

import "strings"
  

func NextArg(s *string, str string) bool {
	if s == nil || *s == "" {
		return false
	} else {
		r := strings.HasPrefix(*s, str)
	if r {
       *s = (*s)[len(str):]
    }
	return r
  }
}


NOTE: Strings are passed immutably in Golang, therefore a pointer to string (`*string`) was used to reflect this. Keep in mind that operation might be risky and not entirely common place for simple operations involving strings. Review in broader context might be required.