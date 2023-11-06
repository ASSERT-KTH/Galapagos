package main

import (
	"C"
	"unsafe"
)

//import "golang.org/x/sys/unix"

// #cgo CFLAGS: -DHAVE_EXPLICIT_BZERO
// #include <strings.h>
// #include <stdio.h>
// import "C"
/*
void sodium_memzero(void *pnt, size_t len) {
	#ifdef HAVE_MEMSET_S
	if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
		exit(1);
	}
	#elif defined(HAVE_EXPLICIT_BZERO)
	explicit_bzero(pnt, len);
	#elif defined(HAVE_MEMSET_EXPLICIT)
	memset_explicit(pnt, 0, len);
	#elif defined(HAVE_EXPLICIT_MEMSET)
	explicit_memset(pnt, 0, len);
	#else
	volatile unsigned char *volatile pnt_ =
		(volatile unsigned char *volatile) pnt;
	size_t i = (size_t) 0U;
	while (i < len) {
	    pnt_[i++] = 0U;
	}
	#endif
}

void zeroMemory(void *pnt, size_t len) {
	sodium_memzero(pnt, len);
}
*/
//export Go_sodium_memzero
func Go_sodium_memzero(pnt unsafe.Pointer, len C.size_t) {
	C.zeroMemory(pnt, len)
}
