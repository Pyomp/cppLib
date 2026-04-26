#pragma once

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

    namespace timeAverage {
        static std::unordered_map<std::string, Clock::time_point> t;
        static std::unordered_map<std::string, std::vector<float>> timesAverageValueMap;
        void time(const std::string& label) {
            t[label] = Clock::now();
        }

        void timeEnd(const std::string& label, size_t size) {
            auto it = timesAverageValueMap.find(label);
            if (it == timesAverageValueMap.end()) {
                timesAverageValueMap[label] = std::vector<float>();
            }

            auto it2 = t.find(label);
            if (it2 != t.end()) {
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - it2->second);
                timesAverageValueMap[label].push_back(duration.count());
                t.erase(it2);
                if (timesAverageValueMap[label].size() >= size) {
                    float a = 0;

                    for (float d : timesAverageValueMap[label])
                        a += d;

                    timesAverageValueMap[label].clear();

                    std::cout << label << ": " << a / size << " micro s" << std::endl;
                }
            }
            else {
                std::cerr << "Timer Average '" << label << "' does not exist!" << std::endl;
            }
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

    inline void printTimestampMilliseconds() noexcept {
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }

    inline void logPrefix() noexcept {
        printTimestampMilliseconds();
        std::cout << std::endl;
    }

    inline void logPrefix(const std::string& ownerName) noexcept {
        printTimestampMilliseconds();
        std::cout << " [" << ownerName << "]";
        std::cout << std::endl;
    }

    template<typename... Args>
    void log(Args&&... args) {
        ((std::cout << std::forward<Args>(args)), ...);
        std::cout << std::endl;
    }
}
