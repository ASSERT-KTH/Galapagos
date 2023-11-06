It looks like there are some mistakes in the reference implementation you provided. In it, the `args` variable is not declared nor initialized. Besides, the `STREQ` function (typically used in C to compare strings) is not a standard C function, and it seems to be a macro. However, it appears that the purpose of the function is to compare `str` to the value pointed by `args`, increment the pointer if they are equal, then return the result of the comparison. 

Assuming `args` as a pair of strings (as it seems you're dealing with a sequence of arguments in a command-line scenario), here's a functional equivalent in Go. Changes have been made due to natural language syntax and approach differences:

go
func nextArg(args *[]string, str string) bool {
	if len(*args) == 0 {
		return false
	}

	r := (*args)[0] == str

    if r {
        // remove the first element
        *args = (*args)[1:]
    }

	return r
}

This function receives a pointer to a slice of strings (representing the arguments) and a string `str` to compare with. If the list is empty, it returns `false`, signifying that there are no more arguments. Otherwise, it checks if the first string in `args` equals `str` and removes the first element from the slice `args` if `r` is true. It then returns the comparison result. 

Go manages slices (dynamic arrays) instead of raw pointers, resulting in changes to how the equivalent functionality is achieved.
Please note that functions that change the content of parameters usually aren't idiomatic in Go. As a norm, mutable actions like these would be encapsulated in a method of a struct.