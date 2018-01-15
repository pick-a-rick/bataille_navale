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
const int NBBAT = 5;
// ================================== Types ================================= //
/* d�clarez ici les nouveaux types */

typedef char t_grille[MAXPLT][MAXPLT];

typedef char t_chaine[MAXCH];

typedef struct  {
                    int vie ;
                    int lig ;
                    int col ;
                    int sens ;
                    int lng ;

                }t_bat;

typedef t_bat t_flote [NBBAT];
// ============================ Sous programmes ============================= //
/* d�clarez ici les sous-programmes */


char menu ()
{
     char chx;
do{
    cout<<"     Bataille navale "<<endl;
    cout<<"menu:"<<endl;
    cout<<" <p>jouer en pvp"<<endl;
    cout<<" <q>quitter"<<endl;
    cout<<"que voulez vous faire ?"<<endl;
    cin>>chx;
  }while (chx !='p' && chx!='q');  /* code */

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
         grille[cptl][cptc]='=';
        }

    }
}





void aff_grille(t_grille & grille)
{
   //aff la grille
   int i,j;
   cout<<"         A B C D E F G H I J "<<endl;
   for(i=0 ; i<MAXPLT ; i++)
   {
     cout<<i+1<<"        ";
    for(j=0 ; j<MAXPLT ; j++)
    {
      cout<<grille[i][j];
      cout<<" ";
    };
    cout<<endl;
  }
}

void demender_placement(t_grille & grille_placement , t_bat & bateau , int taille_bat)
{
    char lettre_col,sens,cara;
    int col , lig ,cpt ;
    bool validsens ;

      bateau.vie= taille_bat;
      bateau.lng = taille_bat;
      switch(taille_bat)
      {
          case 5:
              cara = 'p';
              break;

          case 4 :
              cara = 'c';
              break;
          case 3 :
              cara = 's';
              break;

          case 2 :
              cara = 't';
              break;

          default :
              cara = ' ';
                ;
      }


    cout<<"placement du bateau de "<<taille_bat<<" case"<<endl;
    cout<<"entrez une case"<<endl;

    do
    {
        cout<<"colone (lettre en majuscule):"<<endl;
        cin>>lettre_col;

    }while (lettre_col < 65 || lettre_col > 74);

    col = lettre_col - 65 ;  // A = 65(ascii dec)  J= 74 (ascii dec)
    bateau.col = col;



    do
    {
          cout<<"ligne (nombre de 1 a 10):"<<endl;
        cin>>lig;

    }while (lig < 1 || lig > 10);

    lig = lig - 1 ;  // A = 65(ascii dec)  J= 74 (ascii dec)
    bateau.lig = lig ;



    cout<<"dans quel sens voulez vous le mettre ?"<<endl;
    cout<<"     <h> vers le haut"<<endl;
    cout<<"     <b> vers le bas"<<endl;
    cout<<"     <g> vers le gauche"<<endl;
    cout<<"     <d> vers le droite"<<endl;

    do
    {

      cin>>sens;

          switch (sens)
          {
              case 'h':

                      if(lig - taille_bat < 0)
                        {
                        validsens = false ;
                        }
                      else
                        {
                        validsens = true ;
                        }


                      break;

              case 'b':

                      if(lig + taille_bat > 9)
                          {
                          validsens = false ;
                          }
                        else
                          {
                            validsens = true ;
                          }

                        break;

              case 'g':

                      if(col - taille_bat < 0)
                          {
                            validsens = false ;
                          }
                          else
                          {
                              validsens = true ;
                            }

                      break;

              case 'd' :

                      if(col + taille_bat > 9)
                          {
                            validsens = false ;
                          }
                          else
                          {
                            validsens = true ;
                          }
                      break;

              default :

                        validsens = false ;

          }

    }while(validsens== false);

    bateau.sens = sens;



    switch (sens)
    {
        case 'h' :



              for(cpt = lig ; cpt>(lig-taille_bat) ; cpt --)
                  {
                    grille_placement[cpt][col]=cara;

                  }

                  break;

        case 'b':

              for(cpt = lig ; cpt<(lig+taille_bat) ; cpt ++)
                  {
                    grille_placement[cpt][col]=cara;

                  }

                break;

      case 'g':

            for(cpt = col; cpt>(col-taille_bat) ; cpt --)
              {
                grille_placement[lig][cpt]=cara;

              }

              break;

      case'd':

          for(cpt = col; cpt<(col+taille_bat) ; cpt ++)
              {
                grille_placement[lig][cpt]=cara;

              }

              break;

      default:
              ;


      }

   // pas fini
}

