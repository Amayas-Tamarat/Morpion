#include <iostream>
using namespace std;



char M[3][3] = { '1','2','3','4','5','6','7', '8','9' };
int ligne,colone;
char Joueur = 'X';
int choixjoueur;



void Table()
{
    //Creation de la table de jeu

    cout<<"Joueur - 1 [X] Joueur - 2 [O]\n";
    cout<<"     |     |     \n";
    cout<<"  "<<M[0][0]<<"  |  " <<M[0][1]<<"  |  "<<M[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<M[1][0]<<"  |  " <<M[1][1]<<"  |  "<<M[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<M[2][0]<<"  |  " <<M[2][1]<<"  |  "<<M[2][2]<<" \n";
    cout<<"     |     |     \n";
    cout << endl;
}



void Selection()
{
	//input du joueur 
    int choixjoueur;
    cout << "Choisire un nombre : ";
    cin >> choixjoueur;
    //filtre des choix valide 
    switch(choixjoueur){
    	case 1: ligne=0; colone=0; break;
        case 2: ligne=0; colone=1; break;
        case 3: ligne=0; colone=2; break;
        case 4: ligne=1; colone=0; break;
        case 5: ligne=1; colone=1; break;
        case 6: ligne=1; colone=2; break;
        case 7: ligne=2; colone=0; break;
        case 8: ligne=2; colone=1; break;
        case 9: ligne=2; colone=2; break;
        default:
            cout<<"Choisissez un nombre entre 1 et 9. \n";
}

//modif de la matrice selon les choix du joueur
    if (choixjoueur == 1)
        M[0][0] = Joueur;
    else if ( choixjoueur == 2)
        M[0][1] = Joueur;
    else if (choixjoueur == 3)
        M[0][2] = Joueur;
    else if (choixjoueur == 4)
        M[1][0] = Joueur;
    else if (choixjoueur == 5)
        M[1][1] = Joueur;
    else if (choixjoueur == 6)
        M[1][2] = Joueur;
    else if (choixjoueur == 7)
        M[2][0] = Joueur;
    else if (choixjoueur == 8)
        M[2][1] = Joueur;
    else if (choixjoueur == 9)
        M[2][2] = Joueur;
}

//Rotation des joueurs
void RotationJoueur()
{
    if (Joueur == 'X')
        Joueur = 'O';
    else
        Joueur = 'X';
}

//Definition des conditions de victoire pour chaque joueur
char victoire()
{
    //J1
    //victoire ligne
    if (M[0][0] == 'X' && M[0][1] == 'X' && M[0][2] == 'X')
        return 'X';
        
    if (M[1][0] == 'X' && M[1][1] == 'X' && M[1][2] == 'X')
        return 'X';
        
    if (M[2][0] == 'X' && M[2][1] == 'X' && M[2][2] == 'X')
        return 'X';
	//victoire colone 
     if (M[0][0] == 'X' && M[1][0] == 'X' && M[2][0] == 'X')
        return 'X';
        
    if (M[0][1] == 'X' && M[1][1] == 'X' && M[2][1] == 'X')
        return 'X';
        
    if (M[0][2] == 'X' && M[1][2] == 'X' && M[2][2] == 'X')
        return 'X';
 	//victoire diagonal
    if (M[0][0] == 'X' && M[1][1] == 'X' && M[2][2] == 'X')
        return 'X';
        
    if (M[2][0] == 'X' && M[1][1] == 'X' && M[0][2] == 'X')
        return 'X';
 
    //J2
    //victoire ligne
    if (M[0][0] == 'O' && M[0][1] == 'O' && M[0][2] == 'O')
        return 'O';
        
    if (M[1][0] == 'O' && M[1][1] == 'O' && M[1][2] == 'O')
        return 'O';
        
    if (M[2][0] == 'O' && M[2][1] == 'O' && M[2][2] == 'O')
        return 'O';
 	//victoire colone 
    if (M[0][0] == 'O' && M[1][0] == 'O' && M[2][0] == 'O')
        return 'O';
      
    if (M[0][1] == 'O' && M[1][1] == 'O' && M[2][1] == 'O')
        return 'O';
        
    if (M[0][2] == 'O' && M[1][2] == 'O' && M[2][2] == 'O')
        return 'O';
 	//victoire diagonal
    if (M[0][0] == 'O' && M[1][1] == 'O' && M[2][2] == 'O')
        return 'O';
        
    if (M[2][0] == 'O' && M[1][1] == 'O' && M[0][2] == 'O')
        return 'O';
 
    return '/';
}

//affichage resultat
int main()

{
    Table();
    while (1)
    {
        Selection();
        Table();
        if (victoire() == 'X')
        {
            cout << "Le joueur 1 est vainqueur!" << endl;
            break;
        }
        else if (victoire() == 'O')
        {
            cout << "Le joueur 2 est vainqueur!" << endl;
            break;
        }
        RotationJoueur();
    }
    system("pause");
    return 0;
}
