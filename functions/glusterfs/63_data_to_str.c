data_to_str (data_t *data)
{
        if (!data) {
                gf_log_callingfn ("dict", GF_LOG_WARNING, "data is NULL");
                return NULL;
        }
        return data->data;
}