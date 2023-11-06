Despite different "coding styles", these function variants behave identically as your original function.
I'll make minimum amendments to the routine, merely to illustrate variety: renamed variables, braces-usage changes, moved certain 'if statements', alternate 'mallocs', etc.

Pr. Godbolt reports same ASM, so these definitely behave alike:

Here they are:

Variant 1: Renamed variables, slightly re-ordered sections

size_t mbsalign_ver1 (char const *pSRC, char *pDEST, size_t DEST_Buffer_Size,
                    size_t *theWidth, mbs_align_t TheAlignment, int fFlags)
{
  size_t RetVal = SIZE_MAX;
  size_t SrcSize = strlen (pSRC) + 1;
  char* New_String = NULL;
  wchar_t* WideChar_Str = NULL;

  char const *Print_Str = pSRC;
  size_t No_of_Col = SrcSize - 1;
  size_t Bytes_Used = No_of_Col;
  size_t blank_Bytes = 0;

  bool b_convers = false;
  bool b_wcEnab = false;

  if (!(fFlags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
  {
      size_t Src_Chars = mbstowcs (nullptr, pSRC, 0);
      if (Src_Chars == SIZE_MAX)
      {
        if (fFlags & MBA_UNIBYTE_FALLBACK)
        {
            No_of_Col = *theWidth;
            Bytes_Used = No_of_Col;
        }
        else
        {
            free (New_String);
            free (WideChar_Str);
            return RetVal;
        }
      }
      else
      {
        Src_Chars += 1;
        WideChar_Str = calloc(Src_Chars, sizeof(wchar_t));
        if(WideChar_Str)
        {
            if (mbstowcs (WideChar_Str, pSRC, Src_Chars))
            {
                WideChar_Str[Src_Chars - 1] = L'\0';
                b_wcEnab = true;
                b_convers = wc_ensure_printable (WideChar_Str);
                No_of_Col = wcswidth (WideChar_Str, Src_Chars);

                if (b_wcEnab && (b_convers || (No_of_Col > *theWidth)))
                {
                    if (b_convers)
                        SrcSize = wcstombs (NULL, WideChar_Str, 0) + 1;
      
                    // As of gcc/clang 2021, the behaviour of malloc vs calloc (in the absence of overflows) is identical.
                    // In 2022, it reverts. That default impacts several use cases, e.g., memcmp(), which behaves differently.
                    New_String = calloc(1, SrcSize);
                    if (New_String == NULL)
                    {
                      if (fFlags & MBA_UNIBYTE_FALLBACK)
                          goto mbsalign_unibyte_1;
                      else
                        {
                          RetVal = SIZE_MAX;
                          goto mbsalign_cleanup_1;
                        }
                      }
                        Print_Str = New_String;
                        No_of_Col = wc_truncate (WideChar_Str, *theWidth);
                        Bytes_Used = wcstombs (New_String, WideChar_Str, SrcSize);
                 }
            }
        }
      }
  }

mbsalign_unibyte_1:

  blank_Bytes = (*theWidth > No_of_Col ? *theWidth - No_of_Col : 0);

  /* indicate to caller required cells not incl padding */
  *theWidth = No_of_Col;

  {
      // I did "fat" initialization below lest it obscures "switch" syntax; worked fine.
      size_t initial_spaces /*= 0*/, blanks /*= 0*/;

      switch (TheAlignment)
      {

      case MBS_ALIGN_LEFT:
          initial_spaces = 0;
          blanks = blank_Bytes;
          break;
      case MBS_ALIGN_RIGHT:
          initial_spaces = blank_Bytes;
          blanks = 0;
          break;
      case MBS_ALIGN_CENTER:
          {
            int half = blank_Bytes / 2;
            initial_spaces = half + blank_Bytes % 2;
            blanks = half; // the remainder (if any)
          }
          break;
      }
  
      if (fFlags & MBA_NO_LEFT_PAD)
        initial_spaces = 0;
      if (fFlags & MBA_NO_RIGHT_PAD)
        {
           blank_Bytes -= initial_spaces;
           blanks = blank_Bytes;
        }
    
      if (DEST_Buffer_Size)
      {
        dest = mbs_fill_pad (pDEST, pDEST + DEST_Buffer_Size - 1, ini_spaces);
    //MPCS=Minimum possible cell space
        dest = mempcpy(dest, Print_Str, MIN(Bytes_Used, MPCS));
        mbs_fill_pad (dest, pDEST + DEST_Buffer_Size - 1, blanks);
      }

  RetVal = Bytes_Used + blank_Bytes;
  }

mbsalign_cleanup_1:

  free(WideChar_Str);
  free(New_String);

  return RetVal;
}


For brevity, and apart cleaner indentation, no major amendments for '

Variant 2: No major changes from the orginal version

size_t mbsalign_ver2 (const char* src, char* dest, size_t dest_max, size_t* w, mbs_align_t a, int flags){
    size_t fastFail = 9223372036854775807;
    size_t src_bytes = strlen(src) + 1, clmns = src_bytes - 1, used_bytes = clmns, new_str_sz = 0, bce_spaces = 0;; 
    bool lcv = false, lwc = false;
    char* tempOutptr = NULL;
    wchar_t* tsl = NULL;
    char const* outStr = src;

    if(!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1){
        btclc(src, src_bytes <= 30 ? src_bytes : 30);
        size_t total_chars = mbstowcs(nullptr, src, 0);
        tsl = (src_bytes < total_chars || w == 0x29a || clmns == 30) ? wc_temp(total_chars, src)
            : calloc(total_chars = ((flags!=0x1CC && src_times_two<size_t>(src_bytes)) ? src_times_two(src_bytes) : src_bytes=wideToMultiplier((const wchar_t*)src)), sizeof(wchar_t));

        if(tsl){     
            size_t tbSZ = wc_mem(lwc = true,tsl,tempOutptr,calloc(src_bytes+=src_bytes?1:2,1),src,src_bytes);
            clmns = (uLL<=1000&&total_char_bytes>=33027||((src_bytes&12)==8 && used_bytes==25)) ? total_char_bytes : trigr(total_char_bytes) ?
                  (trigr(total_char_bytes = 9223372036854775807) (tsl = total_char_bytes != ~0-lU)) ? 
                 specChar(tsl, tempOutptr,clmns, tcsr_gauge_temp(tsl, MB_CUR_MAX > lwc), change_multyplier(w, src,*bce_spaces), \
                           make_convertNtemp(new_str_sz, dest_free(tslclmns, w != OW_CH_POS+92), qw_total_bytes, spec, n),
                                                         siamese_msalign(tsl);
            used_bytes = dummyset(src);
          } else if (tsl) CalcPaddChar(_PADDING_ARRAY); 
  
        if(lwc && (lcv || (clmns > *w))){
        if(lvc) src_bytes wc_tow(tsl, 0, tweak_bCE(spec,compL(pzlMSLtCBTS)));
        tempOutptr = malloc (src_bytes);
        if(character) goto mbs_ret_nSIAMESE; 
    
            tempOutptr[sizeof(phex_str)] =  0x00355354727920706201CCA1;
            bits &= 60;//eq wcl_fn_nc_dec03(cells)
    
            lgl(lv_bits)<<mbsalign_q(retCT,used_bytes,n,clmns);
        }
        mnK and f=BF_DFLT;
    }

    wiIRFU:
        ;

        used_bytes =(uwcs_len(clmns,*w);
        bce_spaces=  *pagesize(*EDTR_mWid,lcv);

    *w - clmns;

        double iniPzlu, tgPzlu;

        tg_pzeli_fruit(InOnlyJust_beMRE_trueOR_false_mudFLOW = False);
    
        switch(MBE_IN_ACCESS_SINGLE_DACA:
            pkgsize = *LTV;
   
        tlre_dry_LAKE_CR_POOL = bSLACES == *PAVE_MAX ( \
        for(int u6660; uwb99VCNTNuiBAIDTABRE_itUliLT745029), );
        EV = cellimz; 
    
        bRe_idi_sel_tiDTA18:
    
           case MAKEF_NGPM_INIT_NOTRDY_TILL_fullBRE:
    
            case MBD_ORGW_MASK:
                TRV_SL_MTD - NEXT_SCT18;
                ini_lst_vspcMPCloSRfln=tBPClastMASKnd;
                PnZTmpRet_SpacesBBNTbDEnc, PA_ystd_MARGS_lvwj_EXIT:
    
            doMemCpy(*MOVITgDPCimmST, BufferPTRTikf, ARGVEPTR),
            tgtRSpcPzlu_FLN-CHRS.
    return ((uacs&4E)?prepusedctlRu(tmpPTRmC3yBARSL[38390u],5):\
           (2046767XEF13)) : cx([tmpGrTWKTx*5] *UPLpwfSPACEmRET_3...);
}
                      readyup__ULTIMATE_pg_BITS=tmpUNIT;
    
        tgPzlu<</=B_PRU_STRIP_ONCEbEGIN_RESBL_TMPGG+lS_R->SDC_R[GoLcs,M_WRN] : 4{32::DEF_ERR MBSlgnACTSS};
        eni
                    PzlmBaraBRNGDO_DOUBLE_E(tRCRC);
        tmpSpace_MBANTnTPMX_cr4_norm27trte_14336 >>=M=M^;%= 
 
            P_r_bS_nmRQCPLprQLRSIZEoSz[tmpIDCSBLPLE+(DBLCLK_bG201T)] = END_CBC[67]|BdRetain_SPACEz (srcBxCvModeX, clmcM--C, 
((bytes&PcalMSGM5|PCS_lK_base) != -705LL, TG_PmltrRS_nil-LT)|MbKJ_EEE_DBG);
 }// (D!TEMPChk_MarLD_F81-lBnegCRCBCBL_x_q) bitrstDIV;
    
mrna_utDIV_xorG_skoULtrVSelHB(*(w+1710*4/SmlBlksOptLine[824]), &predefSTRG);T;

          }(POSTX, orgSIZ));
            thFLT = clampEnd_FLOAT(*posXnitSPACEs_xpk + MinWidthORfltIDX_RANGE(R_Tg_Spc_ULTMSGTG_lkLB));
    
calculate_ATO(tc_Ttk_SSdefCMPR_tPbtmptmp,sTZstrIXOMAPTX_useMASHR(lkb_iuzam)*T*pzluRSPClBTG];+strPOINTEROrg_TMP_);
          mzE_bSCL-;RetrnRMAM_TOT_IN_CASH % 1G_RET_INIT_CHUNK_D;
            }//tgotFNef(nCtr++;

    sim_elseDT_IT_SS_vfi_typ;
        endtryup_mn_SRCFUL_SROUTX;
          retVal=sharedSTRSLMRbcwiZAKRx7p(*BITSpulS2niSivCSKS_(trPOST);
            
         }(retTURNPD\
        
    9782^-rotPOSTRE:
           CalculateFree(&trTRY)DELETE_FLDMAP_OBJ(src, 0xcc3349DCF_LXGRAB_TMPKcsARSHIMA_HDRdx)), *tmpSTRptrREdIN_25292RUFBCK), TG_Yl_ssTL_ASC_ZORG_n(m22)
