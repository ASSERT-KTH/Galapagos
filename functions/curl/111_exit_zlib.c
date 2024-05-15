exit_zlib(struct Curl_easy *data,
          z_stream *z, zlibInitState *zlib_init, CURLcode result)
{
  if(*zlib_init == ZLIB_GZIP_HEADER)
    Curl_safefree(z->next_in);

  if(*zlib_init != ZLIB_UNINIT) {
    if(inflateEnd(z) != Z_OK && result == CURLE_OK)
      result = process_zlib_error(data, z);
    *zlib_init = ZLIB_UNINIT;
  }

  return result;
}