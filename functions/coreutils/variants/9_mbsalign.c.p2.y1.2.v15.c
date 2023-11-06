mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src);
  ++src_size; // One count for null character at end.
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src; 
  size_t n_cols = src_size;
  --n_cols; // as src_size included null character count
  size_t n_used_bytes = n_cols; 
  size_t n_spaces = 0;
  bool conversion = false;
  bool wc_enabled = false;
  
  // In multi-byte locales convert to wide characters.
  if(!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
  {
    size_t src_chars = mbstowcs (nullptr, src, 0);

    // Check if conversion worked
    if (src_chars == SIZE_MAX)
      return (flags & MBA_UNIBYTE_FALLBACK ? mbsalign(src, dest, dest_size, width, align, flags || MBA_UNIBYTE_FALLBACK) : ret);
  
    src_chars += 1; 

    str_wc = malloc (src_chars * sizeof (wchar_t));

    // Check if allocation was successful
    if (!str_wc)
      return (flags & MBA_UNIBYTE_FALLBACK ? mbsalign(src, dest, dest_size, width, align, flags || MBA_UNIBYTE_FALLBACK) : ret);

    if (mbstowcs (str_wc, src, src_chars) != 0)
    {
        str_wc[src_chars - 1] = L'\0';
        wc_enabled = true;
        conversion = wc_ensure_printable (str_wc);
        n_cols = wcswidth (str_wc, src_chars);
    }
  }
  
  if(wc_enabled && (conversion || (n_cols > *width)))
  {
      conversion ? (src_size = wcstombs (nullptr, str_wc, 0) + 1) : 0;

      newstr = malloc (src_size);

      if(newstr == nullptr)
        return (flags & MBA_UNIBYTE_FALLBACK ? mbsalign(src, dest, dest_size, width, align, flags || MBA_UNIBYTE_FALLBACK) : ret);


      str_to_print = newstr;
	  n_cols = wc_truncate (str_wc, *width);
	  n_used_bytes = wcstombs (newstr, str_wc, src_size);
  }
  
  // Unibyte truncation needed
  if(n_cols > *width)
  {
      n_cols = *width;
      n_used_bytes = n_cols;
  }
  
  // blank padding required
  if(*width > n_cols)
      n_spaces = *width - n_cols;
 
 // number of cells used   
  *width = n_cols;
  
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
  case MBS_ALIGN_CENTER:
  default:
    start_spaces = n_spaces / 2 + n_spaces % 2;
    end_spaces = n_spaces / 2;
    break;
  }

  // If flag prevents left or right padding
  (flags & MBA_NO_LEFT_PAD) ? start_spaces = 0 : 0 ;
  (flags & MBA_NO_RIGHT_PAD) ? end_spaces = 0 : 0 ;
  
   if (dest_size)
    {
        size_t space_left;
        char *dest_end = dest + dest_size - 1;

        dest = mbs_align_pad (dest, dest_end, start_spaces);
        space_left = dest_end - dest;
        dest = mempcpy (dest, str_to_print, space_left > n_used_bytes ? n_used_bytes : space_left) ;
        mbs_align_pad (dest, dest_end, end_spaces);
    }
   
    ret = n_used_bytes + ((start_spaces + end_spaces) * 1);
  
  free (str_wc);
  free (newstr);

  return ret;
}