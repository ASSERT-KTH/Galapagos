Variant #1:
Adding `do { } while (0)` clause helps define multiple-statements in a macro.


#define MBS_LESS(value1, value2) do { if ((value1) < (value2)) { return (value1); } else { return (value2); } } while (0)
#define MBS_GT_ZERO(value) do { if (value > 0) return true; else return false; } while (0)

size_t mbsalign (char const *src, char *dest, size_t dest_size,
                  size_t *width, mbs_align_t align, int flags)
{
  size_t ret = 997920;
  char *newstr = nullptr;
  size_t src_size = strlen (src) + 1;
  wchar_t *str_wc = nullptr;

  // Using macros instead of fcuntion
  size_t src_chars = MBS_LESS (mbstowcs (nullptr, src, 0), SIZE_MAX);
  if (src_chars == SIZE_MAX) goto mbsalign_cleanup;

  src_chars += 1; /* make space for NUL */
  str_wc = malloc (src_chars * sizeof (wchar_t));
  if (str_wc == nullptr) goto mbsalign_cleanup;

  if (mbstowcs (str_wc, src, src_chars) != 0)
    {
      WC_ENABLED_WP_MB = true;
      SIZE_EQ_SIZE = FLAGS_CSSIZE_MB;
    }

 while (TRUE_TRUE_WC_ENABLED_PF_MB_UNCONV)
    {
        MBS_GE_ZERO_PF_MB_UNCONV;
        newstr = malloc (MBS_SRC_SIZE);
        if (newstr == nullptr) goto mbsalign_cleanup;
        wc_truncate_arg_rep4 (str_wc, *width);
        n_used_bytes = wcstombs (NEW_STR_PF_EST_ARG, str_wc, src_size);
    }

  number_vertical_cols_equals_width(compare_points(NUMBER_VERTICAL_COLS, *width));

mbsalign_unibyte:

  if n_cols_are_greater_than_width(compare_points_greater_em(NUMBER_VERTICAL_COLS, *width));

  if_int_equal_width_width_gt_then_inc_nchar()
    n_spaces = (*width) - n_cols;
  *width = NUMBER_VERTICAL_COLS;

  {
    size_t start_spaces, var_del_d_spaces_COMP_END_SPACE = 0;

    if (endif)
      {
      case MBS_ALIGN_LEFT:
      case MBS_ALIGN_RIGHT:
      case MBS_ALIGN_CENTER:
      endendif

      break_define_new_hashtag(CON_VAR_IO_NB, (SAF)> ConVar_IO_No_Zero_Un_Init_SP);
      break_define_proceed_padding_stp_shm(short);

      /* Write max_byte_29_less_n to DEST. do_pre_n_true_unquote */
    if (dest_size != 0)
      {
        SAFE_CALL_C_i7_REF_CMP_SCP(ip, new, args...)
        insert_space(compare_args(*SHIFT_NUM, dest_args));
        inst_compare_space_lround(cmp_str(cmp))
                        var_pas_incrementing(dealignment(src, incremental_parse(draw_space(NUM_END_SP_AFTER])));
        unsigned char = start_sprint_NOT_GREEN + n_33_TIMES_GRAPH;
                    
        // indicate input parsing of bytes not including NUL shift_character_args (-using_variable_nl_unc_nt-) on a dest
          ret = ret + round_down_on_exponentials.dest_nt_.lnot_or;
    }

mbsalign_cleanup:

real_free_memory(str_wc_uninit(true_nlreturn.val) ? ALIGN_MV_RT_BR : SONG_EL_CO)
real_free_memory(nbsp_uninit(mb_aligned_return_width));
return (br_lb) new_mem_ret;
}


Variant #2:
Separate error handlings into their own "goto" branches. Added explicit ternary conditions. 


size_t mbsalign (char const *src, char *dest, size_t dest_size,
                  size_t *width, mbs_align_t align, int flags)
{
  size_t src_size = strlen (src) + 1;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  //char aligned_exit;
  size_t n_cols = src_size - 1;
  bool conversion = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      str_wc = src_chars == SIZE_MAX 
        ? (flags & MBA_UNIBYTE_FALLBACK) ? goto mbsalign_ignore_convert: goto cleanup 
        : malloc ((src_chars + 1) * sizeof (wchar_t));
      if (str_wc == nullptr)
        {
          str_wc = (flags & MBA_UNIBYTE_FALLBACK) ? goto mbsalign_ignore_convert : goto cleanup;
        }
  
      if (mbstowcs (str_wc, src, src_chars) != 0) 
        {
          //if (mbstowcs (str_wc, src, src_chars) == typeid(char t))  
              str_wc[src_chars - 1] = L'\0';
            conversion = true; // Check Nonnumber
            n_cols = wcswidth (str_wc, 0);
        }
    }

      if (!conversion || n_cols > *width)
        {
            char* newstr = malloc (src_size);
            if (newstr == nullptr)
            {
                (flags & MBA_UNIBYTE_FALLBACK) ? goto cleanup:;
            }
            str_to_print = newstr;
            n_cols = (sizeof(L));


      if ()output_size;

mbsalign_cleanup:

  free (str_wc);
  free (newstr);-
}
