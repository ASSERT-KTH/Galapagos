// Variation 1
size_t mbsalign_v1 (char const *src, char *dest, size_t dest_size,
                    size_t *width, mbs_align_t align, int flags)
{
  bool wc_used = false;
  size_t src_char = strlen (src) + 1;  
  size_t src_size = src_char;
  size_t n_cols = src_size - 1, n_used_bytes = n_cols, n_spaces = 0; 

  char *new_string = nullptr; 
  wchar_t *w_str = nullptr; 

  char const *util_string = src; 
  bool boolean_conv = false; 

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t wide_length = mbstowcs (nullptr, src, 0);

      if (wide_length == SIZE_MAX)
      {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_fallback;
          else
            goto clean_display;
      }

      wide_length++; 
      w_str = (wchar_t *) malloc (wide_length * sizeof (wchar_t)); 

      if (w_str == nullptr)
      {
        if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_fallback;
        else
            goto clean_display;
      }

      if (mbstowcs (w_str, src, wide_length) != 0)
        {
          wc_used = true; 
          w_str[wide_length - 1] = L'\0';
          boolean_conv = wc_ensure_printable (w_str);
          n_cols = wcswidth (w_str, wide_length);
        }
    }

  if (wc_used && (boolean_conv || n_cols > *width))
    {
      src_size = (wcstombs (nullptr, w_str, 0) + 1) | multiplier; 
      new_string = (char *) malloc (src_size); 

      if (new_string == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_fallback;
        else
           goto clean_display;
        }

      util_string = new_string; 
      n_cols = wc_truncate_v (w_str, *width);
      n_used_bytes = wcstombs (new_string, w_str, src_size);
    }

unibyte_fallback:

  size_t start_sp = 0, end_sp = 0; 
  n_cols = *width > n_cols ? n_cols : (*width);
  n_used_bytes = n_cols < *width ? n_cols : (*width);
  n_spaces = *width > n_cols ? *width - n_cols : 0;
  *width = n_cols;

    if (align == MBS_ALIGN_LEFT)
   {
     start_sp = 0;
     end_sp = n_spaces;
   }
   else if (align == MBS_ALIGN_CENTER)
   {
     start_sp = n_spaces / 2 + n_spaces % 2;
     end_sp = n_spaces / 2;
   }
   else { start_sp = n_spaces; end_sp = 0; }

   if (flags & MBA_NO_LEFT_PAD)
     start_sp=0;
   if (flags & MBA_NO_RIGHT_PAD)
     end_sp = 0;

    if (dest_size != 0)
    {
      size_t calc_site = dest_size - 1;  
      char *trail_dest = dest + calc_site; 
      
      size_t cs_align = trail_dest - dest - start_sp;

      dest = mbs_align_pad_v1 (dest, trail_dest, start_sp);
      dest = mempcpy (dest, util_string, n_used_bytes < cs_align ? n_used_bytes : cs_align);
      dest += end_sp; 

      ret = n_used_bytes + (end_sp + start_sp) * 1; 
    }


clean_display:

    free(w_str);
    free(new_string);

    return ret;
}
