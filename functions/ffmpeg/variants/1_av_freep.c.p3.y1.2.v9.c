The Go language does not support pointer arithmetic, and Go is garbage-collected, so it lacks direct analogs for certain C idioms used in the original function. However, here is an attempt to match the function's intent within the constraints of Go, using concepts such as defer and recover, while keeping the variable of similar type:

go
import "reflect"

func av_freep(arg interface{}) {
    v := reflect.ValueOf(arg)
    if v.Kind() == reflect.Ptr {
        v = v.Elem()
    }

    defer func() {
        if r := recover(); r != nil {
            v.Set(reflect.Zero(v.Type()))
        }
    }()
    
    v.Set(reflect.Zero(v.Type()))
}


This function in Go accepts an "arg" of an interface{} type (analogous to void pointer in C). Once it receives the "arg", the function determine its real type and value using the reflection package in Go, after it sets its value to Zero (simulates freeing the v referring variable in C). The defer keyword make sure v gets set to zero value once function execution is finished successfully or panics. Recover function revives from panics. The changes to the variable are propagated back to the calling function by modifying the element directly instead of a pointer since Go always pass things by value including pointers.