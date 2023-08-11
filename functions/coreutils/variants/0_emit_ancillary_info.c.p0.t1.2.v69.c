1) Replace the putchar with fputc function to output characters one at a time instead of using fputs which outputs an entire string:
    

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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      char const *msg = _("Report any translation bugs to "
                     "<https://translationproject.org/team/>\n");
      int a = 0;
      while(msg[a] != '\0'){
        fputc (msg[a], stdout);
        a++;
      }
    }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}

   
2) Instead of using the ternary operator, apply an if-else statement(s).  


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

  while (map_prog->program && ! STREQ (program, map_prog->program)){
    map_prog++;
  }
  if (map_prog->node){
    node = map_prog->node;
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
 if (lc_messages){ 
      if(STRNCMP_LIT (lc_messages, "en_")){   
        fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
        }
    }

  char const *url_program = program;
 if(STREQ (program, "[")){
    url_program= "test";
 }
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
 if(node==program){
  printf (_("or available locally via: info '(coreutils) %s invocation'\n"), node);
 } else{
  printf (_("or available locally via: info '(coreutils) %s'\n"), node);
 }
}
