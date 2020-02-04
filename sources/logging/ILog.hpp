//
// Created by kaktus on 2/4/20.
//

#pragma once

namespace fatanyu
{
    class ILog
    {
    public:
        virtual void trace() = 0;
        virtual void debug() = 0;
        virtual void info() = 0;
        virtual void warning() = 0;
        virtual void error() = 0;
        virtual void critical() = 0;
    };
}