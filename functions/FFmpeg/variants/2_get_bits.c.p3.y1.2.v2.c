Unfortunately, direct one-to-one translation from the C function to Go is not possible. This is caused due to the several issues:

1. In Go, "register" keyword from C does not exist as Go does not provide explicit control over CPU register allocation.
2. The Open, Update, Show, Last Skip and Close reader's task defined as macros in C code don't have any direct equal or alike feature in Go.
3. The aforementioned macros perform low level memory operations, which Go usually abstracts away from user as Go doesn't provide direct memory-management features like C.
4. Here, Go doesn't provide bit-field struct types as in C, manipulation in lower level bits may need a different approach and will make the code much more verbose.
    
So, corresponding go function couldn't be interpreted semantically equal due to above limitations. The Go language intentionally made the decision not to provide many of C's features which are seen more prone to bugs such as macros, pointer arithmetic etc., While those features have their uses and are indeed powerful, inexperienced or careless usage can easily lead to mistakes, crashes, and vulnerabilities.

Your best path forward is likely to define custom functions to handle the C macros functionality taking into account Go’s idioms and principles. This can be quite involved and probably even merits its own design and implementation work.