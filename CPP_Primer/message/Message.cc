/*************************************************************************
    > File Name: Message.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 22时10分04秒
 ************************************************************************/

#include"Message.h" 
#include"Folder.h"
using std::set;
Message::Message(const Message &m):
	contents(m.contents), folders(m.folders)
{
	put_Msg_in_Folders(folders);	
}

void Message::put_Msg_in_Folders(const set<Folder*> &rhs)
{
	for(std::set<Folder*>::const_iterator beg = rhs.begin();
			beg != rhs.end(); ++beg)
	{
		(*beg)->addMsg(this);
	}
}

Message& Message::operator=(const Message &rhs)
{
	if(&rhs != this)
	{
		remove_Msg_from_Folders();
		contents = rhs.contents;
		folders =  rhs.folders;
		put_Msg_in_Folders(folders);
	}
	return *this;
}

void Message::remove_Msg_from_Folders()
{ for(std::set<Folder*>::const_iterator beg = folders.begin();
			beg != folders.end(); ++beg)

		(*beg)->remMsg(this);
}

Message::~Message()
{
	remove_Msg_from_Folders();
}

void Message::save(Folder& rhs)
{
	rhs.addMsg(this);
	this->addFldr(&rhs);
}

void Message::remove(Folder& rhs)
{
	rhs.remMsg(this);
	this->remFldr(&rhs);
}

void Message::addFldr(Folder* prhs)
{
	folders.insert(prhs);
}

void Message::remFldr(Folder* prhs)
{
	folders.erase(prhs);
}







