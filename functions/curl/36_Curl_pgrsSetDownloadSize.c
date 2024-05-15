void Curl_pgrsSetDownloadSize(struct Curl_easy *data, curl_off_t size)
{
  if(size >= 0) {
    data->progress.size_dl = size;
    data->progress.flags |= PGRS_DL_SIZE_KNOWN;
  }
  else {
    data->progress.size_dl = 0;
    data->progress.flags &= ~PGRS_DL_SIZE_KNOWN;
  }
}