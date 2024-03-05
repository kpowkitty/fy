/**
* @project Fy: Your Financial Guide
* @file bot.cpp
* @developers @kpowkitty, @huynhkatrina
*/

#include "ai.h"

#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>

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

/** Get question.
* @param none
* @return none
* @remarks Grabs the question the user wants to ask.
*/

/*void AI::get_question(std::string& my_string) {
    std::cout << "What would you like to ask me?\n";
    std::getline(std::cin, my_string);
    std::cin.clear();
}*/

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
    //std::cout << "Fy: " << _conversation.GetLastResponse() << std::endl;
    std::string conv = _conversation.GetLastResponse();
    std::cout << word_wrapper(conv) << "\n\n";
    std::cout << "What other questions do you have?" << std::endl;
}

/** Word wrapper.
* @param string to be wrapped
* @return none
* @remarks Takes the AI's string and wraps it to 80 cols.
*/
std::string AI::word_wrapper(std::string& my_string) {
    std::stringstream new_string;
    new_string << my_string;
    // vector to create formatted_output easier(?) with .push_back()
    std::vector<std::string> formatted_string;
    // current piece of my_string that we are looking at
    std::string current;
    std::string white_space = " ";
    int i = 0;
    while (new_string >> current) {
        // adds the amount of characters + 1 for white space
        i += current.length() + 1;
        // add current word to vector
        formatted_string.push_back(current);
        // add a space to vector because our current string isnt grabbing it
        formatted_string.push_back(white_space);
        // if we are at 80 chars, then insert newline (estimated)
        if (i >= 80) {
            formatted_string.push_back("\n");
            i = 0;
        }
        // problem: gpt likes numbered lists...
        if (is_list(formatted_string, current, i)) {
            numbered_list(formatted_string, current);
            i = 0;
        }
    }
    std::string final_string;
    for (auto& e : formatted_string) {
        final_string += e;
    }
    return final_string;
}


/** Is list.
* @param current word, vector to check, and the current count of characters
* @return bool
* @remarks check if current string's first character is == a number
*         AND the next character is a "." (OR the next char is another digit
*         followed by a ".")
*         i.e. current
*/
bool AI::is_list(std::vector<std::string>& my_vector, std::string& current,
                    int i) {
    // initialize all chars so they are null if they do not meet conditions
    char first_char = current[0];
    char second_char;
    char third_char;
    // if the current string's length is == 2 or 3, then it is possibly a
    // numbered list!...so let's check:
    if (current.length() == 2) {
        // for single digit numbered lists "2."
        second_char = current[current.length() - 1];
        two_digit = true;
    } else if (current.length() == 3) {
        // for double digit numbered lists "10."
        second_char = current[current.length() - 2];
        third_char = current[current.length() - 1];
        three_digit = true;
    }
    // if we haven't recently done a newline, and the form is either "n."
    // or "nn.", then return true, where n are numbers
    if ((i != 0 && !isalpha(first_char))
            && (second_char == '.' ||
                (!isalpha(second_char) && third_char == '.'))) {
            return true;
    }
    // if we didn't return in the if statement above, then we will reset our
    // bools to false to guard against false flagging
    two_digit = false;
    three_digit = false;
    return false;
}

/** Numbered list.
* @param current word and vector to check
* @return void, modifies the string obj in parameter
* @remarks this is only entered if the function passes the "is_list" check.
*           if it does, then it inserts a newline before the numbered point.
*/

void AI::numbered_list(std::vector<std::string>& my_vector, std::string& current) {
    auto iterCurrent = my_vector.begin();
    auto iterEnd = my_vector.end();
    int size = static_cast<int>(my_vector.size());
    int count = 0;
    // this traverses the vector to the point right before the numbered point
    while (count < (size - 2) && iterCurrent != iterEnd) {
        ++count;
        ++iterCurrent;
    }
    my_vector.insert(iterCurrent, "\n");
}

void AI::hide_keystrokes() {
    termios tty;

    tcgetattr(STDIN_FILENO, &tty);

    /* we want to disable echo */
    tty.c_lflag &= (~ICANON & ~ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

