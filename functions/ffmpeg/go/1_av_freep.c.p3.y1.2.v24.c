Unfortunately, making a direct, semantically equivalent translation of this code from C to Go is difficult due to several fundamental differences between them:

- Go has automatic garbage collection and it doesn't support manual memory management methods like `av_free()`. Therefore, this function doesn't make sense in Go.

- Go being a statically typed language, it does not support raw manipulation of any memory block with no type attached (void pointer), while the av_freep function in C is designed to operate on such generic data.

Technically, the only portion of your function that isn't managing memory is nullifying the located data pointed at by the incoming pointer (except in Go it's not handled via pointers). Say if incoming data is type of `*string`, your function could be translated to following Go function:

go
func resetString(s *string) {
	*s = ""
}


But this is for a specific type (`string`) and you'd need reset functions for other potential types as well (`*int`, `*[]byte`, etc). That's why a directly equivalent function in Go to the referenced C function which works for all kinds of data just can't be made.