There's no direct equivalent for Go programming as Go does not inherently support some of the features used by this C function code, which includes pointers, intptr types, and explicit memory allocation and reclamation. OpenSSL and EVP libraries also done have a direct equivalent in Go.

The closest thing would be to show how typically unfrees and/or clears memory in case of Go with garbage collector where memory cleaning is automatic, using methods close to the original function's functionality. Something like this:

go
import (
   "crypto/x509"
)

type EVP_PKEY struct {
   References int
   Lock int
   exData int
   Attributes []*x509.Certificate
}

func EVP_PKEY_free(k *EVP_PKEY) {
   if k == nil {
      return
   }
   k.References--
   if k.References > 0 {
     return
   }
   // Clean up internal data. In Go you would typically "close" resources, not
   // free them, because Go's GC would take care of it.
   // Ignoring cleanup operations for types that don't have a direct equivalent
   // Assume some free/close operations happened.
   k = nil   // assume it becomes garbage collected
}

We've taken some liberties here as Go doesn't make use of explicit destructor like C because Go takes care of memory allocation through garbage collector, meaning developers do not need to worry much about manual memory management nor the freeing up of explicit references. However, it's good practice clearing pointed data if they might consume significant amount memory which allows the garbage collector to dispose them. Main operational difference appears because C is a memory unsafe language where Go is memory safe one.

And talking from another perspective, if OpenSSL based crypto tasks in Go is expected may be its better to go with the library there for: crypto/tls which would provide out-the-box tools for dealing with much both lower and higher level of tasks effectively from the TLS layer over, i.e keys, certs and communication parts. Or if need much oscure opportunities of 'cipher' partially what OpenSSL offers can go 'crypto/cipher'.