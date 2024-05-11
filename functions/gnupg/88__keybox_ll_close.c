_keybox_ll_close (estream_t fp)
{
  gpg_error_t err;
  struct stream_buffer_s *sbuf;
  int i;

  if (!fp)
    return 0;

  sbuf = ll_buffer_size? es_opaque_get (fp) : NULL;
  if (es_fclose (fp))
    err = gpg_error_from_syserror ();
  else
    err = 0;
  if (sbuf)
    {
      for (i=0; i < DIM (stream_buffers); i++)
        if (stream_buffers + i == sbuf)
          break;
      log_assert (i < DIM (stream_buffers));
      stream_buffers[i].inuse = 0;
    }


  return err;
}