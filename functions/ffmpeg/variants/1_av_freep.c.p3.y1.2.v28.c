Unfortunately, due to Go's garbage collector and safety practices, it is quite impossible to directly free an object as we usually do in C, more so to implement a C-based function (like the av_freep func mentioned above) in Go. Memory in Go is managed by Go itself, no mechanism to explicitly demote memory.

However, the common methodology in Go whenever you feel want to free up memory (like when we do free() in C) is to nil them out, and eventually let golang's garbage collector do its job when it feels like it.

Ideally,

import "reflect"

func AVFreep(arg interface{}) {
	 v := reflect.ValueOf(arg).Elem()
	 v.Set(reflect.Zero(v.Type()))
}

In the coding snippet provided, the reflect package is used. Using the function reflect.Valueof(arg).Elem(), we will be able to return the vaule that the interface wraps (Elem operates on the enclosed value which it would be set to zero or any other default values based on its datatype). Nevertheless, use of reflect package to mutate the original state of data is not suggested unless really necessary.

Value remains in the heap because object in Go is a type of pointer similarly in C as long as there is reference to an object, heap memory shall be consumed. When its garbage collected, it will have no effect until garbage collector finds it, moreover it doesnt happen immediately. 

Whilst Go tries to provide many of the merits of a language with a garbage collector, giving the programmer the concept that manual intervention of such things might not be needed as vast freedom from a compiler based collection process could not be achieved. Hence it plays a bit differnently in C and Go, both languages have there own strength and weaknesses, and have been built keeping separate needs in mind. Hence, suggesting the elimination of manual life would not explicitly meet availablilty and desirability in every application.
