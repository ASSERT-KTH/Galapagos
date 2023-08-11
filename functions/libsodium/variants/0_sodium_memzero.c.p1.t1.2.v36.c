Your request seems to be about mantaining the original functionality and behavior while allowing some variant in coding. Here is a simplified variation maintaining its essence :


void sodium_memzero(void * const pnt, const size_t len) 
{
    if(len < 1) 
        return;
    
    #ifdef _WIN32
        SecureZeroMemory(pnt, len);
    #else
        unsigned char * p = (unsigned char *) pnt;
        while(len--) 
            *p++ = 0;
    #endif
}

This variant directly uses `SecureZeroMemory` for Windows (_WIN32 defined) and uses a simple loop to manually zero-fill memory for other platforms. Notice we cast pointer `pnt` to unsigned char * tipy to fill byte by byte. The length condition (`len < 1`) at top ensuring function quick return when no work needs to be done.