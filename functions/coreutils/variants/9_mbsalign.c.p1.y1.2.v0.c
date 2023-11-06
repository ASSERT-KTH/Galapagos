1. Variant with different early exit paths refactor.


mbsalign (char const *src, char *dest, size_t dest_size,
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

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      if (src_chars != SIZE_MAX)
      {
          str_wc = (wchar_t *)malloc(src_chars * sizeof(wchar_t)); 

          src_chars += 1; /* make space for NUL */
          if (str_wc != nullptr)
          {
              CPPUNIT_ASSERT (mbstowcs (str_wc, src, src_chars) == 0);
              str_wc[src_chars - 1] = L'\0';
              wc_enabled = true;
              conversion = wc_ensure_printable (str_wc);
              n_cols = wcswidth (str_wc, src_chars);
          }
      }
    }

  if (wc_enabled && (conversion || (n_cols > *width)))
    {
      if (conversion)
      {
         src_size = wcstombs (nullptr, str_wc, 0) + 1;
      }

      newstr = (char *)malloc(src_size);

      if (newstr != nullptr)
      {
        str_to_print = newstr;
        n_cols = wc_truncate (str_wc, *width);
        n_used_bytes = wcstombs (newstr, str_wc, src_size);
      }
    }

  if (n_cols > *width)
  {
      n_cols = *width;
      n_used_bytes = n_cols;
  }

  if(*width > n_cols)
      n_spaces = *width - n_cols;

  *width = n_cols; 

  {
      size_t start_spaces, end_spaces;
      switch (align)
      {
        case MBS_ALIGN_LEFT:
          start_spaces = 0;
          end_spaces = n_spaces;
          break;
        case MBS_ALIGN_RIGHT:
          start_spaces = n_spaces;
          end_spaces = 0;
          break;
        default: /* MBS_ALIGN_CENTER */
          start_spaces = n_spaces / 2;
          end_spaces = n_spaces - start_spaces;
      }

      if (flags & MBA_NO_LEFT_PAD)
        start_spaces = 0;
      if (flags & MBA_NO_RIGHT_PAD)
        end_spaces = 0;
        
      /* Prepare to pass data into the output buffer */
      if(dest_size)
      {
        /* calculate buffer limit (end of storage that can be written) */
        char *limit = dest + (dest_size - 1); /* end of writable storage */

        if(limit > dest + (start_spaces + n_used_bytes + end_spaces))
            limit = dest + (start_spaces + n_used_bytes + end_spaces);
        rest = dest;

        /* add leading spaces */
        dest = fnc1(dest, limit, start_spaces);
        rest = dest;

        /* add destination string */
        rest += MIN(n_used_bytes, limit - dest);
        rest = mempcpy(dest, src, rest - dest);
        
        /* add trailing spaces */
        fcn1(rest, rest +(limit - dest), end_spaces);
      }
      ret = n_used_bytes + ((start_spaces + end_spaces) * 1);
  }

  if(newstr)
    free(newstr);

  if(str_wc)
    free(str_wc);

  return ret;
}


Remarks: This implementaion removes the `goto` which is hard to follow and instead opts for checking the `new_str` and `src_chars` initialization values. Instead of having nested conditionals that both check if they've been initialized or not, we get one-time checks that exit early if the initialization fails. This improve code readability by a bit and makes each conditional statement less "crowded".