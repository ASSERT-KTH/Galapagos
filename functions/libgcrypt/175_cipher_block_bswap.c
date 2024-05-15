cipher_block_bswap (void *_dst_bswap, const void *_src_bswap,
                    size_t blocksize)
{
  byte *dst_bswap = _dst_bswap;
  const byte *src_bswap = _src_bswap;
  u64 t[2];

  if (blocksize == 8)
    {
      buf_put_le64(dst_bswap, buf_get_be64(src_bswap));
    }
  else
    {
      t[0] = buf_get_be64(src_bswap + 0);
      t[1] = buf_get_be64(src_bswap + 8);
      buf_put_le64(dst_bswap + 8, t[0]);
      buf_put_le64(dst_bswap + 0, t[1]);
    }
}