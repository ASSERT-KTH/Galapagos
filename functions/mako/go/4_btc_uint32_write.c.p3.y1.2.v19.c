go
func btcUint32Write(zp *[]byte, x uint32) int {
    if binary.BigEndian {
        *zp = append(*zp, byte(x >> 0))
        *zp = append(*zp, byte(x >> 8))
        *zp = append(*zp, byte(x >> 16))
        *zp = append(*zp, byte(x >> 24))
        return len(*zp)
    } else {
        buf := new(bytes.Buffer)
        binary.Write(buf, binary.LittleEndian, x)
        *zp = append(*zp, buf.Bytes()...)
        return len(*zp)
    }
}

Notice that some points may not be directly translatable from C to Go, as these languages some have distinctive features.

 1. In Go, unlike C, slices (*[]byte for zp) inherently contain information about their own length. So it is necessary to calculate the offset by getting and returning the length of byte slice.
 2. Go has a built-in "binary" package to deal with binary data; read/write binary data type. So binary.Write() is using to prepare and append bytes to given byte slice i.e. serialize the unsigned int32 x into binary data and append resultant data to given byte slice.
 3. In Go, there're no direct built-in macros to check if the running system is big-endian or little-endian, however it generally should be little-endian at the byte level.

Please let me know if you have feature request or you have something to discuss!