In Go, there isn’t a semantically equivalent function due to multiple reasons. Some of those reasons including:

1. Unlike, C Go has automatic memory management (garbage collection). So there isn’t any analog to av_free in Go 
2. Go lacks the pointer arithmetic functionality offered by C, so there isn't a perfect equivalent in Go to memcpy.
3. Unline C Go doesn't support assigning nil to an arbitrary pointer

Though if you would like to design a function in Go which is taking a pointer and making it nil you can create a function which takes an interface and attempt to set it to nil. (But remember an interface is consisting two things type and value and you can not change original value inside a function as arguments are passed by value not by reference). For instance:

func av_freep(arg interface{}) {
   val := arg.(*interface{})
   *val = nil
}

In order to use av_freep you need pass a pointer to pointer which fulfill the *(void *) arg signature from original function which can be done like this:
 go
 var arg *MyType
 av_freep(&arg)  // pass address of arg to mimic void* arg
 