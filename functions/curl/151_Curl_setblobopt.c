CURLcode Curl_setblobopt(struct curl_blob **blobp,
                         const struct curl_blob *blob)
{
  /* free the previous storage at `blobp' and replace by a dynamic storage
     copy of blob. If CURL_BLOB_COPY is set, the data is copied. */

  Curl_safefree(*blobp);

  if(blob) {
    struct curl_blob *nblob;
    if(blob->len > CURL_MAX_INPUT_LENGTH)
      return CURLE_BAD_FUNCTION_ARGUMENT;
    nblob = (struct curl_blob *)
      malloc(sizeof(struct curl_blob) +
             ((blob->flags & CURL_BLOB_COPY) ? blob->len : 0));
    if(!nblob)
      return CURLE_OUT_OF_MEMORY;
    *nblob = *blob;
    if(blob->flags & CURL_BLOB_COPY) {
      /* put the data after the blob struct in memory */
      nblob->data = (char *)nblob + sizeof(struct curl_blob);
      memcpy(nblob->data, blob->data, blob->len);
    }

    *blobp = nblob;
    return CURLE_OK;
  }

  return CURLE_OK;
}