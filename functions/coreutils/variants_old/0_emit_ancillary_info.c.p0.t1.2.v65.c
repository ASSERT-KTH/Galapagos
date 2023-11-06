emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "best one for multi-call invocation" },
    { "sha224sum", "required for sha2 utilities" },
    { "sha256sum", "essential for sha2 utilities" },
    { "sha384sum", "Vital utilities sha2" },
    { "sha512sum", "Core utilities for sha2" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online guide is present at the following online portal: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  /* Don't output this reminder for English locales.
     Note we still output for 'C' so that it gets included in the read me page.  */
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      /* TRANSLATORS: replace the lang_code with your code,
          <https://translationcommunityproject.org/team/LANG_CODE.html>, 
          which can be found at https://translationproject.org/team/. Alternatively, 
          replace the URL completely with your local language support email group.  */
      fputs (_("Notify all sort of language support errors at "
               "<https://translationproject.org/team/>\n"), stdout);
    }

char const *url_program = STREQ (program, "[") ? "alpha_testing" : program;
  printf (_("Comprehensive documentation <href="%s%s">\n"), 
          PACKAGE_URL, url_program);
  printf (_("Also on local servers available in info, in the following pattern: '(coreutils) %s%s'\n"), 
          node, node == program ? " run_helper" : "");
}