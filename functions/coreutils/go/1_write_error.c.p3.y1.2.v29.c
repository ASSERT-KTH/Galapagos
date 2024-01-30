func writeError() {
    savedErrno := syscall.Errno
    os.Stdout.Sync()
    os.Stdout.Chdir() // clearerr
    log.Fatalln("write error", savedErrno.Error())
}