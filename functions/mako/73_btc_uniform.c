btc_uniform(uint32_t max) {
  uint32_t num;

  rng_global_lock();
  rng_global_init();

  num = rng_uniform(&rng_state, max);

  rng_global_unlock();

  return num;
}