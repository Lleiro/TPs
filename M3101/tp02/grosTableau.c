#define N 18432 
#define P 2 

static volatile char Image[N][N]; // image de N lignes et N colonnes

int main()
{
  int iter;
  int colonne;
  int ligne;

  // parcours de l'image
  for (iter=0; iter<P; iter++) // P parcours
    for (colonne=0; colonne<N; colonne++) // pour chaque colonne faire..
    for (ligne=0; ligne<N; ligne++)       // pour chaque ligne faire..
    {
      Image[ligne][colonne] = P;
    }

  return 0;
}
