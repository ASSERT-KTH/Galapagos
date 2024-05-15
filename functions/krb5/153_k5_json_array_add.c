k5_json_array_add(k5_json_array array, k5_json_value val)
{
    k5_json_value *ptr;
    size_t new_alloc;

    if (array->len >= array->allocated) {
        /* Increase the number of slots by 50% (MIN_ALLOC_SLOT minimum). */
        new_alloc = array->len + 1 + (array->len >> 1);
        if (new_alloc < MIN_ALLOC_SLOT)
            new_alloc = MIN_ALLOC_SLOT;
        ptr = realloc(array->values, new_alloc * sizeof(*array->values));
        if (ptr == NULL)
            return ENOMEM;
        array->values = ptr;
        array->allocated = new_alloc;
    }
    array->values[array->len++] = k5_json_retain(val);
    return 0;
}