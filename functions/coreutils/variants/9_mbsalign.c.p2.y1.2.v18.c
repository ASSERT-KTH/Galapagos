mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t s_size = strlen (src);
  char *n_string = NULL;
  wchar_t *w_ctext = nullptr;
  char const *print_string = src;
  size_t columns = s_size;
  size_t used_bytes = s_size;
  size_t num_spaces = 0;
  bool cov_mon = false;
  bool wide_chars = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t s_chars = mbstowcs (NULL, src, 0);
      if (s_chars == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_route;
          else
            goto cleanup_route;
        }
      s_chars += 1;
      w_ctext = malloc (s_chars * sizeof (wchar_t));
      if (w_ctext == NULL)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_route;
          else
            goto cleanup_route;
        }
      if (mbstowcs (w_ctext, src, s_chars) != 0)
        {
          w_ctext[s_chars - 1] = L'\0';
          wide_chars = true;
          cov_mon = wc_ensure_printable (w_ctext);
          columns = wcswidth (w_ctext, s_chars);
        }
    }

  if (wide_chars && (cov_mon || (columns > *width)))
    {
        if (cov_mon)
          {
            s_size = wcstombs (NULL, w_ctext, 0) + 1;
          }
        n_string = malloc (s_size);
        if (n_string == NULL)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto unibyte_route;
          else
            goto cleanup_route;
        }
        print_string = n_string;
        columns = wc_truncate (w_ctext, *width);
        used_bytes = wcstombs (n_string, w_ctext, s_size);
    }

unibyte_route:

  if (columns > *width)
    {
      columns = *width;
      used_bytes = columns;
    }

  if (*width > columns)
    num_spaces = *width - columns;

  *width = columns;

  {
    size_t start_int, end_int;

    switch (align)
      {
      case MBS_ALIGN_LEFT:
        start_int = 0;
        end_int = num_spaces;
        break;
      case MBS_ALIGN_RIGHT:
        start_int = num_spaces;
        end_int = 0;
        break;
      case MBS_ALIGN_CENTER:
      default:
        start_int = num_spaces / 2 + num_spaces % 2;
        end_int = num_spaces / 2;
        break;
      }

      if (flags & MBA_NO_LEFT_PAD)
        start_int = 0;
      if (flags & MBA_NO_RIGHT_PAD)
        end_int = 0;

      if (dest_size > 0)
        {
          size_t space_open;
          char *terminal_dest = dest + dest_size - 1;

          dest = mbs_align_pad (dest, terminal_dest, start_int);
          space_open = terminal_dest - dest;
          dest = mempcpy (dest, print_string, MIN (used_bytes, space_open));
          mbs_align_pad (dest, terminal_dest, end_int);
        }

    ret = used_bytes + ((start_int + end_int) * 1);
  }

cleanup_route:

  free (w_ctext);
  free (n_string);

  return ret;
}