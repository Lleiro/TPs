#include "EnvoiReception.hpp"

void EnvoiReception::envoyer_entier(boost::asio::ip::tcp::socket& sock, unsigned long entier)
{
  boost::asio::write(sock,boost::asio::buffer(&entier, sizeof(unsigned long)));
}

void EnvoiReception::envoyer_chaine(boost::asio::ip::tcp::socket& sock, const std::string& chaine)
{
  envoyer_entier(sock,chaine.size());
  boost::asio::write(sock,boost::asio::buffer(&chaine.front(), chaine.size()));
  
}

unsigned long EnvoiReception::recevoir_entier(boost::asio::ip::tcp::socket& sock)
{                                                     
  unsigned long rep ;
  boost::asio::read(sock,boost::asio::buffer(&rep, sizeof(unsigned long)));
  return rep;
}

std::string EnvoiReception::recevoir_chaine(boost::asio::ip::tcp::socket& sock)
{
  unsigned long taille = recevoir_entier(sock);
  std::string chaine(taille,' ') ;
  boost::asio::read(sock,boost::asio::buffer(&chaine.front(), taille));

  return chaine;
}
