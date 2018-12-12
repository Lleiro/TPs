/* 
 * File:   Mondial.cpp
 * Author: hb
 * 
 * Created on 22 novembre 2018, 16:05
 */

#include "Mondial.h"

#include <iostream>     // pour cout
#include <iomanip>      // pour setw()
#include <limits>       // pour numeric_limits<unsigned int>::max
#include <sstream>
#include <iterator>

Mondial::Mondial(const char* filename) {
    // Chargement du fichier XML en mémoire
    imageMondial.LoadFile(filename);
    // Initialisation de l'attribut racineMondial avec la racine (élément <mondial>)
    racineMondial = imageMondial.FirstChildElement();
}

void Mondial::Print() {
    imageMondial.Print();
}

/*
 * FOURNIE
 */
int Mondial::getNbAirports() const {
    // initialisation du nombre d’aéroports
    int nb = 0;
    // accéder à <airportscategory>, c’est un fils de l'élément <racineMondial>
    XMLElement* airportsCategory = racineMondial->FirstChildElement("airportscategory");
    // parcours complet des fils de <airportscategory> en les comptants
    // 1) accéder au premier fils <airport> de <airportscategory>
    XMLElement* currentAirport = airportsCategory->FirstChildElement();
    // 2) parcourir tous les <airport> qui sont des frères
    while (currentAirport != nullptr) {
        // un aéroport supplémentaire
        nb = nb + 1;
        // avancer au frère <airport> suivant de currentAirport
        currentAirport = currentAirport->NextSiblingElement();
    }
    // currentAirport n’a plus de frère {currentAirport == nullptr}, c’est le dernier
    return nb;
}

/*
 * FOURNIE
 */
void Mondial::printCountriesCode() const {
    int rank = 1; // rang du pays
    string carcodeValue; // valeur de l'attribut "car_cod" du pays courant
    // accéder à <countriescategory>, c’est un fils de l'élément <racineMondial>)
    XMLElement* countriesCategory = racineMondial->FirstChildElement("countriescategory");
    // parcours complet des fils de <countriescategory> en affichant le rang et le code
    // 1) accéder au premier fils <country> de <countriescategory>
    XMLElement* currentCountry = countriesCategory->FirstChildElement();
    // 2) parcourir tous les <country> qui sont des frères
    while (currentCountry != nullptr) {
        // traiter le pays courant
        //      1) récupérer la valeur de l’attribut "car_code"
        carcodeValue = currentCountry->Attribute("car_code");
        //      2) faire l’affichage
        cout << setw(5) << rank << " : " << carcodeValue << endl;
        // avancer au frère <country> suivant de currentCountry
        currentCountry = currentCountry->NextSiblingElement();
        // mettre à jour le rang
        rank = rank + 1;
    }
    // currentCountry n’a pas de frère {currentCountry == nullptr}, c’est fini
}


/*
 * A COMPLETER
 */
int Mondial::getNbDeserts() const {
    // initialisation du nombre d’aéroports
    int nb = 0;

    
    
    return nb;
}

/*
 * A COMPLETER
 */
int Mondial::getNbElemCat(const string categoryName) {
    // décoder le categoryName vers le nom de la balise XML
    string XMLElementName = decod_category[categoryName];
    /*
     * l'accès à la catégorie demandée dans les données se fera avec
     * racineMondial->FirstChildElement(XMLElementName.c_str())
     */
    
    // initialiser le compteur
    int nb = 0;
    // accéder à <NameCategory>
    // attention il faut convertir le XMLElement de type string en un type char* (aux étudiants de trouver !)
    XMLElement* theCategory = racineMondial->FirstChildElement(XMLElementName.c_str());
    
    
    
    
    
    return nb;
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getCountryXmlelementFromNameRec(string countryName) const {
    
    // A SUPPRIMER APRÈS COMPLÉTION
    return nullptr;
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getCountryXmlelementFromNameRecWorker(XMLElement* currentCountryElement, string countryName) const {

    
    // A SUPPRIMER APRÈS COMPLÉTION
    return nullptr;
}

/*
 * A COMPLETER
 */
string Mondial::getCountryCodeFromName(string countryName) const throw (PrecondVioleeExcep) {
    
    
    // A SUPPRIMER APRÈS COMPLÉTION
    return "je dois retourner un code de pays ou lever une exception !";
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getCountryXmlelementFromNameIter(string countryName) const {
    
    
    // A SUPPRIMER APRÈS COMPLÉTION
    return nullptr;
}

/*
 * A COMPLETER
 */
int Mondial::getCountryPopulationFromName(string countryName) const {
    
    
    // A SUPPRIMER APRÈS COMPLÉTION
    return 0;
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getCountryXmlelementFromCode(string countryCode) const {
    
    
    // A SUPPRIMER APRÈS COMPLÉTION
    return nullptr;
}

/*
 * A COMPLETER
 */
void Mondial::printCountryBorders(string countryName) const {
    
    
    // A SUPPRIMER APRÈS COMPLÉTION
    cout << "Je dois afficher des frontières de pays !" << endl;
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getRiverXmlelementFromNameIter(string riverName) const {
    
    
    // A SUPPRIMER APRÈS COMPLÉTION
    return nullptr;
}

/*
 * A COMPLETER
 */
void Mondial::printAllCountriesCrossedByRiver(string riverName) const {
        
    
    // A SUPPRIMER APRÈS COMPLÉTION
    cout << "Je dois afficher tous les pays traversés par un fleuve !" << endl;
}

/*
 * A COMPLETER
 */
void Mondial::printCountriesWithProvincesCrossedByRiver(string riverName) const {
         
    
    // A SUPPRIMER APRÈS COMPLÉTION
    cout << "Je dois afficher tous les pays qui ont des divisions administratives traversés par un fleuve !" << endl;
}

/*
 * A COMPLETER
 */
void Mondial::printCountriesAndProvincesCrossedByRiver(string riverName) const {
         
    
    // A SUPPRIMER APRÈS COMPLÉTION
    cout << "Je dois afficher les pays et pour chaque pays les divisions adminstratives, s'il y en a, traversés par un fleuve !" << endl;
}

/*
 * A COMPLETER
 */
void Mondial::printCityInformation(string cityName) const {
         
    
    // A SUPPRIMER APRÈS COMPLÉTION
    cout << "Je dois afficher les informations relatives à une ville !" << endl;
}

/*
 * Méthodes de service fournies
 */

template<typename Out>
void Mondial::split(string& s, char delim, Out result) const {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<std::string> Mondial::split(string& s, char delim) const {
    vector<std::string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

Mondial::~Mondial() {
}

