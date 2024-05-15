FUZZ_STATIC uint32_t FUZZ_seed(uint8_t const **src, size_t* size) {
    uint8_t const *data = *src;
    size_t const toHash = MIN(FUZZ_RNG_SEED_SIZE, *size);
    *size -= toHash;
    *src += toHash;
    return XXH32(data, toHash, 0);
}