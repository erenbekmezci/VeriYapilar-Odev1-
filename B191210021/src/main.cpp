/** 
* @ file                   main.cpp
* @ description            Dosya okuma işlemleri
* @ course                 1.Öğretim C grubu
* @ assignment             1. Odev
* @ date                   08/11/2021
* @ author                 Eren Bekmezci eren.bekmezci@sakarya.edu.tr
*/

#include <iostream>
#include <cstdlib> //c++ 11 ve asagi sürümler icin atoi

using namespace std;

#include <fstream>
#include "Liste.hpp"




int main(){


fstream dosya;

dosya.open("Veri.txt" , ios::in);

Liste* p = new Liste();

if(dosya.is_open()){
  
    string veri;
    
    while (!dosya.eof())
    {


        //dosyadaki verileri satır satır alma
        getline(dosya,veri);

        
        //index alma
        int pos1= veri.find("(");
        int pos2=veri.find("#");

        int basamak = pos2 - (pos1+1);
        string str = veri.substr(pos1 + 1 ,basamak );


        //atoi ile string inte çevirmek için str2 adında char dizi oluşturdum ve str'nin değerlerini attım (sayı stringini)


        char str2[str.length()+1]; 
        
        for (int x = 0; x < sizeof(str2); x++) 
        { 
            str2[x] = str[x];   
        }

        //daha sonra str3 pointeri tanımladım ve str2 yi gösterdim
        const char* str3 = str2;

        

        int sayi = atoi(str3);
        
        int index = sayi;  

        //isim , soyisim degerini alma
        int pos3 = veri.find(")");
        
        string veriSon = veri.substr(pos2 + 1 , pos3 - pos2 - 1);
    

                          
        
        if (veri[0] == 'E')
        {
  
            p->ekle(veriSon ,index);

           
        }
        if(veri[0] == 'S')
        {
            
            p->sil(index);
        }
        
        
        
    }
    


}
else
    cout<<"Dosya okuma basarisiz";

p->yazdir();

delete p;

dosya.close();

}