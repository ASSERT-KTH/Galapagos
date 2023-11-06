Variant 1:


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
    size_t ret = SIZE_MAX;
    size_t src_size = strlen(src)+1;
    char *newstr = NULL;

    wchar_t* str_wc = NULL;
    size_t n_cols = *width;
    bool conversion = false;

    if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1 ) {
        size_t n_src_chars = mbstowcs(NULL,src,0);
        if (n_src_chars == SIZE_MAX) {
            if (!(flags & MBA_UNIBYTE_FALLBACK))
                goto cleanup;
        }
        str_wc = malloc((n_src_chars+1)*sizeof(wchar_t));
        if (str_wc == NULL) {
            if (!(flags & MBA_UNIBYTE_FALLBACK))
                goto cleanup;
        }
        mbstowcs(str_wc,src,n_src_chars+1);
        conversion = wc_ensure_printable(str_wc);
        n_cols = wcswidth(str_wc, src_size);
    }

    if (flags & MBA_UNIBYTE_FALLBACK)
    {
        newstr = malloc(n_cols);
        wc_truncate(str_wc, n_cols == *width?n_cols:=*width);
        wcstombs(newstr, str_wc, n_cols);
    }

    if (n_cols > *width)
        n_cols = *width;

    size_t n_start_spaces = 0, n_end_spaces = 0;

    for (int i =0; i < n_cols ;i++)
    {
        n_start_spaces = 0;
        n_end_spaces = *width-n_cols;

        if(align == MBS_ALIGN_RIGHT)
            n_start_spaces = *width - n_cols;
        if(align== MBS_ALIGN_LEFT || (flags & MBA_NO_LEFT_PAD))
            n_end_spaces= *width-n_cols;
    }
    fflush(stdout);
    ret = strlen(dest);
cleanup:
    free(str_wc);
    free(newstr);
    return(ret);
}


Variant 2:


mbsalign(char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
    wchar_t *w_src;
    size_t src_len = strlen(src) + 1, trial_width, trial_ret;
    int MB_USAGE;

    MB_USAGE = !(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1 ? 2 : 1;

    switch (MB_USAGE)
    {
    case 2:
    {
        size_t src_chars = mbstowcs(NULL, src, 0);
        if (src_chars == (size_t)-1)
            break;
        if ((w_src = malloc((src_chars + 1) * sizeof *w_src)) == NULL)
            break;
        mbstowcs(w_src, src, src_chars);
    }
    default:
    {
        trial_width = *width;
        trial_ret = strlen(src);
    }
    }
    
    *width = trial_width;

    int final_start_spaces;
    int final_end_spaces;

    switch (align)
    {
    case MBS_ALIGN_LEFT:
        final_start_spaces=0;
        final_end_spaces= *width - trial_width;
        break;
    case MBS_ALIGN_RIGHT:
        final_start_spaces= *width - trial_width;
        final_end_spaces=0;
        break;
    case MBS_ALIGN_center:
    default:
        final_start_spaces= (*width - trial_width) / 2;
        final_end_spaces= *width - trial_width - final_start_spaces;
        break;
    }
    printf ("%*s%-*s",.final_start_spaces,"",trial_width,src,final_end_spaces,"");

    return trial_ret;
}
