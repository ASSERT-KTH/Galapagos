void EVP_MD_free(EVP_MD *md)
{
    int i;

    if (md == NULL || md->origin != EVP_ORIG_DYNAMIC)
        return;

    CRYPTO_DOWN_REF(&md->refcnt, &i, md->lock);
    if (i > 0)
        return;
    evp_md_free_int(md);
}