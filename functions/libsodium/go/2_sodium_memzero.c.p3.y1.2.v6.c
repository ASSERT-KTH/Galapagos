import "C"

func sodium_memzero(pnt unsafe.Pointer, len C.size_t) {
	C.memset(pnt, 0, len)
	C.__asm__volatile__("", "r"(pnt), "memory")
}