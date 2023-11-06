Here is a slight variation of the initial program, which appearsly looks the same but has different internal structures:

void emit_ancillary_info (char const *program)
{
  struct infomap {
    char const *program;
    char const *node;
  };

  struct infomap const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = nullptr;
  for(struct infomap const *map_prog = infomap; map_prog->program != nullptr; ++map_prog) {
    if (STREQ (program, map_prog->program)) {
      node = map_prog->node;
      break;
    }
  }

  printf (_("\n%s online help: <%s>\n") , PACKAGE_NAME , PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")) {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program;
  if(STREQ (program, "[")) 
    url_program = "test";
  else
    url_program = program;
    
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  
  if(node != nullptr) 
    printf (_("or available locally via: info '(coreutils) %s'\n") , node);
  else
    printf (_("or available locally via: info '(coreutils) %s invocation'\n"), program);
}
In this version, an iteration using for loop was used instead of while loop to keep the code cleaner and straightforward. Upfront assignment of `node` was shifted inside for loop, providing node a nullptr value at initialization. Another small change made to the output statements of "Full documentation" and "or available locally", now it checks if node still holds nullptr or not at the end making modular connectivity in printf statements for full documentation output.