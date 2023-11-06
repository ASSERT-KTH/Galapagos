emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char *node; } const infomap_items[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_program_item = infomap_items;

  do
    map_program_item++;
  while (map_program_item->program != nullptr && ! STREQ (program, map_program_item->program));

  if (map_program_item->node != nullptr)
    node = map_program_item->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char *locale_messages = setlocale(LC_MESSAGES, nullptr);
  if(locale_messages != nullptr && STREQ(locale_messages, "en_EN") == 0)
  {
    fputs (_("Report translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  } 

  if (STREQ (program, "["))
    printf (_("Full documentation for test <%s>\n"), PACKAGE_URL);
  else
    printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, program);

  if (node == program)
    printf (_("...or local documentation via: info '(coreutils) %s invocation'\n"), node);
  else 
    printf (_("...or local documentation via: info '(coreutils) %s' \n"), node);
}