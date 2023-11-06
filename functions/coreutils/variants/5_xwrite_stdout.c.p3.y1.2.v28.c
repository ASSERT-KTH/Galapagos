import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer string, n_bytes int64) {
    if n_bytes > 0 {
        count, err := fmt.Fprint(os.Stdout, buffer[:n_bytes])
		if err != nil {
			fmt.Printf("error writing %s:, %v", "standard output", err)
			os.Exit(1)
		}
		if int64(count) < n_bytes {
			fmt.Printf("error writing %s:, %v", "standard output", err)
			os.Exit(1)
		}
    }
}