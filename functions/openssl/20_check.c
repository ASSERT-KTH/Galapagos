check(krb5_error_code code)
{
    if (code != 0) {
        com_err("t_ser", code, NULL);
        abort();
    }
}