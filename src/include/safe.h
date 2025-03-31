/**
 * @file safe.h
 */

#ifndef CSC232_SAFE_H_
#define CSC232_SAFE_H_

#include "plain_box.h"
#include <string>

namespace csc232
{
    // TODO: Declare Safe class AS_A PlainBox
    template <typename T>
    class Safe : private PlainBox<T>
    {
    private:
        std::string pass_code_;

    public:
        explicit Safe( const std::string &pass_code = "0000" );
        bool open_and_store( const std::string &pass_code, const T &item );
        bool change_pass_code( const std::string &old_code, const std::string &new_code );
        T remove_item( const std::string &pass_code ) const;
    };
}

#endif
