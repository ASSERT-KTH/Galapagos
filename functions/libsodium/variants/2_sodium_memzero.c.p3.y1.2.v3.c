The precise implementation differs depending on available options for securely erasing memory. Go language runtime doesn't offer the same low-level utilities as C. Due to cross-platform differences and the instability of some operations in runtime, working out a semantically 1:1 transition would not be practically achievable.

However, there is a commonly used alternative function in Go which emulates the general functionality of `sodium_memzero()` by filling a slice of bytes with zeros:

go
import (
     "crypto/subtle"
)

func sodium_memzero(pnt []byte) {
     for i := range pnt {
          pnt[i] = 0
     }

     subtle.ConstantTimeCopy(1, pnt, make([]byte, len(pnt)))
}


While there is no ideal replacement in Go for all of these options, as the Go community tends to favor simplicity over highly-branching low-level customization, the functional properties—if not always the meticulous subcultural exactitude—of the original function are preserved.

Yet, for cryptographic usages wherein preventing Side Channel Attacks is necessary (the Zero-on-Free property embedded in `SecureZeroMemory()` and similar), this code herein would not be adequate replacing `sodium_memzero()`.

N.B. Discussing it with your security team and analyzing the complexity and capability of your application's design would indeed be the preeminent manner to proceed the task.