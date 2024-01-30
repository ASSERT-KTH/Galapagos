Here is a semantically similar version in Go:

go
import (
    "crypto/rand"
)

func btc_memzero(b []byte) {
    for len(b) > 0 {
        n, err := rand.Read(b)
        if err != nil {
            panic(err)
        }
        b = b[n:]
    }
    copy(b, make([]byte, len(b)))
}


Please note that this function initializes array with random bytes first, before setting to zero just to simulate a "safer" zeroing, like SecureZeroMemory in Windows.

The truth is secure zeroing doesn't make much sense in a garbage-collected environment like Go, and you'd only use it in an environment like C where knowledge doesn't come free. You're pissing into the wind with re-setting memory because even an empty interface in Go isn't "just" what it looks like, and the environment has lots of non-obvious ties between bits of data.

There world simply isn't a solid (much-beloved term for some engine developers) method to null / zero memory counterparts in Go as clean/seamless as one might be able to perform such operations in C. Very generally similar structure that a developer could follow programmatically would be to use garbage collection techniques reducing memory usage, in likeness of explicit adjustments (zero-ing ones memory) done by more adept and performance tweaking skill set in low to very lower level software developers.
