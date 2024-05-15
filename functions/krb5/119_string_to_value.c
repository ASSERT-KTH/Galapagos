string_to_value(const char *in, k5_json_object obj, const char *key)
{
    krb5_error_code ret = 0;
    k5_json_string str = NULL;

    if (in == NULL)
        return 0;

    ret = k5_json_string_create(in, &str);
    if (ret)
        return ret;
    ret = k5_json_object_set(obj, key, str);
    k5_json_release(str);

    return ret;
}