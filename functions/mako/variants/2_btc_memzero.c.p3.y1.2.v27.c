Here is a Go implementation, using the subtle.Zero package for additionally security:

go
import "golang.org/x/crypto/internal/subtle"

func btcMemzero(ptr *[]byte, len int) {
    if len > 0 {
        subtle.Zero(*ptr)
    }
}

It’s important to note that Go does not allow direct manipulation of memory like C/C++. The Go garbage collector might reallocate memory and leave seemingly cleared data behind. The subtle.Zero function is a workaround for this issue by calling a function builtin to the Go runtime, that cannot be optimized away.

It's also noteworthy that subtlety in data handling which is typical in crypto contexts should preferably be left to professional crypto libraries instead of doing it in an ad-hoc manner.

Bear in mind that managing such tasks manually in Go is generally discouraged by the language's philosophy.