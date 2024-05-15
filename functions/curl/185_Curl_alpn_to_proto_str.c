CURLcode Curl_alpn_to_proto_str(struct alpn_proto_buf *buf,
                                const struct alpn_spec *spec)
{
  size_t i, len;
  size_t off = 0;

  memset(buf, 0, sizeof(*buf));
  for(i = 0; spec && i < spec->count; ++i) {
    len = strlen(spec->entries[i]);
    if(len >= ALPN_NAME_MAX)
      return CURLE_FAILED_INIT;
    if(off + len + 2 >= sizeof(buf->data))
      return CURLE_FAILED_INIT;
    if(off)
      buf->data[off++] = ',';
    memcpy(buf->data + off, spec->entries[i], len);
    off += len;
  }
  buf->data[off] = '\0';
  buf->len = (int)off;
  return CURLE_OK;
}