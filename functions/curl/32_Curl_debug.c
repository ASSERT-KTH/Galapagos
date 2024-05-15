void Curl_debug(struct Curl_easy *data, curl_infotype type,
                char *ptr, size_t size)
{
  if(data->set.verbose) {
    static const char s_infotype[CURLINFO_END][3] = {
      "* ", "< ", "> ", "{ ", "} ", "{ ", "} " };
    if(data->set.fdebug) {
      bool inCallback = Curl_is_in_callback(data);
      Curl_set_in_callback(data, true);
      (void)(*data->set.fdebug)(data, type, ptr, size, data->set.debugdata);
      Curl_set_in_callback(data, inCallback);
    }
    else {
      switch(type) {
      case CURLINFO_TEXT:
      case CURLINFO_HEADER_OUT:
      case CURLINFO_HEADER_IN:
        fwrite(s_infotype[type], 2, 1, data->set.err);
        fwrite(ptr, size, 1, data->set.err);
        break;
      default: /* nada */
        break;
      }
    }
  }
}