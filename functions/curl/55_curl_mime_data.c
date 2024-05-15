CURLcode curl_mime_data(curl_mimepart *part,
                        const char *ptr, size_t datasize)
{
  if(!part)
    return CURLE_BAD_FUNCTION_ARGUMENT;

  cleanup_part_content(part);

  if(ptr) {
    if(datasize == CURL_ZERO_TERMINATED)
      datasize = strlen(ptr);

    part->data = Curl_memdup0(ptr, datasize);
    if(!part->data)
      return CURLE_OUT_OF_MEMORY;

    part->datasize = datasize;
    part->readfunc = mime_mem_read;
    part->seekfunc = mime_mem_seek;
    part->freefunc = mime_mem_free;
    part->flags |= MIME_FAST_READ;
    part->kind = MIMEKIND_DATA;
  }

  return CURLE_OK;
}