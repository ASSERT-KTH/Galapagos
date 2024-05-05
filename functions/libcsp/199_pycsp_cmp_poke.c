static PyObject* pycsp_cmp_poke(PyObject *self, PyObject *args) {
    uint8_t node;
    uint32_t timeout;
    uint8_t len;
    uint32_t addr;
    Py_buffer inbuf;

    if (!PyArg_ParseTuple(args, "biIbw*", &node, &timeout, &addr, &len, &inbuf)) {
        Py_RETURN_NONE;
    }

    if (len > CSP_CMP_POKE_MAX_LEN) {
        return PyErr_Error("csp_cmp_poke() - exceeding max size", CSP_ERR_INVAL);
    }
    struct csp_cmp_message msg;
    msg.poke.addr = csp_hton32(addr);
    msg.poke.len = len;
    memcpy(msg.poke.data, inbuf.buf, len);

    int res;
    Py_BEGIN_ALLOW_THREADS;
    res = csp_cmp_poke(node, timeout, &msg);
    Py_END_ALLOW_THREADS;
    if (res != CSP_ERR_NONE) {
        return PyErr_Error("csp_cmp_poke()", res);
    }

    Py_RETURN_NONE;
}