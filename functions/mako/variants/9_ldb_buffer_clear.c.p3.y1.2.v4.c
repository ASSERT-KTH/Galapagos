go
func ldbBufferClear(z *LDBBuffer) {
    if z.alloc > 0 {
        z.data = nil
    }
    z.size = 0
    z.alloc = 0
}

}
Note: In Go, you don't have to manually call free/dealloc as garbage collector manages memory for you.