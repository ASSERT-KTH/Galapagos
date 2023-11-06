import (
    "os"
    "log"
)

func xwrite_stdout(buffer []byte, n_bytes uint) {
    if n_bytes > 0 {
        num, err := os.Stdout.Write(buffer[:n_bytes])
        if uint(num) < n_bytes || err != nil {
            log.Fatalf("error writing %s: %v", "standard output", err)
        }
    }
}