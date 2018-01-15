//*************************************************************************** //
//  PROGRAMME :  modele.ccp (mettre � jour ce cartouche)
//  DATE      :
//  OBJET     :
//  AUTEUR(S) :
//***************************************************************************

// ===================== Liste des fichiers d'en-t�te ======================= //
#include <iostream>			// flux d'entr�e sortie
#include <iomanip>			// manipulateurs de flux
#include <cstdlib>		    // biblioth�que c standart
#define _USE_MATH_DEFINES	// biblioth�que math�matique
#include <cmath>
#include <clocale>			// caract�res accentu�s

using namespace std;		// permet d'utiliser les flux cin et cout
//*************************************************************************** //
//  PROGRAMME :  modele.ccp (mettre � jour ce cartouche)
//  DATE      :
//  OBJET     :
//  AUTEUR(S) :
//***************************************************************************

// ===================== Liste des fichiers d'en-t�te ======================= //
#include <iostream>			// flux d'entr�e sortie
#include <iomanip>			// manipulateurs de flux
#include <cstdlib>		    // biblioth�que c standart
#define _USE_MATH_DEFINES	// biblioth�que math�matique
#include <cmath>
#include <clocale>			// caract�res accentu�s

using namespace std;		// permet d'utiliser les flux cin et cout

// =============================== Constantes =============================== //
/* d�clarez ici les constantes */
const int MAXPLT = 10;
const int MAXCH = 30;
// ================================== Types ================================= //
/* d�clarez ici les nouveaux types */

typedef char t_grille[MAXPLT][MAXPLT];

typedef char t_chaine[MAXCH];

typedef struct  {
                    int vie;
                    int x ;
                    int y ;
                    int lng;

                }t_bat;

// ============================ Sous programmes ============================= //
/* d�clarez ici les sous-programmes */


char menu ()
{
     char chx;

    cout<<"     Bataille navale "<<endl;
    cout<<"menu:"<<endl;
    cout<<" <p>jouer en pvp"<<endl;
    cout<<" <q>quitter"<<endl;
    cout<<"que voulez vous faire ?"<<endl;
    cin>>chx;


    return(chx);
}

void nom_joueur(t_chaine & nom_joueur)
{

    cout<<"Entrez le nom du joueur "<<endl;
    cin>>nom_joueur;

}

void initgrille(t_grille & grille)
{
   int cptl , cptc;



    for(cptl = 0 ; cptl < MAXPLT ;cptl++)
    {
        for(cptc = 0 ; cptc < MAXPLT ; cptc++)
        {
         grille[cptl][cptc]=' ';
        }

    }
}





void aff_grille(t_grille & grille)
{
   //aff la grille
   int i,j;
   for(i=0 ; i<MAXPLT ; i++)
   {
    for(j=0 ; j<MAXPLT ; j++)
    {
      cout<<grille[i][j];
    };
  }
}

void demender_placement(t_grille & grille_placement, int taille_bat)
{
    char lettre_col,sens ;
    int col , lig ;


    cout<<"placement du bateau de "<<taille_bat<<" case"<<endl;
    cout<<"entrez une case"<<endl;
    cout<<"colone (lettre en majuscule):"<<endl;
    do
    {
        cin>>lettre_col;

    }while (lettre_col < 65 || lettre_col > 74);

    col = lettre_col - 65 ;  // A = 65(ascii dec)  J= 74 (ascii dec)



    cout<<"ligne (nombre de 1 a 10):"<<endl;
    do
    {
        cin>>lig;

    }while (lig < 0 || lig > 10);

    lig = lig + 1 ;  // A = 65(ascii dec)  J= 74 (ascii dec)

    cout<<"dans quel sens voulez vous le mettre ?"<<endl;
    cout<<"     <h> vers le haut"<<endl;
    cout<<"     <b> vers le bas"<<endl;
    cout<<"     <g> vers le gauche"<<endl;
    cout<<"     <d> vers le droite"<<endl;

    do
    {

      cin>>sens;

    }while(sens!= 'h' || sens!= 'b' || sens!= 'g' || sens!= 'd' );



   // pas fini
}

void placement_bateaux(t_grille & grille_placement)
{

    aff_grille(grille_placement);
    demender_placement(grille_placement , 5);
    aff_grille(grille_placement);
    demender_placement(grille_placement , 4);
    aff_grille(grille_placement);
    demender_placement(grille_placement , 3);
    aff_grille(grille_placement);
    demender_placement(grille_placement , 3);
    aff_grille(grille_placement);
    demender_placement(grille_placement , 2);
    aff_grille(grille_placement);
}



