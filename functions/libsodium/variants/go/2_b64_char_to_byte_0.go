package main

func b64CharToByte(c int32) uint32 {
	const x = ((((((uint32(c) - uint32('A')) >> 8) & 0xFF) ^ 0xFF) & (((((uint32('Z') - uint32(c)) >> 8) & 0xFF) ^ 0xFF) & (c - 'A'))) |
		(((((uint32(c) - uint32('a')) >> 8) & 0xFF) ^ 0xFF) & (((((uint32('z') - uint32(c)) >> 8) & 0xFF) ^ 0xFF) & (c - ('a' - 26)))) |
		(((((uint32(c) - uint32('0')) >> 8) & 0xFF) ^ 0xFF) & (((((uint32('9') - uint32(c)) >> 8) & 0xFF) ^ 0xFF) & (c - ('0' - 52))) |
		(((0 - (uint32(c) ^ uint32('+'))) >> 8) & 0xFF) ^ 0xFF) & 62) |
		(((0 - (uint32(c) ^ uint32('/'))) >> 8) & 0xFF) ^ 0xFF) & 63)
	return x | (((((0 - (uint32(x) ^ uint32(0))) >> 8) & 0xFF) ^ 0xFF) & (((((0 - (uint32(c) ^ uint32('A'))) >> 8) & 0xFF) ^ 0xFF) ^ 0xFF))
}


func main(){
    b64CharToByte(0)
}
