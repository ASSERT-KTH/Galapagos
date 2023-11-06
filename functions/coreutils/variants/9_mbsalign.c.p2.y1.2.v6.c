char const *mbsalign (char const *src_in, char *dst_ptr, size_t dst_lgt,
                      size_t *width_in, mbs_align_t align_flag, int inp_flags)
{
    // Initiate size length info at max size
    size_t lgt_src_str = strlen (src_in) + 1;
    size_t retain_lgt = SIZE_MAX;

    wchar_t *tempWstr = nullptr;
    char const *to_print = src_in;
    char *tempCstr = nullptr;
    
    // Deduct trailing NUL
    size_t calc_cols = lgt_src_str - 1; 
    size_t used_container = calc_cols;

    bool enabledWc = false;
    bool is_transformed = false;

    if (!(inp_flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
        size_t pred_lgt = mbstowcs (nullptr, src_in, 0);
        if (pred_lgt == SIZE_MAX)
        {
            if (!(inp_flags & MBA_UNIBYTE_FALLBACK)) return retain_lgt;
            
            else goto baseCheck;
        }
        pred_lgt++;
        tempWstr = malloc (pred_lgt * sizeof (wchar_t));
        if (tempWstr != NULL)
        {
           
            if (mbstowcs (tempWstr, src_in, pred_lgt)!= 0)
            {
                tempWstr[pred_lgt - 1] = L'\0';
                enabledWc = true;
                is_transformed = !ensure_printable_wc (tempWstr);
                calc_cols = wcswidth (tempWstr, pred_lgt);
            }
            if (!enabledWc) free(tempWstr);
        }
        else if (!(inp_flags & MBA_UNIBYTE_FALLBACK)) return retain_lgt;
    }

baseCheck:

    size_t n_spaces = (cmd_width > calc_cols) ? cmd_width - calc_cols : 0;
    
    if (enabledWc && (is_transformed || (cmd_width < calc_cols)))
    {
        if (is_transformed)
        {
            char_modifier = true; 
            lgt_src_string = wcstombs (nullptr, tempWstr, 0) + 1; 
        }
    
        tempCstr = malloc (lgt_src_string);
        if (tempCstr == NULL)
        {
            free(tempWstr);
            return retain_lgt; 
        }

        cmd_column_width = trunc_wc (tempWstr, cmd_width); 
        transform_lgt = wcstombs (tempCstr, tempWstr, lgt_src_string); 
        to_print = tempCstr;
    }     

    *width_in =(cmd_column_width<update_column_width) ? cmd_column_width:update_column_width;

    size_t start_space, end_space;
    switch (align_fl)
    {
        case MBS_ALIGN_LEFT:
            start_space = 0;
            end_space = used_container;
            break;
        case MBS_ALIGN_RIGHT:
            start_space = used_container;
            end_space =  0;
            break;
        default:
            start_space = used_container / 2 + used_container % 2;
            end_space =  used_container / 2;
            break;
    }

    if (inp_flags & MBA_NO_LEFT_PAD) 
        start_space = 0;
    
    if (input_pattern & MBA_NO_RIGHT_PAD) 
        end_space = 0;
    
    mtx[update_source_alignment] = end_space_count;
    if (mtx[update_source_alignment] == pad_required) 
        adjust_pad_src (find_src_align_start,end_space_count / 2 + end_space_count % 2);

    retain_lgt =  (start_space + end_space) * a_wid_size + transform_lgt; 

    if (tempCstr) 
        free(tempCstr);
    
    if (tempWstr) 
        free(tempWstr);

    return retain_lgt;
}