#pragma once

#include "ILogger.hpp"
#include "Exception.hpp"
#include <ostream>
#include <iostream>
#include <mutex>

namespace kaktus
{
    class Logger : public ILogger
    {
    public:
        explicit Logger(std::ostream &ostream = std::cout) : m_logStream(ostream)
        {
            printIntroduction();
        }
        ~Logger()
        {
            printEnding();
        }

        void trace(const char *message, const std::experimental::source_location &source_location = std::experimental::source_location::current()) noexcept override
        {
            print(message, source_location, "trace");
        }

        void debug(const char *message, const std::experimental::source_location &source_location = std::experimental::source_location::current()) noexcept override
        {
            print(message, source_location, "debug");
        }

        void info(const char *message, const std::experimental::source_location &source_location = std::experimental::source_location::current()) noexcept override
        {
            print(message, source_location, "info");
        }

        void warning(const char *message, const std::experimental::source_location &source_location = std::experimental::source_location::current()) noexcept override
        {
            print(message, source_location, "warning");
        }

        void error(const char *message, const std::experimental::source_location &source_location = std::experimental::source_location::current()) noexcept override
        {
            print(message, source_location, "error");
        }

        void critical(const char *message, const std::experimental::source_location &source_location = std::experimental::source_location::current()) noexcept override
        {
            print(message, source_location, "critical");
        }

    protected:
        class LogStream
        {
        public:
            explicit LogStream(std::ostream &ostream) : m_ostream(ostream)
            {
                if (!m_ostream)
                {
                    throw kaktus::Exception("Logger init failed. Stream is nullptr.");
                }
            }

            friend std::ostream &operator<<(const LogStream &logStream, const std::string& message)
            {
                std::lock_guard<std::mutex> lockGuard(logStream.m_mutex);
                logStream.m_ostream << message;
                return logStream.m_ostream;
            }

        protected:
            mutable std::mutex m_mutex;
            std::ostream &m_ostream;
        };

        void print(const char *message, const std::experimental::source_location &source_location, const char* severityLevel) noexcept
        {
            m_logStream << formatCollumn(severityLevel) <<
                formatCollumn(source_location.file_name()) <<
                formatCollumn(source_location.line()) <<
                formatCollumn(source_location.column()) <<
                formatCollumn(source_location.function_name()) <<
                formatCollumn(message) << std::endl;
        }

        static std::string formatCollumn(const char* value)
        {
            return std::string("[").append(value).append("]");
        }
        static std::string formatCollumn(int value)
        {
            return std::string("[").append(std::to_string(value)).append("]");
        }

        void printIntroduction() noexcept
        {
            m_logStream << formatCollumn("info") << formatCollumn(std::string("Compiled: ").append(__DATE__).append(" ").append(__TIME__).c_str()) << std::endl;
        }
        void printEnding() noexcept
        {
            m_logStream << formatCollumn("info") << formatCollumn("Destroying logger") << std::endl;
        }

        LogStream m_logStream;
    };
}
