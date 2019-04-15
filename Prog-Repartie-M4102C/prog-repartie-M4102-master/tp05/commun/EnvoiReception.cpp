#include "EnvoiReception.hpp"

void EnvoiReception::envoyer_entier(boost::asio::ip::tcp::socket& sock, unsigned long entier)
{
  boost::asio::write(sock, boost::asio::buffer(&entier, sizeof(unsigned long)));
}

void EnvoiReception::envoyer_chaine(boost::asio::ip::tcp::socket& sock, const std::string& chaine)
{
  // Envoyer la taille de la chaine en premier
  envoyer_entier(sock, chaine.size());

  // Envoyer la chaîne en deuxième
  boost::asio::write(sock, boost::asio::buffer(&chaine.front(), chaine.size()));
}

unsigned long EnvoiReception::recevoir_entier(boost::asio::ip::tcp::socket& sock)
{
  unsigned long entier_recu = 0;
  boost::asio::read(sock, boost::asio::buffer(&entier_recu, sizeof(unsigned long)));
  return entier_recu;
}

std::string EnvoiReception::recevoir_chaine(boost::asio::ip::tcp::socket& sock)
{
  // Recevoir la taille de la chaîne en premier
  unsigned long taille = recevoir_entier(sock);

  // Recevoir la chaîne en deuxième
  std::string chaine;
  chaine.resize(taille);
  boost::asio::read(sock, boost::asio::buffer(&chaine.front(), taille));

  return chaine;
}
