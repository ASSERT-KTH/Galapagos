Below is a changed variant of your function btc_memzero. The variant imitates the original function btc_memzero yet changes the original approach slightly. The changes includes incorporating standard memset function regardless to CPU flag and Windows macro. The previous code might be firstly trying to inject the assembly, but if not possible then tries for Windows specific SecureZeroMemory. Eventually as not any case fulfilled, attempting memset at the last, but that is not sure shot applicable. But normally, memset() can provide you the desired functionality universally. Loop is constructed for initializing each byte to maintain memory location overwrites effectiveness.


void btc_memzero(void *ptr, size_t len) {
    unsigned char *p = (unsigned char *)ptr;
    while(len--) {
        *p++ = 0;
    }
}

In your original code, memset(filename, size) seems to be common segment, and that's only being varied according to platform or features enabled flags. So I've employed memset universally in an alternative way.