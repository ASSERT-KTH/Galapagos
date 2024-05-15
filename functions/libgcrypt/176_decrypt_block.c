decrypt_block( IDEA_context *c, byte *outbuf, const byte *inbuf )
{
    if( !c->have_dk ) {
       c->have_dk = 1;
       invert_key( c->ek, c->dk );
    }
    cipher( outbuf, inbuf, c->dk );
}