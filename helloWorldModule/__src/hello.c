// In all C files, include its corresponding header file in the very first line.
// No need to include <Python.h> as we did that already in the header file.
// Just make sure that <Python.h> is included BEFORE any other header file.
#include "hello.h"


// Our function implementation
PyObject* hello(PyObject *self, PyObject *args) {
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name)) {
        return NULL;
    }

    printf("Hello, %s!\n", name);
    
    return PyLong_FromLong(42);
}

// Our function implementation
// Our modified function implementation to accept two lists
PyObject* hello2(PyObject *self, PyObject *args) {
    PyObject *list1;
    PyObject *list2;

    // Parse the input arguments, expecting two lists of integers
    if (!PyArg_ParseTuple(args, "OO", &list1, &list2)) {
        return NULL;
    }

    // Check if the input is a list
    if (!PyList_Check(list1) || !PyList_Check(list2)) {
        PyErr_SetString(PyExc_TypeError, "Both inputs must be lists");
        return NULL;
    }

    // Function logic for the first list
    Py_ssize_t size1 = PyList_Size(list1);
    for (Py_ssize_t i = 0; i < size1; ++i) {
        PyObject *item = PyList_GetItem(list1, i);
        if (!PyLong_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "List elements must be integers");
            return NULL;
        }
        long value = PyLong_AsLong(item);
        printf("Hello from list1, %ld!\n", value);
    }

    // Function logic for the second list
    Py_ssize_t size2 = PyList_Size(list2);
    for (Py_ssize_t i = 0; i < size2; ++i) {
        PyObject *item = PyList_GetItem(list2, i);
        if (!PyLong_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "List elements must be integers");
            return NULL;
        }
        long value = PyLong_AsLong(item);
        printf("Hello from list2, %ld!\n", value);
    }

    return PyLong_FromLong(42);
}
