#include <bits/stdc++.h>

using namespace std;

#define space(x) {int i; for(i = 0; i < x; i++) cout<<endl;}

class SendMessage {
  private:
    list<string> _sm;

  public:

    void set_sm(string s) {
        this->_sm.push_front(s);
    }

    string get_sm() {
        if(!_sm.empty())
            return this->_sm.front();
        return "No sent message\n";
    }

    int get_total_msg_sent() {
        return _sm.size();
    }

    list<string> get_msgs() {
        list <string> s; //for return empty
        if(!_sm.empty())
            return _sm;
        return s;
    }
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

    list<string> get_rec_msgs() {
        list<string> r;//for return empty
        if(!_rm.empty())
            return _rm;
        return r;
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

    void sendMsg(Message &receiver, string s) {
        sm.set_sm(s);
        receiver.rm.set_rm(s);
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

    void findMsg(string s) {
        list<string> fmsg = sm.get_msgs();

        auto it = find(fmsg.begin(), fmsg.end(), s);

        if(it != fmsg.end())
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
    }

    void showAllMsg() {
        list<string> s = sm.get_msgs();
        list<string> r = rm.get_rec_msgs();

        if(s.empty() && r.empty()) {
            cout<<"No Message Found"<<endl;
            return;
        }

        //reverse list for showing from old to recent
        reverse(s.rbegin(), s.rend());
        reverse(r.rbegin(), r.rend());

        cout<<this->userName<<" -> "<<"Sent Messages: ";
        for(auto it = s.begin(); it != s.end(); it++)
            cout<<*it<<" ";

        cout<<endl;

        cout<<this->userName<<" -> ""Received Messages : ";
        for(auto it = r.begin(); it != r.end(); it++)
            cout<<*it<<" ";

        cout<<endl;
    }
};

int main() {
    Message user1("Tony"), user2("Rohan");

   user1.sendMsg(user2, "Hello!");
   user1.showSendMsg();
   user2.showReceiveMsg();

   user2.sendMsg(user1, "Hey!");
   user2.showSendMsg();
   user1.showReceiveMsg();

   user1.sendMsg(user2, "How are you?");
   user1.showSendMsg();
   user2.showReceiveMsg();

   user2.sendMsg(user1, "I am fine, what about you?");
   user2.showSendMsg();
   user1.showReceiveMsg();

   space(2);

   user1.totalReceivedMsgCount();
   user2.totalReceivedMsgCount();

   space(2);
   user1.findMsg("Hello!");

    space(2);

    user1.showAllMsg();
    user2.showAllMsg();

    return 0;
}
