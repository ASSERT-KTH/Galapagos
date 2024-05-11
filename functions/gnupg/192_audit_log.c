audit_log (audit_ctx_t ctx, audit_event_t event)
{
  log_item_t item;

  if (!ctx || ctx->failure)
    return;  /* Audit not enabled or an internal error has occurred. */
  if (!event)
    {
      ctx->failure = "Invalid event passed to audit_log";
      return;
    }
  if (!(item = create_log_item (ctx)))
    return;
  item->event = event;
}