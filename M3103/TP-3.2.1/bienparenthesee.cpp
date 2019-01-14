/* 
 * File:   newmain.cpp
 * Author: hb
 *
 * Created on 16 octobre 2014, 16:23
 */

#include <stack>          // pour les piles
#include <string>         // pour les chaînes
#include <iostream>
#include <cstdlib>
#include "PrecondVioleeExcep.h"

using namespace std;

bool estBienParentheseeSimple(string maChaine) {
    /*
     * A COMPLETER
     */
    stack<char> ouverture;
    int fermeture = 0;
    // A SUPPRIMER ENSUITE
        for(int i=0; i<maChaine.size() && fermeture%2==0; i++){
            if (maChaine[i] == ')')
                fermeture++;
            
            if (maChaine[i] == '(')
                ouverture.push(maChaine[i]);
            else if (!ouverture.empty() && maChaine[i] == ')'){
                ouverture.pop();
                fermeture++;                
            }
        }
    
        return ouverture.empty() && fermeture%2==0;
}

void testeEstBienParentheseeSimple() {
    cout << "DEBUT testeEstBienParentheseeSimple()" << endl << endl;
    string chaineVide;
    cout << "Une chaîne vide est-elle bien parenthésée : " << estBienParentheseeSimple(chaineVide) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine1 = "(";
    cout << "La chaîne \"(\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine1) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine2 = ")";
    cout << "La chaîne \")\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine2) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine3 = "()";
    cout << "La chaîne \"()\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine3) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine4 = "(((()(()))))";
    cout << "La chaîne \"((((()(()))))\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine4) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine5 = "(((()(())))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine5) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine6 = "(((()(())))))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine6) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    cout << "DEBUT testeEstBienParentheseeSimple()" << endl << endl;
}

bool estBienParenthesee(string maChaine) {
    /*
     * A COMPLETER
     */
    // A SUPPRIMER ENSUITE
    stack<char> ouverture;
    int fermeture = 0;//indicateur qui permet de connaitre les fermetures sans ouvertures.
    
    
    for(int i = 0; i<maChaine.size() && fermeture%2==0; i++){
        if (maChaine[i] == ')' || maChaine[i] == '}' || maChaine[i] == ']')
            fermeture++;
        
        if (maChaine[i] == '(' || maChaine[i] == '{' || maChaine[i] == '[')
            ouverture.push(maChaine[i]);
        else if (!ouverture.empty()){
             if (ouverture.top() == '(' && maChaine[i] == ')'){
                fermeture++;
                ouverture.pop();
             }
            else if (ouverture.top() == '[' && maChaine[i] == ']'){
                fermeture++;
                ouverture.pop();
            }
            else if (ouverture.top() == '{' && maChaine[i] == '}'){                
                fermeture++;
                ouverture.pop();        
            }
        }
    } 
    
    return ouverture.empty() && fermeture%2==0;
}

void testeEstBienParenthesee() {
    cout << "DEBUT testeEstBienParenthesee()" << endl << endl;

    cout << "--> début tests de non régression" << endl << endl;
    string chaineVide;
    cout << "Une chaîne vide est-elle bien parenthésée : " << estBienParenthesee(chaineVide) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine1 = "(";
    cout << "La chaîne \"(\" est-elle bien parenthésée : " << estBienParenthesee(chaine1) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine2 = ")";
    cout << "La chaîne \")\" est-elle bien parenthésée : " << estBienParenthesee(chaine2) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine3 = "()";
    cout << "La chaîne \"()\" est-elle bien parenthésée : " << estBienParenthesee(chaine3) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine4 = "(((()(()))))";
    cout << "La chaîne \"((((()(()))))\" est-elle bien parenthésée : " << estBienParenthesee(chaine4) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine5 = "(((()(())))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParenthesee(chaine5) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine6 = "(((()(())))))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParenthesee(chaine6) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    cout << "--> fin tests de non régression" << endl << endl;

    cout << "--> début tests généraux" << endl << endl;
    string chaine7 = "({[";
    cout << "La chaîne \"({[\" est-elle bien parenthésée : " << estBienParenthesee(chaine7) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine8 = "({})";
    cout << "La chaîne \"({})\" est-elle bien parenthésée : " << estBienParenthesee(chaine8) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine9 = "({}])";
    cout << "La chaîne \"({}])\" est-elle bien parenthésée : " << estBienParenthesee(chaine9) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine10 = "({}[()(())][{(())}[{}(())]])";
    cout << "La chaîne \"({}[()(())][{(())}[{}(())]])\" est-elle bien parenthésée : " << estBienParenthesee(chaine10) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine11 = "({}[()(())][{(())}[{}((())]])";
    cout << "La chaîne \"({}[()(())][{(())}[{}((())]])\" est-elle bien parenthésée : " << estBienParenthesee(chaine11) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine12 = "({}[()(())][{(())}[{}(()()]])";
    cout << "La chaîne \"({}[()(())][{(())}[{}(()()]])\" est-elle bien parenthésée : " << estBienParenthesee(chaine12) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    cout << "--> fin tests généraux" << endl << endl;

    cout << "DEBUT testeEstBienParenthesee()" << endl << endl;
}

/*
 * 
 */
int main() {
    testeEstBienParentheseeSimple();
    testeEstBienParenthesee();
    return 0;
}

// TRACE ATTENDUE
/*
DEBUT testeEstBienParentheseeSimple()

Une chaîne vide est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "(" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne ")" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "()" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "((((()(()))))" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "(((()(())))" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "(((()(())))" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

DEBUT testeEstBienParentheseeSimple()

DEBUT testeEstBienParenthesee()

--> début tests de non régression

Une chaîne vide est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "(" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne ")" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "()" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "((((()(()))))" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "(((()(())))" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "(((()(())))" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

--> fin tests de non régression

--> début tests généraux

La chaîne "({[" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "({})" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "({}])" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "({}[()(())][{(())}[{}(())]])" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "({}[()(())][{(())}[{}((())]])" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "({}[()(())][{(())}[{}(()()]])" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

--> fin tests généraux

DEBUT testeEstBienParenthesee() 
 */
