#include "plain_box.h"

namespace csc232
{
    template <typename T>
    PlainBox<T>::PlainBox( const T &an_item ) : item{ an_item }
    {
    }

    template <typename T>
    void PlainBox<T>::set_item( const T &an_item )
    {
        item = an_item;
    }

    template <typename T>
    T PlainBox<T>::get_item( ) const
    {
        return item;
    }
}
