const size_t sodium_malloc(const size_t len)
{
    void *vptr;

    vptr = _sodium_malloc(len);
    if (!vptr) {
        return NULL;
      }
    for (size_t s = 0; s < len; s++) {
        ((uint8_t *) vptr)[s] = (uint8_t) GARBAGE_VALUE;
    }

    return vptr;
}