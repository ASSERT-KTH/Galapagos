mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_printer = src;
  size_t n_cols = src_size - 1;
  size_t n_bytes_used = n_cols; 
  size_t n_pad_spaces = 0; 
  bool flag_conversion = false; 
  bool flag_wc_enabled = false;  

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_characters = mbstowcs (NULL, src, 0);
      if (src_characters == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_variant_unibyte;
          else
            goto mbsalign_variant_cleanup;
        }
      src_characters += 1;  
      str_wc = (wchar_t *) malloc (src_characters * sizeof (wchar_t));
      if (str_wc == NULL)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_variant_unibyte;
          else
            goto mbsalign_variant_cleanup;
        }
      if (mbstowcs (str_wc, src, src_characters) != 0)
        {
          str_wc[src_characters - 1] = L'\0';
          flag_wc_enabled = true;
          flag_conversion = wc_ensure_printable (str_wc);
          n_cols = wcswidth (str_wc, src_characters);
        }
    }

  if (flag_wc_enabled && (flag_conversion || (n_cols > *width)))
    {
        if (flag_conversion)
          {
            src_size = wcstombs (nullptr, str_wc, 0) + 1;
          }
        newstr = (char *) malloc (src_size);
        if (newstr == NULL)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_variant_unibyte;
          else
            goto mbsalign_variant_cleanup;
        }
        str_to_printer = newstr;
        n_cols = wc_truncate (str_wc, *width);
        n_bytes_used = wcstombs (newstr, str_wc, src_size);
    }

mbsalign_variant_unibyte:

  if (n_cols > *width)
    {
      n_cols = *width;
      n_bytes_used = n_cols;
    }

  if (*width > n_cols)
    n_pad_spaces = *width - n_cols;

  *width = n_cols;

  {
    size_t pad_start_spaces, pad_end_spaces;

    switch (align)
      {
      case MBS_ALIGN_LEFT:
        pad_start_spaces = 0;
        pad_end_spaces = n_pad_spaces;
        break;
      case MBS_ALIGN_RIGHT:
        pad_start_spaces = n_pad_spaces;
        pad_end_spaces = 0;
        break;
      case MBS_ALIGN_CENTER:
      default:
        pad_start_spaces = n_pad_spaces / 2 + n_pad_spaces % 2;
        pad_end_spaces = n_pad_spaces / 2;
        break;
      }

    if (flags & MBA_NO_LEFT_PAD)
        pad_start_spaces = 0;
    if (flags & MBA_NO_RIGHT_PAD)
        pad_end_spaces = 0;

    if (dest_size != 0)
        {
          size_t leftover_space;
          char *end_dest = dest + dest_size - 1;

          dest = mbs_align_pad (dest, end_dest, pad_start_spaces);
          leftover_space = end_dest - dest;
          dest = mempcpy (dest, str_to_printer, MIN (n_bytes_used, leftover_space));
          mbs_align_pad (dest, end_dest, pad_end_spaces);
        }

    ret = n_bytes_used + ((pad_start_spaces + pad_end_spaces) * 1);
  }

mbsalign_variant_cleanup:

  free (str_wc);
  free (newstr);

  return ret;
}