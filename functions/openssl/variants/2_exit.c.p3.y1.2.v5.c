The Go programming language, as designed, doesn't have built-in support for the functionality depicted on this provided C code, specifically:

1. Dlsym is a Unix-specific library function to fetch symbol details from shared objects (.so) or executable file itself. There's no library in typical Go that provides similar functionality.

2. The explicit use of sleep functions in Go doesn't block the exit of the program.

3. There's no exact C style "exit" function mechanism in Go. You cannot replace os.Exit because it directly stops the program exactly after it is called.

Therefore, an equivalent conversion into Go is technically not possible adhering to the way code is written and also the constraint that we need to explicitly keep within the same function that you have described. Please note that mentioned issues are basic limitations of languages, one being a low-level language (like C) and other with managed operations (like Go).