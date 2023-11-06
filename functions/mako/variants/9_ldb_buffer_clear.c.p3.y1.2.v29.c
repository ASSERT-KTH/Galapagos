In Go, methods can be defined directly on struct types, and the memory management is garbage-collected, so freeing memory is not necessary. 

go
type LDBBuffer struct {
	Data  []byte
	Size  int
	Alloc int
}

func (dbBuffer *LDBBuffer) Clear() {
	dbBuffer.Data = nil
	dbBuffer.Size = 0
	dbBuffer.Alloc = 0
}

Please note that Go does not support upper-case starting character for local or function variables/objects. Therefore, the member `Data` and type `LDBBuffer` are written in camel case in line with Go naming convention.
Also, the term `clear` is made as method for LDBBuffer which input is only the struct itself indicated by asterisk `LDBBuffer` in function declaration (*LDBBuffer). If it does not alter struct then this function could be changed to regular function and input would be `dbBuffer LDBBuffer`.