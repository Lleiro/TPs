#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_

// Classe avec opérateur parenthèses défini
class MonThread
{
public :
  MonThread(const unsigned long num);
  void operator()(void);

private :
  const unsigned long numero;
};

#endif // MONTHREAD_HPP_
