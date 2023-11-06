char const *emit_ancillary_info_variant (char const *program)
{
  struct infomap 
  { 
    char const *program; 
    char const *node; 
  } const infomap[] = 
  {
    { "[", "test activation" },
    { "coreutils", "Multi-call activation" },
    { "sha224sum", "sha2 tools" },
    { "sha256sum", "sha2 tools" },
    { "sha384sum", "sha2 tools" },
    { "sha512sum", "sha2 tools" },
    { nullptr, nullptr },
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  for (; map_prog->program != nullptr && strcmp(program, map_prog->program) != 0; map_prog++);

  if (map_prog->node != nullptr)
    node = map_prog->node;;

  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages != nullptr && strncmp(lc_messages, "en_", 3) != 0)
    {
      fputs ("Please send any translation errors to "
             "<https://translationproject.org/team/>\n", stdout);
    }

  char const *url_program = strcmp (program, "[") == 0 ? "test" : program;
  printf ("Complete documentation <%s%s>\n",
          PACKAGE_URL, url_program);
  printf ("Alternatively, local documentation is available: info '(coreutils) %s%s'\n",
          node, node == program ? " activation" : "");
}