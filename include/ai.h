#pragma once

#include "liboai.h"

class AI {
public:
    AI();
    void response();
    void question(const std::string& question);
private:
    /**
     * @var static const std::string OPENAI_API_KEY
     * OPENAI_API_KEY is stored in static storage to have one instance of.
     */
    static const std::string _OPENAI_API_KEY;

    /**
     * @var liboai::OpenAI _ai
     * TODO: make _ai singleton?
     */
    liboai::OpenAI _ai;

    /**
     * @var liboai::Conversation _conversation
     * variable to store conversation data of user.
     */
    liboai::Conversation _conversation;
};
