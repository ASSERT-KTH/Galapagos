long BIO_ctrl(BIO *b, int cmd, long larg, void *parg)
{
    long ret;

    if (b == NULL)
        return -1;
    if (b->method == NULL || b->method->ctrl == NULL) {
        ERR_raise(ERR_LIB_BIO, BIO_R_UNSUPPORTED_METHOD);
        return -2;
    }

    if (HAS_CALLBACK(b)) {
        ret = bio_call_callback(b, BIO_CB_CTRL, parg, 0, cmd, larg, 1L, NULL);
        if (ret <= 0)
            return ret;
    }

    ret = b->method->ctrl(b, cmd, larg, parg);

    if (HAS_CALLBACK(b))
        ret = bio_call_callback(b, BIO_CB_CTRL | BIO_CB_RETURN, parg, 0, cmd,
                                larg, ret, NULL);

    return ret;
}