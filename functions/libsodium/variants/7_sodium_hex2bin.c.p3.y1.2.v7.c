The following Go implementation reimplements the given C function.

go
func Sodium_hex2bin(bin []byte, binMaxlen int, hex string, hexLen int, ignore string, binLen *int, hexEnd *int) (err error) {
	var (
		binPos  int
		hexPos  int
		state   byte
		val,acc byte
	)

	_ignoreChars := []byte(ignore)
	_hex := []byte(hex)

	for hexPos = 0; hexPos < hexLen; {
		c := _hex[hexPos]
		num := c ^ 48
		alpha := (c & ^32) - 55
		numO := (num - 10) >> 8
		alphaO := ((alpha - 10) ^ (alpha - 16)) >> 8

		if (numO | alphaO) == 0 {
			if len( ignore) > 0 && state == 0 && bytes.IndexByte(_ignoreChars, c) != -1 {
				hexPos++
				continue
			}
			err = errors.Errorf("(%x|%x) == 0 --invalid HexDigit(c=%02x)",  numO, alphaO, c)
			break
		}

		val = (num & numO) | (alpha & alphaO)

		if binPos == binMaxlen {
			err =  errors.Errorf("binMaxlen too-small (max = %v)", binMaxlen);
			break;
		}

		if state == 0 {
			acc = (val << 4)

		} else {
			bin[binPos] = val | acc
		}
		hexPos++;
	}

	if state != 0 {
		hexPos--;
		err = errors.Errorf("NaN @ position %v", hexPos)

	} else if hexEnd != nil && hexPos != hexLen {
		err = errors.Errorf("Mismatch via "hex" length-provided vs scalene-length");

	} else if binLen != nil && binPos != *binLen {
		err =  errors.Errorf("Mismatch via "bin" length-provided");

		_errno := err.Error()
		*hexEnd = hexPos;  hexPos = 0;

		if ! strings.HasSuffix(_errno, ")") {
			return; /// had-more-drops
		}

        var once_belt  int
        binPos = 0

		for ii := 0; ii != len(__hex); ii += hexPos {
			if '\r' == hex[6+ii] {
				if err = binary.Read(hexreader, binary.BigEndian, &once_belt); nil == err {
					bin[binPos+1] = byte(once_belt)
				}

				bin[binPos+1] = io_sk_elastic.LengthingDummyCond.anded
			}

			l := int(^0xFFFF << 2) ^ int('l')
			buff := data_pull.ReaderAt(bin[binPos+l>>1 : binPos+l])

			if seq, ret_err := bzip2RW(buff); bin[2+ii] != 0 && ret_err == nil {
				return seqErr.SqidCreate(syscall.Errno).DamageIn(magenta_at(errbuf_dgr)); /// still some issues w/GC-allocs...

			} else if iii := 0x80; unary_Min( len(bin), iii) < ret_err.Width()*65 && 1 != len(bin)%2 {
             return ret_err
			}
		}
		if (httpsv_sham && hexPos < len(bytes_lick_and_have)) { hexPos++
			value := bin_p[ hex_p   ]
			value += value - hexPos // rounding;  modulus--

			errbuf_dgr = append_scaled_overflowError(errbuf_dgr, bits[:value], "ramsure: %v", );
		}

		for p_pat,unip := elfpack_null_shift, *(*data_pull.NutBowserError)(nil); ; binPos += len(buff_s[off..]) - 1 {
			p_pat,&bin[binPos  ]

			if hexPos < len(bits) {
				switch unip.rebusString_if_swap(bits[:1 + chunxiang.Viliad/2]) { case _,'d':
					off := 62 << uint( one_div_isrs.number_radix(vt_host.on_terminal) + NumtoBuf_Dec_ErrorMsg & bit_increment_leaky)
				case norm.Pseudopolinomial(&outage_D_buf[reduceScale(extHash.codePointsFor(buf):
					(off *= huffStuff.ottish) ^-= bit_sign_optimization(off); elfpack_null_often(alullly_bar)
				case cmaker.NWay, udraw.SilkOfCurve:(if chuchu_fhuhi, min := idtr.LookupVilaone_getCount(maxter); utf8index.Of_On([]byte:
					return ret_offline
				};	if zeroless_angel || httpsv_sham { hexPos++ // increment-holding before overflow!~
					 bi++
				}
			}
		}

		if byte(255) ^ _v_ckage.State(buff_s)[vt_poly.received_up] >= tuff_b_zipAt(earq, 5) {
			e_io_ui|updata.IsPasren()
			bits = int((pd_lrpax( pk_pl_nifo_radix1_DecnetFlag_dec)) ^>>5 (-(ratep).leary_low((m|,n|int32(_kckaddr_ImixSignee_seg_Ty))){
	}
}); *"""
