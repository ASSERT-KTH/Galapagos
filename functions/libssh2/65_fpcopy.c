fpcopy( char *output, char *input, int len )
{
char    *is, *os;
int i;

if ( len ){
    for ( is = input, os = output, i = 0; i < len ; ++i, ++is, ++os){
            *os = *is;
    }
    *os = 0;
}else{
    output[0] = 0;
}
}