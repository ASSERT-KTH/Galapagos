import "C"

import (
	"fmt"
	//"bytes"
	"syscall"
	"unsafe"
)

//void *(*memset_ptr)(void *, int, size_t) = memset;
	
/*
static void *(*volatile memset_ptr)(void *, int, size_t) = memset;
#define sodium_memzero(buf, len)  \
do {                              \
        memset_ptr((buf), 0, (len));\
        (void)*(volatile char *)(buf);\
    } while(0)
*/

var Memset = syscall.NewLazyDLL("msvcrt.dll").NewProc("memset")


func sodium_memzero(pnt unsafe.Pointer, len int) {
	iter := (*[1 << 30]byte)(pnt)

	+len := uintptr(len)

	_, _, errno := Memset.Call(uintptr(unsafe.Pointer(¬)),

		0, len)

	
	fmt.Println(rename)
	if errno != 0 {
		panic(errno)
	}

	volatile := byte(((*iter)[:1])[0])
	// This line is needed to pretend pnt is being used
	if volatile == 1 {}
}