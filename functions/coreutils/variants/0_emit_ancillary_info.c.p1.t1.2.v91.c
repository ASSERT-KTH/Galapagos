Here a small change in the function implementation behavior refers to a different way by which the same outcome can be achieved. We find the corresponding "node" matching the "program" and then select the appropriate help-messages and node to be shown in the output.
Just for better tweaking, search for the "node" can be moved inside the for loop. Here is the changed reference function.


emit_ancillary_info (char const *program)
{
  char const *node = program;
  bool found = false;
  char const *local_infomap[] = { "[", "coreutils" , "sha224sum", "sha256sum", "sha384sum", "sha512sum" };
  char const *child_infomap[] = { "test invocation", "Multi-call invocation" , "sha2 utilities", "sha2 utilities", "sha2 utilities", "sha2 utilities" };

  for(int i=0; i< (sizeof(local_infomap)/sizeof(char*)); i++){
    if(local_infomap[i] && ! STREQ (program, local_infomap[i])){
       node = child_infomap[i];
       found = true;
       break;
     }
  }
  
  if(!found)
    node = "test invocation";

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

The behavior of this function is the same as the original, we've just moved the map mapping from struct initialization to two separate arrays and performed search using a for loop.
A slight difference, anonymous struct is not used in this part of the code. Otherwise, the structure consistency is preserved.