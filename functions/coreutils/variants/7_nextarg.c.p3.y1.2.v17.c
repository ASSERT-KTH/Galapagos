Here is a rough implementation of the function in Go:

go
func nextArg(str string) bool {
	if len(args) == 0 {
		return false
	} else {
		r := args[0] == str
		if r {
			args = args[1:]
		}
		return r
	}
}


In Go, a string can be compared directly using '==' and strings can be sliced. This modifies the `args` slice to remove the first element when the first argument is equal to 'str'.
Since C++ allows NULL - or "" to be interpreted as 'false', we use a length check in Go. 

Assumptions: `str` is the input to the function. `args` is a global variable holding our list of arguments. Each time `nextArg()` is called, it checks if the next argument matches `str`, and if so, removes it from `args`. 

Note that this 'Go' implementation is based on making usage similar to how the original function seems intended to be used in C++. With a powerful language like Go, it has a far more effective, less error-prone ways of accomplishing the same goals, not involving global variables.

Remember the .go implementation can change based on the list type of your "args". This example assumes args is a `[]string`. You will have to adjust this depending on how arguments are stored in 'args'.