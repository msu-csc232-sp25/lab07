/**
 * @file safe.cpp
 */

#include "safe.h"
#include <stdexcept>

namespace csc232
{
    // TODO: Task 2b - Define Safe operations
    template<typename T>
    Safe<T>:: Safe(const std::string &pass_code = "0000" ) : pass_code_(pass_code) {}
    
    template<typename T>
    bool Safe<T>::open_and_store( const std::string &pass_code, const T &item )
    {
        if(pass_code == pass_code_){
            this -> set_item(item);
            return true;
        }
        return false;
    }

    template<typename T>
    bool Safe<T>::change_pass_code( const std::string &old_code, const std::string &new_code )
    {
        if(old_code == pass_code_){
            old_code = new_code;
            return true;
        }
        return false;

    }

    template<typename T>
    T Safe<T>::remove_item( const std::string &pass_code ) const
    {
        if(pass_code == pass_code_){
            this->get_item(item);
            return true;
        }
        throw std::logic_error("your passcode is incorrect");
    }
}
