void emit_ancillary_info (char const *program)
{
  int i;
  struct infomap {
    char const *program; 
    char const *node; 
  } const map[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node_key = program;  
      
  for (i = 0; map[i].program; ++i)  
  {
    if (strcmp(program, map[i].program) == 0)  
    {
      node_key = map[i].node;
      break;
    }
  }        

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  
  char const *url_program = strcmp (program, "[") == 0 ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node_key, node_key == program ? " invocation" : "");
}
