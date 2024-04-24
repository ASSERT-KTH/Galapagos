http_string_append(http_string_t *z, const char *xp, size_t xn) {
  http_string_grow(z, z->length + xn);

  if (xn > 0)
    memcpy(z->data + z->length, xp, xn);

  z->length += xn;
  z->data[z->length] = '\0';
}