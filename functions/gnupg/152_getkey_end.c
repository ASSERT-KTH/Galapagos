getkey_end (ctrl_t ctrl, getkey_ctx_t ctx)
{
  if (ctx)
    {
#ifdef HAVE_W32_SYSTEM

      /* FIXME: This creates a big regression for Windows because the
       * keyring is only released after the global ctrl is released.
       * So if an operation does a getkey and then tries to modify the
       * keyring it will fail on Windows with a sharing violation.  We
       * need to modify all keyring write operations to also take the
       * ctrl and close the cached_getkey_kdb handle to make writing
       * work.  See: GnuPG-bug-id: 3097  */
      (void)ctrl;
      keydb_release (ctx->kr_handle);

#else /*!HAVE_W32_SYSTEM*/

      if (ctrl && !ctrl->cached_getkey_kdb)
        ctrl->cached_getkey_kdb = ctx->kr_handle;
      else
        keydb_release (ctx->kr_handle);

#endif /*!HAVE_W32_SYSTEM*/

      free_strlist (ctx->extra_list);
      if (!ctx->not_allocated)
	xfree (ctx);
    }
}