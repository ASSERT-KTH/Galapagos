Because Golang does not support the concept of classes with whether or not a method exists condition, error checking is needed as follows:

Furthermore, because of garbage-collector behaviour in Go, explicit freeing memory is significantly downplayed compared to in C programs, that said,in normal circumstances you do not have `free`, `malloc`, and `destruct`.

go
type BIO struct {
	References int
	Lock       *sync.Mutex
	Method     *MethodBIO
	ExData     map[string]interface{} 
	CallBack struct {
	Call func (a *BIO, b int, c interface{}, d int, e int, f int64, g int64, ret *int) bool
	}
}

type MethodBIO struct {
	Destroy func(a *BIO)
}

func BIOfree(a *BIO) int {
	var ret int

	if a == nil {
		return 0
	}

	if cryptoDownRef(&a.References, &ret, a.Lock) <= 0 {
		return 0
	}

	if ret > 0 {
		return 1
	}
	if ret < 0 {
		panic("ret<0")
	}

	if (a.CallBack.Call!=nil){
		if !a.CallBack.Call(a, "BIO_CB_FREE", nil, 0, 0, 0, 1, &ret) || ret <= 0 {
			return 0
		}
	}

	if a.Method != nil && a.Method.Destroy != nil {
		a.Method.Destroy(a)
	}

	cryptoFreeExData("CRYPTO_EX_INDEX_BIO", a, &a.ExData)
	a.Lock = nil

(gc need not manual deallocate memory(ex: free(a))) 

	return 1
}


Assuming that you have implemented `cryptoDownRef` and `cryptoFreeExData` based on your requirements.