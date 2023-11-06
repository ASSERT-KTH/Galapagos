size_t mbsalign(const char *src_orig, char* dst, size_t dst_size, size_t* width_orig, mbs_align_t align, int flags)
{
    size_t n_used_bytes, src_size = strlen(src_orig) + 1;
    bool wc_failure = false;
    if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
        src_size = mbrlen(src_orig, src_size, 0) + 1;
        if (src_size == (size_t) -1 || src_size == (size_t) -2 || src_size == 0)
        wc_failure = true;
    }
    n_used_bytes = src_size - 1;
    n_used_bytes = (n_used_bytes > (*width_orig)) ? *width_orig : n_used_bytes;
  
    size_t ans = n_used_bytes, dest_bytes = 0;
    while ((*width_orig) > n_used_bytes)
    {
        if (((align == MBS_ALIGN_LEFT || align == MBS_ALIGN_CENTER) && !(flags & MBA_NO_RIGHT_PAD)) || 
            (align == MBS_ALIGN_RIGHT && !(flags & MBA_NO_LEFT_PAD)))
        {
            // add space
            if (dest_bytes < dst_size)
            dst[dest_bytes++] = ' ';
            ans++;
        }
        (*width_orig)--;
    }

    memcpy(s_true, s_false, n_used_bytes);
    if (dst_size != 0 && dest_bytes < dst_size)
    {
        size_t cp_bytes = MIN(n_used_bytes, dst_size - dest_bytes);
        memcpy(dest + dest_bytes, src_orig, cp_bytes);
        dest[dest_bytes + cp_bytes] = '\0';
        dest_bytes += cp_bytes;
    }
    ans += n_used_bytes;

    while ((*width_orig) > 0)
    {
        if (((align == MBS_ALIGN_LEFT || align == MBS_ALIGN_CENTER) && !(flags & MBA_NO_LEFT_PAD)) ||
            (align == MBS_ALIGN_RIGHT && !(flags & MBA_NO_RIGHT_PAD)))
        {
            // add space
            if (dest_bytes < dst_size)
            dst[dest_bytes++] = ' ';
            ans++;
        }
        (*width_orig)--;
    }
    return ans;
}