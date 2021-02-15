#include "Pet.h"

#include "serialization.h"
#include "utility.h"

namespace generated {
namespace dtos {
namespace models {

void Pet::to_json(::nlohmann::json& j, const Pet& obj) {
  j = ::nlohmann::json{
      {"id", obj.id},
      {"category", obj.category},
      {"name", obj.name},
      {"photoUrls", obj.photoUrls},
      {"tags", obj.tags},
      {"status", obj.status},
      {"additionalInfo", obj.additionalInfo},
  };
}

void Pet::from_json(const ::nlohmann::json& j, Pet& obj) {
  j.at("name").get_to(obj.name);
  j.at("photoUrls").get_to(obj.photoUrls);
  detail::to_optional(j, "id", obj.id);
  detail::to_optional(j, "category", obj.category);
  detail::to_optional(j, "tags", obj.tags);
  detail::to_optional(j, "status", obj.status);
  detail::to_optional(j, "additionalInfo", obj.additionalInfo);
}

std::string Pet::to_string(Pet::Status value) {
  switch (value) {
    case Pet::Status::AVAILABLE:
      return "AVAILABLE";
    case Pet::Status::PENDING:
      return "PENDING";
    case Pet::Status::SOLD:
      return "SOLD";
  }
  UNREACHABLE_CODE
}

void Pet::to_json(::nlohmann::json& j, const Pet::Status& value) {
  j = Pet::to_string(value);
}

void Pet::from_json(const ::nlohmann::json& j, Pet::Status& value) {
  auto str = j.get_ref<const ::nlohmann::json::string_t&>();
  if (str == "AVAILABLE") {
    value = Pet::Status::AVAILABLE;
    return;
  }
  if (str == "PENDING") {
    value = Pet::Status::PENDING;
    return;
  }
  if (str == "SOLD") {
    value = Pet::Status::SOLD;
    return;
  }
  throw invalid_enum_value(str);
}

std::string Pet::to_string(Pet::AdditionalInfo value) {
  switch (value) {
    case Pet::AdditionalInfo::PREORDER:
      return "PREORDER";
    case Pet::AdditionalInfo::IS_REALLY_A_HUMAN_IN_A_COSTUME:
      return "IS_REALLY_A_HUMAN_IN_A_COSTUME";
  }
  UNREACHABLE_CODE
}

void Pet::to_json(::nlohmann::json& j, const Pet::AdditionalInfo& value) {
  j = Pet::to_string(value);
}

void Pet::from_json(const ::nlohmann::json& j, Pet::AdditionalInfo& value) {
  auto str = j.get_ref<const ::nlohmann::json::string_t&>();
  if (str == "PREORDER") {
    value = Pet::AdditionalInfo::PREORDER;
    return;
  }
  if (str == "IS_REALLY_A_HUMAN_IN_A_COSTUME") {
    value = Pet::AdditionalInfo::IS_REALLY_A_HUMAN_IN_A_COSTUME;
    return;
  }
  throw invalid_enum_value(str);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated
