json_boolean_get(int *z, const json_value *obj) {
  if (obj->type == json_integer) {
    if (obj->u.integer != 0 && obj->u.integer != 1)
      return 0;

    *z = obj->u.integer;

    return 1;
  }

  if (obj->type == json_boolean) {
    *z = obj->u.boolean;
    return 1;
  }

  return 0;
}