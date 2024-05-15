Curl_share_lock(struct Curl_easy *data, curl_lock_data type,
                curl_lock_access accesstype)
{
  struct Curl_share *share = data->share;

  if(!share)
    return CURLSHE_INVALID;

  if(share->specifier & (unsigned int)(1<<type)) {
    if(share->lockfunc) /* only call this if set! */
      share->lockfunc(data, type, accesstype, share->clientdata);
  }
  /* else if we don't share this, pretend successful lock */

  return CURLSHE_OK;
}