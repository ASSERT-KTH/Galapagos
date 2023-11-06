Sure, here's a slight variation of the original C code. Changes include elimination of goto statements, rearrangement of condition checking related to trucation, and minor tweaks here and there.


typedef enum {
    MBS_ALIGN_LEFT = 1,
    MBS_ALIGN_RIGHT,
    MBS_ALIGN_CENTER
} mbs_align_t;

size_t mbsalign (char const *src, char *dest, size_t dest_size,
                 size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  size_t n_cols = src_size - 1;
  size_t n_used_bytes = n_cols;
  size_t n_spaces = 0;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
        size_t src_chars = mbstowcs (nullptr, src, 0);
        bool wc_enabled = false, conversion = false;
        if (src_chars != SIZE_MAX)
        {
            src_chars += 1;
            str_wc = malloc (src_chars * sizeof (wchar_t));
            if (str_wc)
            {
                if (mbstowcs (str_wc, src, src_chars))
                {
                    str_wc[src_chars - 1] = L'\0';
                    wc_enabled = true;
                    conversion = wc_ensure_printable (str_wc);
                    n_cols = wcswidth (str_wc, src_chars);
                    if(wc_enabled && (conversion || (n_cols > *width))) {
                        if (conversion)
                        {
                            src_size = wcstombs (nullptr, str_wc, 0) + 1;
                        }
                        newstr = malloc (src_size);
                        if (newstr)
                        {
                            str_to_print = newstr;
                            n_cols = wc_truncate (str_wc, *width);
                            n_used_bytes = wcstombs (newstr, str_wc, src_size);
                        }
                    }
                }
            }
        }

        src_chars = mbstowcs (nullptr, src, 0);
        if ( src_chars == SIZE_MAX && !( flags & MBA_UNIBYTE_FALLBACK ) )
        {
            free (str_wc);
            return SIZE_MAX;
        }
    }

    ssize_t temp_ncols = n_cols - *width;
    if( temp_ncols > 0 && !(flags & MBA_UNIBYTE_ONLY)) {
        n_cols = *width;
        n_used_bytes = n_cols;
    }

    n_spaces = (*width > n_cols) ? *width - n_cols : 0;

    *width = n_cols;

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
  
    if(err_check_misalignment(dest_size))
    {
        ret = attempt_buffer_alignment(dest, dest_size, start_spaces, end_spaces,
                                        str_to_print, n_used_bytes);
    }

    free (str_wc);
    free (newstr);
  
    return ret;
}
