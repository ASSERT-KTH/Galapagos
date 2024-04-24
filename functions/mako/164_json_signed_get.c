json_signed_get(int *z, const json_value *obj) {
  if (obj->type == json_integer) {
    if (obj->u.integer < (INT_MIN / 2))
      return 0;

    if (obj->u.integer > (INT_MAX / 2))
      return 0;

    *z = obj->u.integer;

    return 1;
  }

  return 0;
}