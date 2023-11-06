Option 1:
Replace the while loop at the end with a for loop to clear the memory manually. This is equivalent to the previous behavior of repeatedly setting each index of the input pointer to zero.


sodium_memzero(void * const pnt, const size_t len) {
    volatile unsigned char * p = (volatile unsigned char *volatile) pnt;
  
    for (size_t i = 0; i < len; i++) {
        p[i] = 0;
    }
}

Option 2:
Remove the if condition before calling the memset_s function. The check for len > 0U is not strictly necessary, since it would not affect the behaviour of the code to call memset_s with a length of zero.


sodium_memzero(void * const pnt, const size_t len) {
    volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;

    if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
}

Option 3:
Replace `_sodium_dummy_symbol_to_prevent_memzero_lto` (presumably a no operation function as discussed before) to use `memset` LTO instead.


sodium_memzero(void * const pnt, const size_t len) {
    if (len > 0U) {
        memset(pnt, 0, len);
        memset(pnt, len, len);
    }
}


Notice: maintain caution as the specifications of the functionalities alias restrictions on inlining by link time optimizer are not defined by Libsodium itself but by the particular implementation of the Standard C Library (even environment related `- can be different if provided by GCC/Clang+glibc/musl/newlib e.t.c.) that the build of Libsodium (or the client code utilizing this version of the function in question) is being linked against. Stick to abstractions provided by consuming environment supplier or use an alternative method provided alongside by Libsodium. 

Anyway, assure having in-depth understanding about the consequences on potential differing behavior in different environments, if anyhow manually requesting the link time optimizer through compiler to perform an opt in particular way triggering the behave that an upstream abstraction previously intentionally guarded against. It is all great as long just understanding the responsibilities of these specific cases one opting to walk through. Use safe components and guarantees. Always. Considering the explicit_bzero and etc provided alternatives relate to it.