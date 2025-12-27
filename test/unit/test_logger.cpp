#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "logger.h"

// 重定向 cout 和 cerr 以捕获输出
class LoggerTest : public ::testing::Test {
protected:
    Logger logger;
    
    // 保存原始的缓冲区
    std::streambuf* cout_buf{};
    std::streambuf* cerr_buf{};
    std::stringstream test_cout;
    std::stringstream test_cerr;
    
    void SetUp() override {
        // 重定向 cout 到 string stream
        cout_buf = std::cout.rdbuf();
        std::cout.rdbuf(test_cout.rdbuf());
        
        // 重定向 cerr 到 string stream
        cerr_buf = std::cerr.rdbuf();
        std::cerr.rdbuf(test_cerr.rdbuf());
    }
    
    void TearDown() override {
        // 恢复原始的缓冲区
        std::cout.rdbuf(cout_buf);
        std::cerr.rdbuf(cerr_buf);
    }
};

TEST_F(LoggerTest, LogMessage) {
    logger.log("Test message");
    
    // 检查输出
    std::string output = test_cout.str();
    EXPECT_NE(output.find("[LOG] Test message"), std::string::npos);
    
    // 检查计数
    EXPECT_EQ(logger.getLogCount(), 1);
    EXPECT_EQ(logger.getErrorCount(), 0);
}

TEST_F(LoggerTest, ErrorMessage) {
    logger.error("Error occurred");
    
    // 检查错误输出
    std::string output = test_cerr.str();
    EXPECT_NE(output.find("[ERROR] Error occurred"), std::string::npos);
    
    // 检查计数
    EXPECT_EQ(logger.getLogCount(), 1);
    EXPECT_EQ(logger.getErrorCount(), 1);
}

TEST_F(LoggerTest, WarnMessage) {
    logger.warn("Warning message");
    
    std::string output = test_cout.str();
    EXPECT_NE(output.find("[WARN] Warning message"), std::string::npos);
    EXPECT_EQ(logger.getLogCount(), 1);
}

TEST_F(LoggerTest, MultipleLogs) {
    logger.log("First");
    logger.warn("Second");
    logger.error("Third");
    
    EXPECT_EQ(logger.getLogCount(), 3);
    EXPECT_EQ(logger.getErrorCount(), 1);
}