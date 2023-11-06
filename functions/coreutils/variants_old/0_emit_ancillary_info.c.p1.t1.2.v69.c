Below is a variant of the program that preserves the essential functionality but changes how it operates. This variant does its search through the infomap array using a traditional for loop instead of a while loop:


void emit_ancillary_info(char const *program)
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

      size_t infomap_len = sizeof(infomap) / sizeof(infomap[0]);
      struct infomap const *map_prog = NULL;

      for(size_t i = 0; i < infomap_len; i++) {
        if (!infomap[i].program || STREQ (program, infomap[i].program)){
          map_prog = &infomap[i];
          break; 
        }
      }

      if (map_prog && map_prog->node)
        node = map_prog->node;

      printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

      char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
      if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
        fputs (_("Report any translation bugs to "
                   "<https://translationproject.org/team/>\n"), stdout);
  
      char const *url_program = STREQ (program, "[") ? "test" : program;
      printf (_("Full documentation <%s%s>\n"),
              PACKAGE_URL, url_program);
      printf (_("or available locally via: info '(coreutils) %s%s'\n"),
              node, node == program ? " invocation" : "");
  }

This version still locates, the program in the infomap array if it exists, and continues operations as usual. By calculating the length of the infomap array using sizeof(), and iterating it with a regulated for loop, the search operation is achieved a bit differently than the initial implementation while maintaining the original functionality.