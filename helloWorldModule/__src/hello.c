// In all C files, include its corresponding header file in the very first line.
// No need to include <Python.h> as we did that already in the header file.
// Just make sure that <Python.h> is included BEFORE any other header file.
#include "hello.h"
#include "./MaxMatchingKececioglu/src/driver.h"


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
    Py_ssize_t size2 = PyList_Size(list2);


    // Allocate memory for the integer array
    int* rows = (int*)malloc(size1 * sizeof(int));
    if (rows == NULL) {
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory");
        return NULL;
    }

    // Allocate memory for the integer array
    int* cols = (int*)malloc(size2 * sizeof(int));
    if (cols == NULL) {
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate memory");
        return NULL;
    }

    for (Py_ssize_t i = 0; i < size1; ++i) {
        PyObject *item = PyList_GetItem(list1, i);
        if (!PyLong_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "List elements must be integers");
            return NULL;
        }
        long value = PyLong_AsLong(item);
        rows[i] = PyLong_AsLong(item);
    }

    // Function logic for the second list
    // Convert each element of the list to an integer

    for (Py_ssize_t i = 0; i < size2; ++i) {
        PyObject *item = PyList_GetItem(list2, i);
        if (!PyLong_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "List elements must be integers");
            return NULL;
        }
        long value = PyLong_AsLong(item);
        cols[i] = PyLong_AsLong(item);
    }


    match(rows, cols, rows, size1-1,size1-1,size2);

    return PyLong_FromLong(42);
}
