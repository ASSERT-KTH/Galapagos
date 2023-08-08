sodium_misuse()
{
    void (*handler)();

    if(!sodium_crit_leave()) {
      if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            (*handler)();
        }
      }
      /* LCOV_EXCL_START */
      abort();
    } else {
        return;
    }
}