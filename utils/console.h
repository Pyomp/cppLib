#include <iostream>
#include <chrono>
#include <unordered_map>
#include <string>

namespace console {
    using Clock = std::chrono::high_resolution_clock;
    static std::unordered_map<std::string, Clock::time_point> timers;

    void time(const std::string& label) {
        timers[label] = Clock::now();
    }

    void timeEnd(const std::string& label) {
        auto it = timers.find(label);
        if (it != timers.end()) {
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - it->second);
            std::cout << label << ": " << duration.count() << " ms" << std::endl;
            timers.erase(it);
        }
        else {
            std::cerr << "Timer '" << label << "' does not exist!" << std::endl;
        }
    }

    template<typename T>
    void logHelper(T&& arg) {
        std::cout << std::forward<T>(arg);
    }

    template<typename T, typename... Args>
    void logHelper(T&& first, Args&&... args) {
        std::cout << std::forward<T>(first) << " ";
        logHelper(std::forward<Args>(args)...);
    }

    template<typename... Args>
    void log(Args&&... args) {
        ((std::cout << std::forward<Args>(args)), ...);
        std::cout << std::endl;
    }
}
