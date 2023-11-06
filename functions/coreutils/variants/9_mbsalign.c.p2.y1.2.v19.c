mbsalign(char const* src, char* dest, size_t dest_size,
    size_t* width, mbs_align_t align, int flags)
{
    size_t ret = SIZE_MAX;
    size_t src_size = strlen(src) + 1;
    char* newstr = nullptr;
    wchar_t* wc_str = nullptr;
    char const* str_to_print = src;
    size_t n_cols = src_size - 1;
    size_t n_copy_bytes = n_cols;
    size_t n_spaces = 0;
    bool convert_set = false;
    bool wc_set = false;

    if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
        size_t src_chars = mbstowcs(nullptr, src, 0);
        assert(src_chars != SIZE_MAX);

        if (src_chars == SIZE_MAX) {
            if (!(flags & MBA_UNIBYTE_FALLBACK))
                return ret;
        }
        else
        {
            wc_str = (wchar_t*)malloc(++src_chars * sizeof(wchar_t));
            assert(wc_str != nullptr);

            if (mbstowcs(wc_str, src, src_chars) != 0)
            {
                wc_str[src_chars - 1] = L'\0';
                wc_set = true;
                convert_set = wc_ensure_printable(wc_str);
                n_cols = wcswidth(wc_str, src_chars);
            }
        }
    }

    if (wc_set && (convert_set || (n_cols > * width)))
    {
        if (convert_set) {
            src_size = wcstombs(nullptr, wc_str, 0) + 1;
        }
        newstr = (char*)malloc(src_size);
        assert(newstr != nullptr);
        str_to_print = newstr;
        n_cols = wc_truncate(wc_str, *width);
        n_copy_bytes = wcstombs(newstr, wc_str, src_size);
    }

    if (n_cols > * width)
    {
        n_cols = *width;
        n_copy_bytes = n_cols;
    }

    if (*width > n_cols) 
        n_spaces = *width - n_cols;

    *width = n_cols;

    size_t start_spaces = 0, end_spaces = 0;

    switch (align)
    {
    case MBS_ALIGN_LEFT:
        break;
    case MBS_ALIGN_RIGHT:
        start_spaces = n_spaces;
        break;
    default:
        start_spaces = n_spaces / 2 + n_spaces % 2;
        end_spaces = n_spaces - start_spaces;
        break;
    }
    if (flags & MBA_NO_LEFT_PAD) start_spaces = 0;
    if (flags & MBA_NO_RIGHT_PAD) end_spaces = 0;

    if (dest_size)
    {
        size_t padding = start_spaces;
        char* end_dest = dest + dest_size - 1;
        mend_dest_from = mbs_align_pad(dest, end_dest, padding);
        padding = end_dest - dest;
        resulting_dest = mempcpy(mend_dest_from, str_to_print, min(n_copy_bytes, padding)); 
        mbs_align_pad(resulting_dest,end_dest,end_spaces);
    }

    ret = n_copy_bytes + (start_spaces + end_spaces) * 1;

    free(wc_str);
    free(newstr);

    return ret;
}