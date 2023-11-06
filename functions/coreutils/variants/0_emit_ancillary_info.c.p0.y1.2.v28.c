void emit_ancillary_info (char const *program)
{
 struct infomap 
 { 
   char const *program; 
   char const *node; 
 } const infomap_data[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { 0, 0 }
  };

  const char *node = program;
  const struct infomap *ptr_infomap_data = infomap_data;

  while (ptr_infomap_data->program && ! STREQ (program, ptr_infomap_data->program))
    ptr_infomap_data++;

  if (ptr_infomap_data->node)
    node = ptr_infomap_data->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lang = setlocale (LC_MESSAGES, 0);
  if (lang && STRNCMP_LIT (lang, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  const char *url_formatter = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_formatter);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}