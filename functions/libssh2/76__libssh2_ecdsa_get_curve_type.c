_libssh2_ecdsa_get_curve_type(libssh2_ecdsa_ctx *ec_ctx)
{
#ifdef USE_OPENSSL_3
    int bits = 0;
    EVP_PKEY_get_int_param(ec_ctx, OSSL_PKEY_PARAM_BITS, &bits);

    if(bits == 256) {
        return LIBSSH2_EC_CURVE_NISTP256;
    }
    else if(bits == 384) {
        return LIBSSH2_EC_CURVE_NISTP384;
    }
    else if(bits == 521) {
        return LIBSSH2_EC_CURVE_NISTP521;
    }

    return LIBSSH2_EC_CURVE_NISTP256;
#else
    const EC_GROUP *group = EC_KEY_get0_group(ec_ctx);
    return EC_GROUP_get_curve_name(group);
#endif
}