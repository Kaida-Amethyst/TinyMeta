

// Trait provides type traits for compile-time programming
// - [ ] IsSame: To check if two types are same
// - [ ] IfThenElse: To select type based on condition
// - [ ] ... more

namespace Meta {
namespace Trait {


/*
 * IsSame
 *
 *   parameters:  typename T1, typename T2
 *   description: If T1 and T2 are same type
 *                return true, else return false
 *
 *   example:     IsSame<int, int>    // return true
 *                IsSame<int, double> // return false
 *
 */
template<typename T1, typename T2>
struct IsSame_ {
  static constexpr bool value = false;
};

template<typename T>
struct IsSame_<T, T> {
  static constexpr bool value = true;
};

template<typename T1, typename T2>
static constexpr bool IsSame = IsSame_<T1, T2>::value;


/*
 * IfThenElse
 *
 *   parameters:  bool condition, typename T1, typename T2
 *   description: If condition is true
 *                return T1, else return T2
 *
 *   example:     IfThenElse<true, int, double>  // return int
 *                IfThenElse<false, int, double> // return double
 *
 */
template <bool condition, typename T1, typename T2>
struct IfThenElseT;


template <typename T1, typename T2>
struct IfThenElseT<true, T1, T2> {
  using Type = T1;
};

template <typename T1, typename T2>
struct IfThenElseT<false, T1, T2> {
  using Type = T2;
};

template <bool condition, typename T1, typename T2>
using IfThenElse = typename IfThenElseT<condition, T1, T2>::Type;


}; // namespace trait

}; // namespace Meta
