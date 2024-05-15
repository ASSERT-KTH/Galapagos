cc_result cc_close (apiCB     *in_context,
                    ccache_p **io_ccache)
{
    cc_result err = ccNoError;

    if (!in_context) { err = cci_check_error (ccErrBadParam); }
    if (!io_ccache ) { err = cci_check_error (ccErrBadParam); }

    if (!err) {
        err = ccapi_ccache_release (*io_ccache);
    }

    if (!err) {
        *io_ccache = NULL;
    }

    return cci_remap_error (err);
}