Variant 1:

mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t result = SIZE_MAX;
  size_t source_size = strlen (src) + 1;
  char *altered_string = NULL;
  wchar_t *wchar_string = NULL;
  char const *output_string = src;
  size_t column_count = source_size - 1;
  size_t byte_count = column_count;
  size_t padding_num = 0;
  bool convert_status = false;
  bool wchar_status = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t char_count = mbstowcs (NULL, src, 0);
      if (char_count == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_round;
          else
            goto cleanup_round;
        }
      char_count += 1;
      wchar_string = malloc (char_count * sizeof (wchar_t));
      if (wchar_string == NULL)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_round;
          else
            goto cleanup_round;
        }
      if (mbstowcs (wchar_string, src, char_count) != 0)
        {
          wchar_string[char_count - 1] = L'\0';
          wchar_status = true;
          convert_status = wc_ensure_printable (wchar_string);
          column_count = wcswidth (wchar_string, char_count);
        }
    }

  if (wchar_status && (convert_status || (column_count > *width)))
    {
        if (convert_status)
            source_size = wcstombs (NULL, wchar_string, 0) + 1;
        altered_string = malloc (source_size);
        if (altered_string == NULL)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_round;
          else
            goto cleanup_round;
        }
        output_string = altered_string;
        column_count = wc_truncate (wchar_string, *width);
        byte_count = wcstombs (altered_string, wchar_string, source_size);
    }

unibyte_round:

  if (column_count > *width)
    {
      column_count = *width;
      byte_count = column_count;
    }

  if (*width > column_count)
    padding_num = *width - column_count;

  *width = column_count;

  {
    size_t initial_padding, final_padding;

    switch (align)
      {
      case MBS_ALIGN_LEFT:
        initial_padding = 0;
        final_padding = padding_num;
        break;
      case MBS_ALIGN_RIGHT:
        initial_padding = padding_num;
        final_padding = 0;
        break;
      case MBS_ALIGN_CENTER:
      default:
        initial_padding = padding_num / 2 + padding_num % 2;
        final_padding = padding_num / 2;
        break;
      }

      if (flags & MBA_NO_LEFT_PAD)
        initial_padding = 0;
      if (flags & MBA_NO_RIGHT_PAD)
        final_padding = 0;

      if (dest_size != 0)
        {
          size_t space_remaining;
          char *dest_end = dest + dest_size - 1;

          dest = mbs_align_pad (dest, dest_end, initial_padding);
          space_remaining = dest_end - dest;
          dest = mempcpy (dest, output_string, MIN (byte_count, space_remaining));
          mbs_align_pad (dest, dest_end, final_padding);
        }

    result = byte_count + ((initial_padding + final_padding) * 1);
  }

cleanup_round:

  free (wchar_string);
  free (altered_string);

  return result;
}
