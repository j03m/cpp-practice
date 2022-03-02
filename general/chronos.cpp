#include<chrono>
#include<iostream>
#include<atomic>
#include<type_traits>

int main(){
    std::atomic<std::chrono::time_point<std::chrono::steady_clock>> now;
    std::chrono::time_point<std::chrono::steady_clock> now2;
    std::cout << std::is_trivially_copyable<std::chrono::time_point<std::chrono::steady_clock>>::value;
    std::cout << std::is_copy_constructible<std::chrono::time_point<std::chrono::steady_clock>>::value;
    std::cout << std::is_move_constructible<std::chrono::time_point<std::chrono::steady_clock>>::value;
    std::cout << std::is_trivially_copyable<std::chrono::time_point<std::chrono::steady_clock>>::value;
    std::cout << std::is_copy_assignable<std::chrono::time_point<std::chrono::steady_clock>>::value;
    std::cout << std::is_move_assignable<std::chrono::time_point<std::chrono::steady_clock>>::value;
    now = std::chrono::steady_clock::now();
    now2 = std::chrono::steady_clock::now();
    now2 += std::chrono::milliseconds(20);
    now = now2;
}