void tir( t_grille & grille_tir , t_grille & grille_placement ,bool & resultat)
{

}

void qgagnant ( bool & resultat , int & joueur , int & score )
{

}

void tour ()
{
  bool resultat;
  int joueur , score ;
  t_grille grille;
  do {
    aff_grille(grille);
    qgagnant ( resultat , joueur , score );




  }while(resultat != true );
}

// ========================== Programme principal =========================== //
int main(void)
{

   // D�clarations locales

   // Actions
  menu();
   setlocale(LC_ALL, "french");

   // retour au syst�me d'exploitattion
   return 0;
}
// ============================ Fin du programme ==========================

// =============================== Constantes =============================== //
/* d�clarez ici les constantes */
const int MAXPLT = 10;
const int MAXCH = 30;
// ================================== Types ================================= //
/* d�clarez ici les nouveaux types */

typedef char t_grille[MAXPLT][MAXPLT];

typedef char t_chaine[MAXCH];

typedef struct  {
                    int vie;
                    int x ;
                    int y ;
                    int lng;

                }t_bat;

// ============================ Sous programmes ============================= //
/* d�clarez ici les sous-programmes */


char menu ()
{
     char chx;

    cout<<"     Bataille navale "<<endl;
    cout<<"menu:"<<endl;
    cout<<" <p>jouer en pvp"<<endl;
    cout<<" <q>quitter"<<endl;
    cout<<"que voulez vous faire ?"<<endl;
    cin>>chx;


    return(chx);
}

void nom_joueur(t_chaine & nom_joueur)
{

    cout<<"Entrez le nom du joueur "<<endl;
    cin>>nom_joueur;

}

void initgrille(t_grille & grille)
{
   int cptl , cptc;



    for(cptl = 0 ; cptl < MAXPLT ;cptl++)
    {
        for(cptc = 0 ; cptc < MAXPLT ; cptc++)
        {
         grille[cptl][cptc]=' ';
        }

    }
}





void aff_grille(t_grille & grille)
{
   //aff la grille
   int i,j;
   for(i=0 ; i<MAXPLT ; i++)
   {
    for(j=0 ; j<MAXPLT ; j++)
    {
      cout<<grille[i][j];
    };
  }
}

void demender_placement(t_grille & grille_placement, int taille_bat)
{
    char lettre_col;
    int col , lig ;


    cout<<"placement du bateau de "<<taille_bat<<" case"<<endl;
    cout<<"entrez une case"<<endl;
    cout<<"colone (lettre en majuscule):"<<endl;
    do
    {
        cin>>lettre_col;

    }while (lettre_col < 65 || lettre_col > 74);

    col = lettre_col - 65 ;  // A = 65(ascii dec)  J= 74 (ascii dec)



    cout<<"ligne (nombre de 1 a 10):"<<endl;
    do
    {
        cin>>lig;

    }while (lig < 0 || lig > 10);

    lig = lig + 1 ;  // A = 65(ascii dec)  J= 74 (ascii dec)

    cout<<"dans quel sens voulez vous le mettre ?"<<endl;
    cout<<"     <h> vers le haut"<<endl;
    cout<<"     <b> vers le bas"<<endl;
    cout<<"     <g> vers le gauche"<<endl;
    cout<<"     <d> vers le droite"<<endl;
  
    do 
    {
      
      cin>>sens;
      
    }while(sens!= h || sens!= b || sens!= g || sens!= d )

      
      
   // pas fini
}

void placement_bateaux(t_grille & grille_placement)
{

    aff_grille(grille_placement);
    demender_placement(grille_placement , 5);
    aff_grille(grille_placement);
    demender_placement(grille_placement , 4);
    aff_grille(grille_placement);
    demender_placement(grille_placement , 3);
    aff_grille(grille_placement);
    demender_placement(grille_placement , 3);
    aff_grille(grille_placement);
    demender_placement(grille_placement , 2);
    aff_grille(grille_placement);
}



void tir( t_grille & grille_tir , t_grille & grille_placement ,bool & resultat)
{

}

void qgagnant ( bool resultat , int & joueur , int & score )
{

}

void tour ()
{
  do {
    aff_grille(t_grille & grille);
    
    
    
    
    
  }while(resultat != true );
  

// ========================== Programme principal =========================== //
int main(void)
{

   // D�clarations locales

   // Actions
  menu();
   setlocale(LC_ALL, "french");

   // retour au syst�me d'exploitattion
   return 0;
}
// ============================ Fin du programme ==========================
