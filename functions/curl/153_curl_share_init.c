curl_share_init(void)
{
  struct Curl_share *share = calloc(1, sizeof(struct Curl_share));
  if(share) {
    share->magic = CURL_GOOD_SHARE;
    share->specifier |= (1<<CURL_LOCK_DATA_SHARE);
    Curl_init_dnscache(&share->hostcache, 23);
  }

  return share;
}