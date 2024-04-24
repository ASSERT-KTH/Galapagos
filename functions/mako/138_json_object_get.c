json_object_get(const json_value *obj, const char *name) {
  json_object_entry *entry = json_object_find(obj, name);

  if (entry == NULL)
    return NULL;

  return entry->value;
}