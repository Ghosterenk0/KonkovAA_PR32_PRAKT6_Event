#include <iostream>
#include <Windows.h>
using namespace std;

struct EventSystem {
    void (*handlers[100])();
    int count = 0;
};

void registerHandler(EventSystem& system, void(*handlers)()) {
    
}

void triggerEvent(const EventSystem &system) {

}

void onUserLogin() {
    if (true) {
        cout << "Пользователь вошел в систему"; 
    }
}
void onUserLogout() {
    if (true) {
        cout << "Пользователь вышел из системы";
    }
}
void onError() {
    if (true) {
        cout << "Произошла ошибка";
    }
}

int main()
{
    EventSystem sys;
    registerHandler(sys, *sys.handlers);
}

