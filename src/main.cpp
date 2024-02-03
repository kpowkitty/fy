#include "ai.h"

#include <stdlib.h>
#include <string>
#include <iostream>

int main() {
    AI ai;
    // TODO: call menu function
    std::cout << “Hi, welcome to your financial helper! Please choose a prompt to get started.” << std::endl;
    //prompts
    std::cout << “1 : enter prompt here.” << std::endl;

    bool exit = false;
    int choice = 0;
    std::cin >> choice;

    while (!exit) {
        if(choice == 0) {
	    std::cout << “Prompt was not chosen.” << std::endl;
        }
        else if(choice == 1) {
    	    try {
                ai.response();
    	    }
    	    catch (std::exception& e) {
                // this means the conversation broke
                std::cout << e.what() << std::endl;
    	    }
        }
	std::str continue = “”;
	std::cout << “Would you like to continue using the menu? (y/n)” << std::endl;
	std::cin >> continue;
        if(continue == “n”)
        {
            exit = True;
        }
        else if (continue != “y”)
        {
	    std::cout << “Your input was invalid. The menu will reappear.” << std::endl;
        }
    }
    std::cout << “Thanks for using our financial helper!” << std::endl;
    return 0;
}
