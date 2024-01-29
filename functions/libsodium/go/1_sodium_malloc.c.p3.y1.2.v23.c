Unfortunately Go does not support low level memory allocation functions like malloc in C. Also, unlike in C there's no concept of uninitialized or garbage value in Go.

Therefore, you cannot "manually" instantiate a "garbage" value and assign it to a block on memory rather if you're still using malloc conceptually to throughtout instantiate a type might use below mentioned code snippet.

	func sodiumMalloc(size int) []byte {
		ptr := make([]byte, size)
		if ptr == nil {
			return nil
		}
		for i := range ptr {
			ptr[i] = GARBAGE_VALUE
		}
		return ptr
	}

In the above snippets replace the `GARBAGE_VALUE` with a value of byte type as to what you feel should be garbage if insert a spellbound memory address or a undefined figure or so might lead to unnecessary and difficult to debug software crashes.

Also, While replacing realloc concept please try using append in go rather realloc that takes care previous pointer attempt destruction and resulting in possible software crashes.