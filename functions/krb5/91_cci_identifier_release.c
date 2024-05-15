cc_int32 cci_identifier_release (cci_identifier_t in_identifier)
{
    cc_int32 err = ccNoError;

    /* Do not free the static "uninitialized" identifier */
    if (!err && in_identifier && in_identifier != cci_identifier_uninitialized) {
        free (in_identifier->server_id);
        free (in_identifier->object_id);
        free (in_identifier);
    }

    return cci_check_error (err);
}