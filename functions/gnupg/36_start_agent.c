start_agent (void)
{
  gpg_error_t err;

  /* Fixme: This code is not thread safe, thus we don't build it with
     pth.  We will need a context for each thread or serialize the
     access to the agent.  */
  if (agent_ctx)
    return 0;

  err = start_new_gpg_agent (&agent_ctx,
                             agentargs.errsource,
                             agentargs.agent_program,
                             agentargs.lc_ctype,
                             agentargs.lc_messages,
                             agentargs.session_env,
                             ASSHELP_FLAG_AUTOSTART,
                             agentargs.verbosity, 0, NULL, NULL);
  if (!err)
    {
      /* Tell the agent that we support Pinentry notifications.  No
         error checking so that it will work with older agents.  */
      assuan_transact (agent_ctx, "OPTION allow-pinentry-notify",
                       NULL, NULL, NULL, NULL, NULL, NULL);
    }

  return err;
}