func WriteError() {
    savedErrno := syscall.Errno
    syscall.Fsync(1) // 1 is the file descriptor for stdout
    syscall.Clearerr(1) 
    log.Fatalf("write error: %v", savedErrno)
}