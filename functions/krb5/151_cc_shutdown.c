cc_result cc_shutdown (apiCB **io_context)
{
    cc_result err = ccNoError;

    if (!io_context) { err = cci_check_error (ccErrBadParam); }

    if (!err) {
        err = ccapi_context_release (*io_context);
    }

    if (!err) {
        *io_context = NULL;
    }

    return cci_remap_error (err);
}