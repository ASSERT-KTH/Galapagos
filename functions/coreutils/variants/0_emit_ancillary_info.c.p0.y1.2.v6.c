void emit_ancillary_info (const char *program)
{
  typedef struct Infomap {
    const char *program;
    const char *node;
  } Infomap;

  Infomap infomap_arr[] = 
  { 
    {"[", "test invocation" }, 
    {"coreutils", "Multi-call invocation" },
    {"sha224sum", "sha2 utilities" }, 
    {"sha256sum", "sha2 utilities" }, 
    {"sha384sum", "sha2 utilities" }, 
    {"sha512sum", "sha2 utilities" }, 
    {nullptr, nullptr} 
  };

  const char *node = program;
  Infomap *cur_infomap = infomap_arr;

  while (cur_infomap->program && strcmp(program, cur_infomap->program) != 0)
    ++cur_infomap;

  node = cur_infomap->node ? cur_infomap->node : node;

  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);
  const char* lc_messages = setlocale(LC_MESSAGES, NULL);
  
  if (lc_messages && strncmp(lc_messages, "en_", 3)!=0)
    puts("Report any translation bugs to <https://translationproject.org/team/>\n");

  const char *url_program = strcmp(program, "[") == 0 ? "test" : program;

  printf("Full documentation <%s%s>\n", PACKAGE_URL, url_program);
  printf("or available locally via: info '(coreutils) %s%s'\n", node, node == program ? " invocation" : "" );
}
