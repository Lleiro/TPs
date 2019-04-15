#include <iostream>
#include <thread>
#include "MonThread.hpp"

using namespace std;

MonThread::MonThread(const unsigned long num): numero(num) {}


void MonThread::operator()(void)
{
    cout << numero;
}
