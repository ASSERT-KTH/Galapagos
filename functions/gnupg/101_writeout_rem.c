writeout_rem (audit_ctx_t ctx, const char *format, ...)
{
  va_list arg_ptr;

  if (ctx->use_html)
    {
      int i;

      es_fputs ("  <tr><td><table><tr><td>*", ctx->outstream);
      for (i=1; i < ctx->indentlevel; i++)
        es_fputs ("&nbsp;&nbsp;", ctx->outstream);
      es_fputs ("&nbsp;&nbsp;&nbsp;</td><td> (", ctx->outstream);

    }
  else
    es_fprintf (ctx->outstream, "* %*s  (", (ctx->indentlevel-1)*2, "");
  if (format)
    {
      va_start (arg_ptr, format) ;
      writeout_v (ctx, format, arg_ptr);
      va_end (arg_ptr);
    }
  if (ctx->use_html)
    es_fputs (")</td></tr></table></td></tr>\n", ctx->outstream);
  else
    es_fputs (")\n", ctx->outstream);
}