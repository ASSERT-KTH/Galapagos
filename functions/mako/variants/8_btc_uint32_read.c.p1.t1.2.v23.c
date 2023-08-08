Sure, maintaining the same functionality of the function but making some alterations, the variation of the given function could look like this:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4) { // Put preferred conditions at the beginning, reduces one layer of indention and improves readability
#if defined(BTC_BIGENDIAN)
    *zp = (*xp)[0]
        | ((*xp)[1] <<  8)
        | ((*xp)[2] << 16)
        | ((*xp)[3] << 24); // Removed unnecessary casting, no need to bit shift by 0
#else
    memcpy(*zp, xp, sizeof(*zp)); // Moved the de-referencing to memcpy to normalize the pattern. The previous one was fine but could induce people to make errors
#endif

    *xp += 4;
    *xn -= 4;

    return 1; // Success
  }

  return 0; // Fail
}

The modified code above can help illustrate that keeping logic simple (Do the "normal"/"happy" paths first helps achieve that), direct (don't shift by 0 when it isn't needed) and consistent (keep all dereferences in the same spot) often lead to easier to read and therefore maintain code. Even this kind of small function can benefit from such extraction.