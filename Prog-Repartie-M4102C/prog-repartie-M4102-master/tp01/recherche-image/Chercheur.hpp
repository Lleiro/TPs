#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_
#include "ImagePPM.hpp"

// Classe pour stocker le résultat des recherches effectuées par chaque thread
class SearchImageData
{
  public :
    int match;     // meilleure correspondance trouvée dans l'image
    int x;         // position de cette meilleure correspondance
    int y;
    SearchImageData() : match(0), x(0), y(0) {}
};

// Classe avec opérateur parenthèses défini
class Chercheur
{
  public :
    Chercheur (t_image& src, t_image& qu, SearchImageData& sid);

    void operator()(void);

  private :
    t_image& source;
    t_image& query;
    SearchImageData& data;
};

#endif // MONTHREAD_HPP_
