void emit_ancillary_info (char const *program)
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
  
  char const *node = nullptr;
  struct infomap const *map_prog = infomap;
  
  while (map_prog->program){
    if(STREQ(program, map_prog->program)){
      node = map_prog->node;
      break;
    }
    map_prog++;
  }

  if (!node) node = program;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")){
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program=is_same_str(program, "[")? "test()" : program;
  printf (_("Full docs at <%s%s>\n"), PACKAGE_URL, url_program);
  if(map_prog->program)
    printf (_("or available locally via: info '(coreutils) %s%s'\n"), node == program ? program : node, 
                             node == program ? " invocation" : "");
  else 
    printf (_("Local documentation not currently available.\n"));
}
This program variant maintains the same functionality. The main changes have been underlying assumptions and checks to ensure node very reliably. Also, the message displayed has been modified slightly, reporting if local documentation isn't available instead of attempting an invalid invocation.