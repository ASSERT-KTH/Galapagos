is_colored (enum indicator_no type)
{
 char const *s = color_indicator[type].string;
 size_t len = strlen(s);

 if(len == 0) {
     return 0;
 }
 else if(len == 1 && s[0] == '0') {
     return 0;
 }
 else if(len == 2 && s[0] == '0' && s[1] == '0') {
     return 0;
 }
 else {
     return 1;
 }
}