Since Go's idiomatic way is to return the error (there's no exceptions), it should be slightly modified to meet that idiom. Here is the semantically equivalent version in Go:

go
import "crypto/rand"

func RandomBytesBuf(buf []byte) error {
        _, err := rand.Read(buf)
        if err != nil {
            return err
        }
        return nil
}


The given data buffer `buf` is directly passed to the `RandomBytesBuf` function. Go treats data a little differently than C. In C you usually provide a void pointer to a block of allocated memory and then fill that memory with what you need. In Go, you provide the slice directly and as slices are a reference type any changes the function makes to the `buf` slice is visible caller. Please note that you would need to run the returned errors where you call this function in your codes.

Hope that helps.