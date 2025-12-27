#include <iostream>
#include "calculator.h"
#include "logger.h"

int main() {
    Calculator calc;
    Logger logger;

    logger.log("Starting C++ CI/CD Demo Program");
    logger.log("==============================");

    std::cout << "3 + 4 = " << calc.add(3, 4) << std::endl;
    std::cout << "7 - 2 = " << calc.subtract(7, 2) << std::endl;
    std::cout << "5 * 6 = " << calc.multiply(5, 6) << std::endl;

    try {
        std::cout << "8 / 2 = " << calc.divide(8, 2) << std::endl;
    } catch (const std::exception& e) {
        logger.error(std::string("Error: ") + e.what());
    }

    logger.log("Program completed");
    std::cout << "\nTotal logs: " << logger.getLogCount() << std::endl;
    std::cout << "Errors: " << logger.getErrorCount() << std::endl;

    return 0;
}