#include <iostream>
using namespace std;

class HandlersList {
    struct Node {
    public:
        void (*handler)(const string&);
        Node* next;
        Node* prev;

        Node(void(*Handler)(const string&)) : handler(Handler), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    void push_back(void(*Handler)(const string&)) {
        Node* node = new Node(Handler);
        if (tail == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    void display(const string &mes) {
        Node* node = head;
        while (node != nullptr) {
            node->handler(mes);
            node = node->next;
        }
    }

};
struct EventSystem {
    HandlersList hl;
};


void registerHandler(EventSystem& system, void(*handlers)(const string& message)) {
    system.hl.push_back(handlers);
}
void triggerEvent(EventSystem& system, const string& message) {
    system.hl.display(message);
}
void onUserLogin(const string& message) {
    cout << "Пользователь вошел в систему: " << message << endl;
}
void onUserLogout(const string& message) {
    cout << "Пользователь вышел из системы: " << message << endl;
}
void onError(const string& message) {
    cout << "Произошла ошибка: " << message << endl;
}


int main()
{
    setlocale(LC_ALL, "ru");

    EventSystem sys;
    registerHandler(sys, onUserLogin);
    registerHandler(sys, onUserLogout);
    registerHandler(sys, onError);

    triggerEvent(sys, "User");
    triggerEvent(sys, "Error");
}
