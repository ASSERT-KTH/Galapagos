data_destroy (data_t *data)
{
        if (data) {
                LOCK_DESTROY (&data->lock);

                if (!data->is_static) {
                        if (data->data) {
                                if (data->is_stdalloc)
                                        free (data->data);
                                else
                                        GF_FREE (data->data);
                        }
                }

                data->len = 0xbabababa;
                if (!data->is_const)
                        mem_put (data);
        }
}