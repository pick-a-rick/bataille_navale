//*************************************************************************** //
//  PROGRAMME :  bataille navale
//  DATE      :
//  OBJET     :
//  AUTEUR(S) : thomas cdln + bubu aka le tombeur de rousses
//***************************************************************************

// ===================== Liste des fichiers d'en-t�te ======================= //
#include <iostream>			// flux d'entr�e sortie
#include <iomanip>			// manipulateurs de flux
#include <cstdlib>		    // biblioth�que c standart
#define _USE_MATH_DEFINES	// biblioth�que math�matique
#include <cmath>
#include <clocale>			// caract�res accentu�s
#include <conio.h>
#include <time.h>
#include <windows.h>


using namespace std;		// permet d'utiliser les flux cin et cout

// =============================== Constantes =============================== //
/* d�clarez ici les constantes */
const int MAXPLT = 10;
const int MAXCH = 30;
const int NBBAT = 5;
 const int MAXJOUEUR = 8 ;
// ================================== Types ================================= //
/* d�clarez ici les nouveaux types */

typedef char t_grille[MAXPLT][MAXPLT];

typedef char t_chaine[MAXCH];

typedef t_grille t_mer[MAXJOUEUR];

typedef int t_vie[MAXJOUEUR];

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
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

char menu ()
{
  char chx;
 do{
    cout<<"     Bataille navale "<<endl;
    cout<<"menu:"<<endl;
    cout<<" <p> jouer en pvp"<<endl;
    cout<<" <o> jouer contre l'ordinateur"<<endl;
    cout<<" <q> quitter"<<endl;
    cout<<"que voulez vous faire ?"<<endl;
    cin>>chx;
  }while (chx !='p' && chx!='q' && chx!='o');  /* code */

    return(chx);
}

void nom_joueur(t_chaine & nom_joueur, int & nbj)
{

    cout<<"Entrez le nom du joueur "<<nbj<<" : ";
    cin>>nom_joueur;
    cout<<endl;
    nbj++;
}

void initgrille(t_grille & grille)
{
   int cptl , cptc;

    for(cptl = 0 ; cptl < MAXPLT ;cptl++)
    {
        for(cptc = 0 ; cptc < MAXPLT ; cptc++)
        {
         grille[cptl][cptc]='~';
        }

    }
}

void aff_grille(t_grille & grille)
{
   //aff la grille
   int i,j;
   int k;
   cout<<"___________________________________________________"<<endl;
   cout<<"          | A | B | C | D | E | F | G | H | I | J |"<<endl;
   for(i=0 ; i<MAXPLT ; i++)
   {
     cout<<"___________________________________________________"<<endl;
     cout<<i+1;
     if(i+1==10)cout<<"      ";
     else cout<<"       ";
    for(j=0 ; j<MAXPLT ; j++)
    {
      cout<<" | ";
      cout<<grille[i][j];
    };
    cout<<" | ";
    cout<<endl;
  }
  cout<<"___________________________________________________"<<endl<<endl<<endl;
}

void demender_placement(t_grille & grille_placement , t_bat & bateau , int taille_bat)
{
    char lettre_col,sens,cara;
    int col , lig ,cpt , validbat ;
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






    do
    {

            validbat = 0 ;



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

        cin>>sens;

          switch (sens)
          {
              case 'h':

                      if ( (lig - taille_bat +1 )<  0)
                        {
                        validsens = false ;

                        }
                      else
                        {
                        for(cpt = lig ; cpt>(lig-taille_bat) ; cpt --)
                            {
                            if(grille_placement[cpt][col] == '~')
                                {
                                  validbat++ ;
                                }

                            }

                        }

                      break;

              case 'b':

                      if(lig + taille_bat -1 > 9)
                            {
                            validsens = false ;
                            }
                            else
                            {
                             for(cpt = lig ; cpt<(lig+taille_bat) ; cpt ++)
                                {
                                   if(grille_placement[cpt][col] == '~')
                                    {
                                    validbat++ ;
                                    }

                                }
                          }

                        break;

              case 'g':

                      if(col - taille_bat +1 < 0)
                          {
                            validsens = false ;
                          }
                          else
                            {
                              for(cpt = col; cpt>(col-taille_bat) ; cpt --)
                                    {
                                         if(grille_placement[lig][cpt] == '~')
                                            {
                                                validbat++ ;

                                            }
                                    }
                            }

                      break;

              case 'd' :

                      if(col + taille_bat -1 > 9)
                          {
                            validsens = false ;
                          }
                          else
                          {
                             for(cpt = col; cpt<(col+taille_bat) ; cpt ++)
                                {
                                     if(grille_placement[lig][cpt] == '~')
                                        {
                                        validbat++ ;
                                        }

                                }
                          }
                      break;

              default :

                        validsens = false ;

          }



        if(validsens== false && validbat != taille_bat )
        {
            cout<<endl;
            cout<<"placement invalide ( chevauchement , hors grille )"<<endl;

            cout<<endl;
        }

    }while(validsens== false && validbat != taille_bat );

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


}

