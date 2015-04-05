#ifndef _PARSER_H
#define _PARSER_H

class Scanner;
class Node;

enum EStatus
{
    STATUS_OK,
    STATUS_ERROR,
    STATUS_QUIT
};

class Parser
{
public:
    Parser(Scanner &sc);
    void parse();
    double calculate();
    EStatus getStatus() const;
private:
    Node *expr();
    Node *term();
    Node *factor();

private:
    Scanner &scanner_;
    Node *tree_;
    EStatus status_;
};
#endif
