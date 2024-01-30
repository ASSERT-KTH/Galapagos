Unfortunately, creating semantically equivalent version of the function in the Go programming language isn't possible due to the nature of the two languages.

The language fundamentally differs from C in a few ways that prevents this:

1. Go does not support inline assembly or linker hacks so getting the address of exit with dlsym is impossible directly in Go.

2. Go does not expose a standard library method to mangling with the unmangled low-level function names in the system. Which means an equivalent of dlsym cannot be found in Go.

Given the nature of task required to be performed, it is suggested to not use function interception in Go. You can just write clean Go code without requiring to redefine native calls. In case you ever need to "wait" before calling os.Exit() in Go, here is suggestive example for simulating. 

``
import (
  "time"
  "os"
)

func reproduceExit(status int) {
  time.Sleep(100 * time.Millisecond)
  os.Exit(status)
}
``

This issue is well-documented in Go community where Rob Pike, one of the creators of Go, has spoken out saying that Go just isn't meant to support comparable behaviour to some C operations because they go against the design goals of Go being simple, straightforward and safe. Else, executing system calls os having os level access is highly suggested for unmanaged languages like C, C++. 

The code you need indeed does a reflection like search on a symbol table access at runtime - it is almost certainly not going to be elegant, idiomatic or easy in Go.