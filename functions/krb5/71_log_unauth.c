log_unauth(
    char *op,
    char *target,
    gss_buffer_t client,
    gss_buffer_t server,
    struct svc_req *rqstp)
{
    size_t tlen, clen, slen;
    char *tdots, *cdots, *sdots;

    tlen = strlen(target);
    trunc_name(&tlen, &tdots);
    clen = client->length;
    trunc_name(&clen, &cdots);
    slen = server->length;
    trunc_name(&slen, &sdots);

    /* okay to cast lengths to int because trunc_name limits max value */
    return krb5_klog_syslog(LOG_NOTICE,
                            _("Unauthorized request: %s, %.*s%s, "
                              "client=%.*s%s, service=%.*s%s, addr=%s"),
                            op, (int)tlen, target, tdots,
                            (int)clen, (char *)client->value, cdots,
                            (int)slen, (char *)server->value, sdots,
                            client_addr(rqstp->rq_xprt));
}