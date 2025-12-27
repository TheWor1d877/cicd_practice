#include <gtest/gtest.h>
#include "calculator.h"
#include "logger.h"

// 集成测试：测试 Calculator 和 Logger 一起工作
class IntegrationTest : public ::testing::Test {
protected:
    Calculator calc;
    Logger logger;
};

TEST_F(IntegrationTest, CalculatorWithLogging) {
    int result = calc.add(2, 3);
    logger.log("Added 2 + 3 = " + std::to_string(result));

    EXPECT_EQ(result, 5);
    EXPECT_EQ(logger.getLogCount(), 1);
}

TEST_F(IntegrationTest, ErrorHandlingWithLogging) {
    try {
        calc.divide(5, 0);
        FAIL() << "Expected exception";
    } catch (const std::runtime_error& e) {
        logger.error(std::string("Division error: ") + e.what());
        EXPECT_STREQ(e.what(), "Division by zero");
    }

    EXPECT_EQ(logger.getErrorCount(), 1);
}