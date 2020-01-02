#include <iostream>
#include <fstream>

/*https://www.programiz.com/cpp-programming/arrays - https://www.w3schools.com/cpp/cpp_arrays.asp*/

int main(void) {
    Dosya.open("input.txt");
    std::cout << "Toplam soru sayısını giriniz";
    std::cin  >> ToplamSoru;
    std::cout << "Cevap anahtarını giriniz:\n";
    int Ortalama = 0;
	int ToplamSoru = 0;
    int i;
    int Not = 0;
    int ToplamKisi = 0;
    int z = 0;
    int ToplamNot = 0;
    int Ack;
    int KisiNotlari[ToplamKisi+5];
    char x = '\0';
    char CevapAnahtari[ToplamSoru];
    char KisiCevap[ToplamSoru+1];
	std::fstream Dosya;
   
    for (i = 0; i < ToplamSoru; i++) {
    std::cin >> CevapAnahtari[i];
    if (Dosya.is_open()) {
    for(int i = 0; i < ToplamSoru; i++) {
    Dosya << CevapAnahtari[i];
	}
    }
    }
    std::cout << "Mevcut öğrenci sayısını giriniz:";
    std::cin >> ToplamKisi;
    if (ToplamKisi <= 100) {
    for (i = 1; i <= ToplamKisi; i++) {
    std::cout << "Öğrenci numarasını ve cevaplarını sırayla giriniz:";
    for (i = 0; i <= ToplamSoru; i++) {
    std::cin >> KisiCevap[i+1];
    if (Dosya.is_open()) {
    for(int i = 0; i < ToplamSoru+1; i++) {
    Dosya << KisiCevap[i+1];
    }
    }
                
    for (i = 0; i <= ToplamSoru; i++) {
    if (CevapAnahtari[i] == KisiCevap[i+1]) {
    Not = Not + 4;
    }
    else if (CevapAnahtari[i] != KisiCevap[i+1]) {
    Not = Not - 1;
    }
    else if(KisiCevap[i+1] == x){
    Not = Not + 0;
    }         
    KisiNotlari[i] = Not;
    ToplamNot = ToplamNot + Not;
    }      
    }
    if (Not < 0) {
    Not = 0;
    }
    }
    }
    for (i = 0; i <= ToplamKisi; i++) {
    if (KisiNotlari[i] > KisiNotlari[i+1]) {
    KisiNotlari[i] = z;
    KisiNotlari[i+1] = KisiNotlari[i];
    KisiNotlari[i+1] = z;
    }
    }
    Ortalama = ToplamNot % ToplamKisi;
    Ack = KisiNotlari[ToplamKisi] - KisiNotlari[0];
    KisiNotlari[ToplamKisi+1] = KisiNotlari[0];
    KisiNotlari[ToplamKisi+2] = KisiNotlari[ToplamKisi];
    KisiNotlari[ToplamKisi+4] = KisiNotlari[ToplamKisi % 2];
    KisiNotlari[ToplamKisi+5] = Ack;
    Dosya.close();
    return 0;
}
