#ifndef GENERATED_DTOS_MODELS_Category_H_
#define GENERATED_DTOS_MODELS_Category_H_

#include <optional>
#include <string>

#include "nlohmann/json.hpp"

namespace generated {
namespace dtos {
namespace models {

/**
 * \brief A category for a pet
 */
struct Category {
  static void to_json(::nlohmann::json& j, const Category& obj);
  static void from_json(const ::nlohmann::json& j, Category& obj);

  // optional fields
  std::optional<int64_t> id;
  std::optional<std::string> name;
};

}  // namespace models
}  // namespace dtos
}  // namespace generated

namespace generated {
namespace dtos {
namespace models {

inline void to_json(nlohmann::json& j, const Category& obj) {
  Category::to_json(j, obj);
}

inline void from_json(const nlohmann::json& j, Category& obj) {
  Category::from_json(j, obj);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

#endif /* GENERATED_DTOS_MODELS_Category_H_ */
