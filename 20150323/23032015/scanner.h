#ifndef _SCANNER_H
#define _SCANNER_H

#include <string>

enum EToken
{
    TOKEN_END,
    TOKEN_ERROR,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPARENTHESIS,
    TOKEN_RPARENTHESIS,
    TOKEN_IDENTIFER
};


class Scanner
{
public:
    Scanner(std::string &buf);
    double number();
    EToken token();
    void skipWhite();
    void accept();

private:
    std::string buf_;
    unsigned int curPos_;
    double number_;
    EToken token_;
};
#endif
