#include <memory>
#include <iostream>
#include "pimpl.hpp"

struct impl
{
    void call () const
    {
        std::cout << "Hello from impl" << std::endl;;
    }
};

void deleter::operator () (impl *ptr)
{
    std::default_delete<impl>{} (ptr);
}

pimpl::pimpl ()
    : data_ (std::unique_ptr<impl, deleter>()) {}

void pimpl::call ()
{
    data_->call ();
}

/* Fast pimpl idiom.  */

fast_pimpl::fast_pimpl ()
{
    data_ = new (&storage_) impl ();
}

fast_pimpl::~fast_pimpl ()
{
    data_->~impl ();
}

void fast_pimpl::call ()
{
    data_->call ();
}

