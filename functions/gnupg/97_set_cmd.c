set_cmd( enum cmd_and_opt_values *ret_cmd, enum cmd_and_opt_values new_cmd )
{
    enum cmd_and_opt_values cmd = *ret_cmd;

    if( !cmd || cmd == new_cmd )
	cmd = new_cmd;
    else if( cmd == aSign && new_cmd == aEncr )
	cmd = aSignEncr;
    else if( cmd == aEncr && new_cmd == aSign )
	cmd = aSignEncr;
    else if( cmd == aSign && new_cmd == aSym )
	cmd = aSignSym;
    else if( cmd == aSym && new_cmd == aSign )
	cmd = aSignSym;
    else if( cmd == aSym && new_cmd == aEncr )
	cmd = aEncrSym;
    else if( cmd == aEncr && new_cmd == aSym )
	cmd = aEncrSym;
    else if (cmd == aSignEncr && new_cmd == aSym)
        cmd = aSignEncrSym;
    else if (cmd == aSignSym && new_cmd == aEncr)
        cmd = aSignEncrSym;
    else if (cmd == aEncrSym && new_cmd == aSign)
        cmd = aSignEncrSym;
    else if(	( cmd == aSign	   && new_cmd == aClearsign )
	     || ( cmd == aClearsign && new_cmd == aSign )  )
	cmd = aClearsign;
    else {
	log_error(_("conflicting commands\n"));
	g10_exit(2);
    }

    *ret_cmd = cmd;
}