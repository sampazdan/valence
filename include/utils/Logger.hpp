#pragma once
#include <string>

namespace valence {
namespace utils {

class Logger {
public:
    static void info(const std::string& msg);
    static void error(const std::string& msg);
    // etc...
};

} // namespace utils
} // namespace valence
