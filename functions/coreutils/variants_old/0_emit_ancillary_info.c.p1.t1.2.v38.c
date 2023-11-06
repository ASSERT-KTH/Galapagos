Here's an alternative variant of the function, the logic and original functionality is maintained but changes have been made in the usage of pointers and array for accessing the ancillary data. The if-check comparing the program name with "[" program have also been optimized using conditional programming (`program = STREQ(program, "[") ? "test" : program;`) to reduce code redundancy and keep it more compact.


emit_ancillary_info (char const *program)
{
  char const *node;
  char const * infomap[7][2]={
    { "[",         "test invocation"           },
    { "coreutils",   "Multi-call invocation"  },
    { "sha224sum",   "sha2 utilities"         },
    { "sha256sum",   "sha2 utilities"         },
    { "sha384sum",   "sha2 utilities"         },
    { "sha512sum",   "sha2 utilities"         },
    { nullptr,     nullptr                   }
  };
  
  node = program;
  int program_index = 0;

  while (infomap[program_index][0] && ! STREQ (program, infomap[program_index][0]))
  {
     program_index++;
  }

  if (infomap[program_index][1]){
    node = infomap[program_index][1];
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}
