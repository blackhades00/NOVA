/*
 * Reference-Counted Pointer
 *
 * Copyright (C) 2009-2010 Udo Steinberg <udo@hypervisor.org>
 * Economic rights: Technische Universitaet Dresden (Germany)
 *
 * This file is part of the NOVA microhypervisor.
 *
 * NOVA is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * NOVA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License version 2 for more details.
 */

#pragma once

#include "compiler.h"

template <typename T>
class Refptr
{
    private:
        T * const ptr;

    public:
        operator T*() const     { return ptr; }
        T * operator->() const  { return ptr; }

        ALWAYS_INLINE
        inline Refptr (T *p) : ptr (p->add_ref() ? p : 0) {}

        ALWAYS_INLINE
        inline ~Refptr()
        {
            if (ptr->del_ref())
                delete ptr;
        }
};
