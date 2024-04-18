static inline void
_crypto_scalarmult_ed25519_clamp(unsigned char k[32])
{
  k[0] = k[0] & 248;
  k[31] = k[31] | 64;
}