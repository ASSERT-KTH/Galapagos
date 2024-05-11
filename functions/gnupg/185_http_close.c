http_close (http_t hd, int keep_read_stream)
{
  if (!hd)
    return;

  log_assert (hd->magic == HTTP_CONTEXT_MAGIC);

  /* First remove the close notifications for the streams.  */
  if (hd->fp_read)
    es_onclose (hd->fp_read, 0, fp_onclose_notification, hd);
  if (hd->fp_write)
    es_onclose (hd->fp_write, 0, fp_onclose_notification, hd);

  /* Now we can close the streams.  */
  my_socket_unref (hd->sock, NULL, NULL);
  if (hd->fp_read && !keep_read_stream)
    es_fclose (hd->fp_read);
  if (hd->fp_write)
    es_fclose (hd->fp_write);
  http_session_unref (hd->session);
  hd->magic = 0xdeadbeef;
  http_release_parsed_uri (hd->uri);
  while (hd->headers)
    {
      header_t tmp = hd->headers->next;
      xfree (hd->headers->value);
      xfree (hd->headers);
      hd->headers = tmp;
    }
  xfree (hd->buffer);
  xfree (hd);
}