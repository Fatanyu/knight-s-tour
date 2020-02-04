#pragma once

#include <exception>
#include <string>
#include <experimental/source_location>
#include <sstream>

namespace fatanyu
{
    class Exception : public std::exception
    {
    public:
        explicit Exception(const char* message, const std::experimental::source_location& source_location = std::experimental::source_location::current()) : m_source_location(source_location)
        {
            m_message = message;
            formatMessage();
        }

        [[nodiscard]]
        const char *what() const noexcept override
        {
            return m_finalMessage.c_str();
        }

    protected:
        void formatMessage()
        {
    //stringstream for some reason not working https://stackoverflow.com/questions/41854840/var-create-unable-to-create-variable-object
            m_finalMessage.append( m_source_location.file_name());
            m_finalMessage.append(m_delimiter);
            m_finalMessage.append(std::to_string(m_source_location.line()));
            m_finalMessage.append(m_delimiter);
            m_finalMessage.append(std::to_string(m_source_location.column()));
            m_finalMessage.append(m_delimiter);
            m_finalMessage.append(m_source_location.function_name());
            m_finalMessage.append(m_delimiter);
            m_finalMessage.append(m_message);
        }

        const char* m_message;
        const char* m_delimiter = ":";
        std::string m_finalMessage;
        const std::experimental::source_location& m_source_location;
    };
}