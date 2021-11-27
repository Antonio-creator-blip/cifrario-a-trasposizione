#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;

using std::cout; using std::cin;
using std::endl; using std::string;
using std::map; using std::copy;




int main() {
    fstream newfile;
    map<char, string> mymap;
    int i=0;
    newfile.open("encrypted.txt",ios::in);
    if (newfile.is_open()){
        string tp,str;
        while(getline(newfile, tp)){
            if (tp.find(';') != std::string::npos){
                for(int i=2;i<tp.size()-1;i++){
                str =str +  tp[i];
                }
                mymap[tp[0]] = str;
                str= "";
                
            }
            else{
                mymap['0'] = tp; 
            }
            i++;
            
            
        }
        newfile.close(); //close the file object.
    }

    int z=0;
    string chiave;
    for (auto &item : mymap) {
        if(z==0){
            chiave = item.second;
        }
        z++;
    }


    int j=0;
    string decrypted;
    while(j<chiave.size() * mymap[chiave[0]].size()){
        for(int i=0;i<chiave.size();i++){
        string str = mymap[chiave[i]];
            for(j; j<mymap[chiave[i]].size();j++){
                decrypted = decrypted + str[j];
                break;
            }
        }
        i=0;
        j++;
    }
    cout<<decrypted<<endl;
    

    ofstream outdata;
    outdata.open("decrypted.txt"); 
    if( !outdata ) { 
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    outdata<<decrypted;
    outdata.close();

}
