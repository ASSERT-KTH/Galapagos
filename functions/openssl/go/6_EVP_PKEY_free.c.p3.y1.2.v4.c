Given that Golang does not support C or OpenSSL-like libraries out of the box, you can't do this directly. C is more low level and cryptography functions should not be manually translated between languages as it might become a security issue due to vulnerabilities related to the differences between the languages. Therefore, we should use Golang supported libraries and cryptographic nuances correctly. For safety, I would recommend to use used cryptographical functions given by Golang standard library. 

But still if we try to have an analogous version of your code in Golang, it would look something like this:

golang
import (
	"crypto"
	"sync"
	"errors"
)


type SafeCounter struct {
	mu      sync.Mutex
	counter int
}

func (c *SafeCounter) DecrementAndGet() int {
	c.mu.Lock()
	c.counter--
	defer c.mu.Unlock()

	return c.counter
}

type EVP_PKEY struct {
	References *SafeCounter
	Lock       interface{}  // Undefined
	Data       []byte       // Undefined
}

func EVP_PKEY_free(PKEY *EVP_PKEY) error {
	if PKEY == nil {
		return errors.New("nil parameter")
	}

	ref := PKEY.References.DecrementAndGet()

	if ref > 0 {
		return nil
	} else if ref < 0 {
		return errors.New("error")
	}

	PKEY = nil  // placeholder for actual clean up and memory deallocation
	return nil
}

This does not include equivalents of OpenSSL CRYPTO_DOWN_REF,  REF_PRINT_COUNT, REF_ASSERT_ISNT, evp_pkey_free_it, CRYPTO_free_ex_data, CRYPTO_THREAD_lock_free etc because these are core part of OpenSSL and Golang does not have exact equivalent built-in functionalities, so we must write or find ones that match them as close as possible which might require building auxiliary or helper functions.

The main point being an essential to maintain safe and good cryptographic practices making it highly advisable that your method of switching your crypto code to Golang involve using Go's standard crypto libraries found in the crypto/... standard library pack, rather than trying to translate your OpenSSL code to go.