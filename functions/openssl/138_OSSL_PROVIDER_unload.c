int OSSL_PROVIDER_unload(OSSL_PROVIDER *prov)
{
    if (!ossl_provider_deactivate(prov, 1))
        return 0;
    ossl_provider_free(prov);
    return 1;
}