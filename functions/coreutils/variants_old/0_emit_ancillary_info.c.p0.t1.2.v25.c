Program Transformation 1:
In this transformation, I'll use a conditional statement to customize the outputs for specific programs. Since the new part doesn't modify the main purpose and use the initial functionality, it's considered a variation - mentioning differences in SHA2 utilities.


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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);

  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
      fputs (_("Report any translation bugs to " "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);

  // customization for sha2 programs
  if (STREQ (program, "sha224sum") || STREQ (program, "sha256sum") || STREQ (program, "sha384sum") || STREQ (program, "sha512sum")) {
    printf ("NOTE: %s is part of sha2 utilities.\n", program);
  }

  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}


Program Transformation 2:
In the next transformation, the program will output a different additional message for "coreutils". Since it directly depends on the program's name, an extra conditional if statement checking if the program equals "coreutils" appears.


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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
      fputs (_("Report any translation bugs to " "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);

  if (STREQ (program, "coreutils")) {
    printf("NOTE: %s has a 'Multi-call invocation' capability.\n", program);
  }

  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}
