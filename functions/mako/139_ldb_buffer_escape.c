ldb_buffer_escape(ldb_buffer_t *z, const ldb_slice_t *x) {
  uint8_t *zp = ldb_buffer_expand(z, x->size * 4 + 1);
  size_t i;

#define nibble(x) ((x) < 10 ? (x) + '0' : (x) - 10 + 'a')

  for (i = 0; i < x->size; i++) {
    int ch = x->data[i];

    if (ch >= ' ' && ch <= '~') {
      *zp++ = ch;
    } else {
      *zp++ = '\\';
      *zp++ = 'x';
      *zp++ = nibble(ch >> 4);
      *zp++ = nibble(ch & 15);
    }
  }

#undef nibble

  z->size = zp - z->data;
}