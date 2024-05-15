call_k5_parse_host_string(const char *host, int default_port,
                          krb5_error_code e_code, const char *e_host,
                          int e_port)
{
    krb5_error_code code;
    char *host_out = NULL;
    int port_out = -1;

    code = k5_parse_host_string(host, default_port, &host_out, &port_out);

    assert_int_equal(code, e_code);

    /* Only check the port if the function was expected to be successful. */
    if (!e_code)
        assert_int_equal(port_out, e_port);

    /* If the expected code is a failure then host_out should be NULL. */
    if (e_code != 0 || e_host == NULL)
        assert_null(host_out);
    else
        assert_string_equal(e_host, host_out);

    free(host_out);
}