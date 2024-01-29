func sodiumMemZero(pnt []byte, len int){
    for i := range pnt[:len] {
        pnt[i] = 0
    }
}