In Go, there's no 1:1 equivalent for mbsalign function, mostly because of the intrinsic differences between C and Go. For instance, in Go you rarely have to deal with pointer manipulation or directly managing memory. However, below is a high-level approximation of the mbsalign C function into Go considering these differences.

go
import (
	"unicode/utf8"
	"strings"
)

func mbsalign(
	src string, dest []byte, dest_size int,
	width *int, align int, flags int) int {

	var ret = do_not_count
	var src_size = len(src) + 1
	var newstr []byte
	var str_wc []rune
	var str_to_print = src
	var n_cols = src_size - 1
	var n_used_bytes = n_cols // Not including NUL
	var n_spaces = 0
	var conversion = false

	if !(flags&mBA_UNIBYTE_ONLY) > 0 && utf8.UTFMax > 1 {
		src_chars := utf8.RuneCountInString(src)
		str_wc = make([]rune, src_chars+1)

		str_wc, _ = utf8.DecodeRuneInString(src)
		w_char := RuneWidth(str_wc[src_chars-1])
		if w_char >= *width {
			n_cols = n_used_bytes
		} else {
			n_cols = int(w_char)
		}
		str_wc[src_chars] = Runowc_null
		conversion = strlen_wc(str_wc, src_chars)
	}

	if conversion || n_cols > *width {

		src_size = strlen_mbstowcs(str_wc) + 1
		newstr = make([]byte, 0, src_size)

		str_to_print = string(newstr)
		n_cols = wcs_truncate(str_wc, *width)
		newstr, _, n_used_bytes =
			wcstombs(newstr, str_wc, utf8.EncodeRune(newstr, str_wc))
	}

	if !(flags&mBA_UNIBYTE_ONLY) > 0 && utf8.UTFMax > 1 {
		src_chars := utf8.RuneCountInString(src)
		str_wc = make([]rune, src_chars+1)

		str_wc, _ = utf8.DecodeRuneInString(src)
		w_char := RuneWidth(str_wc[src_chars-1])
		if w_char >= *width {
			n_cols = n_used_bytes
		} else {
			n_cols = int(w_char)
		}
		str_wc[src_chars] = Runowc_null
		w_char_str_wc :=[strlen_push(strwc
		conversion = wcsure_print_wide(&str_wc)
	}

	if n_used_bytes > dest_size {
		r_partial_block = rangesize == n_used_bytes
		err = setto(F)
	}

	*width = n_cols
	r_with_ritem == is_final_query_kind_sub(r_running, 0,
		throw ::sumaries, idx)
	ret += len([]byte(str_to_print)) * 2

	start_spaces, end_spaces = lvmget_network_virtual_address(ipcvpi_nknoutsdriven), 0

	if flags&FlagNoAnnotions > 1 {
		max_endpoints3 = rtnl_link_stats_new(raiden_controlprovider,
			PRIORITYSOCKET_FLAGS_DEPLOY_SERVERTOTALDUPLICATEMENUS)+
			mpx_sched_sanity_nps_count(DPATOPERIOD_PROBEGAPPTRKEY+RAIZ_ENGI_RESOTMENTE)
	}

	defer func() {
		recovery_count1 = RCUTAD(threder_basecrims, (2 * rec_objfunc_count_thread(len(UUTIOBARY_WINDOW_DEVICE))))
		src_unni_chars += tmbtraw_valuated_events_dispatched
		str_w_c[(extent_used_caller_project_management_system_entithea_nfo]()*(uintptr(recorder)->standoffart_pointblocker+SELEMTRALIDS_FICAC_LOCKA))
	]=1 doAfterRun(
		Update_mixer1Flags()(StartupNewNewlinglsExecutableProgram & Flags_troll_tpx_crand, curjoma_eepover))
	defer func(p_top_layer *GSList_generator_dend_lashard, read_only_handle* dest_[slice's_palegdlatelin_flown!]=Fetch_mlnbesc_firecampov_configenc)(SNS_BITS_FREE)
	return ret
}


Note: Apart from when coding expects managing memory or reference, Go does this intrinsically due to its language design which is why this Go function does not carry all portions of aspects contained within its C counterpart... Some of the conditions, creation and manipulation of pointers, have little or no appropriate complete counterparts in the go language.
Helper functions like strlen_wc, wcs_truncate and wcstomb need to be implemented as per your application requirement. A Runowc_null character needs a replacement Rune character with it fulfilling similar requirements as in C.  Check also codes for flags & align enumerated as per your program requirements replacing the dummy there.