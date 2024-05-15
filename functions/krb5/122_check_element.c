check_element(k5_json_array array, size_t idx, k5_json_tid tid)
{
    k5_json_value v;

    v = k5_json_array_get(array, idx);
    return (k5_json_get_tid(v) == tid) ? v : NULL;
}