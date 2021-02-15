#include "Category.h"

#include "serialization.h"
#include "utility.h"

namespace generated {
namespace dtos {
namespace models {

void Category::to_json(::nlohmann::json& j, const Category& obj) {
  j = ::nlohmann::json{
      {"id", obj.id},
      {"name", obj.name},
  };
}

void Category::from_json(const ::nlohmann::json& j, Category& obj) {
  detail::to_optional(j, "id", obj.id);
  detail::to_optional(j, "name", obj.name);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated
