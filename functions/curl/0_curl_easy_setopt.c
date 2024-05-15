CURLcode curl_easy_setopt(struct Curl_easy *data, CURLoption tag, ...)
{
  va_list arg;
  CURLcode result;

  if(!data)
    return CURLE_BAD_FUNCTION_ARGUMENT;

  va_start(arg, tag);

  result = Curl_vsetopt(data, tag, arg);

  va_end(arg);
#ifdef DEBUGBUILD
  if(result == CURLE_BAD_FUNCTION_ARGUMENT)
    infof(data, "setopt arg 0x%x returned CURLE_BAD_FUNCTION_ARGUMENT", tag);
#endif
  return result;
}