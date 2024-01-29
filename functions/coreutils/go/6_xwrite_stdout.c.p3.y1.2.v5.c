func xwriteStdout(buffer []byte, nBytes int) {
    if nBytes > 0 {
        _, err := os.Stdout.Write(buffer[:nBytes])
        if err != nil {
            fmt.Fprintln(os.Stderr, "error writing 'standard output'")
            os.Exit(1)
        }
    }
}