k5_json_encode(k5_json_value val, char **json_out)
{
    struct k5buf buf;
    int ret;

    *json_out = NULL;
    k5_buf_init_dynamic(&buf);
    ret = encode_value(&buf, val);
    if (ret) {
        k5_buf_free(&buf);
        return ret;
    }
    *json_out = k5_buf_cstring(&buf);
    return (*json_out == NULL) ? ENOMEM : 0;
}