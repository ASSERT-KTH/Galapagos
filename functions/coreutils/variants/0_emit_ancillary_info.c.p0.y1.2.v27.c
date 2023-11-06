void emit_ancillary_info (char const *program)
{
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

  const char *node;

  int i;
  for (i = 0; infomap[i].program != nullptr; i++) 
  {
    if (STREQ (program, infomap[i].program))
    {
        node = infomap[i].node;
        break;
    }
  }
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  const char *lc_messages = setlocale (LC_MESSAGES, NULL);
  if (((lc_messages != nullptr) && (STRNCMP_LIT (lc_messages, "en_"))))
  {
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }
  
  const char *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, (node == program ? " invocation" : ""));
}