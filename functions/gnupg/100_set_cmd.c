set_cmd (enum cmd_and_opt_values *ret_cmd, enum cmd_and_opt_values new_cmd)
{
  enum cmd_and_opt_values c = *ret_cmd;

  if (!c || c == new_cmd)
    c = new_cmd;
  else if (c == aSign && new_cmd == aEncrypt)
    c = aSignEncrypt;
  else if (c == aEncrypt && new_cmd == aSign)
    c = aSignEncrypt;
  else
    {
      log_error (_("conflicting commands\n"));
      exit (2);
    }

  *ret_cmd = c;
}