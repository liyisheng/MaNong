/*************************************************************************
    > File Name: Folder.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 23时02分00秒
 ************************************************************************/

#include"Folder.h"
#include"Message.h"

void Folder::addMsg(Message* rhs)
{
	messages.insert(rhs);
}

void Folder::remMsg(Message* rhs)
{
	messages.erase(rhs);
}
