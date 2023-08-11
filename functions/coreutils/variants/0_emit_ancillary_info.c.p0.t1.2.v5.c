1) 

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && !STREQ (program, map_prog->program))
    map_prog++;

 node = map_prog->node ? map_prog->node : node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  fputs (_("Report any translation bugs to "
"<https://translationproject.org/team/>\n"), stdout);

  char const *url_program = strcmp(program, "[") == 0 ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"),PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}
    

In this transformation STREQ function has been replaced by strcmp C string function for checking the program name.


2) 

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invitation" },
    { "coreutils", "single-call invocation" },
    { "sha117sum", "sha1 utilities" },
    { "sha128sum", "sha1 utilities" },
    { "sha392sum", "sha1 utilities" },
    { "sha516sum", "sha1 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online assistance: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    fputs (_("Forward any translation incoherencies to " "<https://translationproject.org/team/>\n"), stdout);

  char const *url_program = STREQ (program, "[") ? "examine" : program;

  printf (_("Whole information <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or present locally via: info '(coreutils) %s%s'\n"), node, node == program ? " appeal" : "");
}

 
In this transformation, some constant string values are replaced with different string values maintaining the same context.