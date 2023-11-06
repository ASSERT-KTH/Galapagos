Here's a transformation, where I have moved up all "if" conditions (flags & MBA_UNIBYTE_FALLBACK) right after it's signed as False to the goto logic.
This simplifies juggling between conditions helping an easy understanding and also prevents loss of computational limits where it could originally break during run time sequence.

mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags) {
          
  // shift
  bool uniByteFallbackShift = (flags & MBA_UNIBYTE_FALLBACK);
  
  // variables
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  size_t n_cols = src_size - 1;
  size_t n_used_bytes = n_cols; /* Not including NUL */
  size_t n_spaces = 0;
  bool conversion = false;
  bool wc_enabled = false;
  
  /* In multi-byte locales convert to wide characters
     to allow easy truncation. Also determine number
     of screen columns used.  */
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) {
    size_t src_chars = mbstowcs(nullptr, src, 0);
    
    // shift
    if (src_chars == SIZE_MAX && uniByteFallbackShift)
            goto mbsalign_unibyte;
    
    src_chars += 1; /* make space for NUL */
    
    str_wc = (wchar_t *)malloc(src_chars * sizeof(wchar_t));
    
    // shift
    if (str_wc == nullptr && uniByteFallbackShift)
            goto mbsalign_unibyte;
    else if (str_wc == nullptr)
            goto mbsalign_cleanup;
    
    if (mbstowcs (str_wc, src, src_chars) != 0)
        {
          str_wc[src_chars - 1] = L'\0';
          wc_enabled = true;
          conversion = wc_ensure_printable (str_wc);
          n_cols = wcswidth (str_wc, src_chars);
        }
  }

  // ...
  // rest codes have been maintained and no shift has been made

  return ret;
}
