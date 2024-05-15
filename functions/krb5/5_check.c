check(krb5_error_code code)
{
    if (code != 0) {
        com_err("t_vfy_increds", code, NULL);
        abort();
    }
}