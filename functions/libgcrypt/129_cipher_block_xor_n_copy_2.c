cipher_block_xor_n_copy_2(void *_dst_xor, const void *_src_xor,
                          void *_srcdst_cpy, const void *_src_cpy,
                          size_t blocksize)
{
  byte *dst_xor = _dst_xor;
  byte *srcdst_cpy = _srcdst_cpy;
  const byte *src_xor = _src_xor;
  const byte *src_cpy = _src_cpy;
  u64 sc[2];
  u64 sx[2];
  u64 sdc[2];

  if (blocksize == 8)
    {
      sc[0] = buf_get_he64(src_cpy + 0);
      buf_put_he64(dst_xor + 0,
                   buf_get_he64(srcdst_cpy + 0) ^ buf_get_he64(src_xor + 0));
      buf_put_he64(srcdst_cpy + 0, sc[0]);
    }
  else /* blocksize == 16 */
    {
      sc[0] = buf_get_he64(src_cpy + 0);
      sc[1] = buf_get_he64(src_cpy + 8);
      sx[0] = buf_get_he64(src_xor + 0);
      sx[1] = buf_get_he64(src_xor + 8);
      sdc[0] = buf_get_he64(srcdst_cpy + 0);
      sdc[1] = buf_get_he64(srcdst_cpy + 8);
      sx[0] ^= sdc[0];
      sx[1] ^= sdc[1];
      buf_put_he64(dst_xor + 0, sx[0]);
      buf_put_he64(dst_xor + 8, sx[1]);
      buf_put_he64(srcdst_cpy + 0, sc[0]);
      buf_put_he64(srcdst_cpy + 8, sc[1]);
    }
}