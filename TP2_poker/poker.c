
#include<stdio.h>
#include<stdlib.h>
#define VALET 11
#define DAME 12
#define ROI 13
#define AS 14

enum Couleur{Coeur, Carreau, Trefle, Pique};
enum Type_combi{RIEN,PAIRE, DOUBLE_PAIRE,BRELAN,SUITE,COULEUR,FULL,CARRE,FLUSH};

typedef struct carte{
	int valeur;
	enum Couleur couleur;
}Carte;

typedef struct MAIN{
	Carte carte[5];
}Main;

typedef struct combinaison{
	enum Type_combi type;
	int valeur1;
	int valeur2;
	int valeur_kicker;
	}Combinaison;
	
void afficher_main(Main joueur);
Combinaison combinaisonAssoc(Main joueur);
	
int main(int argc, char *argv[])
{	
	
	Main mon_jeu;
	char* noms_cartes[15] = {"", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi", "As"};
	char* noms_combi[9] = {"pas de combi", "Paire", "double_paire", "Brelan", "Suite", "Couleur", "Full", "Carre", "Flush"};
	mon_jeu.carte[0].valeur=14;
	mon_jeu.carte[1].valeur=9;
	mon_jeu.carte[2].valeur=11;
	mon_jeu.carte[3].valeur=13;
	mon_jeu.carte[4].valeur=13;
	mon_jeu.carte[0].couleur=Coeur;
	mon_jeu.carte[1].couleur=Carreau;
	mon_jeu.carte[2].couleur=Trefle;
	mon_jeu.carte[3].couleur=Trefle;
	mon_jeu.carte[4].couleur=Pique;
	
	Combinaison combi;
	afficher_main(mon_jeu);
	combi=combinaisonAssoc(mon_jeu);
	printf("%s ", noms_combi[combi.type]);
	if (combi.type==PAIRE || combi.type==DOUBLE_PAIRE || combi.type==BRELAN || combi.type==CARRE || combi.type==FULL )
		printf(" de valeur %s ", noms_cartes[combi.valeur1]);
	if (combi.type==DOUBLE_PAIRE || combi.type==FULL)
		printf(" et de valeur %s ", noms_cartes[combi.valeur2]);
		
	printf("et de valeur kicker %s \n", noms_cartes[combi.valeur_kicker]);
	return 0;
}



void afficher_main(Main joueur)
{
	char* noms_couleurs[4] = {"Coeur", "Carreau", "Trefle", "Pique"};
	int i;
	for (i=0;i<5;i++)
	{
		if (joueur.carte[i].valeur==VALET)
			printf("Valet de  ");
		else if (joueur.carte[i].valeur==DAME)
			printf("Dame de  " );
		else if (joueur.carte[i].valeur==ROI)
			printf("Roi de  ") ;
		else if (joueur.carte[i].valeur==AS)
			printf("As de  ");
		else
			printf("%d de  " ,joueur.carte[i].valeur);
		switch (joueur.carte[i].couleur) {
			case Coeur:
			printf("%s, ",  noms_couleurs[0]);
			break;
			
			case Carreau:
			printf("%s, ",  noms_couleurs[1]);
			break;
			
			case Trefle:
			printf("%s, ",  noms_couleurs[2]);
			break;
			
			case Pique:
			printf("%s, ",  noms_couleurs[3]);
			break;
		}
		printf("\n");
	}
	
}

Combinaison combinaisonAssoc(Main joueur)
{
	Combinaison combi;
	int nbCartesParValeur[15]={0};
	combi.valeur1=0;
	combi.valeur2=0;
	combi.type=RIEN;
	combi.valeur_kicker=0;
	int i;
	
	
	for (i=0;i<5;i++)
	{
		int a=joueur.carte[i].valeur;
		nbCartesParValeur[a]+=1;
		
	}
	int kickeur;
	for (i=2;i<15;i++)
	{
		if(nbCartesParValeur[i]==1)
			{
				combi.valeur_kicker=i;
			}
		
		if(nbCartesParValeur[i]==2)
		{
			
			if(combi.type==BRELAN)
			{
				combi.valeur2=i;
				combi.type=FULL;
			}
			if(combi.type==PAIRE)
			{
				combi.valeur2=i;
				combi.type=DOUBLE_PAIRE;
			}
			else
			{
				combi.valeur1=i;
				combi.type=PAIRE;
			}
		}
		else if (nbCartesParValeur[i]==3)
		{
			if(combi.type==PAIRE)
			{
				combi.valeur2=i;
				combi.type=FULL;
			}
			else
			{
				combi.valeur1=i;
				combi.type=BRELAN;
			}
		}
		else if (nbCartesParValeur[i]==4)
		{
			combi.valeur1=i;
			combi.type=CARRE;
		}
	
	}
	return combi;
}

