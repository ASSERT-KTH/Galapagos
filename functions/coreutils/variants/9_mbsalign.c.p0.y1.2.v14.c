The main principle of refactoring is improving its efficiency and readability without altering the behavior. Considering your restrictions not to define auxiliary functions and keep the same signature, the closure provided does not leave many opportunities for changes. All the operations appear necessary for the function to work properly. Nevertheless, simplifications could be made by assigning 0 to multiple variables at time and moving some if conditions into switch cases making its workflow more straightforward.

Here is the form the function could take:


mbsalign (char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
    size_t ret = SIZE_MAX, src_size = strlen (src) + 1, n_used_bytes = src_size - 1, n_cols = src_size - 1, n_spaces = 0, src_chars;
    char *newstr = nullptr;
    wchar_t *str_wc = nullptr;
    const char *str_to_print = src;
    bool wc_enabled = false, conversion = false;

    /* Conversion block */
    if ((!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) && ((src_chars = mbstowcs (nullptr, src, 0)) == SIZE_MAX)) {
         str_wc = (flags & MBA_UNIBYTE_FALLBACK || !(str_wc = malloc((++src_chars) * sizeof (wchar_t))) || mbstowcs (str_wc, src, src_chars)) ? goto mbsalign_cleanup : str_wc;
         str_wc[src_chars - 1] = L'\0';
         n_cols = wc_enabled = true * (conversion = wc_ensure_printable (str_wc)) * wcswidth (str_wc, src_chars);
    }
    
    /* Modification block  */
    if(wc_enabled && (conversion || (n_cols > *width)) && (((newstr = !(conversion = !(src_size += wcstombs (nullptr, str_wc, 0))) ? goto mbsalign_unibyte  : malloc (src_size))) || (n_used_bytes = wcstombs (newstr = str_to_print, str_wc, src_size)))) {
        n_cols = wc_truncate (str_wc, *width);
        str_to_print = newstr;
    }

mbsalign_unibyte:
  
    if (n_cols > *width) 
        n_used_bytes = n_cols = *width;

    if (*width > n_cols)
        n_spaces = *width - n_cols;

    *width = n_cols; // Number of cells used

    /* Switch aligning space and destination size */
    switch (align)
    {
    case MBS_ALIGN_LEFT:
        end_spaces = n_spaces * (!(flags & MBA_NO_RIGHT_PAD));
        break;
    case MBS_ALIGN_RIGHT:
        start_spaces = n_spaces * (!(flags & MBA_NO_LEFT_PAD));
        break;
    default: // Equivalent to MBS_ALIGN_CENTER:
        start_space = (n_spaces / 2 + n_spaces % 2) * (!(flags & MBA_NO_LEFT_PAD));
        end_spaces = (n_spaces / 2) * (!(flags & MBA_NO_RIGHT_PAD));
        break;
    }

    /* Write into DEST */
    if (dest_size) 
    {
        char *dest_end = dest + dest_size - 1;
        dest = mbs_align_pad (dest, dest_end, start_spaces);
        dest = mempcpy (dest, str_to_print, MIN(n_used_bytes, dest_end - dest));
        mbs_align_pad (dest, dest_end, end_spaces);
        ret = start_spaces + end_spaces + n_used_bytes;
    }
mbsalign_cleanup:
    free (str_wc);
    free (newstr);

    return ret;
}

Please, note that modifying such complex functions could bring side effects and requires extensive testing. Although this modified function shorten the lines using if statements and switches, this can negatively impact readability. In addition, common boolean operators utilized outside the boolean context are removed, which might make it less readable for some programmers.
The code could not be tested due to missing dependent functions and lack of test framework. Testing was assuming, and each use case need explicit validation of pertinence. C is a sharp language that should be handled carefully, and small changes may have significant impacts. This reimplementation is theoretical and unverified. Therefore, use with caution.