/**
* @project Fy: Your Financial Guide
* @file main.cpp
* @developers @huynhkatrina, @kpowkitty
*/

#include "ai.h"
#include "liboai.h"

#include <stdlib.h>
#include <string>
#include <termios.h>
#include <iostream>
#include <unistd.h>

/**
 * @brief Displays the main menu options.
 */
void display_main_menu();

/**
 * @brief Displays the submenu for credit-related questions.
 */
void display_credit_submenu();

/**
 * @brief Displays the submenu for government aid-related questions.
 */
void display_government_submenu();

/**
 * @brief Displays the submenu for college-related questions.
 */
void display_college_submenu();

/**
 * @brief Displays the submenu for feminine-related questions.
 */
void display_feminine_submenu();

int main() {
    AI ai;
    char choice;
    std::string processing = "Let me think for a moment...\n\n";

    std::cout << "Hi, I'm Fy, your financial helper! "
              << "Please choose a prompt." << std::endl;
    ai.hide_keystrokes();

    do {
        display_main_menu();
        choice = getchar();
        try {
            switch (choice) {
            case '1':
                char credit_choice;
                do {
                    display_credit_submenu();
                    credit_choice = getchar();
                    try {
                        switch (credit_choice) {
                            case '1':
                                std::cout << processing;
                                ai.question("What is Credit?");
                                break;
                            case '2':
                                std::cout << processing;
                                ai.question("Best Starter Credit Cards");
                                break;
                            case '3':
                                std::cout << processing;
                                ai.question("What are credit rewards?");
                                break;
                            case '4':
                                std::cout << processing;
                                ai.question("How can I avoid debt?");
                                break;
                            case '5':
                                std::cout << processing;
                                ai.question("How can I build better credit?");
                                break;
                            case '6':
                                std::cout << processing;
                                ai.question("How often should I open credit lines?");
                                break;
                            case '7':
                                break;
                            default:
                                std::cout << "Invalid choice. "
                                          << "Please select a number "
                                          << "from 1-7." << std::endl;
                        }
                    }
                    catch (const std::exception& e) {
                        std::cerr << "Invalid choice. "
                                  << "Please enter a valid number."
                                  << std::endl;
            			std::cin.clear();
        			}
                } while (credit_choice != '7');
                break;
            case '2':
                char government_choice;
                do {
                    display_government_submenu();
                    government_choice = getchar();

                    try {
                        switch (government_choice) {
                            case '1':
                                std::cout << processing;
                                ai.question("What California government aid is out there?");
                                break;
                            case '2':
                                std::cout << processing;
                                ai.question("What is SNAP/TANF?");
                                break;
                            case '3':
                                std::cout << processing;
                                ai.question("Am I eligible for SNAP/TANF?");
                                break;
                            case '4':
                                break;
                            default:
                                std::cout << "Invalid choice. "
                                          << "Please select a number "
                                          << "from 1-4." << std::endl;
                        }
                    }
                    catch (const std::exception& e) {
                        std::cerr << "Invalid input. "
                                  << "Please enter a valid number."
                                  << std::endl;
                        std::cin.clear();
                    }
                } while (government_choice != '4');
                break;
            case '3':
                char college_choice;
                do {
                    display_college_submenu();
                    college_choice = getchar();

                    try {
                        switch (college_choice) {
                            case '1':
                                std::cout << processing;
                                ai.question("What are scholarships?");
                                break;
                            case '2':
                                std::cout << processing;
                                ai.question("Where can I attend college for free?");
                                break;
                            case '3':
                                std::cout << processing;
                                ai.question("What is FAFSA?");
                                break;
                            case '4':
                                std::cout << processing;
                                ai.question("How do I know I am eligible for FAFSA");
                                break;
                            case '5':
                                break;
                            default:
                                std::cout << "Invalid choice. "
                                          << "Please select a number "
                                          << "from 1-5." << std::endl;
                        }
                    }
                    catch (const std::exception& e) {
                        std::cerr << "Invalid input. "
                                  << "Please enter a valid number."
                                  << std::endl;
                        std::cin.clear();
                    }
                } while (college_choice != '5');
                break;
            case '4':
                char feminine_choice;
                do {
                    display_feminine_submenu();
                    feminine_choice = getchar();

                    try {
                        switch (feminine_choice) {
                            case '1':
                                std::cout << processing;
                                ai.question("What is the average pay difference between men and women?");
                                break;
                            case '2':
                                std::cout << processing;
                                ai.question("What can women do to fight financial insecurities?");
                                break;
                            case '3':
                                std::cout << processing;
                                ai.question("What financial options are there for single mothers?");
                                break;
                            case '4':
                                std::cout << processing;
                                ai.question("What is child support?");
                                break;
                            case '5':
                                std::cout << processing;
                                ai.question("How can I budget around a child?");
                                break;
                            case '6':
                                std::cout << processing;
                                ai.question("How can I budget around multiple children?");
                                break;
                            case '7':
                                break;
                            default:
                                std::cout << "Invalid choice. "
                                          << "Please select a number "
                                          << "from 1-5." << std::endl;
                        }
                    }
                    catch (const std::exception& e) {
                        std::cerr << "Invalid input. "
                                  << "Please enter a valid number."
                                  << std::endl;
                        std::cin.clear();
                    }
                } while (feminine_choice != '7');
                break;
            case '5':
                std::cout << "Goodbye! It was a pleasure assisting you. "
                          << "Have a wonderful day!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. "
                          << "Please select a number from 1-5."
                          << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Invalid input. Please enter a valid number."
                      << std::endl;
            std::cin.clear();
        }
    } while (choice != '5');

    return 0;
}

void display_main_menu() {
    std::cout << "-----Main Menu-----\n"
              //<< "1. Ask Fy anything\n"
              << "1. Credit Questions\n"
              << "2. Government Aid Questions\n"
              << "3. College Questions\n"
              << "4. Feminine Questions\n"
              << "5. Exit" << std::endl;
}

void display_credit_submenu() {
    std::cout << "-----Credit Submenu-----\n"
              << "1. What is Credit?\n"
              << "2. Best Starter Credit Cards\n"
              << "3. What are credit rewards?\n"
              << "4. How can I avoid debt?\n"
              << "5. How can I build better credit?\n"
              << "6. How often should I open credit lines?\n"
              << "7. Go back to main menu" << std::endl;
}

void display_government_submenu() {
    std::cout << "-----Government Aid Submenu-----\n"
              << "1. What California government aid is out there?\n"
              << "2. What is SNAP/TANF?\n"
              << "3. Am I eligible for SNAP/TANF?\n"
              << "4. Go back to main menu" << std::endl;
}

void display_college_submenu() {
    std::cout << "-----College Submenu-----\n"
              << "1. What are scholarships?\n"
              << "2. Where can I attend college for free?\n"
              << "3. What is FAFSA?\n"
              << "4. How do I know I am eligible for FAFSA?\n"
              << "5. Go back to main menu" << std::endl;
}

void display_feminine_submenu() {
    std::cout << "-----Feminine Submenu-----\n"
              << "1. What is the average pay difference between men and women?\n"
              << "2. What can women do to fight financial insecurities?\n"
              << "3. What financial options are there for single mothers?\n"
              << "4. What is child support?\n"
              << "5. How can I budget around a child?\n"
              << "6. How can I budget around multiple children?\n"
              << "7. Go back to main menu" << std::endl;
}
