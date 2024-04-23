json_string_get(const char **z, const json_value *obj) {
  if (obj->type != json_string)
    return 0;

  if (strlen(obj->u.string.ptr) != obj->u.string.length)
    return 0;

  *z = obj->u.string.ptr;

  return 1;
}