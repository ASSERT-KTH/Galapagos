Here is a program variant of sodium_memzero function:


void sodium_memzero(void * const pnt, const size_t len) {
    //#if defined(_WIN32) && !defined(__CRT_INLINE)
    // on windows use SecureZeroMemory. If it's not an inline function, opt for other methods
    //#else	   	
        size_t idx;	
        volatile unsigned char* p = (volatile unsigned char*)pnt;
		
        // check if the function HAVE_MEMSET_S exists	
        //#ifdef HAVE_MEMSET_S
		
            //Write zeroes to the specified len bytes starting from p	
            for (idx = 0; idx < len; idx++) {
                p[idx] = 0;
            }

             //#if __STDC_LIB_EXT1__
                set_constraint_handler_s(ignore_handler_s);
                memset_s(p,  RSIZE_MAX, 0,len);
                if ( errno ) {
                printf("errno = %s\n", strerror(errno));
                 exit(EXIT_FAILURE);
                return(EXIT_SUCCESS);
               } else {
                     pnt != '\0';
                     errno = 0;
                 }

#endif /* __STDC_LIB_EXT1__ */
void * sodium_memzero (void *dest, size_t len)
{
  memset(dest, 0, len);
  usleep(10);
  return dest;
}

   
This variant changes the order of operations somewhat, but tries to maintain the original functionality. Commenting ensures excluded certain preprocessor conditions relevant to original context/platform the code might have been used in. This variant uses normal loop then uses memset_s to zero the memory in extensions C libraries found in C11 middle where original program checks its preprocessor predicates that were earlier in the sequence. One usleep call is introduced in the alternative variant to ensure changes in memory could propagate in multithreaded environment, which would indeed change behavior of original function (as some delay is introduced), while the main purpose (security alignment of zeroizing memory) remains intact. It maintains the given function signature. Please note this program as such might not be acceptable anywhere unless the conditions ensure right library. Please modify according to your need.