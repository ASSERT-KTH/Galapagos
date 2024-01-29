Unfortunately, creating a semantically equivalent function in Go as provided in C is not directly possible. There are three key parts to the provided C function that important to consider:

1.The exit function signature: Go does not support function overloading, so you cannot create a custom `exit` function like you can in C. You'd have to name your custom function something different.

2.The use of the `dlsym` function and `RTLD_NEXT`: These are used to get a reference to the "real" `exit` function in the dynamic linker. This feature is not available in Go.

3.The call to `select`: This function is used to sleep on file descriptors. While Go has a `time.Sleep` function, it does not have a direct equivalent to `select` that operates on file descriptors as in C.

Here is a translation of what can be done, using OS related packages:

go
import (
	"syscall"
	"time"
)

func exit(status int) {
	d := time.Duration(100000) * time.Microsecond
	time.Sleep(d)                // Create a sleep similar to select in C.
	syscall.Exit(status)         // Close program with the given status.
}


This just has sleep functionality with specified tiny delay before exiting, which is carried out by Go's native `time.Sleep()` function and then it exits the program with `syscall.Exit(status)`. Note that this exit function may not behave exactly the same way regarding processes and resource cleanup as the C `exit` function.