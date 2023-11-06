Variant 1:

void emit_ancillary_info (char const *program)
{
  struct { char const *program; char const *node; } const mapping[] = {
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *mapping_pointer = mapping;

  while (mapping_pointer->program && ! STREQ (program, mapping_pointer->program))
    mapping_pointer++;

  if (mapping_pointer->node)
    node = mapping_pointer->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *locale_str = setlocale (LC_MESSAGES, nullptr);
  if (locale_str && STRNCMP_LIT (locale_str, "en_"))
    fputs (_("Report any translation bugs to <https://translationproject.org/team/>\n"), stdout);

  char const *url_text = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_text);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}

Variant 2:

void emit_ancillary_info (char const *program)
{
  struct what_prog { char const *program; char const *node; } const another_mapping[] = {
    { "sha256sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "[", "test invocation" },
    { "sha384sum", "sha2 utilities" },
    { "sha224sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { nullptr, nullptr }
  };

  char const *node_id = program;
  struct what_prog const *some_pointer = another_mapping;

  while (some_pointer->program && ! STREQ (program, some_pointer->program))
    some_pointer++;

  if (some_pointer->node)
    node_id = some_pointer->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *locale_lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (locale_lc_messages && STRNCMP_LIT (locale_lc_messages, "en_"))
    fputs (_("Report any translation bugs to <https://translationproject.org/team/>\n"), stdout);

  char const *url_resolve = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_resolve);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node_id, node_id == program ? " invocation" : "");
}
