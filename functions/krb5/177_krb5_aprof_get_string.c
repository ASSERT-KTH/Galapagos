krb5_aprof_get_string(krb5_pointer acontext, const char **hierarchy,
                      krb5_boolean uselast, char **stringp)
{
    krb5_error_code ret;
    char **values;
    int lastidx;

    ret = krb5_aprof_getvals(acontext, hierarchy, &values);
    if (ret)
        return ret;

    for (lastidx = 0; values[lastidx] != NULL; lastidx++);
    lastidx--;

    /* Excise the entry we want from the null-terminated list,
     * and free up the rest. */
    if (uselast) {
        *stringp = values[lastidx];
        values[lastidx] = NULL;
    } else {
        *stringp = values[0];
        values[0] = values[lastidx];
        values[lastidx] = NULL;
    }

    profile_free_list(values);
    return 0;
}