void placement_IA_facile(t_grille & grille_placement , t_bat & bateau , int taille_bat)
{
    char lettre_col,cara, lettre;
    int col , lig ,cpt , validbat , sens , x;
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
    do
    {

            validbat = 0 ;

            do
            {

                lettre_col=rand() % 74;

            }while (lettre_col < 65 || lettre_col > 74);

        col = lettre_col - 65 ;  // A = 65(ascii dec)  J= 74 (ascii dec)
        bateau.col = col;



        		do
            {

            lig = rand() % 10;

            }while (lig < 1 || lig > 10);

        lig = lig - 1 ;  // A = 65(ascii dec)  J= 74 (ascii dec)
        bateau.lig = lig ;


        sens = rand() % 4;

          switch (sens)
          {
              case 0  :
											x=0;
											x=(lig - taille_bat +1 );
                      if (x <  0)
                        {
                        validsens = false;

                        }
                      else
                        {
                        for(cpt = lig ; cpt>(lig-taille_bat) ; cpt --)
                            {
															lettre = grille_placement[cpt][col] ;
                            if(lettre == '~')
                                {
                                  validbat++ ;
																	validsens = true ;
                                }else validsens = false;

                            }

                        }

                      break;

              case 1 :
											x=0;
											x=(lig + taille_bat -1);

                      if(x > 9)
                            {
                            validsens = false ;
                            }
                            else
                            {
                             for(cpt = lig ; cpt<(lig+taille_bat) ; cpt ++)
                                {
																	lettre = grille_placement[cpt][col] ;
                                   if(lettre == '~')
                                    {
                                    validbat++ ;
																		validsens = true ;
                                    }else validsens = false;

                                }
                          }

                        break;

              case 2 :
											x=0;
											x=(col - taille_bat +1);
                      if( x < 0)
                          {
                            validsens = false ;
                          }
                          else
                            {
															for(cpt = col; cpt>(col-taille_bat) ; cpt --)
                                    {
																			lettre = grille_placement[lig][cpt] ;
                                         if(lettre == '~')
                                            {
                                                validbat++ ;
																								validsens = true ;

                                            }else validsens = false;
                                    }
                            }

                      break;

              case 3 :
											x=0;
											x=col + taille_bat -1 ;
                      if( x > 9)
                          {
                            validsens = false ;
                          }
                          else
                          {
                             for(cpt = col; cpt<(col+taille_bat) ; cpt ++)
                                {
																	lettre = grille_placement[lig][cpt];
                                     if(lettre == '~')
                                        {
                                        validbat++ ;
																				validsens = true ;
                                        }else validsens = false;
                                }
                          }
                      break;

              default :

                        validsens = false ;

          }





    }while(validsens== false || validbat != taille_bat );

    bateau.sens = sens;



    switch (sens)
    {
        case 0 :



              for(cpt = lig ; cpt>(lig-taille_bat) ; cpt --)
                  {
                    grille_placement[cpt][col]=cara;

                  }

                  break;

        case 1:

              for(cpt = lig ; cpt<(lig+taille_bat) ; cpt ++)
                  {
                    grille_placement[cpt][col]=cara;

                  }

                break;

      case 2:

            for(cpt = col; cpt>(col-taille_bat) ; cpt --)
              {
                grille_placement[lig][cpt]=cara;

              }

              break;

      case 3:

          for(cpt = col; cpt<(col+taille_bat) ; cpt ++)
              {
                grille_placement[lig][cpt]=cara;

              }

              break;

      default:
              ;


      }


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

void placement_bateaux_IA(t_grille & grille_placement , t_flote & flote)
{
      t_bat pa5 , cr4 , ct3 , sm3 , tr2 ;

      placement_IA_facile(grille_placement , pa5 , 5);
      flote[0]=pa5;
      placement_IA_facile(grille_placement , cr4 , 4);
      flote[1]=cr4;
      placement_IA_facile(grille_placement , ct3 , 3);
      flote[2]=ct3;
      placement_IA_facile(grille_placement , sm3 , 3);
      flote[3]=sm3;
      placement_IA_facile(grille_placement , tr2 , 2);
      flote[4]=tr2;
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


    if(grille_tir[lig][col]== '*' || grille_tir[lig][col]=='0')
    {
        cout<<"vous avez deja tiré ici"<<endl;
        cout<<"veillez retirer"<<endl;
    }



    }while( grille_tir[lig][col]== '*' || grille_tir[lig][col]=='0' );


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
  char c;
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
          cout<<endl<<" Au tour du joueur 2 , appuyer sur c pour continuer "<< endl;
          cin>>c;
          if(c == 'c')system("cls" );


        }

    else
        {
          cout<<" Au tour de "<<joueur_2 <<endl;
          aff_grille(grille_placement_2);
          cout<<endl<<" Grille de tir "<<endl;
          tir(grille_tir_2 , grille_placement_1 , resultat);
          if(resultat == true)score2++;
          joueur--;
          cout<<endl<<" Au tour du joueur 1 , appuyer sur c pour continuer "<< endl;
          cin>>c;
          if(c == 'c')system("cls" );
        }
    if(score1 == 17){jwin=1;fin=true;}
    if(score2 == 17){jwin=2;fin=true;}
  }while(fin != true );
}

