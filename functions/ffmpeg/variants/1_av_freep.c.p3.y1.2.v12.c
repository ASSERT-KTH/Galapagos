It's very important to note that in C, av_freep releases the memory pointed to by your pointer and nulls the pointer. However, to actually free memory in Go, you'd just stop referring to things and allow them to be eligible for garbage collection. 

That being said, mimic av_freep from an API perspective isn't straightforward directly translated into Go, because Go does not have direct fine control over memory like C does, and it handles variables differently from C. In Go there is not really a use case where you'd need to pass a pointer to some data and then have that function overwrite that original pointer (like av_freep does in C). 

For the sake of technicality we can write the function with similar behaviours.

Go
func av_freep(arg **interface{}) {
	*arg = nil
}

There are only two reasons your C code would memcpy the NULL bit pattern over an argument on the callee's stack: You're about to pthread_exit(), or you think NULL-initing locals protects againt TOCTOU-rooted attacks. Today, that's a blue sky you're optimizing yourself towards, since all know vulnerabilities are bugs like racey filesystem paths.

So there's never a need in Go to "clear" contents sometime before function exit, because no pointer from above stack frame can escape via return parameters or leading with panic().
Encourage developer to adopt a different programming patterns instead according to Go's philosophy.