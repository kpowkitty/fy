#pragma once

#include <liboai.h>

class AI {
public:
    AI();
    void response();
private:
    /**
     * @var static const std::string OPENAI_API_KEY
     * OPENAI_API_KEY is stored in static storage to have one instance of.
     */
    static const std::string _OPENAI_API_KEY;

    liboai::OpenAI _ai;
    liboai::Conversation _conversation;
};
