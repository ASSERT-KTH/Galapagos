start_agent (assuan_context_t *ctx_p)
{
  gpg_error_t err;
  session_env_t session_env;

  session_env = session_env_new ();
  if (!session_env)
    log_fatal ("error allocating session environment block: %s\n",
               strerror (errno));

  err = start_new_gpg_agent (ctx_p,
                             GPG_ERR_SOURCE_DEFAULT,
                             opt.agent_program,
                             NULL, NULL,
                             session_env,
                             opt.autostart?ASSHELP_FLAG_AUTOSTART:0,
                             !opt.quiet, 0,
                             NULL, NULL);

  session_env_release (session_env);
  return err;
}