Unfortunately, there isn't a direct way to map this function in Go, because Go error handling is fundamentally different from C - primarily because Go does not use the concept of errno for error management, doesn't have an inbuilt fflush/clearErr function like C, and most importantly, Go doesn't natively support execution cleanup like C does (atexit, error_exit).

Go handles errors by returning them as a second return value in a function call. Errors are not special cases and are a native part of Go's algorithms. For instance, file closing in Go would look something like:

f, err := os.Open("file")
if err != nil {
	panic(err)
}
// do some operations....

err = f.Close()
if err != nil {
	panic(err)
}

In other words, user programs are required to handle every mistake they may encounter, and panic is optional.

While you can replicate behavior of "fflush (stdout)" and "clearerr(stdout)" in Go but that usually handled internally with Write and Read functions, you also don't have an error function; You throw a panic instead. So in reality this refactor can be as simple as checking why an error happen (using strategies based on case) and throwing a panic to be recovered up in hierarchy by a recover() usually in top scope.