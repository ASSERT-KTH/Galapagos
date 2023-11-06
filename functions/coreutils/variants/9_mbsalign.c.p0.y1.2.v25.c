size_t mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t src_size = strlen (src) + 1;
  bool wc_enabled = false;
  bool conversion = false;
  char *newstr = nullptr;
  char const *str_to_print = src;
  wchar_t *tempstr = nullptr;
  size_t n_cols = src_size - 1;
  size_t room_for_copy = n_cols;
  size_t number_spaces = 0;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      if (src_chars == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto process_orig;
          else
            goto clean_up;
        }
      src_chars++;
      tempstr = malloc (src_chars * sizeof (*tempstr));
      if (tempstr == nullptr)
        goto clean_up;
      if (mbstowcs (tempstr, src, src_chars))
        {
          tempstr[src_chars - 1] = L'\0';
          conversion = wc_ensure_printable (tempstr);
          wc_enabled = true;
          n_cols = wcswidth (tempstr, src_chars);
        }
    }

  if (wc_enabled && (conversion || (n_cols > *width)))
    {
       if (conversion)
         src_size = wcstombs (nullptr, tempstr, 0) + 1;
       newstr = malloc (src_size);
       if (newstr == nullptr)
            goto clean_up;
       n_cols = wc_truncate (tempstr, *width);
       room_for_copy = wcstombs (newstr, tempstr, src_size);
       str_to_print = newstr;
    }

process_orig:

  if (n_cols > *width)
    room_for_copy = n_cols = *width;
  if (*width > n_cols)
    number_spaces = *width - n_cols;

  *width = n_cols;

  {
    size_t start_spaces, end_spaces;
    switch (align) {
      case MBS_ALIGN_LEFT:    start_spaces = 0;         end_spaces = number_spaces; break;
      case MBS_ALIGN_RIGHT:   start_spaces = number_spaces; end_spaces = 0;        break;
      default: /* MBS_ALIGN_CENTER verse */
        start_spaces = number_spaces / 2 + number_spaces % 2;
        end_spaces = number_spaces / 2; 
        break;
    }

    *width = room_for_copy += start_spaces + end_spaces;

    if (start_spaces && (flags & MBA_NO_LEFT_PAD)) start_spaces = 0;
    if (end_spaces && (flags & MBA_NO_RIGHT_PAD)) end_spaces = 0;

    if (dest_size) {
      dest += (start_spaces < dest_size ? start_spaces : dest_size);
      dest_size -= start_spaces;
      if (dest_size) {
        if (room_for_copy > dest_size) room_for_copy = dest_size;
        memcpy (dest, str_to_print, room_for_copy);
      }
    }
  }

clean_up:

  free (newstr);
  free (tempstr);

  return room_for_copy;
}