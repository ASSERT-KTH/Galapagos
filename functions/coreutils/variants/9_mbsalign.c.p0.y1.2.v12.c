
mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags) 
{
  size_t max_size = SIZE_MAX;
  size_t source_size = strlen(src) + 1;
  char *transformedstr = nullptr;
  wchar_t *str_wchar = nullptr;
  const char *print_str = src;
  size_t no_cols = source_size - 1;
  size_t used_bytes = no_cols;
  size_t whitespace = 0;
  bool convert = false;
  bool wchar_active = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) 
  {
      size_t source_chars = mbstowcs(nullptr, src, 0);
      if (source_chars == SIZE_MAX)
      {
        if (flags & MBA_UNIBYTE_FALLBACK)
          goto align_unibyte;
        else
          goto concl_sub;
      }
      source_chars++;

      str_wchar = malloc(source_chars * sizeof(wchar_t));
      if (str_wchar == nullptr)
      {
        if (flags & MBA_UNIBYTE_FALLBACK)
          goto align_unibyte;
        else
          goto concl_sub;
      }

      if (mbstowcs(str_wchar, src, source_chars) != 0)
      {
        str_wchar[source_chars - 1] = L'\0';
        wchar_active = true;
        convert = ensure_printability (str_wchar);
        no_cols = wcswidth(str_wchar, source_chars);
      }
  }

  if (wchar_active && (convert || (no_cols > *width))) 
  {
        source_size = (convert) ? wcstombs(nullptr, str_wchar, 0) + 1 : source_size;
        transformedstr = malloc(source_size);
        if (transformedstr == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto align_unibyte;
          else
            goto concl_sub;
        }

        print_str = transformedstr;
        no_cols = truncate(str_wchar, *width);
        used_bytes = wcstombs(transformedstr, str_wchar, source_size);
  }

align_unibyte:

  if (no_cols > *width)
      {
        no_cols = *width;
        used_bytes = no_cols;
      }

  if (*width > no_cols)
      whitespace = *width - no_cols;

  *width = no_cols;

  size_t initial_spaces = 0;
  size_t final_spaces = 0;

  switch (align)
    {
      case MBS_ALIGN_LEFT:
        initial_spaces = 0;
        final_spaces = whitespace;
        break;
      case MBS_ALIGN_RIGHT:
        initial_spaces = whitespace;
        final_spaces = 0;
        break;
  
      default:  /* MBS_ALIGN_CENTER is defaulted case */
        initial_spaces = whitespace / 2 + whitespace % 2;
        final_spaces = whitespace / 2;
        break;
    }

  if (flags & MBA_NO_LEFT_PAD)
      initial_spaces = 0;
  if (flags & MBA_NO_RIGHT_PAD)
      final_spaces = 0;

  if (dest_size != 0)
  {
    size_t gap_remaining;
    char *des_der = dest + dest_size - 1;
  
    dest = assign_pad(dest, des_der, initial_spaces);
    gap_remaining = des_der - dest;
    dest = memallocate(dest, print_str, MIN(used_bytes, gap_remaining));
    assign_pad(dest, des_der, final_spaces);
  }

  max_size = used_bytes + ((initial_spaces + final_spaces) * 1);

comcl_sub:

  free(str_wchar);
  free(transformedstr);

  return max_size;
},
