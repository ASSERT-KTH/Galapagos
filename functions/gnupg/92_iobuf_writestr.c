iobuf_writestr (iobuf_t a, const char *buf)
{
  if (a->use == IOBUF_INPUT || a->use == IOBUF_INPUT_TEMP)
    {
      log_bug ("iobuf_writestr called on an input pipeline!\n");
      return -1;
    }

  return iobuf_write (a, buf, strlen (buf));
}