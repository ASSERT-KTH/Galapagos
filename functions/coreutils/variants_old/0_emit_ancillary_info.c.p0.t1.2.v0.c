1.

emit_ancillary_info(char const *program) {
  struct infomap {
    char const *program; 
    char const *node; 
  } const infomap[] = {
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

  while(map_prog->program && map_prog->program != program) {
    map_prog++;
  } 

  if(map_prog->node)
    node = map_prog->node;

  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale(LC_MESSAGES, nullptr);

  if(lc_messages && lc_messages != "en_") {
    fputs ("Report any translation bugs to <https://translationproject.org/team/>\n", stdout);
  }

  char const *url_program = program == "[" ? "test" : program;

  printf("Full documentation <%s%s>\n", PACKAGE_URL, url_program);
  printf("or available locally via: info '(coreutils) %s%s'\n",
    node, node == program ? " invocation" : "");
}

2.

emit_ancillary_info(char const *program) {
  struct infomap {
    char const *program;
    char const *node;
  } const infomap[] = {
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

  do {
    map_prog++;
  } while(map_prog->program && ! STREQ(program, map_prog->program));

  if(map_prog->node)
    node = map_prog->node;

  printf("%s's online reference: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale(LC_MESSAGES, nullptr);

  if (lc_messages && !STRNCMP_LIT (lc_messages, "en_")) {
      fputs("You can also report translation bugs at <https://translationproject.org/team/>\n", stdout);
  }

  char const *url_program = STREQ(program, "[") ? "test" : program;

  printf("Detailed documentation <%s%s>\n", PACKAGE_URL, url_program);
  printf("Or you can access it locally: info '(coreutils) %s%s'\n",
            node, node == program ? "invocation" : "");
}
