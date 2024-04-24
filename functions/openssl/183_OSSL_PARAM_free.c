void OSSL_PARAM_free(OSSL_PARAM *params)
{
    if (params != NULL) {
        OSSL_PARAM *p;

        for (p = params; p->key != NULL; p++)
            ;
        if (p->data_type == OSSL_PARAM_ALLOCATED_END)
            OPENSSL_secure_clear_free(p->data, p->data_size);
        OPENSSL_free(params);
    }
}