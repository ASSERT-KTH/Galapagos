Unfortunately, the direct equivalent of this function is not possible in Go language. There are several reasons behind it.

1. Go language doesn't support explicit pointer manipulation like done here for the "realexit" function pointer which gets the function pointer to the "exit" function.

2. It is not recommended using OS-specific or C-specific libraries in Go as Go language itself provides more general abstractions for dealing with similar functionalities. The dlsym function is a specific System V Unix, BSD, and POSIX function dealing with dynamic loading libraries and we cannot access it directly from Go. As Go supports static binding of libraries. 

3. Also select syscall in Go does not behave as the way the C-equivalent does.

Therefore as of now, we cannot perfectly replicate the behavior of the shown function in Go language.

The possible replcement to this code can be something like below but it is not equivalent one.

go
import (
	"os"
	"time"
)

func exit(status int) {
	time.Sleep(100 * time.Millisecond) //delay provided equivalent to 100000 microseconds as was given in original function
	os.Exit(status)
}


This replacement considers the time delay part and termination of the processor however we are assuming that Go Runtime takes care of proper exit function clean up. It means, it closes all the closing resources just as available in the exit function.