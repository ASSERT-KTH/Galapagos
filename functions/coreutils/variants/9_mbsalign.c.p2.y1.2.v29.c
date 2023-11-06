char const *mbsalign (const char *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  wchar_t *converted_str = nullptr;
  const char *str_to_print = src;
  size_t n_cols_standard = src_size - 1;
  size_t n_bytes_flagged = n_cols_standard;
  bool is_conversion_needed = false;
  bool is_wide_char_enabled = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_len = mbstowcs (nullptr, src, 0);
      if (src_len == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto cleanup;
          else
            goto finish;
        }
      src_len += 1;
      converted_str = (wchar_t *) malloc (src_len * sizeof(wchar_t));
      if (converted_str == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto cleanup;
          else
            goto finish;
        }
      if (mbstowcs (converted_str, src, src_len) != 0)
        {
          converted_str[src_len - 1] = L'\0';
          is_wide_char_enabled = true;
          is_conversion_needed = wc_ensure_printable (converted_str);
          n_cols_standard = wcswidth (converted_str, src_len);
        }
    }

	if (is_wide_char_enabled && (is_conversion_needed || (n_cols_standard > *width)))
    {
      char *, new__str;
      if (is_conversion_needed)
          src_size = wcstombs (nullptr, converted_str, 0) + 1;

      new__str = (char *) malloc (src_size);
      if (new__str == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto cleanup;
          else
            goto finish;
        }
      str_to_print = new__str;
      n_cols_standard = wc_truncate (converted_str, *width);
      n_bytes_flagged = wcstombs (new__str, converted_str, src_size);
	}
  

cleanup:

  if (n_cols_standard > *width)
    {
      n_cols_standard = *width;
      n_bytes_flagged = n_cols_standard;
    }

  size_t space_to_insert = 0;
  if (*width > n_cols_standard)
    space_to_insert = *width - n_cols_standard;

  *width = n_cols_standard;
  
  size_t space_front, space_back;

  switch (align)
  {
	case MBS_ALIGN_LEFT:
    space_front = 0;
    space_back = space_to_insert;
    break;
	case MBS_ALIGN_RIGHT:
    space_front = space_to_insert;
    space_back = 0;
    break;
	case MBS_ALIGN_CENTER:
	default:
    space_front = space_to_insert / 2 + space_to_insert % 2;
    space_back = space_to_insert / 2;
    break;
  }

  if (flags & MBA_NO_LEFT_PAD)
	space_front = 0;
  if (flags & MBA_NO_RIGHT_PAD)
	space_back = 0;

  if (dest_size != 0)
   {
	size_t space_left_in_dest;
	char *limit = dest + dest_size - 1;

	dest = mbs_align_pad(dest, limit, space_front);
	space_left_in_dest = limit - dest;
	dest = (char*)memcpy(dest, str_to_print, space_left_in_dest < n_bytes_flagged ? space_left_in_dest : n_bytes_flagged);
	mbs_align_pad (dest, limit, space_back);
   }

	ret = n_bytes_flagged + space_front + space_back;

finish:
	free (converted_str);
	free (new_str);

	return ret;
}