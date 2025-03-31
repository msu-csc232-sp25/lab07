/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    task2_test.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Task 2 test fixture.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 2025 James R. Daehn
 */

#include "csc232_test_utils.h"
#include "safe.h"
#include <gtest/gtest.h>

namespace csc232
{
    class Task2TestFixture : public CSC232BaseTestFixture
    {
    public:
        Task2TestFixture( ) = default;

        ~Task2TestFixture( ) override = default;

    protected:
        // Reusable objects for each unit test in this test fixture
    };

#if !TEST_TASK2
    TEST_F( Task2TestFixture, Bootstrap )
    {
        std::cerr << "Task 2 is not ready for evaluation; please toggle the TEST_TASK2 macro to TRUE\n";
        SUCCEED( ); // Just to keep spirits up out of the box ;-)
    }

#else
    // TODO: Add unit tests as needed for task 2
    static const int ITEM{ 420 };

    TEST_F( Task2TestFixture, ItCanOpenAndStoreItemWithValidPassCode )
    {
        auto safe_ptr = std::make_unique<csc232::Safe<int>>( );
        EXPECT_TRUE( safe_ptr->open_and_store( "0000", ITEM ) );
    }
    TEST_F( Task2TestFixture, ItCannotOpenAndStoreItemWithInvalidPassCode )
    {
        auto safe_ptr = std::make_unique<csc232::Safe<int>>( );
        EXPECT_FALSE( safe_ptr->open_and_store( "wrong code", ITEM ) );
    }

    TEST_F( Task2TestFixture, ItCanChangePassCodeWithCorrectCredentials )
    {
        auto safe_ptr = std::make_unique<csc232::Safe<int>>( );
        EXPECT_TRUE( safe_ptr->change_pass_code( "0000", "1111" ) );
    }

    TEST_F( Task2TestFixture, ItCannotChangePassCodeWithIncorrectCredentials )
    {
        auto safe_ptr = std::make_unique<csc232::Safe<int>>( );
        EXPECT_FALSE( safe_ptr->change_pass_code( "1111", "0000" ) );
    }

    TEST_F( Task2TestFixture, ItCanRemoveItemWithValidPassCode )
    {
        auto safe_ptr = std::make_unique<csc232::Safe<int>>( );
        safe_ptr->open_and_store( "0000", ITEM );
        auto expected{ ITEM };
        auto actual{ safe_ptr->remove_item( "0000" ) };
        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task2TestFixture, ItCannotOpenRemoveItemWithInvalidPassCodeAndThrowsLogicError )
    {
        auto safe_ptr = std::make_unique<csc232::Safe<int>>( );
        EXPECT_THROW( safe_ptr->remove_item( "bad code" ), std::logic_error );
    }
#endif

} // end namespace csc232
