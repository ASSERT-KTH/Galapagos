void emit_ancillary_info (char const *program)
{
    char const *ancillary_info_map[] = {
      "[", "test invocation", 
      "coreutils", "Multi-call invocation", 
      "sha224sum", "sha2 utilities", 
      "sha256sum", "sha2 utilities", 
      "sha384sum", "sha2 utilities", 
      "sha512sum", "sha2 utilities",
      nullptr, nullptr
    };
    
    char const *node = program;
    for (int i = 0; ancillary_info_map[i]; i += 2) {
      if (strcmp(program, ancillary_info_map[i])==0) {
        node = ancillary_info_map[i+1];
        break;
      }
    }

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
    
    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && strncmp(lc_messages, "en_", 3) != 0) {
        fputs (_("Report any translation bugs to "
                    "<https://translationproject.org/team/>\n"), stdout);
    }

    char const *url_program;
    if (strcmp(program, "[") == 0) {
        url_program = "test";
    } else {
        url_program = program;
    }
    printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
    printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, strcmp(node, program) == 0 ? " invocation" : "");
}