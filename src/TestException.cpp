#include "TestException.h"

using std::string;

TestException::TestException(
    const string& message,
    const char* filename,
    int lineNumber):

    message(message),
    filename(filename),
    lineNumber(lineNumber) {
}

TestException::~TestException() {}

string TestException::getMessage() const {
    return this->message;
}

const char* TestException::getFilename() const {
    return this->filename;
}

int TestException::getLineNumber() const {
    return this->lineNumber;
}

