Variant 1:


void emit_ancillary_info (const char *program)
{
  const struct infomap {const char *program; const char *node;} infomap[] = {
    {"[", "test"},
    {"coreutils", "Multi-call"},
    {"sha224sum", "sha2"},
    {"sha256sum", "sha2"},
    {"sha384sum", "sha2"},
    {"sha512sum", "sha2"},
    {nullptr, nullptr}
  };

  char const *node_hlp = program;
  const struct infomap *mapping_program = infomap;

  while (mapping_program->program && ! STREQ (program, mapping_program->program))
    mapping_program++;

  if (mapping_program->node)
    node_hlp = mapping_program->node;

  printf (_("\n%s useful information: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *locale_messages = setlocale (LC_MESSAGES, nullptr);
  if (locale_messages && STRNCMP_LIT (locale_messages, "en_"))
    {
      fputs (_("Report translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_of_program = STREQ (program, "[") ? "test" : program;
  printf (_("In-depth Documentation <%s%s>\n"), PACKAGE_URL, url_of_program);
  printf (_("It's locally available via: info '(coreutils) %s%s'\n"), node_hlp, node_hlp == program ? " Invocation" : "");
}


Variant 2:


void emit_ancillary_info (char const *prgm) {
  struct infomap { char const *prgm; char const * nde; } const infos[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *nde = prgm;
  struct infomap const *mapp = infos;

  while (mapp->prgm && ! STREQ (prgm, mapp->prgm))
    mapp++;

  if (mapp->nde)
    nde = mapp->nde;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *locale_messages_c = setlocale (LC_MESSAGES, nullptr);
  if (locale_messages_c && STRNCMP_LIT (locale_messages_c, "en_")) {
    fputs (_("Report translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_prgm = STREQ (prgm, "[") ? "test" : prgm;
  printf (_("Thorough documentation <%s%s>\n"), PACKAGE_URL, url_prgm);
  printf (_("Or accessibly in your locale via: info '(coreutils) %s%s'\n"), nde, nde == prgm ? " Invocation" : "");
}
