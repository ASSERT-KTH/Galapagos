stream_write_byte (estream_t stream, unsigned char b)
{
  gpg_error_t err;
  int ret;

  ret = es_fputc (b, stream);
  if (ret == EOF)
    err = gpg_error_from_syserror ();
  else
    err = 0;

  return err;
}