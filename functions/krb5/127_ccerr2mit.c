ccerr2mit(uint32_t err)
{
    switch (err) {
    case ccNoError:
        return 0;
    case ccIteratorEnd:
        return KRB5_CC_END;
    case ccErrNoMem:
        return ENOMEM;
    case ccErrCCacheNotFound:
        return KRB5_FCC_NOFILE;
    default:
        return KRB5_FCC_INTERNAL;
    }
}