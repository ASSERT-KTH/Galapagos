static ParameterError getstr(char **str, const char *val, bool allowblank)
{
  if(*str) {
    free(*str);
    *str = NULL;
  }
  if(val) {
    if(!allowblank && !val[0])
      return PARAM_BLANK_STRING;

    *str = strdup(val);
    if(!*str)
      return PARAM_NO_MEM;
  }
  return PARAM_OK;
}