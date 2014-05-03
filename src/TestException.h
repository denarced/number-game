#ifndef __TESTEXCEPTION_H
#define __TESTEXCEPTION_H

#include <exception>
#include <string>

class TestException: public std::exception {
public:
    // CREATORS 
    TestException(
        const std::string& message, 
        const char* filename, 
        int lineNumber);
    virtual ~TestException();

    // ACCESSORS
    std::string getMessage() const;
    const char* getFilename() const;
    int getLineNumber() const;

private:
    const std::string message;
    const char* filename;
    const int lineNumber;
};

#endif // __TESTEXCEPTION_H
