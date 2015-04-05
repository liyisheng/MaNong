#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>

Scanner::Scanner(std::string &buf)
    : buf_(buf),
      curPos_(0)
{
    accept();
}

double Scanner::number()
{
    return number_;
}

EToken Scanner::token()
{
    return token_;
}

void Scanner::skipWhite()
{
    while(isspace(buf_[curPos_]))
        ++curPos_;
}

void Scanner::accept()
{   
    skipWhite();
    switch(buf_[curPos_])
    {
    case '+':
        token_ = TOKEN_PLUS;
        ++curPos_;
        break;
    case '-':
        token_ = TOKEN_MINUS;
        ++curPos_;
        break;
    case '*':
        token_ = TOKEN_MULTIPLY;
        ++curPos_;
        break;
    case '(':
        token_ = TOKEN_LPARENTHESIS;
        ++curPos_;
        break;
    case ')':
        token_ = TOKEN_RPARENTHESIS;
        ++curPos_;
        break;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '.':
        token_ = TOKEN_NUMBER;
        char *p;
        number_ = strtod(&buf_[curPos_], &p);
        curPos_ = p - &buf_[0];
        break;
    case '\0': case '\n': case '\r': case EOF:
        token_ = TOKEN_END;
        break;
    default:
        token_ = TOKEN_ERROR;
    }
}

