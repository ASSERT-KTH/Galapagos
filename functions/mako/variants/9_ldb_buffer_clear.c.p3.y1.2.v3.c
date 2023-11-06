func ldbBufferClear(z *ldbBuffer) {
    if z.alloc > 0 {
        free(z.data)
    }

    z.data = nil
    z.size = 0
    z.alloc = 0
}