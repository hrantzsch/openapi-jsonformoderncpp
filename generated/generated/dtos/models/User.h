#ifndef GENERATED_DTOS_MODELS_User_H_
#define GENERATED_DTOS_MODELS_User_H_

#include <optional>
#include <string>

#include "nlohmann/json.hpp"

namespace generated {
namespace dtos {
namespace models {

/**
 * \brief A User who is purchasing from the pet store
 */
struct User {
  static void to_json(::nlohmann::json& j, const User& obj);
  static void from_json(const ::nlohmann::json& j, User& obj);

  // optional fields
  std::optional<int64_t> id;
  std::optional<std::string> username;
  std::optional<std::string> firstName;
  std::optional<std::string> lastName;
  std::optional<std::string> email;
  std::optional<std::string> password;
  std::optional<std::string> phone;
  std::optional<int32_t> userStatus;
};

}  // namespace models
}  // namespace dtos
}  // namespace generated

namespace generated {
namespace dtos {
namespace models {

inline void to_json(nlohmann::json& j, const User& obj) {
  User::to_json(j, obj);
}

inline void from_json(const nlohmann::json& j, User& obj) {
  User::from_json(j, obj);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

#endif /* GENERATED_DTOS_MODELS_User_H_ */
