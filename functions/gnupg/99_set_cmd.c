set_cmd (enum cmd_and_opt_values *ret_cmd, enum cmd_and_opt_values new_cmd)
{
  enum cmd_and_opt_values cmd = *ret_cmd;

  if (!cmd || cmd == new_cmd)
    cmd = new_cmd;
  else if ( cmd == aSign && new_cmd == aEncr )
    cmd = aSignEncr;
  else if ( cmd == aEncr && new_cmd == aSign )
    cmd = aSignEncr;
  else if ( (cmd == aSign && new_cmd == aClearsign)
            || (cmd == aClearsign && new_cmd == aSign) )
    cmd = aClearsign;
  else
    {
      log_error(_("conflicting commands\n"));
      gpgsm_exit(2);
    }

  *ret_cmd = cmd;
}