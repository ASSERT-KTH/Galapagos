You can't directly convert this C function to Go with the same workflow because Go inherently handles memory management through garbage collection; there is no explicit memory management and therefore there is no equivalent to `av_free` in Go (A function responsible for freeing memory). 

In Go, you can set reference of given object (pointer) to `nil` allowing garbage collector to free memory but you definitely can not reassign passed address with reference `nil` as Go passed arguments by value (not by references).

However if this 'NULL' assignment looking required (for whatever reason but it won't reproduce same C behavior), Then the function (take pointer and set it to `nil`) could look like this:

go
func AvFreepP(arg **interface{}) {
    *arg = nil
}

work for any types comply to empty interface (`interface{}`). Communication could look like:

go
var a *string
aPoint := "World!!"
a = &aPoint
fmt.Println(a) // Output: &World
AvFreepP(&a)
fmt.Println(a) // Output: <nil> 
 
The above function didn't manipulate the memory as does the function written in C correctly though. 

If it's a special kind of type like `av` and there is a corresponding function `AvFree`, you need to create a special function with this argument type.