#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;

string removeSpaces(string str)
{
    string stringa;
    for (int i = 0; i<str.size(); i++)
        if (str[i] != ' ')
            stringa = stringa + str[i];
    
    return stringa;
}
 

using std::cout; using std::cin;
using std::endl; using std::string;
using std::map; using std::copy;

template<typename Map>




void PrintMap(Map& m, string key)
{
    ofstream outdata;
    outdata.open("encrypted.txt"); // opens the file
    if( !outdata ) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    cout << "[ ";
    for (auto &item : m) {
        outdata << item.first << ":" << item.second << ";"<<endl;
    }
    cout << "]\n";
    outdata<<key;
    outdata.close();
}


int main(){
    string chiave,frase;
    map<char, string> mymap;
    
    /*cout<<"Inserisci la frase: ";
	cin>>frase;*/

    std::cout << "Inserisci la frase: ";
    std::getline(std::cin, frase);


    //frase = removeSpaces(frase); //inserire per togliere gli spazi

    cout<<frase<<endl;


    cout<<"Inserisci la chiave: ";
    cin>>chiave;

    for(int j=0;j<chiave.size();j++){
        for(int i=j; i<frase.size();i+=chiave.size()){
            mymap[chiave[j]] = mymap[chiave[j]]  + frase[i];
        }
    }
    

    
    
    PrintMap(mymap,chiave);


    for (auto &item : mymap) {
        cout << item.first << ":" << item.second << ";"<<endl;
    }
    return 0;
}


 