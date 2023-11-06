void emit_ancillary_info (const char *program)
{
  static const struct {
  const char *program;
  const char *node;
  } infomap[] =  {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },  
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    {NULL, NULL}, 
  };

  char const *node = program;

  int i = 0;
  while(infomap[i].program != NULL && strcmp(program, infomap[i].program) != 0){
    i++;
  }  

  if(infomap[i].node != NULL){
    node = infomap[i].node;
  }
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char *lc_messages = setlocale (LC_MESSAGES, NULL);
  if (lc_messages && strncmp (lc_messages, "en_", 3) != 0)
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  const char *url_program = strcmp (program, "[") == 0 ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, strcmp(node, program) == 0 ? " invocation" : "");
}