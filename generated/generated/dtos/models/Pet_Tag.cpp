#include "Pet_Tag.h"

#include "serialization.h"
#include "utility.h"

namespace generated {
namespace dtos {
namespace models {

void Pet_Tag::to_json(::nlohmann::json& j, const Pet_Tag& obj) {
  j = ::nlohmann::json{
      {"id", obj.id},
      {"name", obj.name},
  };
}

void Pet_Tag::from_json(const ::nlohmann::json& j, Pet_Tag& obj) {
  detail::to_optional(j, "id", obj.id);
  detail::to_optional(j, "name", obj.name);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated
