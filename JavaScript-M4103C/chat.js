function chat(nom,couleur,age){
  this.nom= nom;
  this.couleur= couleur;
  this.age = age;
}

function miauler(msg){
  alert(msg);
}

tigroo = new chat("tigroo","roux",12);
bestiole = new chat("baghera","gris",1);
elcato = new chat("YesSir","gris",8);
michou = new chat("pasdenom","vert",124);

chats = [tigroo,bestiole,elcato,michou];

for (var i=0; i<chats.length; i++) {
  console.log(i);
  alert("Descriptif du chat : \n" + "Petit nom : " + chats[i].nom +
        "\nCouleur : " + chats[i].couleur + "\nAge : " + chats[i].age + "\nET MAINTENANT SON RUGISSEMENT DE TIGRE !!!!!!!!!")
  if (i == chats.length-1){
    chats[i].prototype = new miauler("uoaim !");
  } else
    chats[i].prototype = new miauler("miaou !");
}
