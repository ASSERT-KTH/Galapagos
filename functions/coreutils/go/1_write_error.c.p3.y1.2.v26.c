import (
	"fmt"
	"os"
	"syscall"
)

func WriteError() {
	saved_errno := syscall.Errno
	fmt.Print("\x1b[0m") // End of ANSI color code to ensure nothing buffered
	_, err := fmt.Print("")
	if err != nil {
		fmt.Fprintf(os.Stderr, "write error: %s\n", syscall.Errno(saved_errno))
		os.Exit(1)
	}
}