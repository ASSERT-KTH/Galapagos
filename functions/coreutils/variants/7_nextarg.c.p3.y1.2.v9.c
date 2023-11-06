It's not possible to completely maintain the function's signature. Go doesn't use optional parameters, nor pointers in the same way as the C language. Also, args are not defined or passed to nextarg function and also the str type in C function doesn't match with STREQ function type or return statements. 

Nevertheless, here is a function in Go similar to the original C implementation taking feasible Go rules and common practice into consideration:

go
func nextArg(args *[]string, str string) bool {
	if args == nil || len(*args) == 0 {
		return false
	}

	r := (*args)[0] == str
	if r {
		*args = (*args)[1:]
	}

	return r
}


This function takes a pointer to a slice of strings and a string to compare with. It checks if the slice is empty or nil, and returns false if so. Otherwise, it compares the first element of the slice with the provided string and removes the first element of the slice if they are the same. It returns whether he first element matched the provided string.