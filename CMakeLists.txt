cmake_minimum_required(VERSION 3.10)
project(cicd_practice)
set(CMAKE_CXX_STANDARD 20)

# ==================== 主程序 ====================
add_executable(cicd_practice src/main.cpp
        src/calculator.cpp
        src/logger.cpp
)
# private用于头文件目录只对这个目标自己编译时有效，其他目标看不到这个包含目录
# public 用于这个目标编译时需要，依赖这个目标的其他目标也需要,会传递给依赖它的其他目标
target_include_directories(cicd_practice PRIVATE include)


# ==================== Google Test ====================
# 配置 Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)


# ==================== 测试1：单元测试 ====================
# 单元测试可执行文件（包含所有单元测试）
add_executable(test_calculator
        test/unit/test_calculator.cpp
        src/calculator.cpp
)
target_include_directories(test_calculator PRIVATE include)
target_link_libraries(test_calculator
    PRIVATE
    GTest::gtest_main
)

# ==================== 测试2：单元测试 ====================
# 单元测试可执行文件（包含所有单元测试）
add_executable(test_logger
        test/unit/test_logger.cpp
        src/logger.cpp
)
target_include_directories(test_logger PRIVATE include)
target_link_libraries(test_logger
        PRIVATE
        GTest::gtest_main
)

# ==================== 测试3：集成测试 ====================
# 集成测试可执行文件
add_executable(integration_tests
    test/integration/test_combined.cpp
    src/calculator.cpp    # 需要链接产品代码
    src/logger.cpp        # 需要链接产品代码
)
target_include_directories(integration_tests PRIVATE include)
target_link_libraries(integration_tests PRIVATE GTest::gtest_main)
# 自动发现集成测试中的所有测试用例
gtest_discover_tests(integration_tests
    TEST_PREFIX "Integration_"
    PROPERTIES LABELS "integration"
)