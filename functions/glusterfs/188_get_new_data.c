get_new_data ()
{
        data_t *data = NULL;

        data = mem_get0 (THIS->ctx->dict_data_pool);
        if (!data) {
                return NULL;
        }

        LOCK_INIT (&data->lock);
        return data;
}