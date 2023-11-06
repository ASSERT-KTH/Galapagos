variant 1:

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test execution" },
    { "coreutils", "Single-call execution" },
    { "sha224sum", "sha2 tools" },
    { "sha256sum", "sha2 tools" },
    { "sha384sum", "sha2 tools" },
    { "sha512sum", "sha2 tools" },
    { nullptr,nullptr}
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && STREQ(program, map_prog->program)!=0)
    map_prog++;

  if (map_prog->node!=nullptr)
    node = map_prog->node;

  printf (_("\n%s web-based help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STREQ (lc_messages,"en_")!=0)
    {
      fputs (_("Report issues related to translation to "
               "<https://translationproject.org/group/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "execute" : program;
  printf (_("Complete text <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or obtainable locally through: info '(coreutils) %s%s'\n"),
          node, node == program ? " execution" : "");
}


variant 2:

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test command" },
    { "coreutils", "Dual-call activation" },
    { "sha224sum", "sha2 services" },
    { "sha256sum", "sha2 services" },
    { "sha384sum", "sha2 services" },
    { "sha512sum", "sha2 services" },
    { nullptr,nullptr}
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && STRCMP (program, map_prog->program)!=0)
    map_prog++;

  if (map_prog->node!=nullptr)
    node = map_prog->node;

  printf (_("\n%s help online: <%s>\n"), PACKAGE_TITLE, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRCMP (lc_messages,"en_")!=0)
    {
      fputs (_("Send translation error reports to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "execute-program" : program;
  printf (_("Read full documentation at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or accessible remotely via: info '(coreutils) %s%s'\n"),
          node, node == program ? " command" : "");
}
