void ec_trace(const char * event, ec_fop_data_t * fop, const char * fmt, ...)
{
    char str1[32], str2[32], str3[32];
    char * msg;
    ec_t * ec = fop->xl->private;
    va_list args;
    int32_t ret;

    va_start(args, fmt);
    ret = vasprintf(&msg, fmt, args);
    va_end(args);

    if (ret < 0)
    {
        msg = "<memory allocation error>";
    }

    gf_log("ec", GF_LOG_TRACE, "%s(%s) %p(%p) [refs=%d, winds=%d, jobs=%d] "
                               "frame=%p/%p, min/exp=%d/%d, err=%d state=%d "
                               "{%s:%s:%s} %s",
           event, ec_fop_name(fop->id), fop, fop->parent, fop->refs,
           fop->winds, fop->jobs, fop->req_frame, fop->frame, fop->minimum,
           fop->expected, fop->error, fop->state,
           ec_bin(str1, sizeof(str1), fop->mask, ec->nodes),
           ec_bin(str2, sizeof(str2), fop->remaining, ec->nodes),
           ec_bin(str3, sizeof(str3), fop->bad, ec->nodes), msg);

    if (ret >= 0)
    {
        free(msg);
    }
}