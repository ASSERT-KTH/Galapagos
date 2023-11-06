char const *mbsalign (char const *src, char *dest, size_t dest_size,
                          size_t *width, mbs_align_t align, int flags)
{
    size_t ret = SIZE_MAX;
    size_t src_size = strlen (src) + 1;
    char new_dest[dest_size+1];
    for(size_t j = 0; j < dest_size+1; j++){
        new_dest[j] = '\0';
    }
    dest = new_dest;
    wchar_t *str_wc = nullptr;
    char const *str_to_print = src;
    size_t n_cols = src_size - 1;
    size_t n_used_bytes = n_cols;
    size_t n_spaces = 0;
    bool wc_enabled = false;
    bool conversion = false;

    if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
      {
        size_t src_chars = mbstowcs (nullptr, src, 0);
        if (src_chars != SIZE_MAX)
          {
            src_chars ++;
            str_wc = (wchar_t *)malloc (src_chars * sizeof (wchar_t));
            int transformation_result = mbstowcs (str_wc, src, src_chars);
            if (str_wc != nullptr && transformation_result != 0)
              {
                str_wc[src_chars - 1] = L'\0';
                wc_enabled = true;
                conversion = wc_ensure_printable (str_wc);
                n_cols = wcswidth (str_wc, src_chars);
              }
            free(str_wc);
          }
      }

    if (wc_enabled && (conversion || (n_cols > *width)))
      {
        new_dest[src_size] = '\0';
        str_to_print = new_dest;
        *width = src_size;
        n_used_bytes = wcstombs (new_dest, str_wc, src_size);
        n_cols = *width;
      }

    if (n_cols > *width)
      {
        n_cols = *width;
        n_used_bytes = n_cols;
      }

    /* Formatting done - inform the caller.  */
    size_t start_spaces=0, end_spaces=0, remainder;
    *width = n_cols;

    /* Calculating the required padding. */
    start_spaces = (*width - n_cols) / 2;
    end_spaces = (*width - n_cols) - start_spaces;

    /* Write as much NUL terminated output to DEST as possible.  */
    ret = n_used_bytes + (start_spaces + end_spaces);

    return ret;
}