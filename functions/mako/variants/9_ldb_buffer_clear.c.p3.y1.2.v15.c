The code should be converted into Go as:

go
func ldbBufferClear(z *ldbBufferT) {
    if z.alloc > 0 {
        ldbFree(z.data)
    }
    z.data = nil
    z.size = 0
    z.alloc = 0
}


This is based on the assumption that all the methods and attributes exist and are correctly defined with the right data types in your Go project.