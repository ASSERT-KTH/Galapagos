Unfortunately, your C function `av_freep(void *arg)` cannot be exactly converted to Go. There are a couple of reasons why:

1. Go does not support pointer arithmetic. Pointers in Go are much safer and simpler but also less flexible than in C. In other words, you cannot have completely equivalent function in Go as the one in your code, primarily because of Go's design choices to simplify and reduce mistakes common in C with regards to pointers and memory operations.
   
2. There doesn't exist a 'NULL' keyword in golang. In golang, you could not directly manipulate 'Pointer' and there's garbage recycle mechanism(similar to Java) available in golang, so you do not need to manually free your objects.

3. `memcpy` concept doesn't exist in Golang because golang does not allow you to manipulate memory directly for security and stability concerns, It provides garbage collector to automatically handle unused variables and clear memory.

4. There is no `void *` type in go. Due to golang's strong type system, any changes in variable types must be explicitly specified. 

Basically in Golang you don't need to worry about Freeing pointers. This is automatically managed by Garbage Collector!

The point of freeing the previous memory address cannot be done, but here is what you could, theoretically, do if trying to mimic that behavior in the context of your function:

Instead :

func av_freep(arg interface{}) {
    myType := rt.TypeOf(arg)
    switch myType.Kind() {
    case rt.IntPtr, rt.UintPtr, rt.UnsafePointer:
        refVal := rt.ValueOf(arg).Elem()
        refVal = rt.Zero(refVal.Type())
    default:
        fmt.Printf("Input argument %s is not a pointer - can not clean\n", myType.Name())
    }
}
Here received object are set to zero values, no ‘NULL’ is set because golang does not support set 'NULL' to a object.
In the case you are still interested of fully implementing it in Go I highly suggest you refer to the cgo documentation, which is a tool within golang that allows to include c code in go code.
Here is the link cgo:
https://golang.org/cmd/cgo/

It defies the go idioms somewhat but can interface directly with C code as outlined in the documentation.