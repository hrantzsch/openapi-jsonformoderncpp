#include "ApiResponse.h"

#include "serialization.h"
#include "utility.h"

namespace generated {
namespace dtos {
namespace models {

void ApiResponse::to_json(::nlohmann::json& j, const ApiResponse& obj) {
  j = ::nlohmann::json{
      {"code", obj.code},
      {"type", obj.type},
      {"message", obj.message},
  };
}

void ApiResponse::from_json(const ::nlohmann::json& j, ApiResponse& obj) {
  detail::to_optional(j, "code", obj.code);
  detail::to_optional(j, "type", obj.type);
  detail::to_optional(j, "message", obj.message);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated
