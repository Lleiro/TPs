#ifndef OUTILS_COND_HPP_
#define OUTILS_COND_HPP_

#include <mutex>
#include <condition_variable>

#include "Outils.hpp"

class OutilsCond : public Outils
{
public :
  OutilsCond();

  void debut_lecture(void);
  void fin_lecture(void);
  void debut_ecriture(void);
  void fin_ecriture(void);

private:
  int nb_lec;
  int nb_red;
  std::mutex mon_mutex;
  std::condition_variable ma_condition;
};

#endif // OUTILS_COND_HPP_
