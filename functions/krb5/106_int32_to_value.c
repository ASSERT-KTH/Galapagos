int32_to_value(krb5_int32 int32, k5_json_object obj, const char *key)
{
    krb5_error_code ret = 0;
    k5_json_number num = NULL;

    ret = k5_json_number_create(int32, &num);
    if (ret)
        return ENOMEM;
    ret = k5_json_object_set(obj, key, num);
    k5_json_release(num);

    return ret;
}