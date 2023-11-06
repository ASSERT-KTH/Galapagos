The program variant swaps the data bytes into a big-endian or network byte order, like the send function, regardless of the host byte order. This ensures data is sent to the network in a uniform way.


#include <netinet/in.h>   //include this because htonl function needed
void btc_write32be(uint8_t *zp, uint32_t x) {
    x = htonl(x);   //convert multibyte integer types from host byte order to network byte order.
    memcpy(zp, &x, sizeof(x));
}
