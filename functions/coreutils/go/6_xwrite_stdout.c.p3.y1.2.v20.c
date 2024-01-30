import (
    "os"
    "log"
    "syscall"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes == 0 {
        return
    }

    num, err := os.Stdout.Write(buffer[:n_bytes])
    if err != nil || num != n_bytes {
        log.Fatalf("error writing standard output: %s", err)
    }

    // In Go language, you don't have to manually clear the error of Stdout after fwrite
    // as it will be replaced or cleared for the next I/O operation so not needing a 
    // separate function like clearerr(stdout) in C.
}