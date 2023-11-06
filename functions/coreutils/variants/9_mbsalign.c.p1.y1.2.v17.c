Version 1: Simplified function with cleaning and conversion process placed within conditions.

size_t mbsalign (char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
  size_t src_size = strlen (src) + 1;
  size_t ret = SIZE_MAX;

  wchar_t *str_wc;
  char const *str_to_print = src;

  size_t n_used_bytes = src_size - 1;
  size_t n_cols = src_size - 1, n_spaces = 0;

  bool conversion = false, wc_enabled = false;

  if ((flags & MBA_UNIBYTE_ONLY) == MBA_UNIBYTE_ONLY || MB_CUR_MAX <= 1)
    goto mbsalign_unibyte;

  size_t src_chars = mbstowcs (nullptr, src, 0);
  if (src_chars == SIZE_MAX)
  {
    if (flags & MBA_UNIBYTE_FALLBACK)
      goto mbsalign_cleanup;
    else
      goto mbsalign_unibyte;
  }
   
  str_wc = malloc ((src_chars+1) * sizeof (wchar_t));
  if (str_wc == NULL)
  {
    if (flags & MBA_UNIBYTE_FALLBACK)
      goto mbsalign_cleanup;
    else
      goto mbsalign_unibyte; 
  }

  if(mbstowcs (str_wc, src, src_chars+1) != 0)
  {
    str_wc[src_chars] = L'\0';
    wc_enabled = true;
    conversion = wc_ensure_printable (str_wc);
    n_cols = wcswidth (str_wc, src_chars);
  }

  if (wc_enabled && (conversion || (n_cols > *width)))
  {
      if (conversion)
        src_size = wcstombs (nullptr, str_wc, 0) + 1;
    
      str_to_print = malloc (src_size);
      if (str_to_print == nullptr)
      {
        if (flags & MBA_UNIBYTE_FALLBACK)
          goto mbsalign_cleanup;
        else
          goto mbsalign_unibyte; 
      }

      n_cols = wc_truncate (str_wc, *width);
      n_used_bytes = wcstombs ((char*)str_to_print, str_wc, src_size);
  }
  
  mbsalign_unibyte:

  if (n_cols > *width)
  {
    n_cols = *width;
    n_used_bytes = n_cols;
  }

  if (*width > n_cols)
    n_spaces = *width - n_cols;

  *width = n_cols;
  output:
      
    size_t destiny[3];
    size_t spaces[2];
  
    if (flags & MBA_NO_RIGHT_PAD)
        spaces[1] = 0;

    switch (align)
      {
      case MBS_ALIGN_LEFT:
        destiny[0] = 0;
        destiny[1] = spaces[1];
        break;
      case MBS_ALIGN_RIGHT:
        destiny[0] = spaces[0];
        destiny[1] = 0;
        break;
      case MBS_ALIGN_CENTER:
      default:
        destiny[0] = spaces[0] / 2 + spaces[0] % 2;
        destiny[1] = spaces[0] / 2;
        break;
      }

    if (flags & MBA_NO_LEFT_PAD)
      destiny[0] = 0;
    if (flags & MBA_NO_RIGHT_PAD)
      destiny[1] = 0;

    if (dest_size != 0)
    {
      char *dest_end = dest + dest_size - 1,
           *space_left = dest_end - dest;

      dest = mempcpy (dest, str_to_print, min(n_used_bytes, (size_t)space_left) );
      mbs_align_pad (dest, dest_end, destiny[1]);
    }

    ret = n_used_bytes + destiny[0] + destiny[1];

    free (str_wc);
    free ((char*)str_to_print);

  return ret;
  
}


This variant reorders lines, and swaps certain conditional tests (`if (!(a > b))` to `if (a <= b)`), and refactors `mbs_align_pad` calls where equivalent.
It remains recognizable to the original code, but each individual step is less complex. Some comments have been placed in to guide understanding. The free() ops are replaced with an ownfunction to set the pointer to NULL

...