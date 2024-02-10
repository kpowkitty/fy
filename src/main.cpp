// where is doxygen style header for start of file?
// refer to STYLE.md for all style errors
#include "ai.h"

#include <stdlib.h>
#include <string>
#include <iostream>

// cpp standard style is prototypes BEFORE main, definitions AFTER main
// naming doesn't follow style guide
// where are doxygen style headers for functions?
void displayMainMenu() {
    // std::endl is an expensive fn, why is this on every line?
    // it should be used to explicitly clear a text buffer, not create a \n
    // also, please align the tabbed couts like this:
    // std::cout << "hi"
    //           << "test"
    //           << "this"
    std::cout << "1. Ask Fy anything" << std::endl
	      << "2. Credit Questions" << std::endl
	      << "3. Govt Aide Questions" << std::endl
	      << "4. College Questions" << std::endl
	      << "5. Exit" << std::endl;
}
// fn not spaced correctly, style guide
void displayCreditSubmenu() {
    std::cout << "1. What is Credit?" << std::endl
	      << "2. Best Starter Credit Cards" << std::endl
	      << "3. What are credit rewards?" << std::endl
	      << "4. How can I avoid debt?" << std::endl
	      << "5. How can I build better credit?" << std::endl
	      << "6. How often should I open credit lines?" << std::endl
	      << "7. Go back to main menu" << std::endl;
}
void displayGovtSubmenu() {
    // unprofessional? govt? that's not acceptable
    std::cout << "1. What California govt aide is out there?" << std::endl
	      << "2. What is SNAP/TANF?" << std::endl
	      << "3. Am I eligible for SNAP/TANF?" << std::endl
	      << "4. Go back to main menu" << std::endl;
}
void displayCollegeSubmenu() {
    std::cout << "1. What are scholarships?" << std::endl
	      << "2. Where can I attend college for free?" << std::endl
	      << "3. What is FAFSA?" << std::endl
	      << "4. How do I know I am eligible for FAFSA" << std::endl
	      << "5. Go back to main menu" << std::endl;
}

int main() {
    AI ai;
    // 80 col? style guide?
    std::cout << "Hi, welcome to your financial helper! Please choose a prompt to get started." << std::endl;
    // passing input as an int? what happens when they don't input an int?
    int choice;

    do {
	displayMainMenu();
	std::cin >> choice;

	switch (choice) {
        // case justified with switch, style guide?
	    case 1:
                // 8 space tab, should be 4?
    	        try {
                    ai.response();
    	        }
    	        catch (std::exception& e) {
                    // this means the conversation broke
                    std::cout << e.what() << std::endl;
    	        }
		break;
	    case 2:
	        do {
	            displayCreditSubmenu();
	            std::cin >> choice;

		    // questions could be stored in array to make printing/inputting
            // easier

	            switch (choice) {
	                case 1:
	                    ai.question("What is Credit?");
	                    break;
	                case 2:
	                    ai.question("Best Starter Credit Cards");
	                    break;
	                case 3:
	                    ai.question("What are credit rewards?");
	                    break;
	                case 4:
	                    ai.question("How can I avoid debt?");
	                    break;
	                case 5:
	                    ai.question("How can I build better credit?");
	                    break;
	                case 6:
	                    ai.question("How often should I open credit lines?");
	                    break;
	                default:
                        // it's only going to say invalid choice if an int is
                        // entered though? if a str is entered, then it's going
                        // to just throw empty
                        // shell lines and the user has no clue what's going on?
	                    std::cout << "Invalid choice. " <<
				      << "Please select a number from 1-7." << std::endl;
	            }
	        } while (choice != 7);
	        break;

	    case 3:
	        do {
	            displayGovtSubmenu();
	            std::cin >> choice;

	            switch (choice) {
	                case 1:
	                    ai.question("What California govt aide is out there?");
	                    break;
	                case 2:
	                    ai.question("What is SNAP/TANF?");
	                    break;
	                case 3:
	                    ai.question("Am I eligible for SNAP/TANF?");
	                    break;
	                default:
	                    std::cout << "Invalid choice. " <<
				      << "Please select a number from 1-4." << std::endl;
	            }
	        } while (choice != 4);
	        break;

	    case 4:
	        do {
	            displayCollegeSubmenu();
	            std::cin >> choice;

	            switch (choice) {
	                case 1:
	                    ai.question("What are scholarships?");
	                    break;
	                case 2:
	                    ai.question("Where can I attend college for free?");
	                    break;
	                case 3:
	                    ai.question("What is FAFSA?");
	                    break;
	                case 4:
	                    ai.question("How do I know I am eligible for FAFSA");
	                    break;
	                default:
	                    std::cout << "Invalid choice. " <<
				      << "Please select a number from 1-5." << std::endl;
	        } while (choice != 5);
	        break;

	    default:
	        std::cout << "Invalid choice. " <<
			  << "Please select a number from 1-5." << std::endl;
	}
    } while (choice != 5);

    // Don't use "our," Fy should be the only one talking
    std::cout << "Thanks for using our financial helper!" << std::endl;
    return 0;
}
