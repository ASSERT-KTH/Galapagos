dict_get_int32 (dict_t *this, char *key, int32_t *val)
{
        data_t * data = NULL;
        int      ret  = 0;

        if (!this || !key || !val) {
                ret = -EINVAL;
                goto err;
        }

        ret = dict_get_with_ref (this, key, &data);
        if (ret != 0) {
                goto err;
        }

        ret = _data_to_int32 (data, val);

err:
        if (data)
                data_unref (data);
        return ret;
}