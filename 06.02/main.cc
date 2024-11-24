#include <iostream>
#include "pimpl.hpp"

/* pimpl is clearly not cache friendly: access occurs through dynamic
   memory.  The Fast PImpl idiom allows you to make cache data local,
   thereby significantly increasing program performance ('impl' data
   is guaranteed to be stored in the same place as the wrapper).  */
auto main () -> int
{
    pimpl obj;
    obj.call ();

    fast_pimpl obj_fpimpl;
    obj_fpimpl.call ();
}

