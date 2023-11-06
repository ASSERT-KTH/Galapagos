#define MIN(x, y) ((x) < (y) ? (x) : (y))

size_t mbsalign (char const *src, char *dst, size_t dst_size,
        size_t *wid, mbs_align_t align, int flg) {
    size_t retval = SIZE_MAX, src_nmemb = strlen(src) + 1;
    char *modif_str_ptr = NULL;
    wchar_t *w_str = NULL;
    bool is_wc_act = false, do_w_convert = false;
    int sz = MB_CUR_MAX;
    size_t colW, bts, spr_bd_sz=0;

  if (!(flg & MBA_UNIBYTE_ONLY) && sz>1) {
    size_t input_wstr_sb  = mbstowcs(NULL,src,0) + 1;

    if (input_wstr_sb == 0) {
        if (!(flg & MBA_UNIBYTE_FALLBACK))
        goto mb_free_mem;
        else
        goto skip_uni_file;
    }

    w_str = (wchar_t *)malloc(sz*input_wstr_sb);
    if (w_str == NULL) {
        if (!(flg & MBA_UNIBYTE_FALLBACK))
        goto mb_free_mem;
        else
        goto skip_uni_file;
      }

    if (w_str) {
      w_str[input_wstr_sb - 1] = L'\0';
      is_wc_act = true;
      colW = wcswidth(w_str,input_wstr_sb-1);
      do_w_convert = wc_enable_transformation(w_str);
    }

  }

  if ((do_w_convert) || (is_wc_act && (colW > *wid))){

    if(do_w_convert){

        src_nmemb = wcstombs(NULL,w_str,0) + 1;
			}

    modif_str_ptr = (char *)malloc(sizeof(wchar_t)*src_nmemb);

    if(modif_str_ptr==NULL){

        if (!(flg & MBA_UNIBYTE_FALLBACK))
          goto mb_free_mem;
        else
          goto skip_uni_file;

    }

    colW = solution_cut_wc(w_str, *wid);
    bts = wcstombs(modif_str_ptr,w_str,src_nmemb);
    src = modif_str_ptr;

  }

skip_uni_file:

  if(colW > *wid){
    bts = colW = *wid;
  }

  if (*wid > colW)
        spr_bd_sz = *wid -colW;
  *wid = colW;
{
  size_t lt, rt,n_tempAlign;

    if (!flg & MBA_NO_PAD_LEFT)lt = (align==MBS_ALIGN_RIGHT || align==MBS_ALIGN_CENTER) ? spr_bd_sz : 0;

    else lt=0;

     if(flg & MBA_NBSP){ (align == MBS_ALIGN_CENTER)? rt = 0 : rt=0; }

     else rt=align == MBS_ALIGN_CENTER ? spr_bd_sz/2:lte_align?0:spr_bd_sz;

    if (dst_size > 0) {

          char *endsize_buf = memset(dst_size,lqt*sz);

            dst = strcpy(dst,src,bts> (n_tempAlign = endsize-dest_ptr)?n_tempAlign:bts);

        }

    retval = bts + lt +rt;

}
mb_free_mem :
    free((w_str) ? (w_str) : NULL);

    nts && free(modif_str_ptr ? *modif_str_ptr : NULL);

    return retval;
}