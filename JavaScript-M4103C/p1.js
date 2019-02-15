function somme(){
  var somme=0;
  for(var i=0; i<val.length-1; i++)
    somme +=val[i];

  return somme;
}

function moyenne(){
  return somme()/(val.length -1)
}

function nombreDeZero(){
  var nb=0;
  for(var i=0; i<val.length-1;i++){
    if (val[i] == 0)
      nb++;
  }
  return nb;
}

var val = [];
var valCourrante;

while (valCourrante != -1){
  valCourrante = prompt("Saisir une valeur (rentrez la valeur -1 pour arrêter les saisies)")
  valCourrante = parseInt(valCourrante);
  val.push(valCourrante);
}

alert("Somme de vos valeurs : " + somme() + "\nMoyenne de vos valeurs : " + moyenne()
      + "\nLe nombre de 0 : " + nombreDeZero() );
