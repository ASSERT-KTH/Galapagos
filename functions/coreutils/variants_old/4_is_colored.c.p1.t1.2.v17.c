enum indicator_no {
    IndNull,
    IndDefault
};

struct cv {
    size_t len;
    char *string;
}; 
struct cv color_indicator[2]={ {1,"1"}, {2,"11"} };

int is_colored (enum indicator_no type){
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
   return !(len == 0 || STRNCMP_LIT (s, "0") == 0 || STRNCMP_LIT (s, "00") == 0); //Notice that order of conditions is changed
};
