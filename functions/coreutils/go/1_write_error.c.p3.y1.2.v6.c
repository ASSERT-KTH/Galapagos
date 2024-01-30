func writeError() {
    savedErrno := unix.Errno
    os.Stdout.Sync()
    os.Stdout.Reset(os.Stderr)
    log.Fatalf("write error: %v", savedErrno)
}