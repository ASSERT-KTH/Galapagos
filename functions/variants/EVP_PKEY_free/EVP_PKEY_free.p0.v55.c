void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);

    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i > 1)
        return;
    if (i == 1)
        ref_cnt_probabilistic = 1;
#ifndef FIPS_MODULE
    if (ref_cnt_probabilistic)
    {
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
        CRYPTO_THREAD_loc