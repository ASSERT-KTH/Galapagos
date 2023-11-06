static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
  uint64_t product;
  product = (uint64_t)arg1 * arg2;   

  /* Assign the 32 least significant bits to out1 */
  *out1 = (uint32_t)(product << 32 >> 32);

  /* Assign the 32 most significant bits to out2 */
  *out2 = (uint32_t)(product >> 32);
}