func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
        n, err := os.Stdout.Write(buffer[:n_bytes])
        if err != nil {
            log.Fatalf("Error writing standard output: %v", err)
        }
        if n < n_bytes {
            log.Fatalf("Error writing standard output: wrote %d bytes instead of %d", n, n_bytes)
        }
    }
}