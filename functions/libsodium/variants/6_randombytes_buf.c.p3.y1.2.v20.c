You cannot maintain the original function's signature when translating it to Go because Go does not allow void or const types for the function parameters. Below is a semantically equivalent version of the function in Go. It fills byte array buf with random bytes of length size. 

go
import "crypto/rand"

func randombytes_buf(buf []byte, size int) {
    if size > 0 {
        _, _ = rand.Read(buf[:size])
    }
}


Please, note it's important to check the error in production quality code. "\<-\_ = rand.Read(buf[:size])" normally you would check and handle this error because the crypto rand read can fail but that was not in the semantics of the original function so it was not included.