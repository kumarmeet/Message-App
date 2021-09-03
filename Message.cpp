#include <bits/stdc++.h>

using namespace std;

#define space(x) {int i; for(i = 0; i < x; i++) cout<<endl;}

class SendMessage {
  private:
    list<string> _sm;

  public:

    void set_sm(string s) {
        this->_sm.push_front(s);
        auto it = _sm.begin();
        *it++;
    }

    string get_sm() {
        if(!_sm.empty())
            return this->_sm.front();
        return "No sent message\n";
    }

    int get_total_msg_sent() {
        return _sm.size();
    }

//    list<string>::iterator get_msgs() {
//        if(!_sm.empty())
//            return _sm.begin();
//    }
};

class ReceiveMessage {
  private:
    list<string> _rm;

  public:
    void set_rm(string s) {
        this->_rm.push_front(s);
    }

    string get_rm() {
        if(!_rm.empty())
            return this->_rm.front();
        return "No received message\n";
    }

    int get_total_msg_received() {
        return _rm.size();
    }
};

class Message {
  private:
    SendMessage sm;
    ReceiveMessage rm;
    string userName;

  public:
    Message(string userName) {
        this->userName = userName;
    }

    void sendMsg(Message &user2, string s) {
        sm.set_sm(s);
        user2.rm.set_rm(s);
    }

    void showSendMsg() {
        cout<<userName<<" sent -> "<<this->sm.get_sm()<<endl;
    }

    void showReceiveMsg() {
        cout<<userName<<" received -> "<<this->rm.get_rm()<<endl;
    }

    void totalSentMsgCount() {
        cout<<userName<<" has total sent messages are -> "<<sm.get_total_msg_sent()<<endl;
    }

    void totalReceivedMsgCount() {
        cout<<userName<<" total received messages are -> "<<rm.get_total_msg_received()<<endl;
    }

//    void findMsg(string s) {
//        auto it = sm.get_msgs();
//        cout<<*it--;
//        return;
//    }

};

int main() {
    Message user1("Tony"), user2("Rohan");

    user1.sendMsg(user2, "Hello!");
    user2.showReceiveMsg();
    user2.sendMsg(user1, "Hey!");
    user1.showReceiveMsg();
    user1.sendMsg(user2, "How are you?");
    user2.showReceiveMsg();
    user2.sendMsg(user1, "I am fine, what about you?");
    user1.showReceiveMsg();

    space(2);
    user1.totalReceivedMsgCount();
    user2.totalReceivedMsgCount();

    space(2);
//    user1.findMsg("Hello");

    return 0;
}
