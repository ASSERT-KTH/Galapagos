dict_set_int32 (dict_t *this, char *key, int32_t val)
{
        data_t * data = NULL;
        int      ret  = 0;

        data = data_from_int32 (val);
        if (!data) {
                ret = -EINVAL;
                goto err;
        }

        ret = dict_set (this, key, data);
        if (ret < 0)
                data_destroy (data);

err:
        return ret;
}