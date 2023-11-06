Variant 1:

emit_ancillary_info (char const *program)
{
  const char * const pair_programs[] = { "[", "coreutils", "sha224sum", "sha256sum", "sha384sum", "sha512sum", nullptr };
  const char * const pair_nodes[] = { "test invocation", "Multi-call invocation", "sha2 utilities", "sha2 utilities", "sha2 utilities", "sha2 utilities", nullptr };

  int index = 0;
  char const *node = program;
  while (pair_programs[index] && strcmp(program, pair_programs[index]) != 0)
    index++;
  
  if (pair_nodes[index])
    node = pair_nodes[index];
   
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && strncmp(lc_messages, "en_", strlen("en_")))
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);

  char const *url_program = strcmp (program, "[") ? program : "test";
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, strcmp(node, program) ? "" : " invocation");
}


Variant 2:

emit_ancillary_info (char const *program)
{
  static struct infomap_struct {
    char const *program;
    char const *node;
  } const infomap_list[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr } 
  };

  struct infomap_struct const *map = infomap_list;
  char const *node_program = program;

  for ( ; map->program; map++) {
    if (!strcmp(map->program, program)) {
      node_program = map->node;
      break;
    }
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  const char *current_locale = setlocale (LC_MESSAGES, nullptr);
  if (current_locale && strncmp(current_locale, "en_", strlen("en_")))
    fputs (_("Report any translation bugs to " "<https://translationproject.org/team/>\n"), stdout);
    
  char const *link_program = strcmp (program, "[") ? program : "test";
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, link_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node_program, strcmp(node_program, program) ? "" : " invocation");
}
