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

  boost::asio::io_service service_es;
  boost::asio::ip::tcp::acceptor socket_ecoute;
};

#endif // SERVEUR_HPP_
