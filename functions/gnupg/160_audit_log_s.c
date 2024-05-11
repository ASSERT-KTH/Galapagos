audit_log_s (audit_ctx_t ctx, audit_event_t event, const char *value)
{
  log_item_t item;
  char *tmp;

  if (!ctx || ctx->failure)
    return;  /* Audit not enabled or an internal error has occurred. */
  if (!event)
    {
      ctx->failure = "Invalid event passed to audit_log_s";
      return;
    }
  tmp = xtrystrdup (value? value : "");
  if (!tmp)
    {
      ctx->failure = "Out of memory in audit_event";
      return;
    }
  if (!(item = create_log_item (ctx)))
    {
      xfree (tmp);
      return;
    }
  item->event = event;
  item->string = tmp;
}