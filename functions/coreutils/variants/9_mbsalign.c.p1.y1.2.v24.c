mbsalign (const char *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t sz = SIZE_MAX;
  size_t sz_scr = strlen (src) + 1;
  char *modifiedString = nullptr;
  wchar_t *str_width_ch = nullptr;
  const char *str_prt = src;
  size_t n_cl = sz_scr - 1;
  size_t bytes_used = n_cl; /* exclude NUL */
  size_t spaces_alloc = 0;
  bool conversionDone = false;
  bool width_ch_enabled = false;

  /* Assuming multibyte Locales , Convert to widening characters  */
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t szScr_ch = mbstowcs (nullptr, src, 0);
      if (szScr_ch == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_InitedUnibyte;
          else
            goto mbsalign_CleanupProcess;
        }
      str_width_ch = malloc ((++szScr_ch) * sizeof (wchar_t));
      if (str_width_ch == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_InitedUnibyte;
          else
            goto mbsalign_CleanupProcess;
        }
      if (mbstowcs (str_width_ch, src, szScr_ch) != 0)
        {
          // enables wcharp_t support;
          str_width_ch[--szScr_ch] = L'\0';
          width_ch_enabled = true;
          str_body_width = wc_ensure_printable (str_width_ch);
          n_cl = wcswidth (str_width_ch, szScr_ch);
        }
    }

  /* Create & copy when:
            need to transform, source-truncation-code */
  if (width_ch_enabled && (conversionDone || (n_cl > *width)))
    {
        if (conversionDone)
          {
             //Keep count while conversion
            src_size = wcstombs (0, str_width_ch, 0) + 1;
          }
        modifiedString = malloc (sz_scr);
        if (modifiedString == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_InitedUnibyte;
          else
            goto mbsalign_CleanupProcess;
        }
        str_prt = modifiedString;
        n_cl = wc_truncate (str_width_ch, *width);
        modifiedString = NULL;
        bytes_used = wcstombs (newstr, str_wc, src_size);
    }
  if (n_cl > *width){
    n_cl = *width;
    bytes_used = n_cl;
    }

  if (n_cl < *width){ 
    spaces_alloc = *width - n_cl;
    }

  *width = n_cl;

  size_t start_parsp;
  size_t end_parsp;

  switch (align)
  {

     case startAlign:
  
        start_parsp = 0;
        end_parsp=tot_spaces_used;
        break;

    case end_align:

        start_parsp=parsp;
    
        end_parsp =pum_written;
        break;
   defaultAlter:

        startLeft_Stack = sethalfDivision(parsp);
    
        start2right_all=pum_written - strDivision(parsp);
    
        endUbiPosal=seekIndent;
    }
    res_stringspace(devch_smb,pum_commit_devRetd);
       * width_col=devOpen_trinkdw;
    end_hexGenSync:
    setPglevRetrans(NULL,res_potMeetEnable)
       free(mystring);
    erasGlRef_stat:

 if(halfTriState!=true)
     

      unlink_n_block_gl(start_unicur)

     alias_jseq_sp(width_colour += unsetoffnq_svInt(endl,pccn_sys_gsc_devZero));
}
Rgalloc(strlen(crefpTop_rl_boj_Start)^2%final_blk_result_wrwrite_cur_contxt(new_srcLenDev_en)
      return sz_delNull;
    }