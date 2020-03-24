#ifndef GENERATED_DTOS_MODELS_Pet_Tag_H_
#define GENERATED_DTOS_MODELS_Pet_Tag_H_

#include <optional>
#include <string>

#include "nlohmann/json.hpp"

namespace generated {
namespace dtos {
namespace models {

/**
 * \brief A tag for a pet
 */
struct Pet_Tag {
  static void to_json(::nlohmann::json& j, const Pet_Tag& obj);
  static void from_json(const ::nlohmann::json& j, Pet_Tag& obj);

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

inline void to_json(nlohmann::json& j, const Pet_Tag& obj) {
  Pet_Tag::to_json(j, obj);
}

inline void from_json(const nlohmann::json& j, Pet_Tag& obj) {
  Pet_Tag::from_json(j, obj);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

#endif /* GENERATED_DTOS_MODELS_Pet_Tag_H_ */
