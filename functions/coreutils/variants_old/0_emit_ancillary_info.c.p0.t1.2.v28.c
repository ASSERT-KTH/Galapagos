1.

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

  do{
    map_prog++;
  }while(map_prog->program && strcmp (program, map_prog->program));

  node = map_prog->node ? map_prog->node : node;

  printf (_("\n%s online support: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (!(lc_messages && strncmp (lc_messages, "en_",3)))
  {
    fputs (_("Report translation errors to "
    "<https://translationproject.org/team/>\n"), stdout);

  }
  
  char const *url_program = (program[0] == '[') ? "test" : program;
  printf (_("Extensive documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("in local repository as: info '(coreutils) %s%s'\n"),
          node, node == program ? " execution" : "");
}

2.

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "sample implementation" },
    { "coreutils", "Multi-call execution" },
    { "sha224sum", "sha2 tools" },
    { "sha256sum", "sha2 tools" },
    { "sha384sum", "sha2 tools" },
    { "sha512sum", "sha2 tools" },
    { nullptr, nullptr }
  };

  char const *node = program;

  int i=0; 
  while (infomap[i].program && strcmp(program, infomap[i].program)){
    i++;  
  }

  node = infomap[i].node ? infomap[i].node : program;


  printf (_("\n%s online helps at <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && strncmp(lc_messages, "en_",3)){
    fputs (_("Report translation issues to "
        "<https://translationproject.org/team/>\n"), stdout);

  }
  
  char const *url_program = (!strcmp(program, "[")) ? "tes" : program;
  printf (_("Complete documentation at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or locally available in: info '(coreutils) %s%s'\n"),
          node, node == program ? " command" : "");
}
