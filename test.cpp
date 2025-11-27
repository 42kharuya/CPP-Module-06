#include <iostream>
#include <cmath> // std::modf, std::fabs
#include <limits> // std::numeric_limits

void getDecimalPlaces_cpp98(float f) {
    // if (std::fabs(f) >= 1e6) {
    //     // 大きすぎる値は指数表記になる可能性があり、正確な桁数計算が困難
    //     // または、単に浮動小数点の精度限界を超えるため、事前に処理を中断
    //     return -1; // エラーとして扱う
    // }

    float integral_part;
    float fractional_part = std::modf(f, &integral_part); // 小数部を取得

    std::cout << f << ": " << fractional_part << std::endl;
    const float EPSILON = 0.0000001f;
    if (fractional_part > EPSILON)
      std::cout << "is not 0" << std::endl;
    else
      std::cout << "is 0" << std::endl;

}

int main() {
    
    getDecimalPlaces_cpp98(100.1f);
    getDecimalPlaces_cpp98(100.0f);
    
    return 0;
}
