#include "Order.h"

#include "serialization.h"
#include "utility.h"

namespace generated {
namespace dtos {
namespace models {

void Order::to_json(::nlohmann::json& j, const Order& obj) {
  j = ::nlohmann::json{
      {"id", obj.id},
      {"petId", obj.petId},
      {"quantity", obj.quantity},
      {"shipDate", obj.shipDate},
      {"status", obj.status},
      {"complete", obj.complete},
  };
}

void Order::from_json(const ::nlohmann::json& j, Order& obj) {
  detail::to_optional(j, "id", obj.id);
  detail::to_optional(j, "petId", obj.petId);
  detail::to_optional(j, "quantity", obj.quantity);
  detail::to_optional(j, "shipDate", obj.shipDate);
  detail::to_optional(j, "status", obj.status);
  detail::to_optional(j, "complete", obj.complete);
}

std::string Order::to_string(Order::Status value) {
  switch (value) {
    case Order::Status::PLACED:
      return "PLACED";
    case Order::Status::APPROVED:
      return "APPROVED";
    case Order::Status::DELIVERED:
      return "DELIVERED";
  }
  UNREACHABLE_CODE
}

void Order::to_json(::nlohmann::json& j, const Order::Status& value) {
  j = Order::to_string(value);
}

void Order::from_json(const ::nlohmann::json& j, Order::Status& value) {
  auto str = j.get_ref<const ::nlohmann::json::string_t&>();
  if (str == "PLACED") {
    value = Order::Status::PLACED;
    return;
  }
  if (str == "APPROVED") {
    value = Order::Status::APPROVED;
    return;
  }
  if (str == "DELIVERED") {
    value = Order::Status::DELIVERED;
    return;
  }
  throw invalid_enum_value(str);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated
