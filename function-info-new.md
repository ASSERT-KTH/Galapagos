# Use case functions picking

#### libsodium

b64_byte_to_char (preprocess) 4
b64_char_to_byte (preprocess) 4
b64_byte_to_urlsafe_char (preprocess) 4
b64_urlsafe_char_to_byte (preprocess) 4
fBlaMka (blamka-round-ref.h) 4

#### ffmpeg

int_sin (preprocess) 5
weight (preprocess) 5
mix (4xm.c) 4
vp5_adjust 4
flac_get_max_frame_size 4

(backups)
av_compare_mod 3 
v210_stride 3 


#### openssl
_booth_recode_w5 4
_booth_recode_w7 4
icbrt64 (inline const) 4
BitInterleave (preprocess) 4
BitDeinterleave (preprocess) 4

(backups)
ROL64 (preprocess) 4 

#### alsa-lib

alaw_to_s16 5
muldiv (preprocess) 5
muldiv_down (preprocess) 4
val_seg 4
ulaw_to_s16 4

#### liboqs

Requires this cmake command, otherwise it will complain. cmake version 3.25
`cmake -GNinja -DCMAKE_C_COMPILER="clang" -DCMAKE_C_FLAGS="--save-temps=obj"  -DOQS_USE_OPENSSL=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=/usr -DOPENSSL_ROOT_DIR=/usr/lib/x86_64-linux-gnu ..`

(type fpr == uint64)
fpr_lt (pqclean_falcon-1024_clean/fpr.h) 5
fpr_half (pqclean_falcon-1024_clean/fpr.h) 5
modp_montymul 4
int16_nonzero_mask 4
modp_norm 4

(backups)
fpr_irsh 3
fpr_ulsh 3
fpr_ursh 3
fpr_double 3
modp_set 3
modp_ninv31 3
modp_add 3
modp_sub 3
montgomery_reduce (preprocess) (src/sig/dilithium/pqcrystals-dilithium_dilithium5_ref/reduce.c) 3
reduce32 (preprocess) (src/sig/dilithium/pqcrystals-dilithium_dilithium5_ref/reduce.c) 3

#### libgcrypt

barrett_reduce (preprocess) 4
ctz 4
montgomery_reduce (preprocess) 3
int16_t_nonzero_mask 3
int16_t_negative_mask 3

(backups)
same_mask 3
fBlaMka (preprocess) 3 
mask_leq 3

