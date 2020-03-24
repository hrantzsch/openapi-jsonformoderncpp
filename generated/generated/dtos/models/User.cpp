#include "User.h"

#include "serialization.h"
#include "utility.h"

namespace generated {
namespace dtos {
namespace models {

void User::to_json(::nlohmann::json& j, const User& obj) {
  j = ::nlohmann::json{
      {"id", obj.id},
      {"username", obj.username},
      {"firstName", obj.firstName},
      {"lastName", obj.lastName},
      {"email", obj.email},
      {"password", obj.password},
      {"phone", obj.phone},
      {"userStatus", obj.userStatus},
  };
}

void User::from_json(const ::nlohmann::json& j, User& obj) {
  detail::to_optional(j, "id", obj.id);
  detail::to_optional(j, "username", obj.username);
  detail::to_optional(j, "firstName", obj.firstName);
  detail::to_optional(j, "lastName", obj.lastName);
  detail::to_optional(j, "email", obj.email);
  detail::to_optional(j, "password", obj.password);
  detail::to_optional(j, "phone", obj.phone);
  detail::to_optional(j, "userStatus", obj.userStatus);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated
