/*************************************************************************
    > File Name: Folder.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 22时34分58秒
 ************************************************************************/

#ifndef _FOLDER_H
#define _FOLDER_H
#include<set>
class Message;
class Folder
{
	public:
		Folder(){ }
		Folder(const Folder&);	
		Folder & operator=(const Folder&);
		void addMsg(Message*);
		void remMsg(Message*);
	private:
		std::set<Message*> messages;
		
};
#endif
