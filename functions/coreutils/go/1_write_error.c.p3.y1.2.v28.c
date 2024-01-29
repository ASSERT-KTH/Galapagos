In Go, this function would have the following tranformation. It is necessary to note that transformation is not a hundred percent equivalent because we cannot directly translate C function error(3) to a semantically equivalent Go function. Normally in Go programming it is typical to return error values.

go
func writeError() {
    stdout := os.NewFile(uintptr(syscall.Stdout), "/dev/stdout")

    savedErrno := syscall.GetErrno()
    
    if err := stdout.Sync(); err != nil {
        log.Fatalln(err)
    }

    if err := stdout.Close(); err != nil {
        fmt.Fprintln(os.Stderr, "write error: ", savedErrno)
        os.Exit(1)
    }
}
