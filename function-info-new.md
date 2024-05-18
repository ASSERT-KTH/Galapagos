# Use case functions picking

### Second attempt (slices of 200 functions)

#### libsodium

b64_byte_to_char
b64_char_to_byte
b64_byte_to_urlsafe_char
b64_urlsafe_char_to_byte
fBlaMka

#### ffmpeg

int_sin (preprocess)
mix (4xm.c)
adjust
vp5_adjust
divide3
round_two
round_two_signed
av_compare_mod
weight (preprocess)
ff_acelp_decode_4bit_to_2nd_delay3
ff_acelp_decode_8bit_to_1st_delay3
ff_acelp_decode_9bit_to_1st_delay6
flac_get_max_frame_size
getsigctxno (preprocess)
ivi_scale_mv
mlp_samplerate
render_point
v210_stride


get_bucket (preprocess)
ff_wma_total_gain_to_bits
ff_speedhq_mb_rows_in_slice
hashNext (preprocess)
shift (sonic.c)
shift_down (sonic.c)


- `67_mid_pred`: seems to respect everything
- `70_av_expr_eval`: call to eval_expr

#### mako

bech32_polymod (preprocess)
btc_value_decompress

asm_uint_size
btc_uint_size
ldb_size_int
clamp8 (preprocess)
clamp16 (preprocess)
clamp_fee (preprocess)
compare_ascending (preprocess)
hash32
size64

- `60_btc_match_bool`: call to `btc_match`
- `69_ldb_open`: call to `ldb_try_open` in 1line do while loop
- `77_json_null_new`: call to calloc
- `99_btc_tx_has_witness`: for loop with 1 if
- `112_json_boolean_get`: changes z arg
- `138_json_boolean_get`: call to `json_object_find`
- `140_ldb_fixed64_decode`: ...seems ok?
- `149_btc_match_uint`: call to `btc_match_int`
- `151_btc_script_is_program`: has macros but not "calling" ones, seem to be regular macros (e.g. defining values)

#### openssl
_booth_recode_w5
_booth_recode_w7

icbrt64 (inline const)

ROL64 (preprocess)
scalar_get_bit

is_power_of_two
gcd

BitInterleave (preprocess, maybe)
BitDeinterleave (preprocess, maybe)

- `62_CRYPTO_memcmp`: for loop with 1 line
- `65_make_data`: seems to respect everything
- `75_BN_cmp`: seems to respect everything
- `85_f`: seems to respect everything
  - same for `86_f`
- `121_BN_value_one`: seems to respect everything
- `155_scalar_get_bit`: seems to respect everything
- `177_BIO_push`: while loop with 1 line

#### alsa-lib

alaw_to_s16
muldiv (preprocess)
muldiv_down (preprocess)
val_seg
ulaw_to_s16


- `140_pcm_frame_diff`: is all good, not very interesting
- `184_snd_pcm_mmap_appl_backward: changes a ptr arg's parameter, otherwise good

#### pipewire

nada!

#### gnupg
ascii_isupper
ascii_islower
ascii_toupper
ascii_tolower
cdb_unpack

- `16_keyid_from_pk1`: has a `compute_fingerprint` call, alters ptr arg `keyid`
- `48_snext`: has one small loop, changes ptr arg `buf`
- `62_get_parameter`: has one small-ish loop
- `74_mem2str`: has one small loop, call to `xmalloc`
- `119_add_tlv`: has one call to `log_assert`
- `121_cdb_unpack: all good
- `144_dns_strlcpy`: 2 small-ish loops
- `149_add_kbnode`: small loop
- `150_dlsym`: call to `GetProcAddress`
- `173_hexstr`: call to `sprintf`
- `174_hextobyte`: alters `s` ptr arg

#### NetworkManager

TODO: doesn't seem like any of use, though

#### libssh2

