dict_set_int8 (dict_t *this, char *key, int8_t val)
{
        data_t * data = NULL;
        int      ret  = 0;

        data = data_from_int8 (val);
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