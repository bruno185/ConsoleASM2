// ConsoleASM.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <ctime>
#include <chrono>


using namespace std;

extern "C" int myProc();
extern "C" int makeitDouble(int i);
extern "C" int makeMul(int i, int j);
extern "C" char doString(char st[]);
extern "C" int doCharLen(char st[]);
extern "C" int doStrLen(string st);
extern "C" int doTab(int[],int);
extern "C" int doReadLocal();
extern "C" void BubbleSort(int[], int);


// commentaire

int main()
{
    int i = 5;
    int j = 8;
    const int maxtab = 40000;
    string myStr = "ABCD";
    // myStr = myStr + myStr + "   ";

    int myNum[maxtab];
    for (i = 0; i < maxtab; i++) {
        myNum[i] = i * i;
    }



    cout << "*************** DEB DU PROGRAMME ***************" << endl;
    char chaine[] = "Salut !!";
    printf(chaine);
    cout << endl << "longeur de chaine = " << strlen(chaine) << endl;
   

    //cout << "Hello World!\n";
    cout << "Result of myProc (eax, sal) : " << myProc() << endl;
    cout << "Result of makeitDouble : " << makeitDouble(i) << endl;
    cout << "Result of makeMul : " << makeMul(i,j) << endl;

    cout << "Result doSring : " << doString(chaine) << endl;
    cout << "Result doCharLen : " << doCharLen(chaine) << endl;
    cout << "Result doStrLen : " << doStrLen(myStr) << endl;

    cout << "Result doReadLocal() before modif. variable globale : " << doReadLocal() << endl; 
    cout << "Result doTab(myNum, 3) : " << doTab(myNum, 3) << endl; // récupère le 3ème élément du tableau
    cout << "Result doReadLocal() after modif. variable globale : " << doReadLocal() << endl;


    unsigned __int64 now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    srand(now);
    for (i = 0; i < maxtab; i++) {
        myNum[i] = std::rand()% 1000;
        //myNum[i] = maxtab - i;
    }

    bool dispalylist = false;

    cout << endl << "Bubble Sort" << endl;
    cout << "************* AVANT TRI *************" << endl;
    
    if (dispalylist) {
        for (i = 0; i < maxtab; i++) {
            cout << " BubbleSort " << i << " : " << myNum[i] << endl;
        }
    }

    BubbleSort(myNum, maxtab);

    cout << "************* APRES TRI *************" << endl;

    if (dispalylist) {
        for (i = 0; i < maxtab; i++) {
            cout << " BubbleSort " << i << " : " << myNum[i] << endl;
        }
    }

    cout << "*************** FIN DU PROGRAMME ***************" << endl;
   
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
