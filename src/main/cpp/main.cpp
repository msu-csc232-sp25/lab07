/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry-point of the main target.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 202 James R. Daehn
 */

#include "csc232.h"
#include "magic_box.h"
#include "plain_box.h"
#include "safe.h"

auto main( int argc, char *argv[] ) -> int
{
    static const int CODE{ 420 };
    static const int MAGIC_NUMBER{ 47 };
    std::cout << "Hello, Main Target!" << std::endl;
    auto plain_box_ptr = std::make_unique<csc232::PlainBox<int>>( );
    plain_box_ptr->set_item( CODE );
    std::cout << plain_box_ptr->get_item( ) << std::endl;

#if TEST_TASK1
    auto magic_box_ptr = std::make_unique<csc232::MagicBox<int>>( );
    magic_box_ptr->set_item( CODE );
    std::cout << magic_box_ptr->get_item( ) << std::endl;
    std::cout << "Changing the contents of the magic box...\n";
    magic_box_ptr->set_item( MAGIC_NUMBER );
    std::cout << magic_box_ptr->get_item( ) << std::endl;
    std::cout << "How magical! It didn't change...\n";
#endif

#if TEST_TASK2
    auto safe_ptr = std::make_unique<csc232::Safe<int>>( );
    if ( safe_ptr->open_and_store( "0000", CODE ) )
    {
        std::cout << "Opened the safe and stored a number in it!\n";
    }
    else
    {
        std::cout << "I guess I don't know the pass code\n";
    }

    try
    {
        safe_ptr->remove_item( "wrong pass code" );
    }
    catch ( const std::exception &e )
    {
        std::cerr << e.what( ) << '\n';
    }

    try
    {
        auto item = safe_ptr->remove_item( "0000" );
        std::cout << "Opps... let me try again. I just removed " << item << " from the safe!\n";
    }
    catch ( const std::exception &e )
    {
        std::cerr << e.what( ) << "\n";
    }

#endif

    return EXIT_SUCCESS;
}