void tir_ia_facile (t_grille & grille_tir , t_grille & grille_placement ,bool & resultat)
{

    int lig ,col ;

    do
    {

      lig = rand() % MAXPLT ;
      col = rand() % MAXPLT ;

    }while( grille_tir[lig][col]== '*' || grille_tir[lig][col]=='0' );


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

void tour_IA (t_chaine & joueur_1 , t_chaine &joueur_2 , t_grille& grille_placement_1, t_grille &grille_placement_2, int & jwin)
{
  char c;
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

          cout<<" A ton tour "<<endl;
          aff_grille(grille_placement_1);
          cout<<endl<<" Grille de tir "<<endl;
          tir(grille_tir_1 , grille_placement_2 , resultat);
          if(resultat == true)score1++;
          joueur++;
          cout<<endl<<" Au tour de l'ordinateur , appuyer sur c pour continuer "<< endl;
          cin>>c;
          if(c == 'c')system("cls" );


        }

    else
        {
          tir_ia_facile (grille_tir_2 , grille_placement_1 ,resultat);
          if(resultat == true)score2++;
          joueur--;
        }
    if(score1 == 17){jwin=1;fin=true;}
    if(score2 == 17){jwin=2;fin=true;}
  }while(fin != true );
}

void initvie(t_vie & vie)
{
  int cpt;



    for(cpt = 0 ; cpt < MAXJOUEUR ; cpt ++)
    {
      vie[cpt]= 17 ;
    }

}

void tirmulti (t_mer & mer_tir, t_mer & mer_pl ,int & cible , int n0joueur ,int nb_joueurs)
 {
   int  lig , col ;
   char col_lettre ;
   bool resultat ;

   t_grille grilleplcible , grilletircible;

    do{
        cout<<"au tour de joueur"<<n0joueur<<endl;
        cout<< " quel joueur voulez vous attaquer ? (chiffre)"<<endl;
        cin>>cible;
      }while(cible < 0 || cible > nb_joueurs ||cible == n0joueur);

      grilleplcible = mer_pl[cible - 1];
      grilletircible = mer_tir[cible - 1];


  tir(grilletircible , grilleplcible , resultat);



    mer_tir[cible-1]=grilletircible;
    mer_pl[cible-1]=grilleplcible;
    cible = cible -1 ;
 }


