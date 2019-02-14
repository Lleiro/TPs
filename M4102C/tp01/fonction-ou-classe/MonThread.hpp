#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_

// Classe avec opérateur parenthèses défini
class MonThread
{
public :
  //--TODO-- à remplacer --TODO--/
  MonThread(unsigned long arg1);
  //-----------------------------/
  void operator()(void);

private :
  //--TODO-- à compléter --TODO--/
  unsigned long m_arg1;
  //-----------------------------/
};

#endif // MONTHREAD_HPP_
