leave_cmd (assuan_context_t ctx, gpg_error_t err)
{
  if (err)
    {
      const char *name = assuan_get_command_name (ctx);
      if (!name)
        name = "?";

      /* Not all users of gpg-agent know about the fully canceled
         error code; map it back if needed.  */
      if (gpg_err_code (err) == GPG_ERR_FULLY_CANCELED)
        {
          ctrl_t ctrl = assuan_get_pointer (ctx);

          if (!ctrl->server_local->allow_fully_canceled)
            err = gpg_err_make (gpg_err_source (err), GPG_ERR_CANCELED);
        }

      /* Most code from common/ does not know the error source, thus
         we fix this here.  */
      if (gpg_err_source (err) == GPG_ERR_SOURCE_UNKNOWN)
        err = gpg_err_make (GPG_ERR_SOURCE_DEFAULT, gpg_err_code (err));

      if (gpg_err_source (err) == GPG_ERR_SOURCE_DEFAULT)
        log_error ("command '%s' failed: %s\n", name,
                   gpg_strerror (err));
      else
        log_error ("command '%s' failed: %s <%s>\n", name,
                   gpg_strerror (err), gpg_strsource (err));
    }
  return err;
}