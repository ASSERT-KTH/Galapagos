CURLcode Curl_hmacit(const struct HMAC_params *hashparams,
                     const unsigned char *key, const size_t keylen,
                     const unsigned char *data, const size_t datalen,
                     unsigned char *output)
{
  struct HMAC_context *ctxt =
    Curl_HMAC_init(hashparams, key, curlx_uztoui(keylen));

  if(!ctxt)
    return CURLE_OUT_OF_MEMORY;

  /* Update the digest with the given challenge */
  Curl_HMAC_update(ctxt, data, curlx_uztoui(datalen));

  /* Finalise the digest */
  Curl_HMAC_final(ctxt, output);

  return CURLE_OK;
}