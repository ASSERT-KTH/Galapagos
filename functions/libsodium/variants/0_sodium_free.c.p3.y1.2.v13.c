In order to replicate the same functionality as the C function you provided, I would first need to import the functionalities from the following Go libraries: 

unittest/unix and cgo where a couple of functionalities like memory deallocation-sodium_free, memguard destroy-sodium_munlock would be replicated.

However, please note that memprotect and working directly with lower-level memory is a bit counter to how Go programs are typically written and created, Go is not going to be able to do the same things as C without either doing something dangerous/unsafe or not practical, in short memory related features are inherently managed by Go. Still the following Go function represents the best idea on how a semantically equivalent Go function would be implemented.
\
\
\

import (
   "unsafe"
   "reflect"
   "syscall"
)   

func safeToLower(v reflect.Value) []byte {
  h := (*reflect.SliceHeader)(unsafe.Pointer(v.Pointer()))
  return *(*[]byte)(unsafe.Pointer(&reflect.SliceHeader{
    h.Data, h.Len * int(v.Type().Elem().Size()),
  }))
}

const page_size = syscall.Getpagesize()

func Sodium.free(ptr unsafe.Pointer){
    var canary []byte
    var base_ptr unsafe.Pointer
    var canary_ptr unsafe.Pointer
    var unprotected_ptr unsafe.Pointer
    if ptr==nil{return}
    canary_ptr=unsafe.Pointer(uintptr(ptr)-unsafe.Sizeof(canary[0]))
    unprotected_ptr=ptr
    base_ptr=unsafe.Pointer(uintptr(unprotected_ptr)-uintptr(page_size)*2)

    unprotected_size:=(*reflect.SliceHeader)(base_ptr)
    var total_size uintptr
    total_size=uintptr(page_size)+uintptr(page_size)+uintptr(unprotected_size.Cap)+uintptr(page_size)

    sodium.memcmp(safeToLower(canary_ptr),canary,safeToLower(len(canary)))               //Not possible with Go to compare values from a void/unsafe/void type of space. Hence someone has to cast it to other visible types.

    if sodium.memcmp(canary, base_ptr)==0{
       four_four()
    }
    protected.Unlock()
}

