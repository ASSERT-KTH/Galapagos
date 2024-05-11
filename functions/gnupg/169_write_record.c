write_record (estream_t stream, const void *record)
{
  gpg_error_t err;
  size_t nwritten;

  nwritten = es_fwrite (record, 1, RECORDSIZE, stream);
  if (nwritten != RECORDSIZE)
    {
      err = gpg_error_from_syserror ();
      log_error ("error writing '%s': %s\n",
                 es_fname_get (stream), gpg_strerror (err));
    }
  else
    err = 0;

  return err;
}