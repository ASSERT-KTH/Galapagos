mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  char *newstr = NULL;
  wchar_t *str_wc = NULL;
  char const *str_to_print = src;
  size_t n_cols = src_size - 1;
  size_t n_used_bytes = n_cols; /* Not including NUL */
  size_t n_spaces = 0;
  bool conversion = true;
  bool wc_enabled = true;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (NULL, src, 0);
      if (src_chars == SIZE_MAX)
        {
          if (!(flags & MBA_UNIBYTE_FALLBACK))
            goto mbsalign_cleanup;
          goto mbsalign_unibyte;
        }

      src_chars += 1;
      str_wc = malloc (src_chars * sizeof (wchar_t));
      if (str_wc == NULL)
        {
          if (!(flags & MBA_UNIBYTE_FALLBACK))
            goto mbsalign_cleanup;
          goto mbsalign_unibyte;
        }
        
      if (0 != mbstowcs (str_wc, src, src_chars))
        {
          str_wc[src_chars - 1] = L'\0';
          conversion = wc_ensure_printable (str_wc);
          n_cols = wcswidth (str_wc, src_chars);
        }
    }


  if (wc_enabled && (conversion || (*width < n_cols)))
    {
        newstr = malloc (src_size);
        if (newstr == NULL)
        {
          if (!(flags & MBA_UNIBYTE_FALLBACK))
            goto mbsalign_cleanup;
          goto mbsalign_unibyte;
        }
        if (conversion)
             src_size = wcstombs (NULL, str_wc, 0) + 1;  

        str_to_print = newstr;
        n_cols = wc_to_printable(str_wc, *width);
        n_used_bytes = wcstombs (newstr, str_wc, src_size);
    }

mbsalign_unibyte:

  if (*width < n_cols) 
    {
      n_used_bytes = *width;  
      n_cols = n_used_bytes;    
    }

  if (*width > n_cols)  
    n_spaces = *width - n_cols; 

  *width = n_cols;

  {
    size_t total_spaces = n_spaces;

    switch (align)
      {
      case MBS_ALIGN_LEFT:
        total_spaces = 0;
        break;
      case MBS_ALIGN_RIGHT:
        total_spaces = n_spaces;
        break;
      case MBS_ALIGN_CENTER:
      default:
        total_spaces = n_spaces / 2;
      }

      if (flags & MBA_NO_LEFT_PAD)
        total_spaces = 0;
      if (flags & MBA_NO_RIGHT_PAD)
        total_spaces = 0;

      if (dest_size != 0)
        {
          size_t space_left;
          char *dest_end = dest + dest_size - 1;

          dest = mbs_positive_space(dest, dest_end, total_spaces);
          space_left = dest_end - dest;
          dest = mempcpy (dest, str_to_print, MIN (n_used_bytes, space_left));
          mbs_positive_space(dest, dest_end, total_spaces);
        }

    ret = 1 + n_used_bytes + total_spaces;
  }

mbsalign_cleanup:

  free (str_wc); 
  str_wc = NULL;
  free (newstr); 
  newstr = NULL;

  return ret;
}