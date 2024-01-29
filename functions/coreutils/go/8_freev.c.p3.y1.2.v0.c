The Go programming language does not directly support union types, variable freeing, or fine-tuned memory management given it's a garbage-collected language. Also, Go's standard library doesn't include a package analogous to GMP which mpz_clear function comes from. Assuming the "VALUE" object in C is a union type with values of string or some large integer, here's is how we might translate clearing that memory to Go. Still, note that intrinsic garbage collection will ultimately take care of memory eliminating this need unlike in C where you manually manage memory.     

go
type Value struct {
    Type string
    U struct {
        S string
        I *big.Int
    }
}

func FreeV(v *Value) {
    if v.Type == "string" {
        v.U.S = ""
    } else {
        v.U.I = v.U.I.SetInt64(0)
    }
    v  = nil
}


In Go `free` is service function invisible to average programmers. Garbage collector automatically takes care of releasing deallocated blocks of memory thus freeing programmer from this duty. Therefore clearning `v` itself does nothing, but included here to complete the analogy to C function. 

Note: Go isn’t built to be a drop-in replacement for C. The converted code in Go will not have exactly the same behavior because different language has different mechanism. Simple data types like string can be garbage collected automatically. You normally won't "release" a BigInt value in Go either as Go's garbage collector will take care of that.