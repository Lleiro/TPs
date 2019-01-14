/* 
 * File:   main.cpp
 * Author: hb
 *
 */

// Documentation à http://www.cplusplus.com/reference/queue/queue/


#include <queue>          // pour les files d'attente
#include <string>         // pour les chaînes
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename TypeInfo>
void afficheFile(queue<TypeInfo> uneFile) {
    // copie de la file dans une file intermédiaire à parcourir et afficher
    queue<TypeInfo> copieFile(uneFile);
    cout << "DEBUT -> ";
    while (!copieFile.empty()) {
        cout << copieFile.front() << " ";
        copieFile.pop();
    }
    cout << " <- FIN" << endl;
} // end afficheListe


void testeEnfile() {
    // déclaration d'une file de strings
    queue<string> maFile;
    
    cout << "DEBUT testeEnfile()" << endl<< endl;
    
    cout << "File vide ? : " << maFile.empty() << " devrait répondre vrai (1) !" << endl << endl;
    
    /* ajout de zéro */
    cout<< "enfile  zéro --> ";
    maFile.push("zéro");
    afficheFile(maFile);
    cout << " - Le premier contient : " << maFile.front() << endl;
    
    /* ajout de un */
    cout<< "enfile  un --> ";
    maFile.push("un");
    afficheFile(maFile);
    cout << " - Le premier contient : " << maFile.front() << endl;
    
    /* ajout de deux */
    cout<< "enfile  deux --> ";
    maFile.push("deux");
    afficheFile(maFile);
    cout << " - Le premier contient : " << maFile.front() << endl;
    
    /* ajout de trois */
    cout<< "enfile  trois --> ";
    maFile.push("trois");
    afficheFile(maFile);
    cout << " - Le premier contient : " << maFile.front() << endl;
    
    /* ajout de quatre */
    cout<< "enfile  quatre --> ";
    maFile.push("quatre");
    afficheFile(maFile);
    cout << " - Le premier contient : " << maFile.front() << endl;
    
    /* ajout de cinq */
    cout<< "enfile  cinq --> ";
    maFile.push("cinq");
    afficheFile(maFile);
    cout << " - Le premier contient : " << maFile.front() << endl;
    
    cout << endl << "File vide ? : " << maFile.empty() << " devrait être faux (0) !" << endl << endl;
    cout << "FIN testeEnFile()" << endl <<endl;
    
    /*
     DEBUT testeEnfile()

    File vide ? : 1 devrait répondre vrai (1) !

    enfile zéro --> DEBUT -> zero  <- FIN
    - le premier contient : zero
    enfile un --> DEBUT -> zero un  <- FIN
    - le premier contient : zero
    enfile deux --> DEBUT -> zero un deux  <- FIN
    - le premier contient : zero
    enfile trois --> DEBUT -> zero un deux trois  <- FIN
    - le premier contient : zero
    enfile quatre --> DEBUT -> zero un deux trois quatre  <- FIN
    - le premier contient : zero
    enfile cinq --> DEBUT -> zero un deux trois quatre cinq  <- FIN
    - le premier contient : zero
    File vide ? : 0 devrait répondre faux (0) !

    FIN testeEnfile()
     */


}

void testeDefile() {
    // déclaration d'une file de strings
    queue<string> maFile;
    
//DEBUT testeDefile()
//
//  Remplissage de la file --> DEBUT -> zero un deux trois quatre cinq  <- FIN
//
//  3 consultations du premier et défile
//   ma file actuelle --> DEBUT -> zero un deux trois quatre cinq  <- FIN
//  sommet actuel : zero
//   ma file actuelle --> DEBUT -> un deux trois quatre cinq  <- FIN
//  sommet actuel : un
//   ma file actuelle --> DEBUT -> deux trois quatre cinq  <- FIN
//  sommet actuel : deux
//   ma file actuelle --> DEBUT -> trois quatre cinq  <- FIN
//  sommet actuel : trois
//
//FIN testeDefile()
    
}

