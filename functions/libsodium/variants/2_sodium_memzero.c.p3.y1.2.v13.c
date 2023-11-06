func sodium_memzero(pnt unsafe.Pointer, len uint) {
    
    pnt_ := *((*[]byte)(unsafe.Pointer(&pnt)))
 
    for i := uint(0); i < len; i++ {
        pnt_[i] = 0
    }

}