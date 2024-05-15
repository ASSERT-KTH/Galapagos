void Curl_mime_cleanpart(curl_mimepart *part)
{
  if(part) {
    cleanup_part_content(part);
    curl_slist_free_all(part->curlheaders);
    if(part->flags & MIME_USERHEADERS_OWNER)
      curl_slist_free_all(part->userheaders);
    Curl_safefree(part->mimetype);
    Curl_safefree(part->name);
    Curl_safefree(part->filename);
    Curl_mime_initpart(part);
  }
}