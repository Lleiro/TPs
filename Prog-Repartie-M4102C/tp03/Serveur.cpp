#include <iostream>

#include "Serveur.hpp"
#include "EnvoiReception.hpp"

using namespace std;
using boost::asio::ip::tcp;

Serveur::Serveur(unsigned short n_port):
socket_ecoute(service_es,tcp::endpoint(tcp::v4(), n_port))
{}
//---------------------------------------------------------------------------------/

[[noreturn]] void Serveur::attend_clients(void)
{
  //--TODO-- à compléter : afficher adresse IP et port locaux du socket d'écoute--TODO--/


  //------------------------------------------------------------------/

  unsigned long entier=42;

  // on va traiter plusieurs clients séquentiellement
  while(true) {

    //-TODO-- à compléter : déclaration d'un socket --TODO--/
    boost::asio::ip::tcp::socket sock(service_es);
    //------------------------------------------------------/

    cout<<"En attente d'un client..."<<endl;
    //--TODO-- à compléter : attendre une connexion TCP --TODO--/
    socket_ecoute.accept(sock);
    //----------------------------------------------------------/

    //--TODO-- à compléter : afficher adresse IP et n°port du client --TODO--/
    cout << "@IP du client : " << sock.remote_endpoint() << endl ;
    //--TODO-- à compléter : afficher adresse IP et n°port du socket de transfert --TODO--/
    cout << "@IP du socket de transfert : " << sock.local_endpoint() << endl ;
    //-----------------------------------------------------------------------/

    // on envoie un entier au client
    cout<<"Envoi de l'entier "<<entier<<"..."<<flush;
    EnvoiReception::envoyer_entier(sock,entier);
    sleep(2);

    cout<<"OK"<<endl;

    // on envoie une chaîne au client
    string chaineEnvoi("Bonjour");
    cout<<"Envoi d'une chaîne : "<< chaineEnvoi << endl <<flush;
    EnvoiReception::envoyer_chaine(sock,chaineEnvoi);

    sleep(2);
    cout<<"OK"<<endl;

    // on attend un peu avant de fermer la connexion TCP
    sleep(10); // sleep() est plus simple et ne nécessite pas d'inclure <thread>

    entier++;
  }
}
// 192.168.141.126/24



// belhadja@pc-dg-027-06:~/m4102C/tp05/serveur$ netstat -np | grep 4544
// (Not all processes could be identified, non-owned process info
//  will not be shown, you would have to be root to see it all.)
// tcp        0      0 192.168.141.126:47914   193.55.51.227:4544      ESTABLISHED 17679/./bin-gcc/cli 
// Ma machine(192.168.141.126) connecté vers transit = 193.55.51.22

// belhadja@transit:~$ netstat -np | grep 4544
// (Not all processes could be identified, non-owned process info
//  will not be shown, you would have to be root to see it all.)
// tcp        0      0 193.55.51.227:45440     52.142.118.161:443      ESTABLISHED -                   
// tcp        0      0 193.55.51.227:4544      192.168.141.126:47914   ESTABLISHED 19671/./bin-gcc/ser 

// Le transite set connecte a ma machine