void placement_bateaux(t_grille & grille_placement , t_flote & flote )
{

    t_bat pa5 , cr4 , ct3 , sm3 , tr2 ;


    aff_grille(grille_placement);
    demender_placement(grille_placement , pa5 , 5);
    flote[0]=pa5;
    aff_grille(grille_placement);
    demender_placement(grille_placement , cr4 , 4);
    flote[1]=cr4;
    aff_grille(grille_placement);
    demender_placement(grille_placement , ct3 , 3);
    flote[2]=ct3;
    aff_grille(grille_placement);
    demender_placement(grille_placement , sm3 , 3);
    flote[3]=sm3;
    aff_grille(grille_placement);
    demender_placement(grille_placement , tr2 , 2);
    flote[4]=tr2;
    aff_grille(grille_placement);
}



void tir( t_grille & grille_tir , t_grille & grille_placement ,bool & resultat)
{
    int lig ,col ;
    char lettre_col;

      aff_grille(grille_tir);
      do{
      do
      {
        cout<<"colone (lettre en majuscule):"<<endl;
          cin>>lettre_col;

      }while (lettre_col < 65 || lettre_col > 74);

      col = lettre_col - 65 ;  // A = 65(ascii dec)  J= 74 (ascii dec)



      do
      {
         cout<<"ligne (nombre de 1 a 10):"<<endl;
          cin>>lig;

      }while (lig < 1|| lig > 10 );

      lig = lig - 1 ;  // A = 65(ascii dec)  J= 74 (ascii dec)
    }while( grille_placement[lig][col]== '*' || grille_placement[lig][col]=='0' );
      if( grille_placement[lig][col]=='p'|| grille_placement[lig][col]=='c'|| grille_placement[lig][col]=='s'|| grille_placement[lig][col]=='t')
      {
        grille_tir[lig][col] = '*' ;
        cout<<"touché"<<endl;
        resultat = true ;
      }
      else
      {
        grille_tir[lig][col] = '0';
        cout<<"raté"<<endl;
        resultat = false ;
      }
}


void tour (t_chaine & joueur_1 , t_chaine &joueur_2 , t_grille& grille_placement_1, t_grille &grille_placement_2, int & jwin)
{
  bool resultat, fin;
  int joueur , score1 , score2 ;
  t_grille grille_tir_1  , grille_tir_2;
  initgrille(grille_tir_1);
  initgrille(grille_tir_2);
  joueur = 1;
  fin    = false;

  do {

    if(joueur== 1)
        {
          cout<<" Au tour de "<<joueur_1<<endl;
          aff_grille(grille_placement_1);
          cout<<endl<<" Grille de tir "<<endl;
          tir(grille_tir_1 , grille_placement_2 , resultat);
          if(resultat == true)score1++;
          joueur++;
        }

    else
        {
          cout<<" Au tour de "<<joueur_2 <<endl;
          aff_grille(grille_placement_2);
          cout<<endl<<" Grille de tir "<<endl;
          tir(grille_tir_2 , grille_placement_1 , resultat);
          if(resultat == true)score2++;
          joueur--;
        }
    if(score1 == 17){jwin=1;fin=true;}
    if(score2 == 17){jwin=2;fin=true;}
  }while(fin != true );
}

// ========================== Programme principal =========================== //
int main(void)
{

   // D�clarations locales
char choix;
t_chaine joueur_1;
t_chaine joueur_2;
t_grille grille_placement_1;
t_grille grille_placement_2;
t_flote flote_1;
t_flote flote_2;
int jwin;

   // Actions

choix= menu();

switch (choix)
{
  case'p':

  cout<<" Entrez nom du joueur 1 : ";
  cin>>joueur_1;
  cout<<endl<<endl<<" Entrez nom du joueur 2 : ";
  cin>>joueur_2;
  cout<<endl;
  initgrille(grille_placement_1);
  placement_bateaux(grille_placement_1,flote_1);
  cout<<endl<<endl<<" Au joueur 2 de placer ces bateaux ! "<<endl;
  initgrille(grille_placement_2);
  placement_bateaux(grille_placement_2,flote_2);
  cout<<endl<<endl;
  tour(joueur_1 , joueur_2 , grille_placement_1,grille_placement_2, jwin);
  if(jwin== 1){cout<<" "<<joueur_1<<" a gagne !! "<<endl;}
  if(jwin== 2){cout<<" "<<joueur_2<<" a gagne !! "<<endl;}

  break;
}
   setlocale(LC_ALL, "french");

   // retour au syst�me d'exploitattion
   return 0;
}
// ============================ Fin du programme ==========================
