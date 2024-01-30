In Go, memory deallocation is handled by the garbage collector, so there isn't an exact equivalent to the function `freev( )` from C. However, clearing up resources could be done for some types (like closing files, database connections, etc.) which aren't applicable in your code. Considering the context of the code(say struct is defined as below), you'll do nothing apart from making sure there's no references left to the object:


type Value struct {
   tpe string
   u *Union  // Union is hypothetically defined to hold "s" as string and "i" as huge int.
}

func (v *Value) Free() {
   if v.tpe == "string" {
      v.u.s = ""
   } else {
      v.u.i = nil
   }
}


(Note: the garbage collector will repurpose this memory automatically once it's sure the application isn't using it anymore.) If 'Free()' isn't called explicitly, garbage collector in Golang will take deal and deallocate objects when they're no longer in use. Adding explicit call might save time in edge cases when garbage collection isn't quick enough, but it's generally not necessary and not a part of 'idiomatic Go'.
Thus Go's garbage collection offers a degree of memory safety that you won't find in a language like C.