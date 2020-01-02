#include <iostream>
#include <fstream>


int main(void) {
    int ToplamSoru = 0;
    int i;
    int Not = 0;
    int ToplamOgrenci = 0;
    int z = 0;
    int ToplamNot = 0;
    int Ortalama = 0;
    int Aciklik;
    int OgrenciNotlari[ToplamOgrenci+5];
    char x = '\0';
    char CevapAnahtari[ToplamSoru];
    char OgrenciCevap[ToplamSoru+1];
    std::fstream Dosya;
    
    Dosya.open("input.txt");
    
    std::cout << "Toplam soru sayısını giriniz";
    std::cin  >> ToplamSoru;
    
    std::cout << "Cevap anahtarını giriniz:\n";
    for (i = 0; i < ToplamSoru; i++) {
        std::cin >> CevapAnahtari[i];
            if (Dosya.is_open()) {
                for(int i = 0; i < ToplamSoru; i++) {
                    Dosya << CevapAnahtari[i];
                }
            }
    }
        
    std::cout << "Mevcut öğrenci sayısını giriniz:";
    std::cin >> ToplamOgrenci;
    if (ToplamOgrenci <= 100) {
        for (i = 1; i <= ToplamOgrenci; i++) {
            std::cout << "Öğrenci numarasını ve cevaplarını sırayla giriniz:";
            
            for (i = 0; i <= ToplamSoru; i++) {
                std::cin >> OgrenciCevap[i+1];
                if (Dosya.is_open()) {
                    for(int i = 0; i < ToplamSoru+1; i++) {
                        Dosya << OgrenciCevap[i+1];
                    }
                }
                
                for (i = 0; i <= ToplamSoru; i++) {
                    if (CevapAnahtari[i] == OgrenciCevap[i+1]) {
                        Not = Not + 4;
                    }
                    else if (CevapAnahtari[i] != OgrenciCevap[i+1]) {
                        Not = Not - 1;
                    }
                    else if(OgrenciCevap[i+1] == x){
                        Not = Not + 0;
                    }
                    
                    OgrenciNotlari[i] = Not;
                    ToplamNot = ToplamNot + Not;
                }
                
            }
            if (Not < 0) {
                Not = 0;
            }
        }
    }
    
    for (i = 0; i <= ToplamOgrenci; i++) {
        if (OgrenciNotlari[i] > OgrenciNotlari[i+1]) {
            OgrenciNotlari[i] = z;
            OgrenciNotlari[i+1] = OgrenciNotlari[i];
            OgrenciNotlari[i+1] = z;
        }
    }
    
    Ortalama = ToplamNot % ToplamOgrenci;
    Aciklik = OgrenciNotlari[ToplamOgrenci] - OgrenciNotlari[0];
    
    OgrenciNotlari[ToplamOgrenci+1] = OgrenciNotlari[0];
    OgrenciNotlari[ToplamOgrenci+2] = OgrenciNotlari[ToplamOgrenci];
    OgrenciNotlari[ToplamOgrenci+4] = OgrenciNotlari[ToplamOgrenci % 2];
    OgrenciNotlari[ToplamOgrenci+5] = Aciklik;
    
    Dosya.close();
    
    return 0;
}
