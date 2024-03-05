#pragma once

#include "liboai.h"

class AI {
public:
    AI();
    //void get_question(char* my_string);
    void question(const std::string& question);
    std::string word_wrapper(std::string& my_string);
    void hide_keystrokes();
private:
    bool is_list(std::vector<std::string>& my_vector,
                    std::string& current, int i);
    void numbered_list(std::vector<std::string>& my_vector,
                        std::string& current);
    /**
     * @var bool two_digit
     * private flag to help with debugging
     */
    bool two_digit = false;

    /**
     * @var bool three_digit
     * private flag to help with debugging
     */
    bool three_digit = false;

    /**
     * @var static const std::string OPENAI_API_KEY
     * OPENAI_API_KEY is stored in static storage to have one instance of.
     */
    static const std::string _OPENAI_API_KEY;

    /**
     * @var liboai::OpenAI _ai
     * TODO: make _ai singleton if time allows
     */
    liboai::OpenAI _ai;

    /**
     * @var liboai::Conversation _conversation
     * variable to store conversation data of user.
     */
    liboai::Conversation _conversation;
};
