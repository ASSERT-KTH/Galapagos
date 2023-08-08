Variant 1:

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };
  char const *node = program;
  struct infomap const *map_prog = infomap;
  
  do{
    if(STREQ (program, map_prog->program)){
        node = map_prog->node;
        break;
    }
    map_prog++;
  }while(map_prog->program)
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && !STREQ (lc_messages, "C") && STRSTR (lc_messages, "en_") == nullptr) {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STRQE (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, STREQ(node,program) ? " invocation" : "");
}


Variant 2:

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
  
  int i =0;
  for(; infomap[i].program != nullptr && ! STREQ (program, infomap[i].program); i++);
  char const *node = infomap[i].node ? infomap[i].node: program;
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP (lc_messages, "en_", 3))
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
   
  char const *url_program = program;
  if (STREQ(program, "[")) url_program = "test";
  printf (_("Full documentation at: <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or read locally using this command: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}
