#ifndef GENERATED_DTOS_MODELS_ApiResponse_H_
#define GENERATED_DTOS_MODELS_ApiResponse_H_

#include <optional>
#include <string>

#include "nlohmann/json.hpp"

namespace generated {
namespace dtos {
namespace models {

/**
 * \brief Describes the result of uploading an image resource
 */
struct ApiResponse {
  static void to_json(::nlohmann::json& j, const ApiResponse& obj);
  static void from_json(const ::nlohmann::json& j, ApiResponse& obj);

  // optional fields
  std::optional<int32_t> code;
  std::optional<std::string> type;
  std::optional<std::string> message;
};

}  // namespace models
}  // namespace dtos
}  // namespace generated

namespace generated {
namespace dtos {
namespace models {

inline void to_json(nlohmann::json& j, const ApiResponse& obj) {
  ApiResponse::to_json(j, obj);
}

inline void from_json(const nlohmann::json& j, ApiResponse& obj) {
  ApiResponse::from_json(j, obj);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

#endif /* GENERATED_DTOS_MODELS_ApiResponse_H_ */
