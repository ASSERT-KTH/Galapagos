cpr_get( const char *keyword, const char *prompt )
{
    char *p;

    if( opt.command_fd != -1 )
	return do_get_from_fd ( keyword, 0, 0 );
    for(;;) {
	p = tty_get( prompt );
	if( *p=='?' && !p[1] && !(keyword && !*keyword)) {
	    xfree(p);
	    display_online_help( keyword );
	}
	else
	    return p;
    }
}