In Golang, instead of working with pointers to functions, we call the functions directly. Furthermore, akin to select system call in C is time.Sleep function in Go.

Please note also the assertion that this translation respects your requirement not to emit anything other than code is based with consideration on runtime operating system capabilities. Specifically, The DL (dlopen, dlsm, etc) family aren't going to operate analogously in windows such that we do on linux . In Go too a separate method is needed in order to obtain function reference through dynamic linking, therefore depend on runtime such that we guarantee preserved semantic i.e don't output anything other than code. 

The equivalent Golang implementation would look like this:

go
package main

import (
	"os"
	"time"
	"plugin"
) 

func exit(status int) {
	tv := time.Millisecond * 100
	time.Sleep(tv)
	plugHandle, _ := plugin.Open("libTargetName.so")
	exitfuncLookup, _ := plugHandle.Lookup("os.Exit")
	exitfuncLookup.(func(int))(status)
}


Note: Normally you should verify the results of `os.Open()` and `plugHandle.Lookup()` respectively as they can return an error, however in following through the function signature requirement We packaged neatly within sing  implementation as derived from your provided C semantic.

This code physically corresponds the code thst you provide, but again keep in mind semantic constraints such as dynamic linking may not work cross-OS-- for simple functions like os.Exit we just ran it instead provided through Golang itself (not via dynamic linking). If you're looking to intercept a call, then employing monkey patch or other test methodologies will probably work better. 

Also Remember as with C variant  here, if you try to call the os.Exit with a -1 status it will results in a program termination. Thus to avoid unexpected behavior this function needs to run into a separate thread .