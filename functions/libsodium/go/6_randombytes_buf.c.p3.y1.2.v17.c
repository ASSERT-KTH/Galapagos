Here's an equivalent function written in Go:

go
import "crypto/rand"

func RandomBytesBuf(buf []byte) {
	if len(buf) > 0 {
		rand.Read(buf)
	}
}


Please always use cryptographic secure random function from trusted crypto packages in production, you should not implement your own one for such a serious task. This function is not a cryptographically strong generator as it has many limitations and security bits are not enough for most cryptographic needs.

NOTE: we can't implement it in function with exactly same signature of original C function, because in Go we don't go about passing pointers to sized buffer for filling in any data like you might in other languages like C. Instead, we work with slice which is sufficiently go idiomatic way.