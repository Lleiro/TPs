#ifndef TAMPON_SBQ_HPP_
#define TAMPON_SBQ_HPP_

#include <boost/thread/sync_bounded_queue.hpp>

#include "Tampon.hpp"
#include "Element.hpp"
#include "EcranManchots.hpp"

class TamponSBQ : public Tampon
{
public:
  TamponSBQ(const unsigned long taille_, EcranManchots& ecran_);

  void deposer_element(Element e);
  Element retirer_element(const unsigned long numcons, const unsigned long nummanchot);

private:
  boost::sync_bounded_queue<Element> queue_sync;
};

#endif // TAMPON_SBQ_HPP_
