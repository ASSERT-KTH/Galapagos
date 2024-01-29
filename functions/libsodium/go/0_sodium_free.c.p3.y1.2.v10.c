Unfortunately, there is no direct equivalent to this C function in Go. In Go, system-oriented programming needs, like direct memory manipulation or system dependant functionalities like munlock, page protection, require the use of cgo or similar tools. This C library function depends heavily on system allocations, memory protections, alignments which are not directly managed in Go. Go internally manages memory and does not give the programmer freedom to adjust such low-level details. These features -- uncontrolled memory management, memory protection, garbage collector -- are features that makes Go safe and easy to drive.

An extraction or rewriting of the function into pure Go would remove such crucial parts of the logic and hence the function would not be semantically equivalent.

Specific points for struct sodium:

- Pointers like sodium_munlock, _unprotected_ptr_from_user_ptr: as Go uses a garbage collector, it doesn't provide a direct way of unlocking the memory.

- Pointer subtraction and some pointer addition operation are not available in Go.

These reflect just few among major differences between low-level language like C and high-level like Go.

Feel free to reach out if more explanation or certain particular solutions needed!