void tour_multi(t_mer & mer_tir ,t_mer & mer_placement , int & jout , int  nb_joueurs)
  {

    int tour , cible; // numeros du joueur qui doit joueur
    t_vie vie;



    tour = 0 ;

    do{

      tour++;
      tirmulti(mer_tir,mer_placement,cible,tour,nb_joueurs);

      vie[cible] = vie[cible] - 1;
      if(vie[cible] == 0)
        {
          jout = cible + 1 ;
        }

    }while( tour>=nb_joueurs || jout==0 );




  }

void partiemulti(t_mer & mer_tir , t_mer & mer_placement )
  {
    int jout , nb_joueurs ;


    cout<<"combien de joueurs ?"<<endl;
    cin>>nb_joueurs;


    do{

      tour_multi(t_mer , mer_placement , jout , nb_joueurs );


      }while(jout == 0);

      cout<<"le joueur"<<jout<<" gagne !"<<endl;

  }

// ========================== Programme principal =========================== //
int main(void)
{

   // D�clarations locales
char choix,chox,q,p;
t_chaine joueur_1;
t_chaine joueur_2;
t_grille grille_placement_1;
t_grille grille_placement_2;
t_flote flote_1;
t_flote flote_2;
int jwin,nbj;
nbj=1;
   // Actions

Color(0,15);
srand(time(0));

do{
choix= menu();

switch (choix)
{
  case'p':

  nom_joueur(joueur_1,nbj);
  nom_joueur(joueur_2,nbj);
  system("cls" );
  cout<<" Placement des bateaux de "<<joueur_1<<endl;
  initgrille(grille_placement_1);
  cout<<"Souhaitez vous placer vos bateaux automatiquemment ?  "<<endl<<"             <0> pour oui        <n> pour non  "<<endl;
  cin>>p;
  switch(p)
  {
    case 'o':placement_bateaux_IA(grille_placement_1 , flote_1);break;
    case 'n':placement_bateaux(grille_placement_1,flote_1);break;
  }
  system("cls" );
  cout<<endl<<endl<<" Au joueur 2 de placer ces bateaux ! "<<endl;
  initgrille(grille_placement_2);
  cout<<"Souhaitez vous placer vos bateaux automatiquemment ?  "<<endl<<"             <0> pour oui        <n> pour non  "<<endl;
  cin>>p;
  switch(p)
  {
    case 'o':placement_bateaux_IA(grille_placement_2 , flote_2);break;
    case 'n':placement_bateaux(grille_placement_2,flote_2);break;
  }
  cout<<endl<<endl;
  tour(joueur_1 , joueur_2 , grille_placement_1,grille_placement_2, jwin);
  if(jwin== 1){cout<<" "<<joueur_1<<" a gagne !! "<<endl;}
  if(jwin== 2){cout<<" "<<joueur_2<<" a gagne !! "<<endl;}
  break;

  case'o':

  cout<<"Qule niveau d'IA ?"<<endl;
  cout<<" <1> Facile"<<endl;
  cout<<" <2> Difficile"<<endl;
  cin>>chox;
  switch (chox)
    {
      case'1':
      nom_joueur(joueur_1,nbj);
      system("cls" );
      initgrille(grille_placement_2);
      placement_bateaux_IA(grille_placement_2,flote_2);
      cout<<" Placement des bateaux de "<<joueur_1<<endl;
      initgrille(grille_placement_1);
      placement_bateaux(grille_placement_1,flote_1);
      system("cls" );
      aff_grille(grille_placement_2);
      tour_IA(joueur_1 , joueur_2 , grille_placement_1,grille_placement_2, jwin);
      if(jwin== 1){cout<<" "<<joueur_1<<" a gagne !! "<<endl;}
      if(jwin== 2){cout<<" YOU LOOSE !!! "<<endl;}
      break;

      case'2':cout<<"Encore en chantier "<<endl;
      break;
    }
  break;
cout<<" Voulez vous rejouer ? Si non , tapez q"<<endl;
cin>>q;
}
}while(q != 'q');




   setlocale(LC_ALL, "french");

   // retour au syst�me d'exploitattion
   return 0;
}
