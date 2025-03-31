/**
 * @file plain_box.h
 */

#ifndef CSC232_PLAIN_BOX_H_
#define CSC232_PLAIN_BOX_H_

#include "box.h"

namespace csc232
{
    template <typename T>
    class PlainBox : public Box<T>
    {
    private:
        T item;

    public:
        explicit PlainBox( const T &initial_item = T{ } );
        void set_item( const T &an_item ) override;
        T get_item( ) const override;
    };
}

#endif
