package monteile.projetmobile.ressources;

import android.arch.persistence.room.ColumnInfo;
import android.arch.persistence.room.PrimaryKey;
import android.util.Log;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Random;

public class Geographie implements Serializable {
    private ArrayList<String> questionEtReponse;
    private String currentReponse;
    private String currentQuestion;
    private int difficulte;

    public Geographie(int diff) {
        difficulte = diff;
        questionEtReponse = new ArrayList<>();

        if (diff == 1) {
            questionEtReponse.add("Autriche Vienne");
            questionEtReponse.add("Allemagne Berlin");
            questionEtReponse.add("Algérie Alger");
            questionEtReponse.add("Australie Canberra");
            questionEtReponse.add("Belgique Bruxelles");
            questionEtReponse.add("Brésil Brasilia");
            questionEtReponse.add("Bulgarie Sofia");
            questionEtReponse.add("Canada Ottawa");
            questionEtReponse.add("Chine Pékin");
            questionEtReponse.add("Danemark Copenhague");
            questionEtReponse.add("Espagne Madrid");
            questionEtReponse.add("Etats-Unis Washington");
            questionEtReponse.add("Finlande Helsinki");
            questionEtReponse.add("France Paris");
            questionEtReponse.add("Grèce Athènes");
            questionEtReponse.add("Hongrie Budapest");
            questionEtReponse.add("Irlande Dublin");
            questionEtReponse.add("Italie Rome");
            questionEtReponse.add("Japon Tokyo");
            questionEtReponse.add("Luxembourg Luxembourg");
            questionEtReponse.add("Portugal Lisbonne");
            questionEtReponse.add("Suède Stockholm");
            questionEtReponse.add("Suisse Berne");
            questionEtReponse.add("Pays-Bas Amsterdam");
            questionEtReponse.add("Pérou Lima");
            questionEtReponse.add("Russie Moscou");
            questionEtReponse.add("Singapour Singapour");
            questionEtReponse.add("Tunisie Tunis");
            questionEtReponse.add("Turquie Ankara");
            questionEtReponse.add("Corée-du-Sud Séoul");
            questionEtReponse.add("Djibouti Djibouti");
            questionEtReponse.add("Croatie Zagreb");
            questionEtReponse.add("Indonésie Jakarta");
            questionEtReponse.add("Maroc Rabat");
            questionEtReponse.add("Mexique Mexico");
            questionEtReponse.add("Monaco Monaco");
            questionEtReponse.add("République-Tchèque Prague");
            questionEtReponse.add("Roumanie Bucarest");
            questionEtReponse.add("Royaume-Uni Londres");
            questionEtReponse.add("Sénégal Dakar");
            questionEtReponse.add("Vatican Vatican");
            questionEtReponse.add("Côte-d'Ivoire Yamoussoukro");
        } else {
            questionEtReponse.add("Afghanistan Kaboul");
            questionEtReponse.add("Albanie Tirana");
            questionEtReponse.add("Andorre Andorre-la-Vieille");
            questionEtReponse.add("Angola Luanda");
            questionEtReponse.add("Arabie-Saoudite Riyad");
            questionEtReponse.add("Argentine Buenos Aires");
            questionEtReponse.add("Arménie Erevan");
            questionEtReponse.add("Azerbaïdjan Bakou");
            questionEtReponse.add("Bahamas Nassau");
            questionEtReponse.add("Bahreïn Manama");
            questionEtReponse.add("Bangladesh Dacca");
            questionEtReponse.add("Barbade Bridgetown");
            questionEtReponse.add("Belize Belmopan");
            questionEtReponse.add("Bénin Porto-Novo");
            questionEtReponse.add("Bhoutan Thimbu");
            questionEtReponse.add("Biélorussie Minsk");
            questionEtReponse.add("Birmanie Naypyidaw");
            questionEtReponse.add("Bolivie Sucre");
            questionEtReponse.add("Bosnie-Herzégovine Sarajevo");
            questionEtReponse.add("Botswana Gaborone");
            questionEtReponse.add("Burundi Bujumbura");
            questionEtReponse.add("Cameroun Yaoundé");
            questionEtReponse.add("Cap-Vert Praia");
            questionEtReponse.add("Chili Santiago");
            questionEtReponse.add("Chypre Nicosie");
            questionEtReponse.add("Colombie Bogota");
            questionEtReponse.add("Comores Moroni");
            questionEtReponse.add("Congo Brazzaville");
            questionEtReponse.add("Corée-du-Nord Pyongyang");
            questionEtReponse.add("Dominique Roseau");
            questionEtReponse.add("Equateur Quito");
            questionEtReponse.add("Erythrée Asmara");
            questionEtReponse.add("Estonie Tallinn");
            questionEtReponse.add("Ethiopie Addis-Abeba");
            questionEtReponse.add("Fidji Suva");
            questionEtReponse.add("Gabon Libreville");
            questionEtReponse.add("Gambie Banjul");
            questionEtReponse.add("Géorgie Tbilissi");
            questionEtReponse.add("Ghana Accra");
            questionEtReponse.add("Guatemala Guatemala");
            questionEtReponse.add("Guinée Conakry");
            questionEtReponse.add("Guinée-équatoriale Malabo");
            questionEtReponse.add("Guinée-Bissau Bissau");
            questionEtReponse.add("Guyana Georgetown");
            questionEtReponse.add("Haïti Port-au-Prince");
            questionEtReponse.add("Honduras Tegucigalpa");
            questionEtReponse.add("Irak Bagdad");
            questionEtReponse.add("Iran Téhéran");
            questionEtReponse.add("Islande Reykjavik");
            questionEtReponse.add("Israël Jérusalem");
            questionEtReponse.add("Jamaïque Kingston");
            questionEtReponse.add("Jordanie Amman");
            questionEtReponse.add("Kazakhstan Astana");
            questionEtReponse.add("Kenya Nairobi");
            questionEtReponse.add("Kirghizistan Bichkek");
            questionEtReponse.add("Kiribati Tarawa");
            questionEtReponse.add("Kosovo Pristina");
            questionEtReponse.add("Laos Vientiane");
            questionEtReponse.add("Lesotho Maseru");
            questionEtReponse.add("Lettonie Riga");
            questionEtReponse.add("Liban Beyrouth");
            questionEtReponse.add("Liberia Monrovia");
            questionEtReponse.add("Libye Tripoli");
            questionEtReponse.add("Liechtenstein Vaduz");
            questionEtReponse.add("Lituanie Vilnius");
            questionEtReponse.add("Macédoine Skopje");
            questionEtReponse.add("Madagascar Antananarivo");
            questionEtReponse.add("Malawi Lilongwe");
            questionEtReponse.add("Maldives Malé");
            questionEtReponse.add("Mali Bamako");
            questionEtReponse.add("Marshall Majuro");
            questionEtReponse.add("Mauritanie Nouakchott");
            questionEtReponse.add("Micronésie Palikir");
            questionEtReponse.add("Moldavie Chisinau");
            questionEtReponse.add("Mongolie Oulan-Bator");
            questionEtReponse.add("Monténégro Podgorica");
            questionEtReponse.add("Mozambique Maputo");
            questionEtReponse.add("Namibie Windhoek");
            questionEtReponse.add("Nauru Yaren");
            questionEtReponse.add("Népal Katmandou");
            questionEtReponse.add("Nicaragua Managua");
            questionEtReponse.add("Niger Niamey");
            questionEtReponse.add("Nigeria Abuja");
            questionEtReponse.add("Norvège Oslo");
            questionEtReponse.add("Nouvelle-Zélande Wellington");
            questionEtReponse.add("Oman Mascate");
            questionEtReponse.add("Ouganda Kampala");
            questionEtReponse.add("Ouzbékistan Tachkent");
            questionEtReponse.add("Pakistan Islamabad");
            questionEtReponse.add("Palaos Melekeok");
            questionEtReponse.add("Palestine Jérusalem-Est");
            questionEtReponse.add("Panama Panama");
            questionEtReponse.add("Paraguay Asunción");
            questionEtReponse.add("Philippines Manille");
            questionEtReponse.add("Pologne Varsovie");
            questionEtReponse.add("Qatar Doha");
            questionEtReponse.add("République-Centrafricaine Bangui");
            questionEtReponse.add("République-Démocratique-du-Congo Kinshasa");
            questionEtReponse.add("République-Dominicaine Saint-Domingue");
            questionEtReponse.add("Rwanda Kigali");
            questionEtReponse.add("Saint-Kitts-et-Nevis Basseterre");
            questionEtReponse.add("Saint-Marin Saint-Marin");
            questionEtReponse.add("Saint-Vincent-et-les-Grenadines Kingstown");
            questionEtReponse.add("Sainte-Lucie Castries");
            questionEtReponse.add("Salomon Honiara");
            questionEtReponse.add("Samoa Apia");
            questionEtReponse.add("Serbie Belgrade");
            questionEtReponse.add("Seychelles Victoria");
            questionEtReponse.add("Sierra-Leone Freetown");
            questionEtReponse.add("Slovaquie Bratislava");
            questionEtReponse.add("Slovénie Ljubljana");
            questionEtReponse.add("Somalie Mogadiscio");
            questionEtReponse.add("Soudan Khartoum");
            questionEtReponse.add("Soudan-du-Sud Djouba");
            questionEtReponse.add("Suriname Paramaribo");
            questionEtReponse.add("Swaziland Mbabane");
            questionEtReponse.add("Syrie Damas");
            questionEtReponse.add("Tadjikistan Douchanbe");
            questionEtReponse.add("Tanzanie Dodoma");
            questionEtReponse.add("Thaïlande Bangkok");
            questionEtReponse.add("Timor-Oriental Dili");
            questionEtReponse.add("Togo Lomé");
            questionEtReponse.add("Tonga Nukualofa");
            questionEtReponse.add("Turkménistan Achgabat");
            questionEtReponse.add("Tuvalu Fanafuti");
            questionEtReponse.add("Ukraine Kiev");
            questionEtReponse.add("Uruguay Montevideo");
            questionEtReponse.add("Vanuatu Port-Vila");
            questionEtReponse.add("Venezuela Caracas");
            questionEtReponse.add("Yémen Sanaa");
            questionEtReponse.add("Zambie Lusaka");
            questionEtReponse.add("Zimbabwe Harare");
        }
    }

