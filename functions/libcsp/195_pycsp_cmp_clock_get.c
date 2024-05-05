static PyObject* pycsp_cmp_clock_get(PyObject *self, PyObject *args) {
    uint8_t node;
    uint32_t timeout = 1000;
    if (!PyArg_ParseTuple(args, "b|I", &node, &timeout)) {
        Py_RETURN_NONE;
    }

    struct csp_cmp_message msg;
    memset(&msg, 0, sizeof(msg));

    int res;
    Py_BEGIN_ALLOW_THREADS;
    res = csp_cmp_clock(node, timeout, &msg);
    Py_END_ALLOW_THREADS;
    if (res != CSP_ERR_NONE) {
        return PyErr_Error("csp_cmp_clock(get)", res);
    }

    return Py_BuildValue("II",
                         csp_ntoh32(msg.clock.tv_sec),
                         csp_ntoh32(msg.clock.tv_nsec));
}