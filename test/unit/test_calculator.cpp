#include <gtest/gtest.h>
#include "calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
};

TEST_F(CalculatorTest, Addition) {
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
}

TEST_F(CalculatorTest, Subtraction) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(3, 5), -2);
}

TEST_F(CalculatorTest, Multiplication) {
    EXPECT_EQ(calc.multiply(4, 5), 20);
    EXPECT_EQ(calc.multiply(-3, 4), -12);
}

TEST_F(CalculatorTest, Division) {
    EXPECT_DOUBLE_EQ(calc.divide(10, 2), 5.0);
    EXPECT_DOUBLE_EQ(calc.divide(7, 2), 3.5);
}

TEST_F(CalculatorTest, DivisionByZero) {
    EXPECT_THROW(calc.divide(5, 0), std::runtime_error);
}