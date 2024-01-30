The below Go code replicates the C code function `btc_uint32_read` and its logic.

go
func btcUint32Read(zp *uint32, xp *[]uint8, xn *int) int {
    if *xn < 4 {
        return 0
    }

    *zp = uint32((*xp)[0]) |
        (uint32((*xp)[1]) << 8) |
        (uint32((*xp)[2]) << 16) |
        (uint32((*xp)[3]) << 24)

    *xp = (*xp)[4:]
    *xn -= 4

    return 1
}


Note that the Go language is inherently "little endian". Therefore, the implementation does not need to cover "big endian" machines specifically as was required in the original C function, hence we don't need the `#if defined(BTC_BIGENDIAN)` conditional from the C code.

The arguments and their types were edited too: to represent C's pointers, we add asterix before type name. To represent function arguments forwarded by reference we use a pointers (`zp *uint32`, `xp *[]uint8`, `xn *int`). 

Also, we don't need to worry about explicit memory management such as `memcpy` function from C standard library. Go’s garbage collector handles memory allocation automatically.