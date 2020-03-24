#ifndef DTOGEN_SERIALIZATION_H
#define DTOGEN_SERIALIZATION_H

#include "nlohmann/json.hpp"

#include <optional>
#include <memory>

namespace nlohmann {

template <typename T>
struct adl_serializer<std::optional<T>> {
    static void to_json(json& j, const std::optional<T>& opt) {
        opt == std::nullopt ? j = nullptr : j = *opt;
    }

    static void from_json(const json& j, std::optional<T>& opt) {
        j.is_null() ? opt = std::nullopt : opt = j.get<T>();
    }
};

template <typename T>
struct adl_serializer<std::shared_ptr<T>> {
    static void to_json(json& j, const std::shared_ptr<T>& ptr) {
        !ptr ? j = nullptr : j = *ptr;
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

#endif // DTOGEN_SERIALIZATION_H
