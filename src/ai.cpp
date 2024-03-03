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
    // set the openAPI key from your environment variables
    // cerr if it does not work
    if (!(_ai.auth.SetKeyEnv("OPENAI_API_KEY"))) {
        std::cerr << "Set OpenAI API key: Failed.\n";
    }
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
    std::string input = "";
    // get next user input
    std::cout << "What would you like to ask me?\n";
    std::getline(std::cin, input);
    std::cin.clear();

    // add user input to conversation
    _conversation.AddUserData(input);

    // get response from OpenAI
    liboai::Response response = _ai.ChatCompletion->create(
        "gpt-3.5-turbo", _conversation);

    // update our conversation with the responseconvo
    _conversation.Update(response);

    // print the response
    std::cout << "Fy: " << _conversation.GetLastResponse() << std::endl;
}

/** Question.
* @param string for question to be asked
* @return none
* @remarks Function for asking the ai a pre-determined question.
*/
void AI::question(const std::string& question) {
    _conversation.AddUserData(question);

    // get response from OpenAI
    liboai::Response response = _ai.ChatCompletion->create(
                                    "gpt-3.5-turbo", _conversation);

    // update our conversation with the responseconvo
    _conversation.Update(response);

    // print the response
    std::cout << "Fy: " << _conversation.GetLastResponse() << std::endl;
}

int main() { return 0; }
