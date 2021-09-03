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

    int get_total_msg_sent()
    {
      return _sm.size();
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

    int get_total_msg_received()
    {
      return _rm.size();
    }
};

class Message
{
private:
    SendMessage sm;
    ReceiveMessage rm;
    string userName;

public:
    Message(string userName)
    {
      this->userName = userName;
    }

    void sendMsg(Message &user2, string s)
    {
        sm.set_sm(s);
        user2.rm.set_rm(s);
    }

    void showSendMsg()
    {
        cout<<userName<<" -> "<<this->sm.get_sm()<<endl;
    }

    void showReceiveMsg()
    {
        cout<<userName<<" -> "<<this->rm.get_rm()<<endl;
    }

    void totalSentMsg()
    {
      cout<<userName<<" -> "<<sm.get_total_msg_sent()<<endl;
    }

    void totalReceivedMsg()
    {
      cout<<userName<<" -> "<<rm.get_total_msg_received()<<endl;
    }
};

int main()
{
    Message user1("Tony"), user2("Rohan");

    user1.sendMsg(user2, "Hello!");
    user1.sendMsg(user2, "How are you?");
    user1.showSendMsg();
    user2.showReceiveMsg();

    user2.sendMsg(user1, "Hey!");
    user2.sendMsg(user1, "I am fine, what about you?");
    user2.showSendMsg();
    user1.showReceiveMsg();
    return 0;
}
