#ifndef GENERATED_DTOS_MODELS__SERIALIZATION_H_
#define GENERATED_DTOS_MODELS__SERIALIZATION_H_

#include <memory>
#include <optional>

#include "nlohmann/json.hpp"

namespace nlohmann {

template <typename T>
struct adl_serializer<std::optional<T>> {
  static void to_json(json& j, const std::optional<T>& opt) {
    if (opt == std::nullopt) {
      j = nullptr;
    } else {
      j = *opt;
    }
  }

  static void from_json(const json& j, std::optional<T>& opt) {
    if (j.is_null()) {
      opt = std::nullopt;
    } else {
      opt = j.get<T>();
    }
  }
};

template <typename T>
struct adl_serializer<std::shared_ptr<T>> {
  static void to_json(json& j, const std::shared_ptr<T>& ptr) {
    if (ptr) {
      j = *ptr;
    } else {
      j = nullptr;
    }
  }

  static void from_json(const json& j, std::shared_ptr<T>& ptr) {
    if (j.is_null()) {
      ptr.reset();
    } else {
      ptr = std::make_shared<T>(j.get<T>());
    }
  }
};

}  // namespace nlohmann

#endif  // GENERATED_DTOS_MODELS__SERIALIZATION_H_
