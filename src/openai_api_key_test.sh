#!/bin/bash

export OPENAI_API_KEY='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'

sleep 2

exec printenv | grep OPENAI_API_KEY

sleep 2

curl https://api.openai.com/v1/chat/completions   -H "Content-Type: application/json"   -H "Authorization: Bearer $OPENAI_API_KEY"   -d '{
    "model": "gpt-3.5-turbo",
    "messages": [
      {
        "role": "system",
        "content": "You are a poetic assistant, skilled in explaining complex programming concepts with creative flair."
      },
      {
        "role": "user",
        "content": "Compose a poem that explains the concept of recursion in programming."
      }
    ]
  }'
