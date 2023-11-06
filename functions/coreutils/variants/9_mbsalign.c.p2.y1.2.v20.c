mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t src_size = strlen (src) + 1;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;

  size_t n_cols = src_size - 1;
  size_t n_used_bytes = n_cols;
  size_t n_spaces = 0;

  bool conversion = false;
  bool is_wc_enabled = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);

      if (src_chars != SIZE_MAX)
        {
          src_chars += 1;
          str_wc = (wchar_t*)malloc (src_chars * sizeof (wchar_t));
          if (str_wc)
            {
              if (mbstowcs (str_wc, src, src_chars) != 0)
                {
                  is_wc_enabled = true;
                  str_wc[src_chars - 1] = L'\0';
                  conversion = wc_ensure_printable (str_wc);
                  n_cols = wcswidth (str_wc, src_chars);
                }
            }
        }
    }

  size_t start_spaces;
  size_t end_spaces;
  if (is_wc_enabled && (conversion || (n_cols > *width)))
  {
    newstr = (char*)malloc (src_size);
    if (newstr)
    {
      str_to_print = newstr;
      n_cols = wc_truncate (str_wc, *width);
      n_used_bytes = wcstombs (newstr, str_wc, src_size);
    }
  }

  if (n_cols > *width) 
    n_used_bytes = n_cols = *width;
    
  if (*width > n_cols)
    n_spaces = *width - n_cols;

  *width = n_cols;

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

  default:
    start_spaces = n_spaces / 2 + n_spaces % 2;
    end_spaces = n_spaces / 2;
  }

  if (flags & MBA_NO_LEFT_PAD) 
    start_spaces = 0;

  if (flags & MBA_NO_RIGHT_PAD)
    end_spaces = 0;

  if (dest_size != 0)
  {
    size_t space_left;
    char *dest_end = dest + dest_size - 1;
    dest = mbs_align_pad (dest, dest_end, start_spaces);
        
    space_left = dest_end - dest;
    dest = mempcpy (dest, str_to_print, MIN (n_used_bytes, space_left));
    mbs_align_pad (dest, dest_end, end_spaces);
  }

  size_t result = n_used_bytes + start_spaces + end_spaces;

  free (str_wc);
  free (newstr);

  return result;
}
