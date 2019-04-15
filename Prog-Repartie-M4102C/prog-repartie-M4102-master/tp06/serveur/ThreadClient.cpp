#include <iostream>
#include <mutex>
#include <sys/syscall.h>

#include "ThreadClient.hpp"
#include "Serveur.hpp"
#include "EnvoiReception.hpp"

using namespace std;

ThreadClient::ThreadClient(ClientConnecte& client_, unsigned long numero_client_) :
  client(client_),
  serveur(client_.serveur),
  numero_client(numero_client_)
{ }

void ThreadClient::dialogue_avec_client(void)
{
  serveur.mutex_cout.lock();
  cout<<"Démarrage d'un thread de TID "<<syscall(SYS_gettid)<<" pour le client n°"<<numero_client<<endl;
  serveur.mutex_cout.unlock();
  try
  {
    while(true)
    {
      // Réception d'une chaîne
      string chaine_recue="";
      chaine_recue = EnvoiReception::recevoir_chaine(client.sock);

      serveur.mutex_cout.lock();
	    cout<<"Client "<<numero_client<<" : "<<client.sock.remote_endpoint()<<" Chaîne reçue : "<<chaine_recue<<endl;
      serveur.mutex_cout.unlock();

      serveur.envoyer_message_vers_tous_clients(numero_client,chaine_recue);
    }
  }
  catch(exception& e)
  {
    serveur.mutex_cout.lock();
    cerr<<"Exception dans un thread: "<<e.what()<<endl;
    serveur.mutex_cout.unlock();
  }
    serveur.mutex_cout.lock();
    cout<<"Client déconnecté : "<<client.sock.remote_endpoint()<<endl;
    cout<<"Suppression du client "<<numero_client<<endl;
    serveur.mutex_cout.unlock();


  // Enlever le client de la map, en exclusion mutuelle
  serveur.envoyer_message_vers_tous_clients(0,"Déconnexion du client n°"+to_string(numero_client)); // 0 = n° spécial représentant le serveur

    serveur.mutex_clients.lock();
    serveur.clients.erase(numero_client);
    serveur.mutex_clients.unlock();

    serveur.mutex_cout.lock();
    cout<<"Nombre de clients restants : "<<serveur.nb_clients()<<endl;

    cout<<"Fin du thread de TID "<<syscall(SYS_gettid)<<" associé au client n°"<<numero_client<<endl;
    serveur.mutex_cout.unlock();
}

void ThreadClient::operator()(void)
{
  dialogue_avec_client();
}
