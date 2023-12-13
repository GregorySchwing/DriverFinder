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
PyObject* hello2(PyObject *self, PyObject *args) {
    PyObject *int_list;

    // Parse the input arguments, expecting a list of integers
    if (!PyArg_ParseTuple(args, "O", &int_list)) {
        return NULL;
    }

    // Check if the input is a list
    if (!PyList_Check(int_list)) {
        PyErr_SetString(PyExc_TypeError, "Input must be a list");
        return NULL;
    }

    // Get the length of the list
    Py_ssize_t list_size = PyList_Size(int_list);

    // Iterate through the list and print each integer
    for (Py_ssize_t i = 0; i < list_size; ++i) {
        PyObject *item = PyList_GetItem(int_list, i);

        // Check if each item is an integer
        if (!PyLong_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "List elements must be integers");
            return NULL;
        }

        // Convert the integer object to a C long
        long value = PyLong_AsLong(item);

        // Print the integer
        printf("Hello, %ld!\n", value);
    }

    return PyLong_FromLong(42);
}