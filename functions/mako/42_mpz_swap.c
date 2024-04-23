mpz_swap(mpz_ptr x, mpz_ptr y) {
  mp_limb_t *limbs = x->limbs;
  mp_size_t alloc = x->alloc;
  mp_size_t size = x->size;

  x->limbs = y->limbs;
  x->alloc = y->alloc;
  x->size = y->size;

  y->limbs = limbs;
  y->alloc = alloc;
  y->size = size;
}