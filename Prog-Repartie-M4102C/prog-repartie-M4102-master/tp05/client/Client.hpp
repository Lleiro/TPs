#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <boost/asio.hpp>

class Client
{
public :
  Client(std::string nom, unsigned short n_port);
  void dialogue_avec_serveur(void);

private :
  // io_service et socket
  boost::asio::io_service service_es;
  boost::asio::ip::tcp::socket sock;
};

#endif // CLIENT_HPP_
