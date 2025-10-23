#include <iostream>
using namespace std;

struct EventSystem {
    void (*handlers[100])(const string&);
    int count = 0;
};

void registerHandler(EventSystem& system, void(*handlers)(const string &message)) {
    system.handlers[system.count] = handlers;
    system.count++;
}

void triggerEvent(const EventSystem &system, const string &message) {
    for (int i = 0; i < system.count; i++)
    {
        system.handlers[i](message);
    }
}

void onUserLogin(const string &message) {
    cout << "Пользователь вошел в систему: " << message << endl;
}
void onUserLogout(const string &message) {
    cout << "Пользователь вышел из системы: " << message << endl;
}
void onError(const string &message) {
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

