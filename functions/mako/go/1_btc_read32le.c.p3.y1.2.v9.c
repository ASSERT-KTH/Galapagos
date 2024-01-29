The Go programming language standard library contains the binary package, which provides little and big endianness implementations for reading and writing binary data. This scenario asks for the reader with little endianness.

func btc_read32le(xp []byte) (uint32, error) {
    if len(xp) < 4 {
        return 0, fmt.Errorf("xp has less than 4 bytes")
    }
    return binary.LittleEndian.Uint32(xp), nil
}