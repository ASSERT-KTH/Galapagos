This function in Go checks if an argument string is equal to a specific string. But Go does not support pointer arithmetic natively like C does, so I wrote a function using slice operator instead. 

go
func nextArg(args *[]string, str string) bool {
	if len(*args) == 0 {
		return false
	} else {
		r := (*args)[0] == str
		if r {
			*args = (*args)[1:]
		}
		return r
	}
}

In the Go implementation `args` is supposed to be a slice of strings. The function checks if the first element of this slice equals to the given string, trims the slice if `true` and then return the result.
This is a best approximation because Go does not make it easy to imitate pointer arithmetic directly. Keep in mind, you have to pass pointer to slice while calling the function.
I believe this serves the intent of the original C function, only in a safe and Go idiomatic way. Note: the checking for empty slice (`if len(*args) == 0`)  assumes the role of the `nullptr` check in the C code.