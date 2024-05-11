find_next_log_item (audit_ctx_t ctx, log_item_t startitem,
                    audit_event_t event, audit_event_t stopevent)
{
  int idx;

  for (idx=0; idx < ctx->logused; idx++)
    {
      if (startitem)
        {
          if (ctx->log + idx == startitem)
            startitem = NULL;
        }
      else if (stopevent && ctx->log[idx].event == stopevent)
        break;
      else if (ctx->log[idx].event == event)
        return ctx->log + idx;
    }
  return NULL;
}