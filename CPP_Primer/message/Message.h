/*************************************************************************
    > File Name: Message.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 22时04分37秒
 ************************************************************************/

#ifndef _MESSAGE_H
#define _MESSAGE_H
#include<string>
#include<set>
class Folder;
class Message
{
	public:
		Message(const std::string &str= ""):
			contents(str){}
		Message(const Message&);
		Message & operator=(const Message &);
		~Message();

		void save(Folder&);
		void remove(Folder &);
	private:
		std::string contents;
		std::set<Folder*> folders;
		void put_Msg_in_Folders(const std::set<Folder*> &);
		void remove_Msg_from_Folders();

		void addFldr(Folder*);
		void remFldr(Folder*);
};

#endif
