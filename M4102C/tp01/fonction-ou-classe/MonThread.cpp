#include <iostream>
#include "MonThread.hpp"

using namespace std;

//--TODO-- à remplacer --TODO--/
MonThread::MonThread(unsigned long arg1) : m_arg1(arg1) {}
//-----------------------------/

void MonThread::operator()(void)
{
//--TODO-- à compléter --TODO--/
cout << m_arg1;
//-----------------------------/
}
