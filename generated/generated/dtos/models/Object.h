#ifndef GENERATED_DTOS_MODELS_OBJECT_H_
#define GENERATED_DTOS_MODELS_OBJECT_H_

/*
 * Note: This is a stub. `Object` does not do anything, has no fields, and will
 * not work. It merely makes include statements and calls to to_/from_json in
 * other models compile.
 */

#include "nlohmann/json.hpp"

namespace generated {
namespace dtos {
namespace models {

struct Object {
  static void to_json(::nlohmann::json& j, const Object& obj) {}
  static void from_json(const ::nlohmann::json& j, Object& obj) {}
};

inline void to_json(nlohmann::json& j, const Object& obj) {
  Object::to_json(j, obj);
}

inline void from_json(const nlohmann::json& j, Object& obj) {
  Object::from_json(j, obj);
}

}  // namespace models
}  // namespace dtos
}  // namespace generated

#endif /* GENERATED_DTOS_MODELS_OBJECT_H_ */
