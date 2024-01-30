In Go, memory is managed automatically, so typically there is no need to free an object manually. However, if for some reason your struct hosts stuff like for example C allocated memory, then you may need to create a method equivalent to the original C program something like:

type Value struct {
    ValueType string
    u         interface{}
}
func (v *Value) freev(){
    if v.ValueType == "string" {
        v.u = nil  // memory will be garbage collected
    } else {
        // This part can be problematic because in Go we don’t have manual memory management.
        // Accumulating big.Ints should decrease memory
        // occcupation. If manual management were to be applied,
        // you would need to do some CGO operations and not idiomatic.
        v.u.(*big.Int).SetUint64(0)
    }
} 

Considering how Go differs from C semantically, the function will still not be completely functionally equivalent to free the objects, especially the situation of manual handlings of memory like mpz_clear. The interface used hands over value deletion to Go's garbage collector seeing how Go is garbage collected by default, freeing and deleting scopes of mechanisms should have no reason to be manually invoked.