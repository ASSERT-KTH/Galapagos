import (
	"os"
	"log"
	"syscall"
)

func xwrite_stdout(buffer []byte) {
	n_bytes := len(buffer)
	
	if n_bytes > 0 {
		_, err := os.Stdout.Write(buffer)
		if err != nil {
			log.Fatalf("error writing %s: %s", "standard output", syscall.Errno)
		}
	}
}