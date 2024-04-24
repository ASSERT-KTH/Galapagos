int OSSL_PARAM_set_size_t(OSSL_PARAM *p, size_t val)
{
#ifndef OPENSSL_SMALL_FOOTPRINT
    switch (sizeof(size_t)) {
    case sizeof(uint32_t):
        return OSSL_PARAM_set_uint32(p, (uint32_t)val);
    case sizeof(uint64_t):
        return OSSL_PARAM_set_uint64(p, (uint64_t)val);
    }
#endif
    return general_set_uint(p, &val, sizeof(val));
}