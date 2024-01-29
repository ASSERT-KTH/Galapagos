You're trying to port a specific implementation of a function from the C language to Go, however, Go doesn't directly support function pointers as parameters.

A possible equivalent in Go may look like this:

Go
func RandomBytesBuf(buf []byte, size uint) {
    if size > 0 {
        rand.Read(buf[0:size])
    }
}


but following are a few important things to note here:

1. Since Go is more abstracted than C language, it handles buffer and sizing details automatically and guarantees slice bounds checking.

2. I replaced "void*" with a byte slice which is a common way to deal with raw bytes in Go.

3. Go doesn't have any functions similar to `randombytes_init_if_needed()` present in your C code, assuming that it checks for some form of global random number generator initialization. The rand module in Go doesn't have such initialization overhead, thus it isn’t required in the above program.

4. Go and C handle error checking differently as well. Go advises to return the error and check explicitly.

5. The function'Implementation->buf()' is replaced by '`rand.Read()`' since functionalities seem similar in principle. Here, we're assuming 'implementation' was a structure where 'buf' function pointer was to some routine that fills buffer with random data. However, complete replication of 'buf' would require more context which is missing from your sample portion of code.
