#include <bits/stdc++.h>

using namespace std;

class SendMessage
{
private:
    list<string> _sm;

public:

    void set_sm(string s)
    {
        this->_sm.push_front(s);
    }

    string get_sm()
    {
        return this->_sm.front();
    }
};

class ReceiveMessage
{
private:
    list<string> _rm;

public:
    void set_rm(string s)
    {
        this->_rm.push_front(s);
    }

    string get_rm()
    {
        return this->_rm.front();
    }
};

class Message
{
private:
    SendMessage sm;
    ReceiveMessage rm;
    string userName;
public:
    Message(string s)
    {
      userName = s;
    }
    void sendMsg(Message &_sm, string s)
    {
        _sm.sm.set_sm(s);
        this->rm.set_rm(s);
    }

    void showSendMsg()
    {
        cout<<userName<<" -> "<<this->rm.get_rm()<<endl;
    }

    void showReceiveMsg()
    {
        cout<<userName<<" -> "<<this->rm.get_rm()<<endl;
    }
};

int main()
{
    Message user1("Tony"), user2("Rohan");

    user1.sendMsg(user2, "Hello!");
    user1.showReceiveMsg();

    user2.sendMsg(user1, "Hey!");
    user2.showReceiveMsg();
    return 0;
}