    public void setQuestionReponse() {
        Random r = new Random();
        int i = 0 + r.nextInt(questionEtReponse.size() - 0);

        String[] splitQuest = questionEtReponse.get(i).split(" ");
        currentReponse = splitQuest[1].toLowerCase();
        currentQuestion = splitQuest[0].toUpperCase();
    }

    public ArrayList<String> getReponsesFausses() {
        Random r = new Random();
        int i;
        ArrayList<String> reponsesFausses = new ArrayList<>();

        while (reponsesFausses.size() <= 3) {
            i = 0 + r.nextInt(questionEtReponse.size() - 0);
            String rep = questionEtReponse.get(i).split(" ")[1].toLowerCase();

            //pour éviter deux fois le même choix
            if (!rep.equals(currentReponse)) {
                reponsesFausses.add(rep);
            }

            //mettre que des réponses différentes
            for (int j=0; j<reponsesFausses.size(); j++) {
                if (!rep.equals(reponsesFausses.get(j)) && !rep.equals(currentReponse))
                    reponsesFausses.add(rep);
            }
        }
        return reponsesFausses;
    }

    public ArrayList<String> getReponsesVraiesFausses() {

        ArrayList<String> reponsesVraiesFausses = new ArrayList<>();

        for (int i =0; i < 3; i++) {
            reponsesVraiesFausses.add(getReponsesFausses().get(i));
        }

        reponsesVraiesFausses.add(currentReponse);
        return reponsesVraiesFausses;
    }

    public String getCurrentQuestion() {
        return currentQuestion;
    }

    public String getCurrentReponse() {
        return currentReponse;
    }
}
