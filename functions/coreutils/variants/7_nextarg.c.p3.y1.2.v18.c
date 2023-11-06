There is no exact or direct mapping between C and Go Lang for certain features such as the ability to directly manipulate pointers, although we can create a semantically equivalent code:

First, we need to convert the idea of `STREQ` function in C to Go lang. Typically `STREQ` in C is a macro that is equivalent to `strcmp` function, which compares two strings and returns true if they are equivalent. For this purpose, we can use `==` operator in Go as such a function is already built-in.
Also, `args` seems to be a global variable being used.

There are multiple problems converting this code "as-is" to Go:

- Unclear what should occur when the check `if (*args == nullptr)` is correct.
- C allows for pointer arithmetic, i.e., `args += r;`, Go does not.
- `args`variable is undefined.

Considering these, let's write a code that encapsulates the basic idea:

Go
package main

import (
	"strings"
)

// Convert a sequence of args into string
// Initialization is arbitrary- "Dummy" for this example
var args string = "Dummy"

func nextarg(str string) bool {
	if strings.Compare(*args, nil){ // Equivalent of nullptr in Go
		return false
	} else {
		r := strings.Compare(*args, str) 
		*args += r
		return r
	}
}


Finally, remember, in Go you can't alter the original string , it is a read only slice of bytes. We are also assuming `args` to be a pointer to a string without any prior context which is not a typical task in Go as strings are usually passed by value - it's efficient and safe, since strings are immutable in Go.

The bottom line is, the provided example is a rather low-level detail thing you'd do in C, but in go the philosophy is to abstract these sort of implementation details.

Note: everything here depends on how everything else in the given C-code functions i.e., whats the exact application of `args` and `str` and the context in general. Hence, one might want to tweak the above codes to ensure correct working in the Go lang ecosystem. For e.g., `nextarg` should take in args as an argument itself if it is supposed to be a string comparision function. And pointers for string comparision in such a simple case is certainly not the right way to do it in Go language.