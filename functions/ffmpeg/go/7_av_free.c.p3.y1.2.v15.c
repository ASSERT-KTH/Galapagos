Since memory management in Go is automatic, there's no need for manual allocation and deallocation as there is in C. As a result, a direct translation of this function to Go isn't possible. Nevertheless, if you want to confirm that a pointer doesn't reference a non-nil interface for later garbage collection in Go, you could adopt a pattern like the following:

go
func avFree(ptr *interface{}) {
    *ptr = nil
}
