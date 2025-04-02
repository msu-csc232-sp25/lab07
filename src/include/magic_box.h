/**
 * @file magic_box.h
 */

#ifndef CSC232_MAGIC_BOX_H_
#define CSC232_MAGIC_BOX_H_

#include "plain_box.h"

namespace csc232
{
    // Task 1a - Declare the MagicBox class below
    template<typename T>
    class MagicBox : public PlainBox<T>
    {
    public:
        MagicBox();
        explicit MagicBox(const T& item);
    };
    
}

#endif