- `1__libssh2_ntohu32`: seems to respect everything
- `13__libssh2_ntohu64`: seems to respect everything
- `14__libssh2_bn_from_bin`: has a call to `BN_bin2bn`, else good
- `39__libssh2_wincng_bn_size`: has a small loop and something which I'm not sure if it's a macro (it's a type?)
- `42__libssh2_comp_methods`: all good, not very interesting
- `95_knownhost_to_external`: has 2 macros, else is good
- `96_libssh2_channel_get_exit_status`: all good, not very interesting
- `102_sftp_attrsize`: has macros, else is good
- `115__libssh2_store_u64`: alters a ptr arg, else is good
- `170__libssh2_wincng_bignum_bits`: has a small loop, else is good

#### krb5

cshift (preprocess)
cshift64
first_free
rotl64

- `9_make_data`: has a macro (constant), else is good
- `78_krb5int_find_pa_data`: has a small loop
- `102_krb5int_c_locate_iov`: has a loop (not necessarily small, but very simple)

#### sqlite

sqlite3AbsInt32
sessionHashAppendI64 (preprocess)
swab32
jsonHexToInt (preprocess)
sqlite3HexToInt (preprocess)

- `21_sqlite3StrICmp`: loop that might be too long, accesses global vars?
- `26_sqlite3_strnicmp`: same but slightly smaller loop

#### curl

- `22_Curl_timediff`: has constant macros
- `41_Curl_share_unlock`: has constant macros
- `76_Curl_timestrcmp`: has a loop; worth to try imo
- `116_Curl_is_ASCII_name`: same as above + has bool macros

#### glusterfs

- `8_uuid_copy`: good
- `13_uuid_is_null`: small loop, else good
- `55_iov_length`: good
- `104_strtail`: small loop
- `141_pstrcpy`: must see if the loop is ok

#### liboqs
(type fpr == uint64)
fpr_lt
fpr_irsh
fpr_ulsh
fpr_ursh
fpr_half
fpr_double

modp_montymul
int16_nonzero_mask
modp_set
modp_norm
modp_ninv31
modp_add
modp_sub

montgomery_reduce (preprocess) (src/sig/dilithium/pqcrystals-dilithium_dilithium5_ref/reduce.c)
reduce32 (preprocess) (src/sig/dilithium/pqcrystals-dilithium_dilithium5_ref/reduce.c)


has 4 but I'm not sure if the source code itself is very suitable for this

#### lz4

XXH32_avalanche (preprocess)
XXH_swap32
XXH_swap64
XXH32_round (preprocess)
XXH64_round (preprocess)

- `29_FUZZ_dataProducer_retrieve32`: good
- `30_FUZZ_getRange_from_uint32`: good
- `41_LZ4IO_readLE32`: good
- `66_LZ4IO_writeLE32`: good
- `86_XXH_swap32`: ...maybe? not sure because of the "custom" U32 type
- `87_XXH_swap64`: same as above

#### libgcrypt

montgomery_reduce (preprocess)
barrett_reduce (preprocess)
int16_t_nonzero_mask
int16_t_negative_mask
ctz
same_mask
fBlaMka (preprocess)
mask_leq
Ch
Maj
ROTR

- `4_buf_put_be32`: good
- `5_buf_put_le32`: good
- `11_buf_get_le64`: good
- `27_gost_val`: good
- `37_interleave`: good
- `38_vec_mul`: constant macros, otherwise good
- `63_buf_get_be64`: good

## coreutils

- `memset`: is small, has a small while loop, does not alter outside variables, does not have external calls
- `wcscmp`: is medium-size (15 lines), has a big for (;;) loop, alters outside variables (s1, s2 args), has macro
- `memcmp`: is small, has a small while loop, does not alter outside variables, does not have external calls
- `wcslen`: is small, has an empty while loop (everything happens in the loop def.), does not alter outside variables, does not have external calls
- `mbsinit`: is small-ish (14 lines), does not have loops, does not alter outside variables, has macro
- `proper_name`: is long-ish (23 lines), does not have loops, does not alter outside variables, has (many) external calls
- `u16_strcmp`: is long (27 lines), has a big for (;;) loop, alters outside variables (s1, s2 args), does not have external calls
- `u32_strcmp`: is small-ish (13 lines), has a big for (;;) loop, alters outside variables (s1, s2 args), does not have external calls
- `xalloc_die`: is small, does not have loops, does not alter outside variables, has external calls (error, abort)
- `bitmap_lookup`: is long-ish (21 lines), does not have loops, does not alter outside variables, does not have external calls
- `atexit`: is small, does not have loops, does not alter outside variables, has an external call (on_exit)
- `c32_apply_type_test`: is small, does not have loops, does not alter outside variables, has external calls + macro
- `c32tob`: is too long (34 lines), does not have loops, does not alter outside variables, has external calls + macros
- `wcsncmp`: is medium-size (19 lines), has a big for (;n;), alters outside variables (s1, s2 args), has a macro
- `uc_is_general_category`: is small, does not have loops, does not alter outside variables, has an external call (bitmap_lookup)
- `sigaddset`: is medium-size (18 lines), does not have loops, alters an outside variable (set arg), has macro
- `pthread_mutex_unlock`: is small-ish (12 lines), does not have loops (has switch, is it relevant?), does not alter outside variables, has external calls
- `parse_datetime`: is small-ish (11 lines), does not have loops, does not alter outside variables, has external calls
- `setenv`: is small, does not have loops, does not alter outside variables, has external calls
- `uc_joining_group_name`: is small, does not have loops, does not alter outside variables, not sure (??)
- `creat`: is too long (33 lines), does not have loops, does not alter outside variables, has macro and external calls
- `wctob`: is small-ish (12 lines), does not have loops, does not alter outside variables, has external calls
- `u32_cmp`: is medium-size (17 lines), has a big for (;n;), alters outside variables (s1, s2 args), does not have external calls
- `canonicalize_filename_mode`: is small-ish (12 lines), does not have loops, does not alter outside variables, has external calls
- `callback`: is long (30 lines), does not have loops, alters outside variables (locals arg),has macro
- `linkat`: is small, does not have loops, does not alter outside variables, has an external call (at_func2)
- `is_open`: is medium-size (15 lines), does not have loops, does not alter outside variables, has external calls and macros
- `memmove`: is medium-size (16 lines), has a small for, does not alter outside variables, does not have external calls
- `freea`: is medium-size (15 lines), does not have loops, does not alter outside variables, has external calls (free, abort)
- `ftell`: is small-ish (12 lines), does not have loops, does not alter outside variables, has an external call (ftello) and macro (??)
- `addtok`: is too long (31 lines), does not have loops, alters outside variables (dfa arg), has external calls
- `pthread_mutex_lock`: is small-ish (12 lines), does not have loops (has switch, is it relevant?), does not alter outside variables, has external calls

## mako

asm_int_size
size64


- `ldb_malloc`: is small, does not have loops, does not alter outside variables, has an external call( abort() )
- `btc_read32le`: is small-ish (12 lines), does not have loops, does not alter outside variables, has an external call (it's built in, memcpy)
- `btc_memzero`: is medium-size (21 lines), does not have loops, alters outside variables (ptr arg), has external callS, has asm code (may be relevant for alive)
- `btc_free`: is small, does not have loops, alters outside variables (ptr arg), has an external call ( abort() )
- `btc_uint32_write`: is small-ish (12 lines), does not have loops, alters outside variables (zp arg), has an external call (it's built in, memcpy)
- `json_integer_new`: is small-ish (14 lines), does not have loops, does not alter outside variables, has an external call (it's built in, calloc)
- `btc_malloc`: is small, does not have loops, does not alter outside variables, has external callS (malloc, abort)
- `btc_write32be`: is small, does not have loops, alters outside variables, has an external call (memcpy)
- `btc_uint32_read`: is medium-size (18 lines), does not have loops, alters outside variables (zp arg, xp arg), has an external call (memcpy)
- `ldb_buffer_clear`: is small, does not have loops, alters outside variables (z arg), has an external call (ldb_free)
- `ldb_slice`: is small, does not have loops, does not alter outside variables, does not have external calls
  - NOTE: there are at least 3 different versions of this function, they all share these characteristics
- `btc_vector_clear`: is small, does not have loops, alters outside variables (z arg), has an external call (btc_free)
- `ldb_batch_put`: is small, does not have loops, MAY alter outside variables via calls, has external callS
- `btc_chain_throw`: is medium-size (21 lines), does not have loops, alters outside variables (chain arg) and may others, has external calls
- `btc_stack_get`: is small, does not have loops, does not alter outside variables, has an external call (to a macro(!), CHECK)
- `ldb_log`: is small, does not have loops, does not alter outside variables, has external calls
- `sc_import`: is small-ish (11 lines), does not have loops, does not alter outside variables, has external calls
- `state_need`: is medium-size (17 lines), does not have loops, does not alter outside variables, has an external call (state_grow)
- `mpz_grow`: is small, does not have loops, I _think_ it alters an outside variable (z arg), has an external call
- `json_hash_new`: is small, does not have loops, does not alter outside variables, has external calls
- `json_object_new`: is long-ish (25 lines), does not have loops, does not alter outside variables, has external calls (calloc, free)
- `sc_montsqrn`: is small, HAS a loop (small - 1 line), does not alter outside variables, has external calls
- `btc_peer_sendmsg`: is small, does not have loops, does not alter outside variables, has external calls
- `btc_time_msec`: is small-ish (15 lines), does not have loops, does not alter outside variables, has external calls
- `btc_uint32_update`: is small, does not have loops, does not alter outside variables, has external calls
- `ldb_iter_destroy`: is small, does not have loops, MAY alter outside variables, has external calls
- `btc_log`: is small-ish (15 lines), does not have loops, does not alter outside variables, has external calls
- `ldb_iter_status`: is small, does not have loops, does not alter outside variables, has external calls
- `ldb_strerror`, is small, does not have loops, does not alter outside variables, has external calls, does not seem relevant
- `btc_rdtsc`: is too long(?) (31 lines), does not have loops, does not seem to alter outside variables (?? weird to check with asm), does not have external calls, has asm code
- `btc_mempool_throw`: is small-ish (13 lines), does not have loops. does not alter outside variables, has external calls
- `json_string_get`: is small, does not have loops, alters outside variables (z arg), has external call (strlen)
- `mpz_sub_ui`: is long (23 lines), does not have loops, alters outside variables(??)(z arg), has external calls;; also seems cool to test
- `btc_socket_close`: is long (25 lines), has a loop (5 loc), alters outside variables (socket arg), has external calls
- `json_amount_new`: is small-ish (14 lines), does not have loops, does not alter outside variables, has an external call (free)
- `btc_uint8_read`: is small, does not have loops, alters outside variables (zp, xp, xn args), does not have external calls
- `json_array_push`: is long (29 lines), does not have loops, alters outside variables (array, value args), has external calls
- `ldb_vector_clear`: is small, does not have loops, alters an outside variable (z arg), has an external call
- `mpz_add_ui`: is medium-size (19 lines), does not have loops, alters an outside variable (z arg), has external calls
- `mpz_set`: is small, does not have loops, alters an outside variable (z arg), has external calls
- `mpz_sub`: is long (27 lines), does not have loops, alters an outside variable (z arg), has external calls;; seems interesting to test
- `mpz_swap`: is small-ish (13 lines), does not have loops, alters outside variables (x, y args), does not have external calls
- `btc_now`: is small, does not have loops, does not alter outside variables, has external calls (time and a macro)
- `btc_sha256_update`: is long (28 lines), does not have loops, alters an outside variable (ctx arg), has external calls
- `json_boolean_new`: is small-ish (14 lines), does not have loops, does not alter outside variables, has an external call (calloc)

## openssl

- `fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32`: is small-ish (13 lines), does not have loops, alters outside variables (out1, out2 args), does not have external calls
- `OPENSSL_free`: is long-ish (21 lines), does not have loops, does not alter outside variables, has external calls
- `BN_free`: is small, does not have loops, does not alter outside variables, has external calls
  - has at least one other version with the same characteristics
- `exit`: is small-ish (11 lines), does not have loops, does not alter variables, has external calls
  - has at least one other version with the same characteristics
- `com_err`: is small, does not have loops, does not alter variables, has external calls
- `fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32`: is small-ish (13 lines), does not have loops, alters outside variables (out1, out2 args), does not have external calls
- `EVP_PKEY_free`: is long-ish (22 lines), does not have loops, does not alter outside variables, has external calls
- `BIO_free`: is TOO long (32 lines), does not have loops, alters outside variables, has external calls
- `OPENSSL_malloc`: is long-ish (21 lines), does not have loops, does not alter outside variables, has external calls
- `BN_CTX_get`: is long (24 lines), does not have loops, alters an outside variable (ctx arg), has external calls (MAY be macros)
  - has variations with either the same or worse problems (longer)
- `fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32`: is small-ish (13 lines), does not have loops, alters outside variables (out1, out2 args), does not have external calls
- `check`: is small, does not have loops, does not alter outside variables, has external calls;; does not seem very relevant (i.e., no core "mechanisms")
  - many variations, all seem to share these issues
- `EVP_PKEY_free`: is small-ish (12 lines), does not have loops, does not alter outside variables, has external calls
  - has a variation, same issues but longer
- `BIO_free`: is medium-size (18 lines), has a loop -- small, just an if, does not alter outside variables, has external calls
  - variation, longer than 30 lines, does not have a loop, other problems are the same
- `fiat_p256_addcarryx_u32`: is small, does not have loops, alters outside variables (out1, out2 args), does not have external calls
- `BN_new`: is small-ish (13 lines), does not have loops, does not alter outside variables, has external calls (macros?)
  - variation, same issue
- `fiat_id_GostR3410_2001_CryptoPro_B_ParamSet_addcarryx_u32`: is small-ish (13 lines), does not have loops, alters outside variables (out1, out2 args), has macro calls
- `fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u64`: same as above
- `fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_mulx_u32`: same as above
- `BIO_puts`: too long (48 lines), does not have loops, alters outside variables (b arg), has external calls
- `OPENSSL_cleanse`: has asm so no
- `krb5_free_principal`: is medium-size (16 lines), has a while loop, alters outside variables (data arg), has a free call
- `BIO_write`: is medium-size (18 lines), does not have loops, alters outside variables (bio arg), has external calls (macro, bwrite)
  - variation, similar yet does not alter outside variables, has no macro
- `OSSL_PARAM_locate`: is small, has a loop (may be small enough? idk), does not alter outside variables, has external call (strcmp)
