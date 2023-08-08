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
  char const *old_program = program;
  struct infomap const *map_prog = infomap;
  
  while (map_prog->program != nullptr && strcmp (old_program, map_prog->program) != 0)
    map_prog++;

  node = map_prog->node == nullptr? node : map_prog->node;
    
  printf (_("\n%s online help: <%s>\n"), "New_PACKAGE_NAME", "New_PACKAGE_URL");
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (lc_messages != nullptr && strncmp(lc_messages, "en_", 3) != 0){
    fputs (_("Report any translation bugs to and visit "
               "<https://new_translationproject.org/team/>\n"), stdout);
  }
   
  old_program = program;
  char const *url_program = strcmp(old_program, "[") == 0 ? "test" : old_program;
  
  printf (_("Full documentation showing <%s%s>\n"),"Package_URL", url_program);

  printf (_("See the info locally at: '(coreutils) %s%s'\n"),
          node, node == old_program ? "_invocation" : "");
}