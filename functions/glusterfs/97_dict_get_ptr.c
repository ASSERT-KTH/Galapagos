dict_get_ptr (dict_t *this, char *key, void **ptr)
{
        data_t * data = NULL;
        int      ret  = 0;

        if (!this || !key || !ptr) {
                ret = -EINVAL;
                goto err;
        }

        ret = dict_get_with_ref (this, key, &data);
        if (ret != 0) {
                goto err;
        }

        ret = _data_to_ptr (data, ptr);
        if (ret != 0) {
                goto err;
        }

err:
        if (data)
                data_unref (data);

        return ret;
}