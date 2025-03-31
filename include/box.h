/**
 * @file box.h
 */

#ifndef CSC232_BOX_H_
#define CSC232_BOX_H_

namespace csc232
{
    template <typename T>
    class Box
    {
    public:
        /**
         * @brief Box mutator method used to add an item to this Box.
         * @param an_item the item to add to this Box
         * @post the given item is the current item in this Box
         */
        virtual void set_item( const T &an_item ) = 0;

        /**
         * @brief Box accessor method used to obtain a copy of the item in this Box.
         * @return the item currently stored in this Box.
         */
        virtual auto get_item( ) const -> T = 0;

        /**
         * @brief Virtual default destructor.
         */
        virtual ~Box( ) = default;
    };
}

#endif
