A program variant of the original function can add a conditional statement checking for special conditions that could control the behavior. Following is an example that adds functionality such now we can ignore the redundant messages for locales set to "en_GB" as well: 


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
  
  /* Don't output this redundant message for English locales.
     Now includes GB English. */
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if ((lc_messages &&
       ! (STRNCMP_LIT (lc_messages, "en_") && STRNCMP_LIT (lc_messages, "en_GB")
       )) || lc_messages[0] == 'C')
    {
      /* Report translation bugs note */
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

 
In this updated version, the behavior change is where we have expanded English local tests to include Great Britain Locale (en_GB).