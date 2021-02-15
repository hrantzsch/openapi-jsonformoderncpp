#ifndef GENERATED_DTOS_MODELS_Pet_H_
#define GENERATED_DTOS_MODELS_Pet_H_

#include <optional>
#include <string>
#include <vector>

#include "Category.h"
#include "Pet_Tag.h"
#include "nlohmann/json.hpp"

namespace generated {
namespace dtos {
namespace models {

/**
 * \brief A pet for sale in the pet store
 */
struct Pet {
  static void to_json(::nlohmann::json& j, const Pet& obj);
  static void from_json(const ::nlohmann::json& j, Pet& obj);

  // enums
  /**
   * \brief pet status in the store
   */
  enum class Status {
    AVAILABLE,
    PENDING,
    SOLD,
  };

  static std::string to_string(Status value);
  static void to_json(::nlohmann::json& j, const Status& value);
  static void from_json(const ::nlohmann::json& j, Status& value);

  enum class AdditionalInfo {
    PREORDER,
    IS_REALLY_A_HUMAN_IN_A_COSTUME,
  };

  static std::string to_string(AdditionalInfo value);
  static void to_json(::nlohmann::json& j, const AdditionalInfo& value);
  static void from_json(const ::nlohmann::json& j, AdditionalInfo& value);

  // required fields
  std::string name;
  std::vector<std::string> photoUrls;

  // optional fields
  std::optional<int64_t> id;
  std::optional<Category> category;
  std::optional<std::vector<Pet_Tag>> tags;
  std::optional<Status> status;
  std::optional<std::vector<AdditionalInfo>> additionalInfo;
};

inline std::string to_string(Pet::Status value) {
  return Pet::to_string(value);
}

inline std::string to_string(Pet::AdditionalInfo value) {
  return Pet::to_string(value);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

namespace nlohmann {

template <>
struct adl_serializer<generated::dtos::models::Pet::Status> {
  static void to_json(json& j,
                      const generated::dtos::models::Pet::Status& value) {
    generated::dtos::models::Pet::to_json(j, value);
  }
  static void from_json(const json& j,
                        generated::dtos::models::Pet::Status& value) {
    generated::dtos::models::Pet::from_json(j, value);
  }
};

template <>
struct adl_serializer<generated::dtos::models::Pet::AdditionalInfo> {
  static void to_json(
      json& j, const generated::dtos::models::Pet::AdditionalInfo& value) {
    generated::dtos::models::Pet::to_json(j, value);
  }
  static void from_json(const json& j,
                        generated::dtos::models::Pet::AdditionalInfo& value) {
    generated::dtos::models::Pet::from_json(j, value);
  }
};

}  // namespace nlohmann

namespace generated {
namespace dtos {
namespace models {

inline void to_json(nlohmann::json& j, const Pet& obj) { Pet::to_json(j, obj); }

inline void from_json(const nlohmann::json& j, Pet& obj) {
  Pet::from_json(j, obj);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

#endif /* GENERATED_DTOS_MODELS_Pet_H_ */
