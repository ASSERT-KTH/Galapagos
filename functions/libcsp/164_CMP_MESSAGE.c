CMP_MESSAGE(CSP_CMP_IDENT, ident)
CMP_MESSAGE(CSP_CMP_ROUTE_SET, route_set)
CMP_MESSAGE(CSP_CMP_IF_STATS, if_stats)
CMP_MESSAGE(CSP_CMP_CLOCK, clock)

/**
   Peek (read) memory on remote node.
   @param[in] node address of subsystem.
   @param[in] timeout timeout in mS to wait for reply..
   @param[in] msg memory address and number of bytes to peek.
   @param[out] msg peeked/read memory.
   @return #CSP_ERR_NONE on success, otherwise an error code.
*/
static inline int csp_cmp_peek(uint8_t node, uint32_t timeout, struct csp_cmp_message *msg) {
    return csp_cmp(node, timeout, CSP_CMP_PEEK, CMP_SIZE(peek) - sizeof(msg->peek.data) + msg->peek.len, msg);
}