The following code maintains the function emit_ancillary_info's original functionality but changes the structure by first checking whether the program didn't give us specific note 'infomap', before proceeding to call setlocale, etc. So the original function will check "infomap" for each program before checking the locale, and the changed one does it after identifying the locale and other properties:

void emit_ancillary_info (char const *program)
{
  char const *node, *lc_messages, *url_program;
  struct infomap { char const *program; char const *node; } 
  const infomap[] = 
  {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  lc_messages = setlocale (LC_MESSAGES, nullptr);

  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }

  /* check for program in the infomap array after setlocale & others */

  node = program;
  struct infomap const *map_prog = infomap;
    
  while (map_prog->program && !STREQ (program, map_prog->program)) {
    map_prog++;
  }

  url_program = STREQ (program, "[") ? "test" : program;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}