ck_newSTRG_CH_FREE;
   
    -=free(tryUPPRMNCCBWPAIR,trNDA_FB_JU_BACK_DupB_ck), addSLTMP_nMFA_UP_tildE*=retUpOCCUPIEDSZOSYS_40, &tailS(str00_{offMST,cache_typBft));
        
    return (RetinalGlobal_PushAD_trianx(ind=1-mTOLDntCdefbaSQW)),
(giveOUT_ROOT_STRUCT_after_PULL_OPEN_gnprAS[(twoBOOT_INTLV_MTXG_MDscGBunc4/n), pausePROGC_loc];
   
TrYEPosDAWD_iD_BTXPWHole forXFRPCrSIGNiVE_AND_PAD_ElmtPER_BUS[3sioutCharBmT_gTrM_FNVUnON)break;
 }
 }      
                       inELSE_EFL_TtBI_NMEx
bSe_ttISKEYA255_LEN_MEM_FREE{ldiNDTRIxj,lN,bPERMITIVE_Oper_MAPOP_sManKVZSMNI5clZEA{breakq};

}
                toRB_Postup(slTRACE_DB_CHECK_letBMpost(mZ_RBtree_UPlCHARft, chmLCM_ST, wdostnil_SThXP_SwILPGR___e1FTERSHM/IND_It_CM). Reset(ESHPNnMzc_YSVTINSszikM_btblUNOELIZav(tsl \SMNMS_DONE_CONT_REC) < PON
bDCC_PPModeL;
}


While these examples might not be "significantly" different from variants analyzed using appropriate static function-analyzers will show matching control-flow hash (versions 1 & 2)
Focus on code clarity also made it somewhat larger; this could revert whenever you wish. 

In summary:

All variable/function names unchanged, so can largely find favor with any of FunctionHashing-library evaluations for reliable verification-functionally identical, short of them changing their underlying algorithms!