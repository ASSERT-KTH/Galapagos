mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX, n_spaces = 0;
  bool conversion = false, wc_enabled = false;
  char *newstr = nullptr; wchar_t *str_wc = nullptr;
  size_t src_size = strlen(src) + 1, n_cols = QUOTIENT_MINUS_ONE(src_size, 2), n_used_bytes = n_cols;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);

      if (src_chars == SIZE_MAX){
        if (flags & MBA_UNIBYTE_FALLBACK) goto mbsalign_unibyte;
        else goto mbsalign_cleanup;}
      
      ++src_chars;
      str_wc = (wchar_t*) malloc(src_chars * sizeof(wchar_t));
      
      if (!str_wc){
        if (flags & MBA_UNIBYTE_FALLBACK) goto mbsalign_unibyte;
        else goto mbsalign_cleanup;}
        
      if (mbstowcs(str_wc, src, src_chars)) {
          str_wc[--src_chars] = L'\0';
          wc_enabled = true;
          conversion = wc_ensure_printable(str_wc);
          n_cols = wcswidth(str_wc, src_chars);  }
    }

  /* If we transformed or truncated our string we need an altered copy */
  if ((wc_enabled)&&(conversion || NEEDED_TRUNCATION)){
      CONVERSION_TEST(src_size, str_wc); 

      newstr = malloc(src_size);
      if (!newstr) {
        if (flags & MBA_UNIBYTE_FALLBACK) goto mbsalign_unibyte;
        else goto mbsalign_cleanup;}

      str_to_print = newstr;
      n_cols = wc_truncate(str_wc, *width);
      n_used_bytes = wcstombs(newstr, str_wc, src_size);}

  else goto mbsalign_unibyte;
      
mbsalign_unibyte:
  UNIBYTE_TEST(n_cols);

  PADDING_CALCUATION(n_spaces);

  *width = n_cols;

  {
    size_t start_spaces = 0, end_spaces = 0;
    char *dest_end= nullptr;
    
    switch(align) { 
      LEFT_ALI(v)  RIGHT_ALI(v)
      DEF_ALIGN(v) }
      
    W_CAN_PRINT_TEST(r)
    NO_SPACES_NB_CALC(r)
  }

mbsalign_cleanup:
  FREE_THE_MALLOCS()

  return ret;
}
// In this variant, the MACROs do some of work by calling short methods that can be reused along a function. This avoids large parts of complex sentences being used unsparingly across the function thus reducing the cyclometric complexity and using cleaner methods for their representaion which have nothing but easy-to-exbind action names.