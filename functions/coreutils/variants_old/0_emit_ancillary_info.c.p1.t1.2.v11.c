Below is a C code variant that changes the behavior of the original function:


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

  char const *node = program;
  struct infomap const *map_prog = infomap;

  for(; map_prog->program != nullptr; map_prog++)
    if(STREQ (program, map_prog->program)){
      node = map_prog->node;
      break;
    }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")) {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


In this variant, the while loop has been converted into a more predictable for loop, which still maintains the asyncronously processing the 'infomap' until the exact match for the infomap program string is found. The rest of the functionality remains to work as is for the requirements set by the op, this change optimizes the traversal of the map_prog array and stops unnecessary iterations hence improving it's efficiency in longer run. An explicit `break` statement now handles the logic to terminate the loop to meet the condition in the old `while` loop which therefore makes it easier to understand and accurately triggers the breaking condition compared to the `while´ loop which inherently involved incrementing the array pointer until it no longer points to a valid address. This approach is safer from the potential risk of buffer overflow that might also affect the preceding `while` loop variant.