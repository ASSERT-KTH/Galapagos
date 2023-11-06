void emit_ancillary_info (char const *program)
{
  struct infomap {char const *program; char const *node;};
  const struct infomap infomap[] = {
    {"[", "test invocation"},
    {"coreutils", "Multi-call invocation"},
    {"sha224sum", "sha2 utilities"},
    {"sha256sum", "sha2 utilities"},
    {"sha384sum", "sha2 utilities"},
    {"sha512sum", "sha2 utilities"},
    {nullptr, nullptr}
  };

  char const * node = program;
  const struct infomap *map_prog = infomap;

  for(; map_prog->program && strcmp (program, map_prog->program) != 0 ; ++map_prog);
  
  if (map_prog -> node) node = map_prog -> node;

  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (lc_messages && strncmp(lc_messages,"en_",3))
  {
      fputs ("Report any translation bugs to "
               "<https://translationproject.org/team/>\n", stdout);
  }
   
  char const *url_program = (strcmp (program, "[")) ? program : "test";
  
  printf ("Full documentation <%s%s>\n", PACKAGE_URL, url_program);

  printf ("or available locally via: info '(coreutils) %s%s'\n",
          node, (strcmp (node, program) == 0) ? " invocation" : "");
}