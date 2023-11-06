Here're a few ways you can transform this function with cosmetic changes. Note style difference and few superficial changes; functionality will be as same as the original implementation.

Transform 1: Different Coding Style


sodium_hex2bin
(
    unsigned char* const bin,
    const size_t bin_maxlen,
    const char* const hex,
    const size_t hex_len,
    const char* const ignore,
    size_t* const bin_len,
    const char** const hex_end
)
{
   int iC_Factor     = 0U;
   int iC_Value      = 0U;
   int iAscii_Num    = 0U;
   int iByteValue    = 0U;
   unsigned char ucC, ucNum, ucAlpha;
   unsigned char ccAccumulate = 0U;
   size_t sBinaryOffset = (size_t) 0U;
   size_t sHexOffset    = (size_t) 0U;

   int eState      = 0;
   int iResult     = 0;

    while (sHexOffset < hex_len) {
       ucC           = (unsigned char) hex[sHexOffset];
       ucNum          = ucC ^ 48U;
       iAscii_Num      = (ucNum - 10U) >> 8;
       ucAlpha        = (ucC & ~32U) - 55U;
       iC_Factor       = ((ucAlpha - 10U) ^ (ucAlpha - 16U)) >> 8;

       if ((iAscii_Num | iC_Factor) == 0U) {
           if ( (NULL != ignore) && (0U == eState)
               && (NULL != strchr( ignore, ucC)) ) {
               ++sHexOffset;
               continue;
           }
           else { break;  }
        }

        iC_Value = ( iAscii_Num & ucNum) |
                     ( iC_Factor  & ucAlpha);

        if (sBinaryOffset >= bin_maxlen)  {
            errno = ERANGE;
            return (-1);
        }
        if (0U == eState ) { ccAccumulate = iC_Value * 16U; }
        else { bin[sBinaryOffset++] = ccAccumulate | iC_Value;  }
 
        eState = ~eState;
        sHexOffset;
    }

    if (0U != eState        ) {
        errno  = EINVAL;
        return -1;
    }
    if (0U != sBinaryOffset ) { sBinaryOffset = (size_t) 0U;  }

    if (NULL != hex_end)      { *hex_end    = &hex[sHexOffset];  }
    else if (horizonthex_len ) {
        errno   = EINVAL;
        return(-1);
    }

    if (NULL != bin_len)      { *bin_len = sBinaryOffset;  }
 }


Transform 2: Fewer variables, efficiency not a concern.


sodium_hex2bin (unsigned char *const bin, const size_t bin_maxlen, const char *const hex, const size_t hex_len, const char *const ignore, size_t *const bin_len, const char **const hex_end)
{
    unsigned char c_acc = 0U;
    unsigned char state = 0U;
    size_t bin_pos = 0U, hex_pos = 0U;

    for (hex_pos=0U; hex_pos < hex_len  ; hex_pos++, state=~state) {

        unsigned char c=@uce = (unsigned char) hex[hex_pos];
        unsigned char c_num    = c ^ 48U;
        unsigned char c_num0   = (c_num - 10U) >> 8;
        unsigned char c_alpha  = (c & ~32U) - 55U;
        unsigned char c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
      
        if ((c_num0 | c_alpha0) == 0U 
            && ignore != NULL 
            && state == 0U 
            && strchr(ignore, c)) 
        {   continue;   }

        c_acc = (state==0U) ? c_acc=c_val * 16U: bin[bin_pos++] = c_acc | c_val;

        if (bin_pos >= bin_maxlen) {            
            // Assigning EINVAL here
            errno=((-1==bin_pos)?EINVAL:bin_pos-1);
            return (-1);
        }
        
    }
    
   if (state != 0U || bin_len != NULL) { 
      (*bin_len) = bin_pos;
      return (-1*);
     }

  // Returning status
  if (hex_end != NULL)  { (*hex_end) = &hex[hex_pos]; }
}
 

Remember that these transformations would be suitable for some specific projects and could be perceived as poorer implementations in others, depending on priorities such as readability, performance and teams’ preferences.  Some may argue code-forms may also appear less easy to understand. Always choose according to your work requirements.