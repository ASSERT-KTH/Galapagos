Variant 1 - Compact form:

btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if(len > 0) { memset(ptr, 0, len); __asm__ __volatile__(""; :: "r"(ptr) : "memory"); } 
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0) SecureZeroMemory(ptr, len);
  #else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = &memset;
    if (len > 0) memset_ptr(ptr, 0, len);
  #endif
}


Variant 2 - Syntactic Whitespaces

btc_memzero    (void *ptr, size_t   len) { #if   defined (BTC_HAVE_ASM)
  if(len > 0) { memset(ptr,   0, len); __asm__   __volatile__    (""
      ::   "r"   (ptr)
      :   "memory"
   );
  }
#elif defined (_WIN32)   && defined  (SecureZeroMemory)
  if (len   > 0)
    SecureZeroMemory(ptr, len);
#else
  static void   *(*const volatile memset_ptr)(void  *, int,   size_t)  =   &memset;
  if (len >  0)
    memset_ptr(ptr, 0,   len);
  #endif
}


Variant 3 - Sytactic Whitespaces with Bracketing Stylization (Variation of sytactic whitespaces)

btMemZero   (void * ptr , size_t  len ) { #if defined  ( BTC_HAVE_ASM )
if ( len > 0 )
{ memset ( ptr ,  0, len ) ;  __asm__ __volatile__ 
("", :: "r" (ptr)
: "memory" 
); } 
#elif defined ( _WIN32 ) && defined (SecureZeroMemory)
if (len > 0) SecureZeroMemory (ptr , len) ;
#else
static void * (  *const volatile memset_ptr )(void * , int , size_t)  =  &memset ;
if (len > 0) memset_ptr (ptr ,   0, len ) ;
#endif 
}
