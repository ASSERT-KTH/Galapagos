btc_zinv_grow(btc_zinv_t *z, size_t zn) {
  if (zn > z->alloc) {
    z->items =
      (btc_zinvitem_t *)btc_realloc(z->items, zn * sizeof(btc_zinvitem_t));
    z->alloc = zn;
  }
}