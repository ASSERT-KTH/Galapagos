bech32_polymod(uint32_t c) {
  uint32_t b = c >> 25;

  return ((c & UINT32_C(0x1ffffff)) << 5)
    ^ (UINT32_C(0x3b6a57b2) & -((b >> 0) & 1))
    ^ (UINT32_C(0x26508e6d) & -((b >> 1) & 1))
    ^ (UINT32_C(0x1ea119fa) & -((b >> 2) & 1))
    ^ (UINT32_C(0x3d4233dd) & -((b >> 3) & 1))
    ^ (UINT32_C(0x2a1462b3) & -((b >> 4) & 1));
}