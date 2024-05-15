kcmreq_init(struct kcmreq *req, kcm_opcode opcode, krb5_ccache cache)
{
    unsigned char bytes[4];
    const char *name;

    memset(req, 0, sizeof(*req));

    bytes[0] = KCM_PROTOCOL_VERSION_MAJOR;
    bytes[1] = KCM_PROTOCOL_VERSION_MINOR;
    store_16_be(opcode, bytes + 2);

    k5_buf_init_dynamic(&req->reqbuf);
    k5_buf_add_len(&req->reqbuf, bytes, 4);
    if (cache != NULL) {
        name = ((struct kcm_cache_data *)cache->data)->residual;
        k5_buf_add_len(&req->reqbuf, name, strlen(name) + 1);
    }
}