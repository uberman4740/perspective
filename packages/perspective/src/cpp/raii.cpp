/******************************************************************************
 *
 * Copyright (c) 2017, the Perspective Authors.
 *
 * This file is part of the Perspective library, distributed under the terms of
 * the Apache License 2.0.  The full license can be found in the LICENSE file.
 *
 */

#include <perspective/first.h>
#include <perspective/base.h>
#include <perspective/raii.h>
#ifndef WIN32
#include <sys/mman.h>
#endif

namespace perspective
{

#ifdef PSP_ENABLE_PYTHON
t_py_handle::t_py_handle(PyObject* pyo) : m_pyo(pyo)
{
}

t_py_handle::~t_py_handle()
{
    if (m_pyo)
        Py_XDECREF(m_pyo);
}

void
t_py_handle::release()
{
    m_pyo = 0;
}

PyObject*
t_py_handle::get()
{
    return m_pyo;
}

#endif

t_file_handle::t_file_handle(t_handle value) : m_value(value)
{
}

t_handle
t_file_handle::value()
{
    return m_value;
}

t_mmap_handle::t_mmap_handle(void* value, t_uindex len)
    : m_value(value), m_len(len)
{
}

void*
t_mmap_handle::value()
{
    return m_value;
}

t_uindex
t_mmap_handle::len() const
{
    return m_len;
}

} // end namespace perspective
