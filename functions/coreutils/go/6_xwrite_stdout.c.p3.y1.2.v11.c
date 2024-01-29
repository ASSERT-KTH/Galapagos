func xwrite_stdout(buffer string, n_bytes int) {
	if n_bytes > 0 {
		_, err := os.Stdout.Write([]byte(buffer[:n_bytes]))
		if err != nil {
			log.Fatalf("error writing %s: %v", "standard output", err)
		}
	}
}