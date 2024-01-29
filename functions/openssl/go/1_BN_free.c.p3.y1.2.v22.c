This task can't be accurately translated into Go semantically because Go doesn't support the explicit and manual memory handling (like freeing) as found in C. In Go language, the garbage collector handles all memory allocation and deallocation processes.

However, we can still create similar functionality somewhat like so:

go
type BIGNUM struct {
	Flags int
}

const (
	BN_FLG_STATIC_DATA = 1 << iota
	BN_FLG_MALLOCED
)

func BN_get_flags(a *BIGNUM, flg int) bool {
	if a == nil {
		return false
	}
	return (a.Flags & flg) != 0
}

func bn_free_d(a *BIGNUM, num int) {
	// Implementation is based on your usage, is filling 0 sufficient?
	if num == 0 {
		*a = BIGNUM{}
	}
}

func OPENSSL_free(a *BIGNUM) {
	*a = BIGNUM{}
}

func BN_free(a *BIGNUM) {
	if a == nil {
		return
	}
	if !BN_get_flags(a, BN_FLG_STATIC_DATA) {
		bn_free_d(a, 0)
	}
	if a.Flags&BN_FLG_MALLOCED > 0 {
		OPENSSL_free(a)
	}
}

This won't behave exactly as the C implementation, but it is the closer you can get with Go because Go have built-in garbage collector and no equivalent keyword to the 'free' c function. 

If C `BIGNUM` interacts with Rest memory, like a malloc() memory, t is impossible to model in Go, because Go completely isolates the programmer from the lower level memory management process.

This should only be used if the C code only models the underlying memory management process and doesn't have any contact with outside code apart from functions in the current execution.