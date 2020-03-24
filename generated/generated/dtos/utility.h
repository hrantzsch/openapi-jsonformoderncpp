#ifndef GENERATED_DTOS_MODELS__UTILITY_H_
#define GENERATED_DTOS_MODELS__UTILITY_H_

#include <stdexcept>

// This macro is used to improve warning behavior across compilers for switch
// statements on enums. It allows us to NOT define a default case, so the
// compiler can warn us about unhandled enum codes, without the compiler
// worrying we might reach the end of a non-void function without returning
// (GCC: -Wreturn-type).
#ifdef __clang__
#define UNREACHABLE_CODE __builtin_unreachable();
#elif __GNUC__
#define UNREACHABLE_CODE __builtin_unreachable();
#elif _MSC_VER
#define UNREACHABLE_CODE __assume(0);
#endif

namespace generated {
namespace dtos {
namespace models {

class invalid_enum_value : public std::runtime_error {
 public:
  using std::runtime_error::runtime_error;
};

namespace detail {

//! \brief Helper method to set optional values from json
template <typename T>
void to_optional(const nlohmann::json& j, const char* key, T& target) {
  if (j.contains(key)) {
    j.at(key).get_to(target);
  } else {
    target = std::nullopt;
  }
}

}  // namespace detail

}  // namespace models
}  // namespace dtos
}  // namespace generated

#endif  // GENERATED_DTOS_MODELS__UTILITY_H_
