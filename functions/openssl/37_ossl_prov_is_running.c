int ossl_prov_is_running(void)
{
    int res;
    static unsigned int rate_limit = 0;

    if (!CRYPTO_THREAD_read_lock(fips_state_lock))
        return 0;
    res = FIPS_state == FIPS_STATE_RUNNING
                        || FIPS_state == FIPS_STATE_SELFTEST;
    if (FIPS_state == FIPS_STATE_ERROR) {
        CRYPTO_THREAD_unlock(fips_state_lock);
        if (!CRYPTO_THREAD_write_lock(fips_state_lock))
            return 0;
        if (rate_limit++ < FIPS_ERROR_REPORTING_RATE_LIMIT)
            ERR_raise(ERR_LIB_PROV, PROV_R_FIPS_MODULE_IN_ERROR_STATE);
    }
    CRYPTO_THREAD_unlock(fips_state_lock);
    return res;
}