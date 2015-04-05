
#ifndef _NODE_H
#define _NODE_H
/*
 接口继承
 实现继承
 */

class Noncopyable
{
protected:
    Noncopyable(){}
    ~Noncopyable(){}
private:
    Noncopyable(const Noncopyable &);
    Noncopyable &operator=(const Noncopyable &);
};

class Node : private Noncopyable
{
public:
    virtual double calc() const =0;
    virtual ~Node(){};
};

class NumberNode : public Node
{
public:
    NumberNode(double num);

    double calc() const;
private:
    const double dNumber_;
};

class BinaryNode : public Node
{
public:
    BinaryNode(Node *left, Node *right);
    ~BinaryNode();

protected:
    Node *pLeft_;
    Node *pRight_;
};

class UNaryNode : public Node
{
public:
    UNaryNode(Node *child);
    ~UNaryNode();
protected:
    Node * pChild_;
};
#if 0
class MultipleNode : public Node
{
public:
    MultipleNode(Node *child);

    ~MultipleNode();

    void addChild(Node *child, bool positive)
    {
        vec_childs.push_back(child);
        vec_positives_.push_back(positive);
    }

protected:
    std::vector<Node *> vec_childs_;
    std::vector<bool> vec_positives_;
};
#endif

class AddNode : public BinaryNode
{
public:
    AddNode(Node *left, Node *right);

    double calc() const;
};

class SubNode : public BinaryNode
{
public:
    SubNode(Node *left, Node *right);

    double calc() const;
};


class MultiplyNode : public BinaryNode
{
public:
    MultiplyNode(Node *left, Node *right);

    double calc() const;
};

class DivideNode : public BinaryNode
{
public:
    DivideNode(Node *left, Node *right);

    double calc() const;
};

class UMinusNode : public UNaryNode
{
public:
    UMinusNode(Node *child);

    double calc() const;
};

#if 0
class SumNode : public MultipleNode
{
public:
    SumNode(Node *child) : MultipleNode(child){}

    double calc() const;
};

class ProductNode : public MultipleNode
{
public:
    ProductNode(Node *child) : MultipleNode(child){}
    double calc() const;
};
#endif


#endif
