static PyObject* pycsp_cmp_peek(PyObject *self, PyObject *args) {
    uint8_t node;
    uint32_t timeout;
    uint32_t addr;
    uint8_t len;
    Py_buffer outbuf;
    if (!PyArg_ParseTuple(args, "biIbw*", &node, &timeout, &addr, &len, &outbuf)) {
        Py_RETURN_NONE;
    }

    if ((len > CSP_CMP_PEEK_MAX_LEN) || (len > outbuf.len)) {
        return PyErr_Error("csp_cmp_peek() - exceeding max size", CSP_ERR_INVAL);
    }

    struct csp_cmp_message msg;
    memset(&msg, 0, sizeof(msg));
    msg.peek.addr = csp_hton32(addr);
    msg.peek.len = len;

    int res;
    Py_BEGIN_ALLOW_THREADS;
    res = csp_cmp_peek(node, timeout, &msg);
    Py_END_ALLOW_THREADS;
    if (res != CSP_ERR_NONE) {
        return PyErr_Error("csp_cmp_peek()", res);
    }
    memcpy(outbuf.buf, msg.peek.data, len);
    outbuf.len = len;

    Py_RETURN_NONE;
}