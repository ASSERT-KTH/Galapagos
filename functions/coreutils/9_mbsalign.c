mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  size_t n_cols = src_size - 1;
  size_t n_used_bytes = n_cols; /* Not including NUL */
  size_t n_spaces = 0;
  bool conversion = false;
  bool wc_enabled = false;

  /* In multi-byte locales convert to wide characters
     to allow easy truncation. Also determine number
     of screen columns used.  */
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      if (src_chars == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_unibyte;
          else
            goto mbsalign_cleanup;
        }
      src_chars += 1; /* make space for NUL */
      str_wc = malloc (src_chars * sizeof (wchar_t));
      if (str_wc == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_unibyte;
          else
            goto mbsalign_cleanup;
        }
      if (mbstowcs (str_wc, src, src_chars) != 0)
        {
          str_wc[src_chars - 1] = L'\0';
          wc_enabled = true;
          conversion = wc_ensure_printable (str_wc);
          n_cols = wcswidth (str_wc, src_chars);
        }
    }

  /* If we transformed or need to truncate the source string
     then create a modified copy of it.  */
  if (wc_enabled && (conversion || (n_cols > *width)))
    {
        if (conversion)
          {
             /* May have increased the size by converting
                \t to \uFFFD for example.  */
            src_size = wcstombs (nullptr, str_wc, 0) + 1;
          }
        newstr = malloc (src_size);
        if (newstr == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_unibyte;
          else
            goto mbsalign_cleanup;
        }
        str_to_print = newstr;
        n_cols = wc_truncate (str_wc, *width);
        n_used_bytes = wcstombs (newstr, str_wc, src_size);
    }

mbsalign_unibyte:

  if (n_cols > *width) /* Unibyte truncation required.  */
    {
      n_cols = *width;
      n_used_bytes = n_cols;
    }

  if (*width > n_cols) /* Padding required.  */
    n_spaces = *width - n_cols;

  /* indicate to caller how many cells needed (not including padding).  */
  *width = n_cols;

  {
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

      if (flags & MBA_NO_LEFT_PAD)
        start_spaces = 0;
      if (flags & MBA_NO_RIGHT_PAD)
        end_spaces = 0;

      /* Write as much NUL terminated output to DEST as possible.  */
      if (dest_size != 0)
        {
          size_t space_left;
          char *dest_end = dest + dest_size - 1;

          dest = mbs_align_pad (dest, dest_end, start_spaces);
          space_left = dest_end - dest;
          dest = mempcpy (dest, str_to_print, MIN (n_used_bytes, space_left));
          mbs_align_pad (dest, dest_end, end_spaces);
        }

    /* indicate to caller how many bytes needed (not including NUL).  */
    ret = n_used_bytes + ((start_spaces + end_spaces) * 1);
  }

mbsalign_cleanup:

  free (str_wc);
  free (newstr);

  return ret;
}