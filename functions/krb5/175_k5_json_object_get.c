k5_json_object_get(k5_json_object obj, const char *key)
{
    struct entry *ent;

    ent = object_search(obj, key);
    if (ent == NULL)
        return NULL;
    return ent->value;
}