#ifndef Liste_hpp
#define Liste_hpp

#include "Dugum.hpp"

class Liste{

private:
    Dugum* ilk;
    int dugumSayisi;

public:
    Liste();
    ~Liste();
   
    void ekle(std::string veri , int index);
    void yazdir();
    Dugum* dugumGetir(int index);
    void sil(int index);
    


};




#endif