var memory ="";
var edition=false;

function rab(){
  document.getElementById('zone_affichage').value = "";
}

function calcul(){
  expression = document.getElementById('zone_affichage').value;
  try {
    expression = eval(expression);
    if (typeof(expression) != "number")
      throw "error";
    document.getElementById('zone_affichage').value = expression;
  }
  catch(err) {
    document.getElementById('zone_affichage').value = "";
    alert(err.message);
  }
}

function affiche(bouton){
  document.getElementById("zone_affichage").value += bouton.value;
}

function init(){
  elements = document.getElementsByClassName("bouton_simple");
  for(elem of elements){
    elem.setAttribute("onClick", "affiche(this)");
  }

  elements = document.getElementsByClassName("bouton_libre");
  for(elem of elements) {
    elem.value = getCookie(elem.id);
  }

}

function plusoumoins(){
  str = document.getElementById("zone_affichage").value;
  if (str.charAt(0) != "-")
    str = "-" + str;
  else
    str = str.substr(1, str.length)
  document.getElementById("zone_affichage").value = str;
}

function range_memory(){
  memory = document.getElementById("zone_affichage").value;
}

function affiche_memory(){
    document.getElementById("zone_affichage").value += memory;
}

function raz_memory(){
  memory = "undefined";
}

function mode_edition(){
  edition = true;
  document.getElementById("E").style.color = "red";
  document.getElementById("E").setAttribute("onClick", "mode_calcul()");

  elements = document.getElementsByClassName("bouton_simple");
  for(elem of elements)
    elem.removeAttribute("onClick");

  elements = document.getElementsByClassName("bouton_libre");
  for(elem of elements)
    elem.setAttribute("ondblclick" , "edit(this)");
}

function mode_calcul(){
  edition = false;
  document.getElementById("E").style.color = "black";
  document.getElementById("E").setAttribute("onClick", "mode_edition()");

  elements = document.getElementsByClassName("bouton_libre");
  for(elem of elements)
    elem.setAttribute("type", "button");

  elements = document.getElementsByClassName("bouton_simple");
  for(elem of elements)
    elem.setAttribute("onClick", "affiche(this)");

  elements = document.getElementsByClassName("bouton_libre");
  for(elem of elements)
    elem.removeAttribute("ondblclick");
    elem.removeAttribute("onblur");
}

function edit(elem){
  elem.setAttribute("type", "text");
  elem.setAttribute("ondblclick", "fix(this)");
  elem.setAttribute("onblur", "save(this)");
}

function fix(elem) {
    elem.setAttribute("type", "button");
    elem.setAttribute("ondblclick", "edit(this)");
    elem.removeAttribute("onblur");
    save(elem);
}

function save(elem){
  setCookie(elem.id, elem.value, 365);
}

function getCookie(cname) {
  var name = cname + "=";
  var ca = document.cookie.split(';');
  for(var i = 0; i < ca.length; i++) {
    var c = ca[i];
    while (c.charAt(0) == ' ') {
      c = c.substring(1);
    }
    if (c.indexOf(name) == 0) {
      return c.substring(name.length, c.length);
    }
  }
  return "";
}

function setCookie(cname, cvalue, exdays) {
  var d = new Date();
  d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
  var expires = "expires="+d.toUTCString();
  document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function zone_affichage(){
  elem = document.getElementById("ligne_affichage");
  calc = document.getElementById("calc")
  if (calc.firstElementChild == elem)
    calc.appendChild(elem);
  else
    calc.insertBefore(elem, calc.firstElementChild);
}
