#ifndef GENERATED_DTOS_MODELS_Order_H_
#define GENERATED_DTOS_MODELS_Order_H_

#include <optional>
#include <string>

#include "nlohmann/json.hpp"

namespace generated {
namespace dtos {
namespace models {

/**
 * \brief An order for a pets from the pet store
 */
struct Order {
  static void to_json(::nlohmann::json& j, const Order& obj);
  static void from_json(const ::nlohmann::json& j, Order& obj);

  // enums
  /**
   * \brief Order Status
   */
  enum class Status {
    PLACED,
    APPROVED,
    DELIVERED,
  };

  static std::string to_string(Status value);
  static void to_json(::nlohmann::json& j, const Status& value);
  static void from_json(const ::nlohmann::json& j, Status& value);

  // optional fields
  std::optional<int64_t> id;
  std::optional<int64_t> petId;
  std::optional<int32_t> quantity;
  std::optional<std::string> shipDate;
  std::optional<Status> status;
  std::optional<bool> complete;
};

inline std::string to_string(Order::Status value) {
  return Order::to_string(value);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

namespace nlohmann {

template <>
struct adl_serializer<generated::dtos::models::Order::Status> {
  static void to_json(json& j,
                      const generated::dtos::models::Order::Status& value) {
    generated::dtos::models::Order::to_json(j, value);
  }
  static void from_json(const json& j,
                        generated::dtos::models::Order::Status& value) {
    generated::dtos::models::Order::from_json(j, value);
  }
};

}  // namespace nlohmann

namespace generated {
namespace dtos {
namespace models {

inline void to_json(nlohmann::json& j, const Order& obj) {
  Order::to_json(j, obj);
}

inline void from_json(const nlohmann::json& j, Order& obj) {
  Order::from_json(j, obj);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

#endif /* GENERATED_DTOS_MODELS_Order_H_ */
