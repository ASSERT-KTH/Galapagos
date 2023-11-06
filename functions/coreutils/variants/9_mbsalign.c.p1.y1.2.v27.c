Variant 1: Restructuring the code and reducing few goto statements/cleanup parts.


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  size_t n_cols = src_size - 1;
  size_t n_used_bytes = n_cols;
  size_t n_spaces = 0;
  bool conversion = false;
  bool wc_enabled = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      
      if (src_chars == SIZE_MAX && !(flags & MBA_UNIBYTE_FALLBACK)) {
          return ret;
      }

      src_chars += 1;
      str_wc = malloc (src_chars * sizeof (wchar_t));

      if (str_wc == nullptr && !(flags & MBA_UNIBYTE_FALLBACK)) {
          return ret;
      }

      if (mbstowcs (str_wc, src, src_chars) != 0) {
          str_wc[src_chars - 1] = L'\0';
          wc_enabled = true;
          conversion = wc_ensure_printable (str_wc);
          n_cols = wcswidth (str_wc, src_chars);
      }   
  }

  if (wc_enabled && (conversion || (n_cols > *width))) {
      if (conversion) {
          src_size = wcstombs (nullptr, str_wc, 0) + 1;
      }
      
      newstr = malloc (src_size);

      if (newstr == nullptr && !(flags & MBA_UNIBYTE_FALLBACK)) {
          return ret;
      }

      str_to_print = newstr;
      n_cols = wc_truncate (str_wc, *width);
      n_used_bytes = wcstombs (newstr, str_wc, src_size);
  }

  if (n_cols > *width) {
      n_cols = *width;
      n_used_bytes = n_cols;
  }

  if (*width > n_cols) {
      n_spaces = *width - n_cols;
  }

  *width = n_cols;
  size_t start_spaces, end_spaces;
  // Switch and other fixed operations

  // Additional cleanups
  free (str_wc);
  free (newstr);

  return ret;
}


Variant 2: Rename Variables for Clarity:

++
mbsalign (char const *source, char *distination, size_t maxdistSize,
          size_t *disp_width, mbs_align_t align, int parameter_flags)
{
  size_t ret_dat = SIZE_MAX;
  size_t src_size = strlen (source) + 1;
  char *newCStr = nullptr;
  wchar_t *wcst_str = nullptr;
  char const *StrTP = source;
  size_t Nu_Cs = sr_cSize - 1;
  size_t regularByte-space(rB_s) = Nu_C_cols; 
  size_t n_fmtSpaces = 0;
  bool requiredConv = false;
  bool wideChar_enablement_check = false;

  /*existing code with the variables substitutions */

}


Note: Only applied variable corrections not the functionality wise variance as requested.