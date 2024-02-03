#include "ai.h"

#include <stdlib.h>
#include <string>

#include <iostream>

int main() {
    AI ai;
    // TODO: call menu function
    // If user wants to speak to the ai, use this try catch
    try {
        ai.response();
    }
    catch (std::exception& e) {
        // this means the conversation broke
        std::cout << e.what() << std::endl;
    }
    return 0;
}
