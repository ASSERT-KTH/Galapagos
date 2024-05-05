static PyObject* pycsp_cmp_clock_set(PyObject *self, PyObject *args) {
    uint8_t node;
    uint32_t sec;
    uint32_t nsec;
    uint32_t timeout = 1000;
    if (!PyArg_ParseTuple(args, "bII|I", &node, &sec, &nsec, &timeout)) {
        Py_RETURN_NONE;
    }

    if (sec == 0) {
        return PyErr_Error("csp_cmp_clock(set) - seconds are 0", CSP_ERR_INVAL);
    }

    struct csp_cmp_message msg;
    memset(&msg, 0, sizeof(msg));
    msg.clock.tv_sec = csp_hton32(sec);
    msg.clock.tv_nsec = csp_hton32(nsec);

    int res;
    Py_BEGIN_ALLOW_THREADS;
    res = csp_cmp_clock(node, timeout, &msg);
    Py_END_ALLOW_THREADS;
    if (res != CSP_ERR_NONE) {
        return PyErr_Error("csp_cmp_clock(set)", res);
    }

    Py_RETURN_NONE;
}