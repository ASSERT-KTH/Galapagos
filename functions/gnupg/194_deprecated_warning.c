deprecated_warning(const char *configname,unsigned int configlineno,
		   const char *option,const char *repl1,const char *repl2)
{
  if(configname)
    {
      if(strncmp("--",option,2)==0)
	option+=2;

      if(strncmp("--",repl1,2)==0)
	repl1+=2;

      log_info(_("%s:%d: deprecated option \"%s\"\n"),
	       configname,configlineno,option);
    }
  else
    log_info(_("WARNING: \"%s\" is a deprecated option\n"),option);

  log_info(_("please use \"%s%s\" instead\n"),repl1,repl2);
}