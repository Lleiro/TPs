#include <iostream>
#include <thread>
#include <chrono>
#include "Chercheur.hpp"
#include "ImagePPM.hpp"

using namespace std;

Chercheur::Chercheur (t_image& src, t_image& qu, SearchImageData& sid) :
  source(src),
  query(qu),
  data(sid)
  {}

void Chercheur::operator()(void)
{
  search_image(source, query, data.x, data.y, data.match);
}
