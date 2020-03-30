/*
 * Don't forget to remove this
 */

#include <iostream>

#include "Pet.h"

static std::string rawPet =
    "{                       \
  \"id\": 0,                 \
  \"category\": {            \
      \"id\": 1,             \
      \"name\": \"non-food\" \
  },                         \
  \"name\": \"doggie\",      \
  \"photoUrls\": [           \
    \"https://doggie.pics/0\"\
  ],                         \
  \"tags\": [                \
    {                        \
      \"id\": 0,             \
      \"name\": \"myTag\"    \
    }                        \
  ],                         \
  \"additionalInfo\": [      \
      \"PREORDER\"           \
  ],                         \
  \"status\": \"AVAILABLE\"  \
}";

using json = nlohmann::json;
using namespace generated::dtos::models;

int main() {
    auto p = json::parse(rawPet).get<Pet>();
    if (p.additionalInfo.has_value())
        for (auto &v : p.additionalInfo.value())
            std::cout << to_string(v) << std::endl;
    else
        std::cout << "no additional info" << std::endl;

    json pj = p;
    std::cout << pj << std::endl;
    return 0;
}
