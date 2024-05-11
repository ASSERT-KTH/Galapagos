cpr_kill_prompt(void)
{
    if( opt.command_fd != -1 )
	return;
    tty_kill_prompt();
    return;
}