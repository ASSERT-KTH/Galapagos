There is no direct translation of this function to Go because the krb5 library and assertion utilised in this code are not available in Go. Furthermore, Go does not allow the implicit conversion of types from error code to a boolean for assertion, the existence of a global `ctx` object similar to kerberos(as in krb5) and implicitly runs a de-allocation approach via garbage collector instead of a `free_error_message` equivalent.

Please check below for a conceptual translation taking into account the adjustments potentially needed:

go
func check(code int) {
	if code != 0 {
		errmsg := krb5.GetErrorMessage(int(code))    // assuming krb5.Pretval(ivt, code) applies
		fmt.Fprintln(os.Stderr, errmsg)             // equivalent to fprintf in stderr
		assert(code == 0)                           // this line would have to change as there's no assert in Go
		// Go has a garbage collector and it deallocates memory automatically.
		// Thus, there's no equivalent for "krb5_free_error_message(ctx, errmsg);"
	}
}


Please note: 

1) This is an oversimplified version as the `krb5.GetErrorMessage` or abstracted `krb5` process call method is assumed, because there is no such library or way in Golang like `krb5`. Usually this part would be handled by custom or packaged error creation and handling. 

2) It is assuming the existence of an `assert` function, Go does not come with built-in assertions. The typical method is to `panic()` or to handle and return the error. 

3) The implementation is focusing on conceptual reference and cannot be considered a running-translated code due to mentioned constraints.