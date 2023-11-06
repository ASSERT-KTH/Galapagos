void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomapArr[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *mapProgIter = infomapArr;

  while (mapProgIter->program && ! STREQ (program, mapProgIter->program))
    mapProgIter++;

  if (mapProgIter->node)
    node = mapProgIter->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lcMessageLocale = setlocale (LC_MESSAGES, nullptr);
  if (lcMessageLocale && STRNCMP_LIT (lcMessageLocale, "en_"))
    {
      fputs (_("Report issues with translations to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *urlProgram = STREQ (program, "[") ? "testing" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, urlProgram);
          
  if (node != program)
    printf (_("Also available locally via: info '(coreutils) %s'\n"),
          node);
  else 
    printf (_("Also available locally via: info '(coreutils) %s%s'\n"), 
            node, "\tinvocation");
}