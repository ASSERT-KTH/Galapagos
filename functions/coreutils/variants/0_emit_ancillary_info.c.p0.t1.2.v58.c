Variant 1:
A variation, this version eliminates extraneous url_program assignment by utilizing a sequence point in the expression which evaluates the boolean directly, allowing true and false outcomes.


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

  while (map_prog->program && !STREQ(program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf(_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  printf(_("Full documentation <%s%s>\n"), 
          PACKAGE_URL, STREQ(program, "[")?"test":program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), 
          node, node == program ? " invocation" : "");
}


Variant 2:
Here, rather than creating a new character pointer url_program, logic incorporated into printf directly evaluates the optimal program name for URL concatenation.


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

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, (STREQ(program, "[") ? "test" : program));
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, (node == program ? " invocation" : ""));
}