void testeBorneDefile() {
    // déclaration d'une file de strings
    queue<string> maFile;
    
//DEBUT testeBorneDefile()
//
// Remplissage de la file -->   ma file actuelle -> DEBUT -> zero un deux trois quatre cinq  <- FIN
//
// Séquence de vidage de la file ->
//  ma file actuelle -> DEBUT -> un deux trois quatre cinq  <- FIN
//  ma file actuelle -> DEBUT -> deux trois quatre cinq  <- FIN
//  ma file actuelle -> DEBUT -> trois quatre cinq  <- FIN
//  ma file actuelle -> DEBUT -> quatre cinq  <- FIN
//  ma file actuelle -> DEBUT -> cinq  <- FIN
//  ma file actuelle -> DEBUT ->  <- FIN
//
//  File vide ? : 1 devrait répondre vrai (1) !
//
// pop() protégé sur une file vide :
//  /!\ pop() sur une file vide ne délenche pas d'exeption ; on a un comportement idéfini
//  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !
//
//  -> /!\ DESOLE, la file est vide, pas de pop() possible !
//
// front() protégé sur une file vide : 
//  /!\ front() sur une file vide ne délenche pas d'exeption ; on a un comportement idéfini
//  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !
//
//  -> /!\ DESOLE, la file est vide, pas de front() possible !
//
// front() non protégé sur une file vide : 
//  front() : 
//  File vide après front() non protégé ? : 1 devrait répondre vrai (1) !
//  C'est OK, la file semble encore vide, mais front() n'a pas retourné de résultat (deux lignes plus haut) !
//  La taille de la file est : 0
//
// pop() non protégé sur une file vide : 
//  File vide après pop() non protégé ? : 0 devrait répondre vrai (1) !
//  C'est étrange, la file devrait être vide !
//  La taille de la file est : 18446744073709551615 ; n'est ce pas surprenant !!
//
//FIN testeBorneDefile()
    
}

int main() {
    testeEnfile();
    testeDefile();
    testeBorneDefile();
    return 0;
} // end main

/*
DEBUT testeEnfile()

  File vide ? : 1 devrait répondre vrai (1) !

  enfile zéro --> DEBUT -> zero  <- FIN
   - le premier contient : zero
  enfile un --> DEBUT -> zero un  <- FIN
   - le premier contient : zero
  enfile deux --> DEBUT -> zero un deux  <- FIN
   - le premier contient : zero
  enfile trois --> DEBUT -> zero un deux trois  <- FIN
   - le premier contient : zero
  enfile quatre --> DEBUT -> zero un deux trois quatre  <- FIN
   - le premier contient : zero
  enfile cinq --> DEBUT -> zero un deux trois quatre cinq  <- FIN
   - le premier contient : zero
  File vide ? : 0 devrait répondre faux (0) !

FIN testeEnfile()

DEBUT testeDefile()

  Remplissage de la file --> DEBUT -> zero un deux trois quatre cinq  <- FIN

  3 consultations du premier et défile
   ma file actuelle --> DEBUT -> zero un deux trois quatre cinq  <- FIN
  sommet actuel : zero
   ma file actuelle --> DEBUT -> un deux trois quatre cinq  <- FIN
  sommet actuel : un
   ma file actuelle --> DEBUT -> deux trois quatre cinq  <- FIN
  sommet actuel : deux
   ma file actuelle --> DEBUT -> trois quatre cinq  <- FIN
  sommet actuel : trois

FIN testeDefile()

DEBUT testeBorneDefile()

 Remplissage de la file -->   ma file actuelle -> DEBUT -> zero un deux trois quatre cinq  <- FIN

 Séquence de vidage de la file ->
  ma file actuelle -> DEBUT -> un deux trois quatre cinq  <- FIN
  ma file actuelle -> DEBUT -> deux trois quatre cinq  <- FIN
  ma file actuelle -> DEBUT -> trois quatre cinq  <- FIN
  ma file actuelle -> DEBUT -> quatre cinq  <- FIN
  ma file actuelle -> DEBUT -> cinq  <- FIN
  ma file actuelle -> DEBUT ->  <- FIN

  File vide ? : 1 devrait répondre vrai (1) !

 pop() protégé sur une file vide :
  /!\ pop() sur une file vide ne délenche pas d'exeption ; on a un comportement idéfini
  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !

  -> /!\ DESOLE, la file est vide, pas de pop() possible !

 front() protégé sur une file vide : 
  /!\ front() sur une file vide ne délenche pas d'exeption ; on a un comportement idéfini
  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !

  -> /!\ DESOLE, la file est vide, pas de front() possible !

 front() non protégé sur une file vide : 
  front() : 
  File vide après front() non protégé ? : 1 devrait répondre vrai (1) !
  C'est OK, la file semble encore vide, mais front() n'a pas retourné de résultat (deux lignes plus haut) !
  La taille de la file est : 0

 pop() non protégé sur une file vide : 
  File vide après pop() non protégé ? : 0 devrait répondre vrai (1) !
  C'est étrange, la file devrait être vide !
  La taille de la file est : 18446744073709551615 ; n'est ce pas surprenant !!

FIN testeBorneDefile()

Segmentation fault: 11
 */
