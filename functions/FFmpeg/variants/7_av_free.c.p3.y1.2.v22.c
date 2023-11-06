Go doesn't provide the capability to separate allocation styles based on environment or configuration macros in the way that C does. Additionally, Go automatically manages memory for the user with garbage collection.

The rough comparable in Go would be setting the variable to `nil` thereby removing its reference to the memory location and allowing the Go runtime's garbage collector to release the memory. 

go
func avFree(ptr *interface{}) {
    *ptr = nil
}


Remember that the garbage collection happens in its own time, this is implicitly giving the "Helping hand", but granting effective rule for the garbage collector to act.