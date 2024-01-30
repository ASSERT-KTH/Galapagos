import (
	"fmt"
	"os"
	"syscall"
)

func write_error() {
	saved_errno := syscall.GetErrno()
	if flusherr := syscall.Fsync(1); flusherr != nil { 
		fmt.Println("Failed to flush stdout:", flusherr)
		os.Exit(1)
	}
	
	var i syscall.Errno 
	
	fmt.Println("write error", saved_errno)
}
Please be aware that Go handles things differently than C in many cases. This does not write directly to errno but provides a similar behavior in Go.
In parallel, Go doesn't provide an identical `Cancelerr()` function approach like C since Go's design of file and error handling is different from C. It rather has desired function to clean/read error situation rather than redo the stream input (file)*. However, if your use case requires `clearerr(like behaviour)()`, incorporating it into Go might require a significant logical change.