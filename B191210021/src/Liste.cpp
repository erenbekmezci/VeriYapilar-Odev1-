/** 
* @ file                   Liste.cpp
* @ description            Dugum sınıfının oluşturulması / dugum ekleme / silme / yazdirma işlemleri
* @ course                 1.Öğretim C grubu
* @ assignment             1. Ödev
* @ date                   08/11/2021
* @ author                 Eren Bekmezci eren.bekmezci@sakarya.edu.tr
*/



#include "Liste.hpp"
#include <iostream>


Liste::Liste(){
    this->ilk = 0;
    
}

Liste::~Liste(){
    Dugum* gec = ilk;

    while (gec!=0)
    {
            
        Dugum* sil = gec;
        gec = gec->sonraki;
        delete sil;
    } 
}

void Liste::yazdir(){

    Dugum* gec = ilk;
        
    using namespace std;


    while (gec!=0)
    {
            
        
        cout<<gec->deger<<" <--> ";
        
          
        gec= gec->sonraki;  

    }

}

Dugum* Liste::dugumGetir(int index){

    int sayac = 0;
    Dugum* gec = ilk;
    while(gec != 0){

        if(index == sayac)
        {
            return gec;
        }    
        gec = gec->sonraki;
        sayac++;
    }

    return 0; 

}

void Liste::sil(int index){
    
    auto silinecek = dugumGetir(index);

    Dugum* gec = ilk;

    
    if(silinecek == 0){     //girilen index no bulunamazsa son düğümü sil
        
        if(ilk == 0) return;

        if(ilk->sonraki == 0)
        {
            delete ilk;
            ilk=0;
            return;
        }

            
        
        Dugum* gec = ilk;
        while (gec->sonraki->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        delete gec->sonraki;
        gec->sonraki = 0;
        
        return;
    }
    else{
        Dugum* kopya;
        while(silinecek->sonraki != 0)
        {
            kopya = silinecek->sonraki;
            silinecek->deger = kopya->deger;
            silinecek = silinecek->sonraki;
        }
        delete silinecek;
        silinecek->onceki->sonraki = 0;
    }
}


void Liste::ekle(std::string veri , int index){
    
    Dugum* yeni = new Dugum(veri);
    using namespace std;
    
    if (ilk == 0)
    {
        ilk = yeni;
        
        
        return; 
    }

        
            
    Dugum* gec = ilk;
    auto dugumSorgu = dugumGetir(index);


    if(dugumSorgu){

        while (gec->sonraki!=0) 
        {
            gec = gec->sonraki;
        }
            yeni->onceki = gec;
            gec->sonraki = yeni;
           
            

        gec = yeni;

        Dugum* kopya;
        while(gec!=dugumSorgu)
        {
           kopya = gec->onceki;
           gec->deger=kopya->deger;
           gec = gec->onceki;
        }
        gec->deger = veri;

    }
    else{

        while (gec->sonraki!=0) 
        {
            gec = gec->sonraki;
        }
            yeni->onceki = gec;
            gec->sonraki = yeni;
            
    }
       


}