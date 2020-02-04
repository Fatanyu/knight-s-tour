#pragma once
#include <experimental/source_location>

namespace fatanyu
{
    class ILogger
    {
    public:
        virtual void trace(const char* message, const std::experimental::source_location& source_location) noexcept = 0;
        virtual void debug(const char* message, const std::experimental::source_location& source_location) noexcept = 0;
        virtual void info(const char* message, const std::experimental::source_location& source_location) noexcept = 0;
        virtual void warning(const char* message, const std::experimental::source_location& source_location) noexcept = 0;
        virtual void error(const char* message, const std::experimental::source_location& source_location) noexcept = 0;
        virtual void critical(const char* message, const std::experimental::source_location& source_location) noexcept = 0;

    };
}