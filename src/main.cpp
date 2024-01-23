#include "liboai.h"

#include <stdlib.h>
#include <string>

#include <iostream>

int main() {
    // TODO: call menu function

    // create openai object
    liboai::OpenAI oai;

    // create a conversation
    liboai::Conversation convo;

    // holds next user input
    std::string input;
    if (oai.auth.SetKeyEnv("OPENAI_API_KEY")) {
        std::cout << "OpenAI key set successfully.\n";
        try {
        while (true) {
            // get next user input
            std::cout << "You: ";
            std::getline(std::cin, input);

            // add user input to conversation
            convo.AddUserData(input);

            // get response from OpenAI
            liboai::Response response = oai.ChatCompletion->create(
                "gpt-3.5-turbo", convo
        );

        // update our conversation with the responseconvo
        convo.Update(response);

        // print the response
        std::cout << "Bot: " << convo.GetLastResponse() << std::endl;
      }
    }
        catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
  } else {
    std::cout << "if you're seeing this message send help";
  }
    return 0;
}
