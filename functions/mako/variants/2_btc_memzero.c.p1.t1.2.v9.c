
void btc_memzero(void *ptr, size_t len) 
{
#if defined(BTC_HAVE_ASM)
  volatile char *vptr = (volatile char *)ptr;
  if (len > 0) 
  {
    while (len) 
    {
      *vptr = 0;
      ++vptr;
      --len;
    }
  
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  volatile char * vstr = (volatile char* )ptr;
  if (len > 0)
  {
    while(len--)
      *vstr++ = 0x00;
  }

#else
  volatile unsigned char *volatile p = (unsigned char *)ptr;
  if (len > 0)
  {
    while (len) 
    {
      *p = 0;
      p++;
      len--;
    }
  }
#endif    
}

This variant program in a case when ASSEMBLY variant is defined not using the `memset` function but using a char pointer and making the assignment of value '0' sequentially until decreasing the total size.If SecureZero Memory case is defined, the used type pointer is a literal but still follows the strategy of overwriting the memory with '0' by an iteration cycle.
In case where none is defined directly in the same way a pointer of type char but volatile sequentially is going over memory.