
size_t mbsalign_refactored (char const *src, char *dest, size_t dest_size,
                            size_t *width, mbs_align_t align, int flags) {
  size_t result = SIZE_MAX;
  size_t src_size = strlen(src) + 1;
  char *dup_str = NULL;
  wchar_t *wc_str = NULL;
  char const *string_to_print = src;
  size_t num_columns = src_size - 1;
  size_t bytes_used = num_columns;
  size_t extra_spaces = 0;
  bool convert = false;
  bool wc_activated = false;
  
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (NULL, src, 0);
      if (src_chars == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_only;
          else
            goto cleanup;
        }
      src_chars++;
      wc_str = malloc (src_chars * sizeof (wchar_t));
      if (wc_str == NULL)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_only;
          else
            goto cleanup;
        }
      
      if (mbstowcs (wc_str, src, src_chars) != 0)
        {
          wc_str[src_chars - 1] = L'\0';
          wc_activated = true;
          convert = wc_ensure_printable (wc_str);
          num_columns = wcswidth (wc_str, src_chars);
        }
    }
    
  if (wc_activated && (convert || (num_columns > *width)))
    {
        if (convert)
            src_size = wcstombs (NULL, wc_str, 0) + 1;
            
        dup_str = malloc (src_size);
        if (dup_str == NULL) 
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_only;
          else
            goto cleanup;
        }

        string_to_print = dup_str;
        num_columns = wc_truncate (wc_str, *width);
        bytes_used = wcstombs (dup_str, wc_str, src_size);
    }

unibyte_only:

  if (num_columns > *width)
    {
      num_columns = *width;
      bytes_used = num_columns;
    }
  else if (*width > num_columns)
    extra_spaces = *width - num_columns;

  *width = num_columns;

  {
    size_t get_spaces_in_beginning, get_spaces_in_end;

    switch (align)
      {
      case MBS_ALIGN_LEFT:
        get_spaces_in_beginning = 0;
        get_spaces_in_end = extra_spaces;
        break;
      case MBS_ALIGN_RIGHT:
        get_spaces_in_beginning = extra_spaces;
        get_spaces_in_end = 0;
        break;
      case MBS_ALIGN_CENTER:
        get_spaces_in_beginning = extra_spaces / 2 + extra_spaces % 2;
        get_spaces_in_end = extra_spaces / 2;
        break;
      default:
        break;
      }

    if (flags & MBA_NO_LEFT_PAD)
        get_spaces_in_beginning = 0;
    if (flags & MBA_NO_RIGHT_PAD)
        get_spaces_in_end = 0;

    if (dest_size) 
    {
        char *dest_end = dest + dest_size - 1;
        dest = mbs_align_pad (dest, dest_end, get_spaces_in_beginning);
        dest = mempcpy (dest, string_to_print, MIN (bytes_used, (size_t)(dest_end - dest)));

        mbs_align_pad (dest, dest_end, get_spaces_in_end);
    }


    result = bytes_used + ((get_spaces_in_beginning + get_spaces_in_end) * 1);
  }

cleanup:

  free (wc_str);
  free (dup_str);

  return result;
}
