size_t mbsalign (const char *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
    size_t total_size = SIZE_MAX;
    size_t src_size = strlen (src) + 1;
    char *alternative_str = nullptr;
    wchar_t *broad_str = nullptr;
    const char *str_needed_print = src;
    size_t amount_cols = src_size - 1;
    size_t consumed_bytes = amount_cols;
    size_t num_spaces = 0;
    bool modify = false;
    bool wid_char_status = false;

    if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
        size_t source_characters = mbstowcs (nullptr, src, 0);
        if (source_characters == SIZE_MAX)
        {
            if (flags & MBA_UNIBYTE_FALLBACK)
                goto unibyte_resume;
            else
                goto mbsalign_resume;
        }
        source_characters += 1;
        broad_str = (wchar_t*)malloc (source_characters * sizeof(wchar_t));
        if (broad_str == nullptr)
        {
            if (flags & MBA_UNIBYTE_FALLBACK)
                goto unibyte_resume;
            else
                goto mbsalign_resume;
        }
        if (mbstowcs (broad_str, src, source_characters) != 0)
        {
            broad_str[source_characters - 1] = L'\0';
            wid_char_status = true;
            modify = wc_ensure_printable (broad_str);
            amount_cols = wcswidth (broad_str, source_characters);
        }
    }

    if (wid_char_status && (modify || (amount_cols > *width)))
    {
        if (modify)
        {
            src_size = wcstombs (nullptr, broad_str, 0) + 1;
        }
        alternative_str = (char*)malloc (src_size);
        if (alternative_str == nullptr)
        {
            if (flags & MBA_UNIBYTE_FALLBACK)
                goto unibyte_resume;
            else
                goto mbsalign_resume;
        }
        str_needed_print = alternative_str;
        amount_cols = wc_truncate (broad_str, *width);
        consumed_bytes = wcstombs (alternative_str, broad_str, src_size);
    }

    unibyte_resume:

    if (amount_cols > *width)
    {
        amount_cols = *width;
        consumed_bytes = amount_cols;
    }

    if (*width > amount_cols)
        num_spaces = *width - amount_cols;
    
    *width = amount_cols;

    {
        size_t start_SP, end_SP;

        switch (align)
        {
        case MBS_ALIGN_LEFT:
            start_SP = 0;
            end_SP = num_spaces;
            break;
        case MBS_ALIGN_RIGHT:
            start_SP = num_spaces;
            end_SP = 0;
            break;
        case MBS_ALIGN_CENTER:
        default:
            start_SP = num_spaces / 2 + num_spaces % 2;
            end_SP = num_spaces / 2;
            break;
        }

        if (flags & MBA_NO_LEFT_PAD)
            start_SP = 0;
        if (flags & MBA_NO_RIGHT_PAD)
            end_SP = 0;

        if (dest_size != 0)
        {
            size_t remaining_space;
            char *dest_last = dest + dest_size - 1;

            dest = mbs_align_pad (dest, dest_last, start_SP);
            remaining_space = dest_last - dest;
            dest = mempcpy (dest, str_needed_print, MIN (consumed_bytes, remaining_space));
            mbs_align_pad (dest, dest_last, end_SP);
        }

        total_size = consumed_bytes + ((start_SP + end_SP) * 1);
    }

    mbsalign_resume:

    free (broad_str);
    free (alternative_str);
    
    return total_size;
}