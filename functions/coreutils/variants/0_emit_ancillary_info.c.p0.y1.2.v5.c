void emit_ancillary_info (char const *program)
{
   struct infomap {
    char const *program; 
    char const *node;
   } const infomap[] = {
    {"[", "test invocation"},
    {"coreutils", "Multi-call invocation"},
    {"sha224sum", "sha2 utilities"},
    {"sha256sum", "sha2 utilities"},
    {"sha384sum", "sha2 utilities"},
    {"sha512sum", "sha2 utilities"},
    {0, 0}
  };

  const char *node = program;
  struct infomap const *ptr_map = infomap;

  while (ptr_map->program &&!(!strcmp(program, ptr_map->program)))
      ptr_map++;

  if (ptr_map->node)
      node = ptr_map->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  char const *lang_setting = setlocale (LC_MESSAGES, 0);

  if(lang_setting && strncmp(lang_setting,"en_", 3))
  fputs (_("Alert translation errors to "
            "<https://translationproject.org/team/>\n"), stdout);
  
  char const *url_program = (!strcmp(program, "[")) ? "test" : program;
  
  printf (_("Complete documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
  printf (_("Also available offline via: info '(coreutils) %s%s'\n"),
            node, node == program ? " introduction" : "");
}