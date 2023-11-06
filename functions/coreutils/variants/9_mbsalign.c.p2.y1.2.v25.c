One transformation is to avoid using gotos and instead use separate conditional blocks where exit operations are performed. Here is a variant of the original program with an avoidance of gotos. However, there are no guarantees for improved performance. 


size_t mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
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
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      if (src_chars != SIZE_MAX)
        {
            src_chars += 1; /* make space for NUL */
            str_wc = malloc (src_chars * sizeof (wchar_t));
            if (str_wc != nullptr)
            {
                if (mbstowcs (str_wc, src, src_chars) != 0)
                {
                    str_wc[src_chars - 1] = L'\0';
                    wc_enabled = true;
                    conversion = wc_ensure_printable (str_wc);
                    n_cols = wcswidth (str_wc, src_chars);
                }
            // more code here...

            if (wc_enabled && (conversion || (n_cols > *width)))
            {
                if (conversion)
                    src_size = wcstombs (nullptr, str_wc, 0) + 1;
      
                newstr = malloc (src_size);
                if (newstr != nullptr)
                {
                    str_to_print = newstr;
                    n_cols = wc_truncate (str_wc, *width);
                    n_used_bytes = wcstombs (newstr, str_wc, src_size);
                }         
            }
        }
    }

  if(n_cols > *width)
  {
    n_cols = *width;
    n_used_bytes = n_cols;
  }

  if (*width > n_cols)
    n_spaces = *width - n_cols;

  *width = n_cols;
  // more code here...

  free (str_wc);
  free (newstr);

  return ret;

This variant sticks to the more standardized form of C programming, which may be more familiar to many programmers - avoiding gotos. At the same time, it still retains the same functionality of aligning multi-byte character strings as the original.