Unfortunately, this direct conversion into Go language is not possible. This task wouldn't be achievable mainly because they are fundamentally different languages with different memory models in terms of permissions and protections.

C programming language provides a relatively transparent relationship with the hardware and is able to directly protect memory pages, force certain alignment and do intense memory operations that other languages don't operate with directly for security reasons.

Go abstracts memory management away from the developer and handles much of it internally. So there's no conception of pages, explicit mangling with protection and memory pointers like in C.

Therefore, a direct port while also maintaining content meaning of its function from a C language implementation to Go is not possible in usual cases.