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
  \"status\": \"available\"  \
}";

using json = nlohmann::json;
using namespace org::openapitools::model;

int main() {
    auto p = json::parse(rawPet).get<Pet>();
    std::cout << p.name << std::endl;
    std::cout << p.category.value().name.value() << std::endl;

    json pj = p;
    std::cout << pj << std::endl;
    return 0;
}
