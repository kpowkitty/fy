/**
* @project Fy: Your Financial Guide
* @file bot.cpp
* @developers @kpowkitty, @huynhkatrina
*/

#include "ai.h"

#include <iostream>
#include <string>

/** AI.
* @param none
* @return none
* @remarks Must check API key to ensure validity.
*           Initializes liboai::openai & liboai::conversation.
*/

AI::AI() : _ai(), _conversation()
{
    if (_ai.auth.SetKeyEnv("OPENAI_API_KEY"));
    else
        std::cerr << "Set OpenAI API key: Failed.\n";
}

/** Response.
* @param none
* @return none
* @remarks Function for talking to the AI.
*           Asks user for input, awaits input. Generates conversation response.
*           Prints response to console.
*           Loops if user wants to ask more.
*/

void AI::response() {
    // holds next user input
    std::string input;

    // flag: if user wants to exit, set to true to break loop
    bool exit = false;
    while(!exit) {
        // get next user input
        std::cout << "What would you like to ask me?";
        std::getline(std::cin, input);

        // add user input to conversation
        _conversation.AddUserData(input);

        // get response from OpenAI
        liboai::Response response = _ai.ChatCompletion->create(
            "gpt-3.5-turbo", _conversation);

        // update our conversation with the responseconvo
        _conversation.Update(response);

        // print the response
        std::cout << "Fy: " << _conversation.GetLastResponse() << std::endl;

        std::cout << "Fy: Y to ask another question, N to exit to main menu";
        std::cin >> input;
        if (input == "N" || input == "n" || input == "no") {
            exit = true;
        }
    }
}
