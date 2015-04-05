#include "node.h"

#include <math.h>
#include <iostream>


NumberNode::NumberNode(double number) : dNumber_(number) {}

double NumberNode::calc() const
{
    return dNumber_;
}

BinaryNode::BinaryNode(Node *left, Node *right)
    : pLeft_(left), pRight_(right)
{}

BinaryNode::~BinaryNode()
{
    delete pLeft_;
    delete pRight_;
}

UNaryNode::UNaryNode(Node *child): pChild_(child){}

UNaryNode::~UNaryNode()
{
    delete pChild_;
}


AddNode::AddNode(Node *left, Node *right)
    : BinaryNode(left, right)
{}


double AddNode::calc()const
{
    return pLeft_->calc() + pRight_->calc();
}

SubNode::SubNode(Node *left, Node *right)
    : BinaryNode(left, right)
{}

double SubNode::calc() const
{
    return pLeft_->calc() - pRight_->calc();
}


MultiplyNode::MultiplyNode(Node *left, Node *right)
    : BinaryNode(left, right)
{}

double MultiplyNode::calc() const
{
    return pLeft_->calc() - pRight_->calc();
}


DivideNode::DivideNode(Node *left, Node *right)
    : BinaryNode(left, right)
{}

double DivideNode::calc() const
{
    double divisor = pRight_->calc();
    if(divisor != 0.0)
        return pLeft_->calc() / divisor;
    else
    {
        std::cout << "divisor by zero" << std::endl;
        return HUGE_VAL;
    }
}

UMinusNode::UMinusNode(Node *child)
    : UNaryNode(child)
{}

double UMinusNode::calc() const
{
    return - pChild_->calc();
}
#if 0
int main(void)
{
    std::cout << "hello,world!" << std::endl;

    return 0;
}
MultipleNode::MutipleNode(Node *child)
{
    vec_childs.push_back(child);
}

MultipleNode::~MultipleNode()
{
    std::vector<Node *>::const_iterator it;
    for(it = vec_childs_.begin(); it != vec_childs_.end(); ++it)
    {
        delete *it;
    }
}

double SumNode::calc() const
{
    double result = 0.0;
    std::vector<Node *>::const_iterator nit = vec_childs_.begin();
    std::vector<bool>::const_iterator bit = vec_positives_.begin();

    for(; nit != vec_childs_.end(); ++nit, ++bit)
    {
        assert(bit != vec_positives_.end());
        double val = (*nit)->calc();
        if(*bit)
            result += val;
        else
            result -= val;
    }
    assert(bit == vec_positives_.end());
    return result;
}


double ProductNode::calc() const
{
    double result = 1.0;
    std::vector<Node *>::const_iterator nit = vec_childs_.begin();
    std::vector<bool>::const_iterator bit = vec_positives_.begin();

    for(; nit != vec_childs_.end(); ++nit, ++bit)
    {
        assert(bit != vec_positives_.end());
        double val = (*nit)->calc();
        if(*bit)
            result *= val;
        else if(val != 0)
            result /= val;
        else
        {
            std::cout << "divisor by zero" << std::endl;
            return HUGE_VAL;
        }
    }
    assert(bit == vec_positives_.end());
    return result;
}

#endif
