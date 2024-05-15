CURLcode easysrc_add(struct slist_wc **plist, const char *line)
{
  CURLcode ret = CURLE_OK;
  struct slist_wc *list = slist_wc_append(*plist, line);
  if(!list) {
    easysrc_free();
    ret = CURLE_OUT_OF_MEMORY;
  }
  else
    *plist = list;
  return ret;
}