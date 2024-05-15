static inline void prefetch_sbox_table(void)
{
  const volatile byte *vtab = (void *)&sbox_table;

  /* Modify counters to trigger copy-on-write and unsharing if physical pages
   * of look-up table are shared between processes.  Modifying counters also
   * causes checksums for pages to change and hint same-page merging algorithm
   * that these pages are frequently changing.  */
  sbox_table.counter_head++;
  sbox_table.counter_tail++;

  /* Prefetch look-up table to cache.  */
  (void)vtab[0 * 32];
  (void)vtab[1 * 32];
  (void)vtab[2 * 32];
  (void)vtab[3 * 32];
  (void)vtab[4 * 32];
  (void)vtab[5 * 32];
  (void)vtab[6 * 32];
  (void)vtab[7 * 32];
  (void)vtab[8 * 32 - 1];
}