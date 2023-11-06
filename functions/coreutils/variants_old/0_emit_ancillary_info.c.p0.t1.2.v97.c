Variant 1:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "normal-bracket", "test invocation" },
    { "general-coreutils", "Multi-call invocation" },
    { "hash-sha224sum", "sha2 utilities" },
    { "hash-sha256sum", "sha2 utilities" },
    { "hash-sha384sum", "sha2 utilities" },
    { "hash-sha512sum", "sha2 utilities" },
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
      fputs (_("Report translation issues at "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "normal-bracket") ? "test" : program;
  printf (_("Complete documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Or access it locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " Invocation" : "");
}


Variant 2:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "===", "test invocation" },
    { "UTILIS", "Multi-call invocation" },
    { "::sha224sum", "sha2 utilities" },
    { "::sha256sum", "sha2 utilities" },
    { "::sha384sum", "sha2 utilities" },
    { "::sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\nOnline support for %s: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Please report translation errors at "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "===") ? "test" : program;
  printf (_("In-depth documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Alternatively available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " Invocation" : "");
}
