/*
Starstructor, the Starbound Toolset 
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STEXCEPTION_HPP
#define STEXCEPTION_HPP

#include <QString>

namespace Starstructor {

class Exception
{
public:
    Exception(const QString& message, 
        const QString& exType = "General exception") noexcept
        : m_message{ message }, m_exType{ exType }
    {}

    virtual ~Exception()
    {}

    QString what() const noexcept
    {
        return m_exType + ": " + m_message;
    }

    QString message() const noexcept
    {
        return m_message;
    }

private:
    QString m_message;
    QString m_exType;
};

class FileNotFoundException : public Exception
{
public:
    FileNotFoundException(const QString& message) noexcept
        : Exception{ message, "File not found exception" }
    {}

    virtual ~FileNotFoundException()
    {}
};

class JsonInvalidFormat : public Exception
{
public:
    JsonInvalidFormat(const QString& message) noexcept
        : Exception{ message, "JSON invalid format exception" }
    {}

    virtual ~JsonInvalidFormat()
    {}
};

}

#endif // STEXCEPTION_HPP