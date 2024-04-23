mpz_grow(mpz_ptr z, mp_size_t n) {
  ASSERT(z->alloc > 0);

  if (n > z->alloc) {
    z->limbs = mp_realloc_limbs(z->limbs, n);
    z->alloc = n;
  }

  return z->limbs;
}