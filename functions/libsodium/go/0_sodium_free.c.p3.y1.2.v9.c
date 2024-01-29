You should note that due to fundamental differences between C and Go, translating the function exactly while maintaining every aspect (e.g., the same function signature, not using "helper function", direct memory handling/manipulation, pointer arithmetic, specific syscalls like mprotect\munlock) is NOT possible.

For the Go programming language, manual memory management is generally not the suitable pattern

Here is how a rough C to Go translation would look while maintaining the found/null checks, available functionality replacements in the context of bounds checking and writing to memory.
Go
import (
    "bytes"
    "crypto/rand"
    "os"
)

var canary []byte
const max_size int = 8192  // replace with C equivalent 

func init() {
    canary = make([]byte, max_size)
    if _, err := rand.Read(canary); err != nil {
        panic(err)
    }
}

func sodium_free(data []byte) {
    canary_size := len(canary)
    if len(data) == 0 {
        return
    }
	
    lower_bound := bytes.Compare(canary, data[:canary_size])
    upper_bound := bytes.Compare(canary, data[len(data)-canary_size:])

    if lower_bound != 0 || upper_bound != 0 {
        panic("Out of bounds memory access.")
    }

    for i := range data {
        data[i] = 0  // Figure equivalent functionality instead of direct memory syscall mprotect\mlock
    }

    if _, _, err := os.Syscall(syscall.SYS_MUNLOCK, uintptr(unsafe.Pointer(&data[0])), uintptr(len(data)), 0); err != 0 {
        panic(err)
    }
}

It is essential to consider that byte array compared to void* requires knowing the actual length of the memory block. There are differences between languages due to how memory manipulated explicitly in C and how in Garbage collected language like Go (this is heavily abstracted for developers). Also, calling to OS syscalls explicitly and handling mlock\mfulock doesn't reflect idiomatic Go.