Variant 1:

void emit_ancillary_info (const char *prog)
{
  const struct { const char *prog; const char *nd; } mapping[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  const char *nd = prog;
  const struct mapping *mapPtr = mapping;

  while (mapPtr->prog && ! STREQ (prog, mapPtr->prog))
    mapPtr++;

  if (mapPtr->nd)
    nd = mapPtr->nd;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char *locmsg = setlocale (LC_MESSAGES, nullptr);
  if (locmsg && STRNCMP_LIT (locmsg, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  const char *urlProg = STREQ (prog, "[") ? "test" : prog;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, urlProg);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          nd, nd == prog ? " invocation" : "");
}
``'

Variant 2:

void emit_ancillary_info (char const *prg)
{
  struct tmpstructure { char const *prgDtls; char const *detail; } const mapinfo[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *nodeDetail = prg;
  struct tmpstructure const *mappingProg = mapinfo;

  while (mappingProg->prgDtls && ! STREQ (prg, mappingProg->prgDtls))
    mappingProg++;

  if (mappingProg->detail)
    nodeDetail = mappingProg->detail;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *localemsg = setlocale (LC_MESSAGES, nullptr);
  if (localemsg && STRNCMP_LIT (localemsg, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *urlprgName = STREQ (prg, "[") ? "test" : prg;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, urlprgName);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          nodeDetail, nodeDetail == prg ? " invocation" : "");
}
