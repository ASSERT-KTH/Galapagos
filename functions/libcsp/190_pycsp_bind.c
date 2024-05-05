static PyObject* pycsp_bind(PyObject *self, PyObject *args) {
    PyObject* socket_capsule;
    uint8_t port;
    if (!PyArg_ParseTuple(args, "Ob", &socket_capsule, &port)) {
        return NULL; // TypeError is thrown
    }

    csp_socket_t * sock = get_obj_as_socket(socket_capsule, false);
    if (sock == NULL) {
        return NULL; // TypeError is thrown
    }

    int res = csp_bind(sock, port);
    if (res != CSP_ERR_NONE) {
        return PyErr_Error("csp_bind()", res);
    }

    Py_RETURN_NONE;
}