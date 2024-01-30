The exact translation to Go won't be possible, because Go uses built-in types like "big.Int" instead of "BIGNUM" and don't deal directly with flags to sanitize memory.

In a "Python-ist" comparison, your wrapper function is checking: if the input is None; if it is a native type; if the input is a dynamic-allocated-through malloc Python. In Go, all your variables are automatically made getting rid of safety flags wrapper functions provided by software like openSSL.

Thanks to Go's garbage collection and automatic memory management, you don't do you the exact memory handling as in C/C++. 

Therefore, a `BN_free` equivalent isn't necessary in Go. But if we had to write something similar bignumber function in Go developed over int(big package) might go:

golang
func BN_free(a *big.Int) {
    if a == nil {
        return
    }
    // Go manages memory by itself
}


Again, this is utterly pointless in context to GO. First line is checking if bn (big number) passed is a null pointer or not. But the rest of the code is unnecessary as Go takes care of it and those features are not present in Go.