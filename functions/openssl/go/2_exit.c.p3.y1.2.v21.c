Unfortunately, it's not entirely possible to translate this function to Go directly while adhering to the restrictions placed. 

However the closest version in Go given the constraints can be:

Go does not have similar methods allowing the direct execution of `dlsym`, this functionality might be available via `C` interoperability or CGO, which can call C code directly.

Also, Go does not directly support particular system level operations like the select system call in this code. 

go
import (
    "os"
    "time"
)

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}

In the above code However it doesn't:
1. Hook into the `exit` function by replacing it as C code
2. Use unix select call, it is just simulating pause by sleep.

This is more idiomatic Go and achieve the behaviour of delayed exit mimics the delay behaviour shown in the C function and exits the current process with status specified.

It indicates limitations, ensuring that the translation often won't be faithful to C especially in terms of systems programming concepts that straddle kernel spaces and are operating system dependent. Go purposefully limits access to these areas in order to provide stronger portability support between operating systems.