void emit_ancillary_info (char const *program)
{
  struct infomap 
  { 
    char const *program; 
    char const *node; 
  } const info[]= {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *ptr = info;

  while (ptr->program && !STREQ (program, ptr->program))
    ptr++;

  if (ptr->node)
    node = ptr->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *locale_messages = setlocale (LC_MESSAGES, nullptr);
  if (locale_messages && STRNCMP_LIT (locale_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *prog_url = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, prog_url);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}