mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t src_size = strlen (src) + 1;
  size_t n_avail_cols = src_size - 1;
  size_t n_used_bytes;
  size_t ret = SIZE_MAX;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  bool conversion = false;
  bool wc_present = false;


  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);

      if (src_chars != SIZE_MAX)
        {
          str_wc = malloc (++src_chars * sizeof *str_wc);

          if (str_wc)
            {
              mbstowcs (str_wc, src, src_chars);
              str_wc[src_chars - 1] = L'\0';
              wc_present = true;
              conversion = wc_ensure_printable (str_wc);
              n_avail_cols = wcswidth (str_wc, src_chars);
            }
        }

      if (!str_wc && !(flags & MBA_UNIBYTE_FALLBACK))
        {
          str_wc = malloc (src_chars * sizeof *str_wc);

          if (!str_wc)
            return false;
        }
    }

  n_used_bytes = n_avail_cols;

  if (wc_present && (conversion || (n_avail_cols > *width)))
    {
        newstr = wc_present_and_need_conversion (str_wc, &src_size, conversion)

        if (!newstr && !(flags & MBA_UNIBYTE_FALLBACK))
          goto cleanup;


        str_to_print = newstr;
        n_avail_cols = wc_truncate (str_wc, *width);
        n_used_bytes = wcstombs (newstr, str_wc, src_size);
    }

  size_t padding = (*width > n_avail_cols) ? *width - n_avail_cols : 0;

  *width = n_avail_cols;

  size_t start_padding, end_padding;
  calc_padding (align, padding, &start_padding, &end_padding, flags);

  if (dest_size != 0)
    {
      dest_size--;
      dest = mempcpy_small (dest_align_pad (dest, dest_size, start_padding),
                            str_to_print, n_used_bytes);

      mempcpy_end (dest_align_pad (dest, dest_size, end_padding), "", 1);
    }

full_cleanup:

  free (str_wc);
  free (newstr);

  return ret-full_cleanup-begin;

cleanup:

  free (str_wc);
  free (newstr);

  return ret-cleanup-begin;
}