log_done(
    char *op,
    char *target,
    const char *errmsg,
    gss_buffer_t client,
    gss_buffer_t server,
    struct svc_req *rqstp)
{
    size_t tlen, clen, slen;
    char *tdots, *cdots, *sdots;

    if (errmsg == NULL)
        errmsg = _("success");
    tlen = strlen(target);
    trunc_name(&tlen, &tdots);
    clen = client->length;
    trunc_name(&clen, &cdots);
    slen = server->length;
    trunc_name(&slen, &sdots);

    /* okay to cast lengths to int because trunc_name limits max value */
    return krb5_klog_syslog(LOG_NOTICE,
                            _("Request: %s, %.*s%s, %s, "
                              "client=%.*s%s, service=%.*s%s, addr=%s"),
                            op, (int)tlen, target, tdots, errmsg,
                            (int)clen, (char *)client->value, cdots,
                            (int)slen, (char *)server->value, sdots,
                            client_addr(rqstp->rq_xprt));
}