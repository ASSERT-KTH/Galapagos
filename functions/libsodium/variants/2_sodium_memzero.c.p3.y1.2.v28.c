In Go, we leverage the built-in copy function. Due to the simplicity of crypto/cipher, it does not require specific system configurations as it does in C, thus this approach should suffice and is semantically equivalent:

go
package main

import "crypto/cipher"

func sodium_memzero(pnt []byte) {
    cipher.NewGCMWithNonceSize(cipher.Block(pnt), len(pnt)).Zero()
}


Keep in mind that there's not an implicit way to override Go's garbage collection or optimize assembly level directives as the equivalent C structure instructions. An alternative model would use basic loop iterations, as shown bellow:

go
package main

func sodium_memzero(pnt []byte) {
	for i := range pnt {
		pnt[i] = 0
	}
}


This last example lacks mitigations against "dead store removal", a compiler optimization which may prevent overwritten data from being actually erased in memory because it's overwritten values haven't side effects. This simple preservation method is not explicitly supported by the Go language.
