func writeError() {
    savedErrno := syscall.Errno

    os.Stdout.Sync()       
    os.Stdout.Truncate(0)  

    log.Fatal(fmt.Sprintf("write error: %v", savedErrno))
}