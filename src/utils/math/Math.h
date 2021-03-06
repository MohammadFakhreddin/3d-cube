#ifndef Math_class
#define Math_class 

#include <cmath>

template<typename T>
T constexpr _piTemplate = (T)3.14159265358979323846264338327950288419;

class Math {
public:

    static constexpr float piFloat = _piTemplate<float>;
    static constexpr double piDouble = _piTemplate<double>;
    
    template<typename A,typename B,typename C>
    static A clamp(const A& value, B minValue, C maxValue) {
      if (value < minValue) {
        return A(minValue);
      }
      if (value > maxValue) {
        return A(maxValue);
      }
      return A(value);
    }

};

#endif