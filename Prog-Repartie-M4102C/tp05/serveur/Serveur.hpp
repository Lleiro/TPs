#ifndef SERVEUR_HPP_
#define SERVEUR_HPP_

#include <boost/asio.hpp>

class Serveur
{
public :
  Serveur(unsigned short n_port);

  [[noreturn]] void attend_clients(void);

private :
  //--TODO-- à compléter : io_service et acceptor --TODO--/
  //------------------------------------------------------/
};

#endif // SERVEUR_HPP_
