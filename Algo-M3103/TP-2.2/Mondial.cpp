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
#include <vector>

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
    XMLElement* desertsCategory = racineMondial->FirstChildElement("desertscategory");
    XMLElement* currentDessert = desertsCategory->FirstChildElement();
    
    while (currentDessert != nullptr) {
        // un aéroport supplémentaire
        nb = nb + 1;
        // avancer au frère <airport> suivant de currentAirport
        currentDessert = currentDessert->NextSiblingElement();
    }
    // currentAirport n’a plus de frère {currentAirport == nullptr}, c’est le dernier
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
    XMLElement* currentCategory = theCategory->FirstChildElement();
    
   while (currentCategory != nullptr) {
        // un aéroport supplémentaire
        nb = nb + 1;
        // avancer au frère <airport> suivant de currentAirport
        currentCategory = currentCategory->NextSiblingElement();
    }
    // currentAirport n’a plus de frère {currentAirport == nullptr}, c’est le dernier
    return nb;
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getCountryXmlelementFromNameRec(string countryName) const {
    XMLElement* countriesCategory = racineMondial->FirstChildElement("countriescategory");    
    
    return getCountryXmlelementFromNameRecWorker(countriesCategory->FirstChildElement(), countryName);
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getCountryXmlelementFromNameRecWorker(XMLElement* currentCountryElement, string countryName) const {

    if (currentCountryElement != nullptr) {
        if (currentCountryElement->FirstChildElement("name")->GetText() == countryName) {
            return currentCountryElement;
        } else {
            return getCountryXmlelementFromNameRecWorker(currentCountryElement->NextSiblingElement(), countryName);
        }
    }
    return nullptr;
}

/*
 * A COMPLETER
 */
string Mondial::getCountryCodeFromName(string countryName) const throw (PrecondVioleeExcep) {
    
    XMLElement * currentCountry = getCountryXmlelementFromNameRec(countryName);
    // A SUPPRIMER APRÈS COMPLÉTION
        if (currentCountry != nullptr) 
            return currentCountry->Attribute("car_code");
        else {
            string msg = "Dans getCountryCodeFromName, le pays " + countryName  +" n'existe pas !";
            throw (PrecondVioleeExcep(msg));
        }
    
    
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getCountryXmlelementFromNameIter(string countryName) const {
    XMLElement* countriesCategory = racineMondial->FirstChildElement("countriescategory");
    XMLElement* currentCountry = countriesCategory->FirstChildElement();
    
        while(currentCountry != nullptr && currentCountry->FirstChildElement("name")->GetText() != countryName){
            currentCountry = currentCountry->NextSiblingElement();
        }
    
    
    return currentCountry;
}

/*
 * A COMPLETER
 */
int Mondial::getCountryPopulationFromName(string countryName) const {
     XMLElement * currentCountry = getCountryXmlelementFromNameIter(countryName);
     
        if (currentCountry != nullptr) {
            if (currentCountry->LastChildElement())
                return atoi(currentCountry->LastChildElement("population")->GetText());
            else 
                return 0;                
        } else {
            return -1;
        }
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getCountryXmlelementFromCode(string countryCode) const {
    XMLElement* racine = racineMondial->FirstChildElement("countriescategory");
    XMLElement* currentCode = racine->FirstChildElement();
    
    while (currentCode != nullptr && currentCode->Attribute("car_code") != countryCode){
        currentCode = currentCode->NextSiblingElement();
    }
    
    return currentCode;
}

/*
 * A COMPLETER
 */
void Mondial::printCountryBorders(string countryName) const {
    XMLElement* currentCountry = getCountryXmlelementFromNameIter(countryName);
        
    if (currentCountry != nullptr) {
        XMLElement* borderCountries = currentCountry->FirstChildElement("border");
        
        if (borderCountries == nullptr)
            cout << "Le pays  : " << countryName << ", n'a pas de pays frontalier !" << endl;
        else {
            cout<< "Le pays : " << countryName << endl;
            while(borderCountries){
                cout << "est frontalier avec : " << getCountryXmlelementFromCode(borderCountries->Attribute("country"))->FirstChildElement()->GetText();
                cout << ", la longueur de sa frontière avec celui-ci est : ";
                cout << borderCountries->Attribute("length") << endl;
                borderCountries = borderCountries->NextSiblingElement("border");
            }
        }
        
    } else   
        cout << "Le pays : " <<countryName <<", n'existe pas !" << endl;
}

/*
 * A COMPLETER
 */
XMLElement* Mondial::getRiverXmlelementFromNameIter(string riverName) const {
    XMLElement* racine = racineMondial->FirstChildElement("riverscategory");
    XMLElement* currentRiver = racine->FirstChildElement();
    
    
    while (currentRiver != nullptr && currentRiver->FirstChildElement("name")->GetText() != riverName){
        currentRiver = currentRiver->NextSiblingElement();
    }
    
    // A SUPPRIMER APRÈS COMPLÉTION
    return currentRiver;
}

/*
 * A COMPLETER
 */
void Mondial::printAllCountriesCrossedByRiver(string riverName) const {
    XMLElement * currentRiver = getRiverXmlelementFromNameIter(riverName);
    string codeCountry = "";
    string nameCountry;
    
    // A SUPPRIMER APRÈS COMPLÉTION
    if (currentRiver != nullptr){
        cout << "La rivière : " << riverName << endl << "traverse les pays suivant : ";
        
        for (int i = 0; i < strlen(currentRiver->Attribute("country"))+1; i++){
            
            if (currentRiver->Attribute("country")[i] == ' ' || currentRiver->Attribute("country")[i] == '\0'){ //si le codePays est finit 
                nameCountry = getCountryXmlelementFromCode(codeCountry)->FirstChildElement()->GetText();
                cout << nameCountry << ", ";
                codeCountry = "";
            } else {// si le code pays n'est pas fini
                codeCountry = codeCountry + currentRiver->Attribute("country")[i];
            }
            
        }
        
        cout << "il a la longueur suivante : " << currentRiver->FirstChildElement("length")->GetText() << endl;
    } else 
        cout << "La rivière : " << riverName << " n'existe pas !" << endl;
    
    
    
}

/*
 * A COMPLETER
 */
void Mondial::printCountriesWithProvincesCrossedByRiver(string riverName) const {
    XMLElement * currentRiver = getRiverXmlelementFromNameIter(riverName);
    string codeCountry;
    string nameCountry;    
    
    if (currentRiver != nullptr){
        XMLElement * currentLocation = currentRiver->FirstChildElement("located"); 
        cout << "La rivière : " << riverName << endl << "traverse les pays suivant : ";
        
        while (currentLocation != nullptr){
            codeCountry = currentLocation->Attribute("country");
            nameCountry = getCountryXmlelementFromCode(codeCountry)->FirstChildElement()->GetText();
            
            if (currentLocation->NextSiblingElement("located") == nullptr)
                cout << nameCountry << " ; ";
            else 
                cout << nameCountry << ", ";
            
            currentLocation = currentLocation->NextSiblingElement("located");
        }
        
        cout << "il a la longueur suivante : " << currentRiver->FirstChildElement("length")->GetText() << endl;
        
    } else 
        cout << "La rivière : " << riverName << " n'existe pas !" << endl;
}

/*
 * A COMPLETER
 */
void Mondial::printCountriesAndProvincesCrossedByRiver(string riverName) const {
    XMLElement * currentRiver = getRiverXmlelementFromNameIter(riverName);
    string codeCountry = "";
    string nameCountry;
    string currentProvince ="";
    
    if (currentRiver != nullptr){
        cout << "Le fleuve : " << riverName << " fait " << currentRiver->FirstChildElement("length")->GetText() << " km de long et il traverse les pays suivant : "<< endl;
        
        for (int i = 0; i < strlen(currentRiver->Attribute("country"))+1; i++){
            
            if (currentRiver->Attribute("country")[i] == ' ' || currentRiver->Attribute("country")[i] == '\0'){ //si le codePays est finit 
                nameCountry = getCountryXmlelementFromCode(codeCountry)->FirstChildElement()->GetText();
                
                XMLElement* provincesElement = currentRiver->FirstChildElement("located");
                
                while (provincesElement != nullptr && provincesElement->Attribute("country") != codeCountry){
                    provincesElement = provincesElement->NextSiblingElement("located");                    
                }
                
                if (provincesElement != nullptr){
                    cout << "\t- " << nameCountry << " où il traverse les divisions administratives suivantes : " <<endl;
                    const char * provinces = provincesElement->Attribute("province");
                    
                    for(int j = 0; j < strlen(provinces)+1 ; j++){
                        if (provinces[j] == ' ' || provinces[j] == '\0'){
                            XMLElement* racine = racineMondial->FirstChildElement("countriescategory");
                            XMLElement* currentCountry = racine->FirstChildElement();
                            
                            while(currentCountry != nullptr && currentCountry->FirstChildElement("name")->GetText() != nameCountry){   
                                currentCountry = currentCountry->NextSiblingElement();
                            }
                                if (currentCountry != nullptr){
                                    XMLElement* test =  currentCountry->FirstChildElement("province");
                                    while (test != nullptr && test->Attribute("id") != currentProvince){
                                        test = test->NextSiblingElement("province");
                                    }
                                    if (test != nullptr && test->Attribute("id") == currentProvince)
                                        cout << "\t\t * " <<  test->FirstChildElement("name")->GetText() << endl;
                                }
                            currentProvince = "";
                        } else 
                            currentProvince = currentProvince + provinces[j];
                    }
                    
                } else
                    cout << "\t- " << nameCountry <<endl;
                
                
                codeCountry = "";
            } else {// si le code pays n'est pas fini
                codeCountry = codeCountry + currentRiver->Attribute("country")[i];
            }
            
        }
    } else 
        cout << "La rivière : " << riverName << " n'existe pas !" << endl;
    
        
}

/*
 * A COMPLETER
 */
void Mondial::printCityInformation(string cityName) const {
    XMLElement* racine = racineMondial->FirstChildElement("countriescategory");
    XMLElement* currentCountry = racine->FirstChildElement();
    XMLElement* currentCity = currentCountry->FirstChildElement("city") ;
    
    
    while (currentCountry != nullptr && currentCity != nullptr && currentCity->FirstChildElement("name")->GetText() != cityName){
        
        while (currentCity != nullptr && currentCity->FirstChildElement("name")->GetText() != cityName){
            currentCity = currentCity->NextSiblingElement("city");
        }
        currentCountry = currentCountry->NextSiblingElement();
        currentCity = currentCountry->FirstChildElement("city");
    }
    
    if (currentCity != nullptr)
        cout << currentCity->FirstChildElement("name")->GetText() << endl;
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

