#include "EnvoiReception.hpp"

void EnvoiReception::envoyer_entier(boost::asio::ip::tcp::socket& sock, unsigned long entier)
{
  // à remplacer
  (void)sock; (void)entier;
}

void EnvoiReception::envoyer_chaine(boost::asio::ip::tcp::socket& sock, const std::string& chaine)
{
  // à remplacer
  (void)sock; (void)chaine;
}

unsigned long EnvoiReception::recevoir_entier(boost::asio::ip::tcp::socket& sock)
{
  // à remplacer
  (void)sock;
  return 0;
}

std::string EnvoiReception::recevoir_chaine(boost::asio::ip::tcp::socket& sock)
{
  // à remplacer
  (void)sock;
  return "";
}
