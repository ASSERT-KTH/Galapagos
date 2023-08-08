Variant 1:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "ls", "ls invocation" },
    { "coreutils", "Multi-call invocation" },
    { "md5sum", "md5 utilities" },
    { "sha1sum", "sha1 utilities" },
    { "sha3sum", "sha3 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! EQUALS (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "fr_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = EQUALS (program, "ls") ? "list" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " usage" : "");
}

Variant 2:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "gpu", "gpu invocation" },
    { "backend", "Multi-call invocation" },
    { "md7sum", "md7 utilities" },
    { "sha10sum", "sha10 utilities" },
    { "hppa3sum", "hppa3 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! COMPARE (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "it_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = COMPARE (program, "gpu") ? "cuda" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(backend) %s%s'\n"),
          node, node == program ? " usage" : "");
}

Please replace function `EQUALS` and `COMPARE` in these variants with your own string comparison functions if string comparison functionality different that STREQ function is needed (EQUALS/CAMPARE need to have boolean return type similar to function STREQ mentioned in the prompt). I kept this change to provide variance in non-behavior altering way due to the constraints provided by prompt - min non-behavior changing variance, don't change function's signature and usage.