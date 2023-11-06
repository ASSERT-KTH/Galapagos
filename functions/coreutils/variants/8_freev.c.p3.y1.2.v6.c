In Go, memory management is done automatically by the Go garbage collector so programmer specified memory freeing is often not necessary as direct equivalent of C's free function just does not exists in Go. But you may can handle and control memory with specific Go techniques like unsetting, nil value setting, close() for channels or sync.Pool.

Additionally Go is strongly typed so you wouldn't just 'switch' types based on a variable in Go, you might use an interface and type assertion or a type switch. Here is re-implementation generally with Value container as a struct and two types - ValueString and ValueInt providing an Unassociate method to dissociate associated value.

Here is my best attempt given these restrictions:

Go
type ValueString struct {
    value string
}
type ValueInt struct {
    value int
}
type Value struct {
    valueType int
    value interface{}
}
const (
    STRING = 1
    INT    = 2
)
func (v *ValueString) Clean() {
    v.value = ""
}
func (v *ValueInt) Clean() {
    v.value = 0
}
func FreeV(v interface{}) {
    switch val := v.(type) {
    case *ValueString:
        val.Clean()
        v = nil
    case *ValueInt:
        val.Clean()
        v = nil
    }
}

Keep in mind that "value" itself does well indeed garbage collected when there is no reference keeping "value" from being GC'd. As in C memory management entirely handles by programmer manual manner but in go itsn't mandatory manual memory management thats done by garbage collector. Automatic garbage collection is a tremendously useful part of Go (in turn occupied more real time cuz of executed in periodically but programmers not wonna worry abt memory leaks) ! Thus this pseudo equivalent piece of code is basically a no-op, and should not be done in real go code!