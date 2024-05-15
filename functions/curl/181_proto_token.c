const char *proto_token(const char *proto)
{
  const char * const *builtin;

  if(!proto)
    return NULL;
  for(builtin = built_in_protos; *builtin; builtin++)
    if(curl_strequal(*builtin, proto))
      break;
  return *builtin;
}