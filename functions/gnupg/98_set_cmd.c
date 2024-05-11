set_cmd (enum cmd_and_opt_values *ret_cmd, enum cmd_and_opt_values new_cmd)
{
  enum cmd_and_opt_values cmd = *ret_cmd;

  if (!cmd || cmd == new_cmd)
    cmd = new_cmd;
  else
    {
      log_error (_("conflicting commands\n"));
      g13_exit (2);
    }

  *ret_cmd = cmd;
}