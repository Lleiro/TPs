function mafonction()
{
  i = i*10;
  return(i+j)
}
var i,j;
i=prompt("entrez une valeur");
i=parseInt(i);
j=parseInt(prompt("entrez une valeur"));
r=mafonction();
console.log("resultat : "+ r);
document.write("<H1>Résultat : " + r + "</H1>");
