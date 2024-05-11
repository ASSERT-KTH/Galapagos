iobuf_get_fd (iobuf_t a)
{
  for (; a->chain; a = a->chain)
    ;

  if (a->filter != file_filter)
    return GNUPG_INVALID_FD;

  {
    file_filter_ctx_t *b = a->filter_ov;
    gnupg_fd_t fp = b->fp;

    return fp;
  }
}