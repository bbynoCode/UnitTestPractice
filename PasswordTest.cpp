/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, double_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, no_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, ten_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zzzzzzzzzz");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, no_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zzzzzz");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, yes_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zZ");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, yes_mixed_case_long)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zZZZzzzzZ");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, empty_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, 1_letter_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("z");
	ASSERT_FALSE(actual);
}