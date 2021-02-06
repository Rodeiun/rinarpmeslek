/*
1: herseydahil
2: taLevel
3: flatbed2
4: tirkasabiliyo
5: tLevel
6: roadtrain2

DEVELOPER NOTES
*/
//=================================================\\

#include <cstdlib>
#include <iostream>
#include <clocale>
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <conio.h>


#define GİSE_UCRET (16)
#define YAKIT (4)
//=================================================\\
 
int taLevel, tLevel; // meslek levelleri
int flatbed, roadtrain, tirkasiyo; // geçici değişkenler
int BolumParaTa; // taşımacılıkta aldığı bölümpara
int BolumParaT; // tırcılıkta aldığı bölümpara
int kazancli; // kazançlı olan meslek
double bolumParaTa;
double tSKM; // ROADTRAİN İLE 1 SEFERDE KAÇ YAKIT KULLANILDIĞI
double tSYakıt; // ROADTRAİN İLE 1 SEFERDE KAÇ KM GİDİLDİĞİ
double taSKM;
double taSYakıt;
int secim2;
double saatgidert;
double saatgiderta;
int kullanım; // kullanım yöntemi, 1 = kayıt ile kullanım, 2 = geçici kullanım.
int giseparast;
int giseparasta;
double bolumParaT;
bool flatbed2, roadtrain2, tirkasabiliyo, kaydoldu, kaydoldug; // varmı yokmu, kasabiliyormu
bool herseydahil; // gişe parası / yakıt parası ödüyor demek.


//=================================================\\

using namespace std;

//=================================================\\

void SendClientMessage(string msj, int gonderen)
{
    cout << "\n=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "<GelenMesaj>" << msj;
    if (gonderen == 0)
        cout << "\nGönderen: Sistem.\n";
    if (gonderen == 1)
        cout << "\nGönderen: Development Team\n";
    if (gonderen == 2) { }
    cout << "\n=-=-=-=-=-=-=-=-=-=-=\n";
}
void SendErrorMessage(string msj, int gonderen)
{
    cout << "\n=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "<HataMesaj>" << msj;
    if (gonderen == 0)
        cout << "\nGönderen: Sistem.\n";
    if (gonderen == 1)
        cout << "\nGönderen: Development Team\n";
    if (gonderen == 2) {}
    cout << "\n=-=-=-=-=-=-=-=-=-=-=\n";
}
void SendSyntaxMessage(string msj, int gonderen)
{
    cout << "\n=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "<BilgiMesaj>" << msj;
    if (gonderen == 0)
        cout << "\nGönderen: Sistem.\n";
    if (gonderen == 1)
        cout << "\nGönderen: Development Team\n";
    if (gonderen == 2) {}
    cout << "\n=-=-=-=-=-=-=-=-=-=-=\n";
}
void tumVerileriKaydet()
{
    ofstream tumVeri("tumveri.txt");
    tumVeri << taLevel << endl; // int0
    tumVeri << tLevel << endl; // int1
    tumVeri << BolumParaT << endl; // int2
    tumVeri << BolumParaTa << endl; // int3
    tumVeri << kazancli << endl; // int4
    tumVeri << giseparasta << endl; // int5
    tumVeri << giseparast << endl; // int // 6 int6
    tumVeri << bolumParaT << endl; // double7
    tumVeri << bolumParaTa << endl; // double8
    tumVeri << tSKM << endl; // double9
    tumVeri << tSYakıt << endl; // double10
    tumVeri << taSKM << endl; // double11
    tumVeri << taSYakıt << endl; // double12
    tumVeri << saatgidert << endl; // double13
    tumVeri << saatgiderta << endl; // double // 8 double14
    tumVeri << flatbed2 << endl; // bool15
    tumVeri << roadtrain2 << endl; // bool16
    tumVeri << tirkasabiliyo << endl; // bool17
    tumVeri << kaydoldu << endl; // bool18
    tumVeri << herseydahil << endl; // 5 bool19
    // 19 değişken kaydedildi:
    tumVeri.close();
}
void tumVerileriCek()
{
    ifstream tumVeri("tumveri.txt");
    string degiskenler[20];
    int degiskenint[7];
    double degiskendouble[9];
    bool degiskenbool[6];
    if (kaydoldu)
    {
        for (int i = 0; i < 21; i++)
            while (getline(tumVeri, degiskenler[i]))
            {
                for (int i = 0; i < 8; i++) 
                    degiskenint[i] = atoi(degiskenler[i].c_str());
                for (int j = 8; j < 16; j++)
                    degiskendouble[j] = atoi(degiskenler[j].c_str());
                for (int k = 18; k < 19; k++)
                    degiskenbool[k] = atoi(degiskenler[k].c_str());
            }
        taLevel = degiskenint[0];
        tLevel = degiskenint[1];
        BolumParaT = degiskenint[2];
        BolumParaTa = degiskenint[3];
        kazancli = degiskenint[4];
        giseparasta = degiskenint[5];
        giseparast = degiskenint[6];
        bolumParaT = degiskendouble[0];
        bolumParaTa = degiskendouble[1];
        tSKM = degiskendouble[2];
        tSYakıt = degiskendouble[3];
        taSKM = degiskendouble[4];
        saatgidert = degiskendouble[5];
        saatgiderta = degiskendouble[6];
        flatbed2 = degiskenbool[0];
        roadtrain2 = degiskenbool[1];
        tirkasabiliyo = degiskenbool[2];
        kaydoldu = degiskenbool[3];
        herseydahil = degiskenbool[4];
    }
    else { SendErrorMessage("Error!", 0); }
    tumVeri.close();

}
void islemİptali(string sbp)
{
    tumVerileriKaydet();
    SendSyntaxMessage("Programdan atıldınız.\nSebep :\t" + sbp + "", 0);
    system("pause");
    exit(0);
}
void kayitgiris()
{
    
}
void turkceDil()
{
    setlocale(LC_ALL, "Turkish");
}
void bolumPara()
{
    //=================================================\\

    if (taLevel == 1)
    {
        if (flatbed2 == true)
            bolumParaTa = 8864;
        else
            bolumParaTa = 6652;
    }
    if (taLevel == 2)
    {
        if (flatbed2 == true)
            bolumParaTa = 9736;
        else
            bolumParaTa = 7792;
    }
    if (taLevel == 3)
    {
        if (flatbed2 == true)
            bolumParaTa = 10786;
        else
            bolumParaTa = 8632;
    }
    if (taLevel == 4)
    {
        if (flatbed2 == true)
            bolumParaTa = 12736;
        else
            bolumParaTa = 10192;
    }
    if (taLevel == 5)
    {
        if (flatbed2 == true)
            bolumParaTa = 14236;
        else
            bolumParaTa = 11392;
    }

    //=================================================\\

    if (tLevel == 1)
    {
        if (roadtrain2 == true)
            bolumParaT = 12144;
        if (roadtrain2 == false)
            bolumParaT = 10120;
    }
    if (tLevel == 2)
    {
        if (roadtrain2 == true)
            bolumParaT = 13962;
        if (roadtrain2 == false)
            bolumParaT = 11635;
    }
    if (tLevel == 3)
    {
        if (roadtrain2 == true)
            bolumParaT = 15786;
        if (roadtrain2 == false)
            bolumParaT = 13155;
    }
    if (tLevel == 4)
    {
        if (roadtrain2 == true)
            bolumParaT = 17616;
        if (roadtrain2 == false)
            bolumParaT = 14680;
    }
    if (tLevel == 5)
    {
        if (roadtrain2 == true)
            bolumParaT = 19428;
        if (roadtrain2 == false)
            bolumParaT = 16190;
    }
}
void seferHesapla()
{
    // BİR SEFERDE NEKADAR KM GİDİLDİĞİNİ, BİR SEFERDE NEKADAR YAKIT HARCANDIĞINI HESAPLAR.
    if (tirkasabiliyo == true)
    {
        if (roadtrain2 == false)
        {
            tSKM = 8.5;
            tSYakıt = 24.73;
        }
        if (roadtrain2 == true)
        {
            tSYakıt = 25.72;
            tSKM = 8.5;
        }
        if (flatbed2 == true)
        {
            taSYakıt = 9.0;
            taSKM = 2.4;
        }
        if (flatbed2 == false)
        {
            taSYakıt = 0.0;
            taSKM = 0.0;
        }
    }
    else
    {
        if (roadtrain2 == false)
        {
            tSKM = 0.0;
            tSYakıt = 0.0;
        }
        if (roadtrain2 == true)
        {
            tSYakıt = 0.0;
            tSKM = 0.0;
        }
        if (flatbed2 == true)
        {
            taSYakıt = 9.0;
            taSKM = 2.4;
        }
        if (flatbed2 == false)
        {
            taSYakıt = 0.0;
            taSKM = 0.0;
        }
    }
}
void GelirGider()
{
    seferHesapla();
    double yakıtparat = 0;
    double yakıtparata = 0;
    double vergiparat =0;
       int vergiparata = 0;

    if (tirkasabiliyo == true)
    {
        if (roadtrain2 == true)
        {
            if (herseydahil == true) {
                giseparast = giseparast + 32, 0;
                yakıtparat = yakıtparat + tSYakıt * 4;
                vergiparat = vergiparat + 15, 0;
            }
            else {
                giseparast = giseparast + 0, 0;
                vergiparat = 0,0;
                yakıtparat = 0, 0;
            }
        }
        else
        {
            if (herseydahil == true)
            {
                giseparast = giseparast + 32, 0;
                yakıtparat = tSYakıt * 4;
                vergiparat = 32, 0;
            }
            else 
            {
                giseparast = giseparast + 0, 0;
                yakıtparat = yakıtparat + 0, 0;
                vergiparat = vergiparat + 0, 0;
            }
        }
    }
    else
    {
        yakıtparat = yakıtparat + 0,0;
        vergiparat = vergiparat + 0,0;
    }

    if (flatbed2 == true)
    {
        if (herseydahil == true)
        {
            giseparasta = giseparasta + 32, 0;
            yakıtparata = taSYakıt * 4;
            vergiparata = 32;
        }
        else { 
            giseparasta = 0, 0; 
            yakıtparata = 0, 0;
            vergiparata = 32, 0;
        }
    }
    else
    {
        if (herseydahil == true)
        {
            yakıtparata = 0, 0;
            vergiparata = 0, 0;
            giseparasta = giseparasta + 32;
        }
        else
        {
            yakıtparata = 0, 0;
            vergiparata = 0, 0;
            giseparasta = giseparasta + 0,0;
        }
    }
    if (tirkasabiliyo == false)
    {
        saatgidert = 0,0;
    }
    saatgidert = yakıtparat + vergiparat;
    saatgiderta = yakıtparata + vergiparata;
}
void FARKVAR()
{
    if (kaydoldu == true)
    {
        system("cls");
        bolumPara();
        double farkTa = bolumParaTa - saatgiderta;
        double farkT = bolumParaT - saatgidert;
        cout << "============================================================================================================" << endl;
        cout << "Tırcılıktan saatlik geliriniz: $" << bolumParaT << "\nTaşımacılıktan saatlik geliriniz: $" << bolumParaTa << "\n" << endl;
        cout << "Tırcılıktan saatlik gideriniz: $" << saatgidert << "\nTaşımacılıktan saatlik gideriniz: $" << saatgiderta << "\n" << endl;
        cout << "Tırcılıktan saatlik net geliriniz(gider dahil) $" << farkT << "\nTaşımacılıktan saatlik net geliriniz(gider dahil) $" << farkTa << "\n" << endl;
        cout << "============================================================================================================" << endl;
        cout << "Vergiyi hesaplarken Nitro, Zırh vergisi vs. dahil edilmez.";
        cout << "Eğer ekranda 0 değeri yazıyorsa, gerek duyulmayan bir değerdir. Herhangi bir bug söz konusu değildir.";
        cout << "Sayı: 'xxxxx.y' şeklindeyse sonundaki '.y' yi aldırış etmeyin. Tam sayı açısından değerlendirilmemektedir." << endl;
        islemİptali("İşlem sonuçlandı.");
    }
    else if (kaydoldu == false)
        islemİptali("Kayıt olmalısınız.");
}
int ortalamaAl(int x, int y)
{
    int toplam = x + y / 2;
    return toplam;
}
void aldigiParaTa() {

    if (taLevel == 1)
        BolumParaTa = 580;
    if (taLevel == 2)
        BolumParaTa = 680;
    if (taLevel == 3)
        BolumParaTa = 750;
    if (taLevel == 4)
        BolumParaTa = 880;
    if (taLevel == 5)
        BolumParaTa = 980;
}
void saatlikKazanc()
{
    system("cls");
    if (kaydoldu == false)
    {
        islemİptali("Programdan atıldınız, lütfen tekrar açtığınızda menüden kayıt yaptırmayı seçin.");
    }
    if (kaydoldu == true)
    {
        if (tirkasabiliyo == true)
        {
            cout << "1 Saat boyunca: \n -Tırcılık kasarsanız \t\t " << bolumParaT << "$ kazancınız olacaktır.\n -Taşımacılık kasarsanız \t\t " << bolumParaTa << "$ kazancınız olacaktır." << endl;
            islemİptali("Program işlevini yerine getirdi.");
        }
        else
        {
            cout << "1 Saat boyunca: \n -Taşımacılık kasarsanız \t\t " << bolumParaTa << "$ kazancınız olacaktır." << endl;
            islemİptali("Program işlevini yerine getirdi.");
        }
    }
}
void aldigiParaT()
{
    if (tLevel == 1)
        BolumParaT = ortalamaAl(708, 405);
    if (tLevel == 2)
        BolumParaT = ortalamaAl(810, 455);
    if (tLevel == 3)
        BolumParaT = ortalamaAl(911, 506);
    if (tLevel == 4)
        BolumParaT = ortalamaAl(1012, 557);
    if (tLevel == 5)
        BolumParaT = ortalamaAl(1113, 607);
}
void kazanci()
{
    system("cls");
    if (kaydoldu == true)
    {
        aldigiParaTa();
        aldigiParaT();
        int Tasima;
        Tasima = BolumParaTa;
        int Tir;
        Tir = BolumParaT;
        if (!tirkasabiliyo)
        {
            if (taLevel != 1)
                kazancli = 1;
            else if (taLevel == 1)
                kazancli = 3;
        }
        if (tirkasabiliyo)
            kazancli = 2;
        //    cout << "Tasimacilik yaparsaniz net kazanciniz bu olacaktir: " << Tasima << " Tircilik yaparsaniz ise ortalama kazanciniz bu olacaktir: " << Tir << endl;
        cout << "Benim önerim ise bence '" << kazancli <<"'olacaktir. Bizi tercih ettiginiz icin tesekkurler.";
        cout << "1 = Tasimacilik\n2 = Tircilik\n3 = Cimento\n";
        islemİptali("Program işlevini yerine getirdi.");
    }
    else
        islemİptali("Lütfen kayıt olunuz.");
}
void KMYakıt()
{
//    system("color purple");
    if (kaydoldu == false)
        islemİptali("Kayıt olmadığınız için atıldınız.");
    else
    {
        if (tirkasabiliyo == true)
            cout << "1 sefer tır yaparsanız(başladığınız yerden tekrar başlangıç yerine):\n" << tSKM << "KM gidersiniz | " << tSYakıt << " yakıt harcarsınız.\n1 sefer taşımacılık yaparsanız(başladığınız yerden tekrar başlangıç yerine):\n" << taSKM << " KM gidersiniz | " << taSYakıt << " yakıt harcarsınız.";
        if (tirkasabiliyo == false)
            cout << "1 sefer taşımacılık yaparsanız(başladığınız yerden tekrar başlangıç yerine):\n" << taSKM << " KM gidersiniz | " << taSYakıt << " yakıt harcarsınız.";
    }
}
void bilgiAl()
{
    if (!kaydoldug)
    {
        cout << "Gişe, yakıt, vergi parasının dahil olmasını istermisiniz?" << endl;
        cout << "(Evet için = 1, Hayır için = 2)" << endl;
        int secimc[2];
        cin >> secimc[0];
        if (secimc[0] == 1) herseydahil = true;
        if (secimc[0] == 2) herseydahil = false;
        if (secimc[0] != 1)
        {
            if (secimc[0] != 2)
            {
                SendErrorMessage("Lütfen, 1 veya 2 giriniz.", 0);
                cin >> secimc[1];
                if (secimc[1] != 1)
                {
                    if (secimc[1] != 2)
                        islemİptali("1 veya 2 girmediniz.");
                }
                if (secimc[1] == 1)
                    herseydahil = true;
                if (secimc[1] == 2)
                    herseydahil = false;
            }
        }
        cout << "==================================================" << endl;
        cout << "===============Taşımacılık İşlemleri==============" << endl;
        cout << "Lütfen taşımacılık levelinizi giriniz: " << endl;
        cout << "Lütfen kullanırken küçük harf kullanmaya özen gösterin." << endl;
        int secimx[2];
        cin >> secimx[0];
        if (secimx[0] == 0) { taLevel = 1; }
        if (secimx[0] > 5)
        {
            SendErrorMessage("Lütfen, 5 den büyük değer girmeyin.", 0);
            cin >> secimx[1];
            if (secimx[1] > 5)
                islemİptali("5 den büyük değer girilemez.");
            taLevel = secimx[1];
        }
        taLevel = secimx[0];

        cout << "Flatbediniz varmı yokmu(Evet ise: 1, Hayır ise 2.)" << endl;
        cin >> flatbed;
        if (flatbed != 1)
        {
            if (flatbed != 2)
            {
                int secimz[2];
                cin >> secimz[0];
                if (secimz[0] == 0) { secimz[0] = 1; }
                if (secimz[0] > 2)
                {
                    SendErrorMessage("1-2 harici sayı girilemez.", 0);
                    cin >> secimz[1];
                    if (secimz[1] > 2)
                        islemİptali("1-2 harici sayı girilmez.");
                    if (secimz[1] == 2)
                        flatbed2 = false;
                    if (secimz[1] == 1)
                        flatbed2 = true;
                }

            }
        }
        if (flatbed != 2)
        {
            cout << "Flatbediniz var olarak ayarlandı!" << endl;
            flatbed2 = true;
        }
        if (flatbed != 1)
        {
            cout << "Flatbediniz yok olarak ayarlandı!" << endl;
            flatbed2 = false;
        }
        cout << "==================================================" << endl;
        cout << "================Tırcılık İşlemleri================" << endl;
        cout << "Dipnot: Hesaplamalar Kaçak Yük üzerinden hesaplanır, Kazancınız hesaplanırken tırcılıkta aldığınız en yüksek para ve en dusuk paranın ortalaması alınır ve kazanca değer girilir." << endl;
        cout << "Tırcılık kasabiliyormusunuz, (En az 10 levelmisiniz?)\n(Evet ise : 1, Hayır ise: 2)" << endl;
        cin >> tirkasiyo;
        if (tirkasiyo != 1)
        {
            if (tirkasiyo != 2) {
                int secimy[2];
                cin >> secimy[0];
                if (secimy[0] == 0)
                    secimy[0] = 1;
                if (secimy[0] > 5)
                {
                    SendClientMessage("1-2 değeri haricinde bir sayı yazmayınız.", 0);
                    cin >> secimy[1];
                    if (secimy[1] > 5)
                        islemİptali("1-2 değeri haricinde bir sayı yazmayınız.");
                    if (secimy[1] == 2)
                        tirkasabiliyo = false;
                    if (secimy[1] == 1)
                        tirkasabiliyo = true;
                }
            }
        }
        if (tirkasiyo == 1)
        {
            cout << "Tır kasabiliyorsunuz olarak ayarlandı!" << endl;
            tirkasabiliyo = true;
        }
        if (tirkasiyo == 2)
        {
            cout << "Tır kasamıyorsunuz olarak ayarlandı!" << endl;
            tirkasabiliyo = false;
        }
        if (tirkasabiliyo == false) {
            kaydoldu = true;
            system("cls");
            cout << "Lütfen seçim yapınız.\n(1 Saatlik kazanç için = 1, Kazançlı olan meslek = 2, KM Yakıt hesaplamak için = 3, Net Gelir Gider için = 4)" << endl;
            cin >> secim2;
            if (secim2 == 1)
            {
                bolumPara();
                saatlikKazanc();
            }
            if (secim2 == 2)
                kazanci();
            if (secim2 == 3)
            {
                seferHesapla();
                KMYakıt();
            }
            if (secim2 == 4)
            {
                GelirGider();
                FARKVAR();
            }
            if (secim2 != 1)
            {
                if (secim2 != 2)
                {
                    if (secim2 != 3)
                    {
                        if (secim2 != 4)
                        {
                            int secimxx[2];
                            cin >> secimxx[0];
                            if (secimxx[0] == 0) { secimxx[0] = 1; }
                            if (secimxx[0] > 5)
                            {
                                SendClientMessage("4 den büyük değer girilemez, tekrar giriniz.", 0);
                                cin >> secimxx[1];
                                if (secimxx[1] > 5)
                                    islemİptali("4 den büyük değer girilemez.");
                                if (secimxx[1] == 1)
                                {
                                    bolumPara();
                                    saatlikKazanc();
                                }
                                if (secimxx[1] == 2)
                                    kazanci();
                                if (secimxx[1] == 3)
                                {
                                    seferHesapla();
                                    KMYakıt();
                                }
                                if (secimxx[1] == 4)
                                {
                                    GelirGider();
                                    FARKVAR();
                                }
                            }
                        }
                    }
                }
            }
        }
        if (tirkasabiliyo == true)
        {
            cout << "Lütfen tırcılık levelinizi giriniz: " << endl;
            int secimxu[2];
            cin >> secimxu[0];
            if (tLevel == 0) { tLevel = 1; }
            if (tLevel > 5)
            {
                if (secimxu[0] == 0) { secimxu[0] = 1; }
                if (secimxu[0] > 5)
                {
                    SendClientMessage("5 den büyük değer girilemez, tekrar giriniz.", 0);
                    cin >> secimxu[1];
                    if (secimxu[1] > 5)
                        islemİptali("5 den büyük değer girilemez.");
                    tLevel = secimxu[1];
                }
            }
            cout << "Roadtrain varmı yokmu(Evet ise: 1, Hayır ise 2.)" << endl;
            cin >> roadtrain;
            if (roadtrain != 1)
            {
                if (roadtrain != 2)
                {
                    int secimxy[2];
                    cin >> secimxy[0];
                    if (secimxy[0] == 0)
                        secimxy[0] = 1;
                    if (secimxy[0] > 5)
                    {
                        SendClientMessage("1-2 harici değer girilemez, tekrar giriniz.", 0);
                        cin >> secimxy[1];
                        if (secimxy[1] > 2)
                            islemİptali("1-2 harici değer girilemez.");
                        if (secimxy[1] == 1)
                            roadtrain2 = true;
                        if (secimxy[1] == 2)
                            roadtrain2 = false;
                    }
                }
            }
            if (roadtrain == 1)
            {
                cout << "Roadtraininiz var olarak ayarlandı!" << endl;
                roadtrain2 = true;
            }
            if (roadtrain == 2)
            {
                cout << "Roadtraininiz yok olarak ayarlandı!" << endl;
                roadtrain2 = false;
            }
        }
        system("cls");
        cout << "==================================================" << endl;
        kaydoldu = true;
        cout << "Lütfen seçim yapınız.\n(1 Saatlik kazanç için = 1, Kazançlı olan meslek = 2, KM Yakıt hesaplamak için = 3, Net Gelir Gider için = 4)" << endl;
        cin >> secim2;
        if (secim2 == 1)
        {
            bolumPara();
            saatlikKazanc();
        }
        if (secim2 == 2)
            kazanci();
        if (secim2 == 3)
        {
            seferHesapla();
            KMYakıt();
        }
        if (secim2 == 4)
        {
            GelirGider();
            FARKVAR();
        }
        if (secim2 != 1)
        {
            if (secim2 != 2)
            {
                if (secim2 != 3)
                {
                    if (secim2 != 4)
                    {
                        int secimxx[2];
                        cin >> secimxx[0];
                        if (secimxx[0] == 0) { secimxx[0] = 1; }
                        if (secimxx[0] > 5)
                        {
                            SendClientMessage("1-4 harici değer girilemez, tekrar giriniz.", 0);
                            cin >> secimxx[1];
                            if (secimxx[1] > 5)
                                islemİptali("1-4 harici değer girilemez.");
                            if (secimxx[1] == 1)
                            {
                                bolumPara();
                                saatlikKazanc();
                            }
                            if (secimxx[1] == 2)
                                kazanci();
                            if (secimxx[1] == 3)
                            {
                                seferHesapla();
                                KMYakıt();
                            }
                            if (secimxx[1] == 4)
                            {
                                GelirGider();
                                FARKVAR();
                            }
                        }
                    }
                }
            }
        }
    }
    else if (kaydoldug)
    {
    system("cls");
    kaydoldug = true;
        cout << "Lütfen seçim yapınız.\n(1 Saatlik kazanç için = 1, Kazançlı olan meslek = 2, KM Yakıt hesaplamak için = 3, Net Gelir Gider için = 4)" << endl;
        cin >> secim2;
        if (secim2 == 1)
        {
            bolumPara();
            saatlikKazanc();
        }
        if (secim2 == 2)
            kazanci();
        if (secim2 == 3)
        {
            seferHesapla();
            KMYakıt();
        }
        if (secim2 == 4)
        {
            GelirGider();
            FARKVAR();
        }
        if (secim2 != 1)
        {
            if (secim2 != 2)
            {
                if (secim2 != 3)
                {
                    if (secim2 != 4)
                    {
                        int secimxx[2];
                        cin >> secimxx[0];
                        if (secimxx[0] == 0) { secimxx[0] = 1; }
                        if (secimxx[0] > 5)
                        {
                            SendClientMessage("5 den büyük değer girilemez, tekrar giriniz.", 0);
                            cin >> secimxx[1];
                            if (secimxx[1] > 5)
                                islemİptali("5 den büyük değer girilemez.");
                            if (secimxx[1] == 1)
                            {
                                bolumPara();
                                saatlikKazanc();
                            }
                            if (secimxx[1] == 2)
                                kazanci();
                            if (secimxx[1] == 3)
                            {
                                seferHesapla();
                                KMYakıt();
                            }
                            if (secimxx[1] == 4)
                            {
                                GelirGider();
                                FARKVAR();
                            }
                        }
                    }
                }
            }
        }
    }
}
void iletisim()
{
    system("cls");
//    system("color 15");
    SendClientMessage("\nDiscord:\nosmancik#2994\t https://discord.gg/gUwUtVu", 1);
    islemİptali("Program işlevini yerine getirdi.");
}
void veriKontrol()
{
    if (!kaydoldu)
    {
        cout << "Bilgisayarınızda kayıtlı hazır 'veriler.txt' bulunamadı. Bilgi kaydı yaptırmakmı yada geçici bilgiyle kullanmakmı?" << endl;
        cout << "(Bilgi kaydı yapmak = 1, Geçici bilgi ile kullanmak = 2)" << endl;
        int degisim[2];
        cin >> degisim[0];
        if (degisim[0] == 0)
            bilgiAlkaydet();
        if (degisim[0] == 1)
            bilgiAlkaydet();
        if (degisim[0] == 2)
            bilgiAl();
        if (degisim[0] != 1)
        {
            if (degisim[0] != 2)
            {
                SendErrorMessage("Lütfen, 1-2 arası sayı girin.", 0);
                cin >> degisim[1];
                if (degisim[1] != 1)
                {
                    if (degisim[1] != 2)
                    {
                        islemİptali("1-2 arası sayı girilmedi.");
                    }
                }
                if (degisim[1] == 0)
                    bilgiAlkaydet();
                if (degisim[1] == 1)
                    bilgiAlkaydet();
                if (degisim[1] == 2)
                    bilgiAl();
            }
        }
    }
    else
    {
        cout << "Bilgisayarınızda kayıtlı hazır 'veriler.txt' bulundu. Bilgi kaydınını kullanmakmı yada geçici bilgiyle kullanmakmı?" << endl;
        cout << "(Bilgi kaydını kullanmak = 1, Geçici bilgi = 2, kayıt yaptırmak için = 3)" << endl;
        int degisimx[2];
        cin >> degisimx[0];
        if (degisimx[0] == 1)
        {
            tumVerileriCek();
            cout << "Lütfen seçim yapınız.\n(1 Saatlik kazanç için = 1, Kazançlı olan meslek = 2, KM Yakıt hesaplamak için = 3, Net Gelir Gider için = 4)" << endl;
            cin >> secim2;
            bolumPara();
            if (secim2 == 1)
                saatlikKazanc();
            if (secim2 == 2)
                kazanci();
            if (secim2 == 3)
            {
                seferHesapla();
                KMYakıt();
            }
            if (secim2 == 4)
            {
                GelirGider();
                FARKVAR();
            }
            if (secim2 != 1)
            {
                if (secim2 != 2)
                {
                    if (secim2 != 3)
                    {
                        if (secim2 != 4)
                        {
                            int secimxx[2];
                            cin >> secimxx[0];
                            if (secimxx[0] == 0) { secimxx[0] = 1; }
                            if (secimxx[0] > 5)
                            {
                                SendClientMessage("5 den büyük değer girilemez, tekrar giriniz.", 0);
                                cin >> secimxx[1];
                                if (secimxx[1] > 5)
                                    islemİptali("5 den büyük değer girilemez.");
                                if (secimxx[1] == 1)
                                {
                                    bolumPara();
                                    saatlikKazanc();
                                }
                                if (secimxx[1] == 2)
                                    kazanci();
                                if (secimxx[1] == 3)
                                {
                                    seferHesapla();
                                    KMYakıt();
                                }
                                if (secimxx[1] == 4)
                                {
                                    GelirGider();
                                    FARKVAR();
                                }
                            }
                        }
                    }
                }
            }
        }
        if (degisimx[0] == 2)
            bilgiAl();
        if (degisimx[0] == 3)
            bilgiAlkaydet();
        if (degisimx[0] != 1)
        {
            if (degisimx[0] != 2)
            {
                if (degisimx[0] != 3)
                {
                    SendErrorMessage("Lütfen, 1-2 arası sayı girin.", 0);
                    cin >> degisimx[1];
                    if (degisimx[1] != 1)
                    {
                        if (degisimx[1] != 2)
                        {
                            islemİptali("1-2 arası sayı girilmedi.");
                        }
                    }
                    if (degisimx[0] == 1)
                    {
                        tumVerileriCek();
                        cout << "Lütfen seçim yapınız.\n(1 Saatlik kazanç için = 1, Kazançlı olan meslek = 2, KM Yakıt hesaplamak için = 3, Net Gelir Gider için = 4)" << endl;
                        cin >> degisimx[0];
                        bolumPara();
                        if (degisimx[0] == 1)
                            saatlikKazanc();
                        if (degisimx[0] == 2)
                            kazanci();
                        if (degisimx[0] == 3)
                        {
                            seferHesapla();
                            KMYakıt();
                        }
                        if (degisimx[0] == 4)
                        {
                            GelirGider();
                            FARKVAR();
                        }
                        if (degisimx[0] != 1)
                        {
                            if (degisimx[0] != 2)
                            {
                                if (degisimx[0] != 3)
                                {
                                    if (degisimx[0] != 4)
                                    {
                                        int secimxx[2];
                                        cin >> secimxx[0];
                                        if (secimxx[0] == 0) { secimxx[0] = 1; }
                                        if (secimxx[0] > 5)
                                        {
                                            SendClientMessage("5 den büyük değer girilemez, tekrar giriniz.", 0);
                                            cin >> secimxx[1];
                                            if (secimxx[1] > 5)
                                                islemİptali("5 den büyük değer girilemez.");
                                            if (secimxx[1] == 1)
                                            {
                                                bolumPara();
                                                saatlikKazanc();
                                            }
                                            if (secimxx[1] == 2)
                                                kazanci();
                                            if (secimxx[1] == 3)
                                            {
                                                seferHesapla();
                                                KMYakıt();
                                            }
                                            if (secimxx[1] == 4)
                                            {
                                                GelirGider();
                                                FARKVAR();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (degisimx[0] == 2)
                        bilgiAl();
                    if (degisimx[0] == 3)
                        bilgiAlkaydet();
                }
            }
        }
    }
}
void menu()
{
    int secim[1];
    cout << "==========================================" << endl;
    cout << "Şuanda menüdesiniz yapmak istediklerinizi lütfen (1-2-3) şeklinde yazın." << endl;
    cout << "Seçim 1 : \tProgramı kullanmanızı sağlar.\nSeçim 2 : \tİletişim bilgilerini almanızı sağlar.\nSeçim 3 : \tProgramdan çıkış yapmanızı sağlar.\n" << endl;
    cout << "==========================================" << endl;

        cin >> secim[0];
        if (secim[0] == 0) secim[0] = 1;
        if (secim[0] == 1)
            veriKontrol();
        if (secim[0] == 2)
            iletisim();
        if (secim[0] == 3)
            islemİptali("Program başarıyla sonuçlandırıldı.");
        if (secim[0] < 3)
        {
            SendErrorMessage("Lütfen 1-3 arası değer girin, bir hak daha sunuldu.", 0);
            cin >> secim[1];
            if (secim[1] == 0) secim[1] = 1;
            if (secim[1] == 1)
                veriKontrol();
            if (secim[1] == 2)
                iletisim();
            if (secim[1] == 3)
                islemİptali("Program başarıyla sonuçlandırıldı.");
            if (secim[1] > 3)
                islemİptali("1-3 harici değer girilmediği için program kapatıldı.");
        }

}
void yazi()
{
    cout << "==========================================" << endl;
    cout << "Rina RPG Meslek kazancı hesaplama programına hoşgeldiniz." << endl;
    cout << "Program: '27.06.2020' tarihinde 'osmancik' tarafından C++ Dili üzerinden kodlanmasına başlanmıştır." << endl;
    cout << "Programda oluşabilecek olağan hataları lütfen discord üzerinden bildiriniz." << endl;
    cout << "==========================================" << endl;
}
void bilgiAlkaydet()
{
    if (!kaydoldu)
    {
        cout << "Gişe, yakıt, vergi parasının dahil olmasını istermisiniz?" << endl;
        cout << "(Evet için = 1, Hayır için = 2)" << endl;
        int secimc[2];
        cin >> secimc[0];
        if (secimc[0] == 1) {
            ofstream dosya("veriler.txt");
            dosya << secimc[0] << endl;
            herseydahil = true;
        }
        if (secimc[0] == 2) {
            ofstream dosya("veriler.txt");
            dosya << secimc[0] << endl;
            herseydahil = false;
        }
        if (secimc[0] != 1)
        {
            if (secimc[0] != 2)
            {
                SendErrorMessage("Lütfen, 1 veya 2 giriniz.", 0);
                cin >> secimc[1];
                if (secimc[1] != 1)
                {
                    if (secimc[1] != 2)
                    {
                        islemİptali("1 veya 2 girmediniz.");
                    }
                }
                ofstream dosya("veriler.txt");
                dosya << secimc[1] << endl;
                if (secimc[1] == 1)
                    herseydahil = true;
                if (secimc[1] == 2)
                    herseydahil = false;
            }
        }
        cout << "==================================================" << endl;
        cout << "===============Taşımacılık İşlemleri==============" << endl;
        cout << "Lütfen taşımacılık levelinizi giriniz: " << endl;
        cout << "Lütfen kullanırken küçük harf kullanmaya özen gösterin." << endl;
        int secimx[2];
        cin >> secimx[0];
        if (secimx[0] == 0) {
            ofstream dosya("veriler.txt");
            dosya << "1" << endl;
            taLevel = 1;
        }
        if (secimx[0] > 5)
        {
            SendErrorMessage("Lütfen, 5 den büyük değer girmeyin.", 0);
            cin >> secimx[1];
            if (secimx[1] > 5)
                islemİptali("5 den büyük değer girilemez.");
            ofstream dosya("veriler.txt");
            dosya << secimx[1] << endl;
            taLevel = secimx[1];
        }
        ofstream dosya("veriler.txt");
        dosya << secimx[0] << endl;
        taLevel = secimx[0];

        cout << "Flatbediniz varmı yokmu(Evet ise: 1, Hayır ise 2.)" << endl;
        cin >> flatbed;
        if (flatbed != 1)
        {
            if (flatbed != 2)
            {
                int secimz[2];
                cin >> secimz[0];
                if (secimz[0] == 0) {
                    ofstream dosya("veriler.txt");
                    dosya << "1"<< endl;
                    flatbed2 = true;
                }
                if (secimz[0] > 2)
                {
                    SendErrorMessage("1-2 harici sayı girilemez.", 0);
                    cin >> secimz[1];
                    if (secimz[1] > 2)
                        islemİptali("1-2 harici sayı girilmez.");
                    ofstream dosya("veriler.txt");
                    dosya << secimz[1] << endl;
                    if (secimz[1] == 1)
                        flatbed2 = true;
                    ofstream dosya("veriler.txt");
                    dosya << "1" << endl;
                    dosya.close();
                    if (secimz[1] == 2)
                        flatbed2 = false;
                    ofstream dosya("veriler.txt");
                    dosya << "2" << endl;
                    dosya.close();
                }
            }
        }
        if (flatbed != 2)
        {
            ofstream dosya("veriler.txt");
            dosya << "1" << endl;
            dosya.close();
            flatbed2 = true;
        }
        if (flatbed != 1)
        {
            ofstream dosya("veriler.txt");
            dosya << "2" << endl;
            dosya.close();
            flatbed2 = false;
        }
        cout << "==================================================" << endl;
        cout << "================Tırcılık İşlemleri================" << endl;
        cout << "Dipnot: Hesaplamalar Kaçak Yük üzerinden hesaplanır, Kazancınız hesaplanırken tırcılıkta aldığınız en yüksek para ve en dusuk paranın ortalaması alınır ve kazanca değer girilir." << endl;
        cout << "Tırcılık kasabiliyormusunuz, (En az 10 levelmisiniz?)\n(Evet ise : 1, Hayır ise: 2)" << endl;
        cin >> tirkasiyo;
        if (tirkasiyo != 1)
        {
            if (tirkasiyo != 2) {
                int secimy[2];
                cin >> secimy[0];
                if (secimy[0] == 0)
                {
                    secimy[0] = 1;
                    ofstream dosya("veriler.txt");
                    dosya << "1" << endl;
                    dosya.close();
                    tirkasabiliyo = true;
                }
                if (secimy[0] > 5)
                {
                    SendClientMessage("1-2 değeri haricinde bir sayı yazmayınız.", 0);
                    cin >> secimy[1];
                    if (secimy[1] > 5)
                        islemİptali("1-2 değeri haricinde bir sayı yazmayınız.");
                    ofstream dosya("veriler.txt");
                    dosya << secimy[1] << endl;
                    dosya.close();
                    if (secimy[1] == 1)
                        tirkasabiliyo = true;
                    if (secimy[1] == 2)
                        tirkasabiliyo = false;
                }
            }
        }
        if (tirkasiyo == 1)
        {
            ofstream dosya("veriler.txt");
            dosya << "1" << endl;
            dosya.close();
            tirkasabiliyo = true;
        }
        if (tirkasiyo == 2)
        {
            ofstream dosya("veriler.txt");
            dosya << "2" << endl;
            dosya.close();
            tirkasabiliyo = false;
        }
        if (tirkasabiliyo == false) {
            kaydoldu = true;
            tumVerileriKaydet();
            system("cls");
            cout << "Lütfen seçim yapınız.\n(1 Saatlik kazanç için = 1, Kazançlı olan meslek = 2, KM Yakıt hesaplamak için = 3, Net Gelir Gider için = 4)" << endl;
            cin >> secim2;
            if (secim2 == 1)
            {
                bolumPara();
                saatlikKazanc();
            }
            if (secim2 == 2)
                kazanci();
            if (secim2 == 3)
            {
                seferHesapla();
                KMYakıt();
            }
            if (secim2 == 4)
            {
                GelirGider();
                FARKVAR();
            }
            if (secim2 != 1)
            {
                if (secim2 != 2)
                {
                    if (secim2 != 3)
                    {
                        if (secim2 != 4)
                        {
                            int secimxx[2];
                            cin >> secimxx[0];
                            if (secimxx[0] == 0) { secimxx[0] = 1; }
                            if (secimxx[0] > 5)
                            {
                                SendClientMessage("5 den büyük değer girilemez, tekrar giriniz.", 0);
                                cin >> secimxx[1];
                                if (secimxx[1] > 5)
                                    islemİptali("5 den büyük değer girilemez.");
                                if (secimxx[1] == 1)
                                {
                                    bolumPara();
                                    saatlikKazanc();
                                }
                                if (secimxx[1] == 2)
                                    kazanci();
                                if (secimxx[1] == 3)
                                {
                                    seferHesapla();
                                    KMYakıt();
                                }
                                if (secimxx[1] == 4)
                                {
                                    GelirGider();
                                    FARKVAR();
                                }
                            }
                        }
                    }
                }
            }
        }
        if (tirkasabiliyo == true)
        {
            cout << "Lütfen tırcılık levelinizi giriniz: " << endl;
            cin >> tLevel;
            if (tLevel == 0) {
                ofstream dosya("veriler.txt");
                dosya << "1" << endl;
                dosya.close();
                tLevel = 1;
            }
            if (tLevel > 5)
            {
                int secimxu[2];
                cin >> secimxu[0];
                if (secimxu[0] == 0) { secimxu[0] = 1; }
                if (secimxu[0] > 5)
                {
                    SendClientMessage("5 den büyük değer girilemez, tekrar giriniz.", 0);
                    cin >> secimxu[1];
                    if (secimxu[1] > 5)
                        islemİptali("5 den büyük değer girilemez.");
                    ofstream dosya("veriler.txt");
                    dosya << secimxu[1] << endl;
                    dosya.close();
                    tLevel = secimxu[1];
                }
            }
            cout << "Roadtrain varmı yokmu(Evet ise: 1, Hayır ise 2.)" << endl;
            cin >> roadtrain;
            if (roadtrain != 1)
            {
                if (roadtrain != 2)
                {
                    int secimxy[2];
                    cin >> secimxy[0];
                    if (secimxy[0] == 0)
                        secimxy[0] = 1;
                    if (secimxy[0] > 5)
                    {
                        SendClientMessage("1-2 harici değer girilemez, tekrar giriniz.", 0);
                        cin >> secimxy[1];
                        if (secimxy[1] > 5)
                            islemİptali("1-2 harici değer girilemez.");
                        ofstream dosya("veriler.txt");
                        dosya << secimxy[1] << endl;
                        dosya.close();
                        if (secimxy[1] == 1)
                            roadtrain2 = true;
                        if (secimxy[1] == 2)
                            roadtrain2 = false;
                    }
                }
            }
            if (roadtrain == 1)
            {
                ofstream dosya("veriler.txt");
                dosya << "1" << endl;
                roadtrain2 = true;
                dosya.close();
            }
            if (roadtrain == 2)
            {
                ofstream dosya("veriler.txt");
                dosya << "2" << endl;
                roadtrain2 = false;
                dosya.close();
            }
        }
        system("cls");
        kaydoldu = true;
        tumVerileriKaydet();
        cout << "==================================================" << endl;
        cout << "Lütfen seçim yapınız.\n(1 Saatlik kazanç için = 1, Kazançlı olan meslek = 2, KM Yakıt hesaplamak için = 3, Net Gelir Gider için = 4)" << endl;
        cin >> secim2;
        if (secim2 == 1)
        {
            bolumPara();
            saatlikKazanc();
        }
        if (secim2 == 2)
            kazanci();
        if (secim2 == 3)
        {
            seferHesapla();
            KMYakıt();
        }
        if (secim2 == 4)
        {
            GelirGider();
            FARKVAR();
        }
        if (secim2 != 1)
        {
            if (secim2 != 2)
            {
                if (secim2 != 3)
                {
                    if (secim2 != 4)
                    {
                        int secimxx[2];
                        cin >> secimxx[0];
                        if (secimxx[0] == 0) { secimxx[0] = 1; }
                        if (secimxx[0] > 5)
                        {
                            SendClientMessage("1-4 harici değer girilemez, tekrar giriniz.", 0);
                            cin >> secimxx[1];
                            if (secimxx[1] > 5)
                                islemİptali("1-4 harici değer girilemez.");
                            if (secimxx[0] == 1)
                            {
                                bolumPara();
                                saatlikKazanc();
                            }
                            if (secimxx[0] == 2)
                                kazanci();
                            if (secimxx[0] == 3)
                            {
                                seferHesapla();
                                KMYakıt();
                            }
                            if (secimxx[0] == 4)
                            {
                                GelirGider();
                                FARKVAR();
                            }
                        }
                    }
                }
            }
        }
    }
    else if (kaydoldu)
    {
        system("cls");
        tumVerileriKaydet();
        cout << "Lütfen seçim yapınız.\n(1 Saatlik kazanç için = 1, Kazançlı olan meslek = 2, KM Yakıt hesaplamak için = 3, Net Gelir Gider için = 4)" << endl;
        cin >> secim2;
        if (secim2 == 1)
        {
            bolumPara();
            saatlikKazanc();
        }
        if (secim2 == 2)
            kazanci();
        if (secim2 == 3)
        {
            seferHesapla();
            KMYakıt();
        }
        if (secim2 == 4)
        {
            GelirGider();
            FARKVAR();
        }
        if (secim2 != 1)
        {
            if (secim2 != 2)
            {
                if (secim2 != 3)
                {
                    if (secim2 != 4)
                    {
                        int secimxx[2];
                        cin >> secimxx[0];
                        if (secimxx[0] == 0) { secimxx[0] = 1; }
                        if (secimxx[0] > 5)
                        {
                            SendClientMessage("5 den büyük değer girilemez, tekrar giriniz.", 0);
                            cin >> secimxx[1];
                            tumVerileriKaydet();
                            if (secimxx[1] > 5)
                                islemİptali("5 den büyük değer girilemez.");
                            if (secimxx[1] == 1)
                            {
                                bolumPara();
                                saatlikKazanc();
                            }
                            if (secimxx[1] == 2)
                                kazanci();
                            if (secimxx[1] == 3)
                            {
                                seferHesapla();
                                KMYakıt();
                            }
                            if (secimxx[1] == 4)
                            {
                                GelirGider();
                                FARKVAR();
                            }
                        }
                    }
                }
            }
        }

    }
}
void giris()
{
    int x = 0;
    tumVerileriCek();
    cout << "Programa hoşgeldiniz, bot ve spam koruması yapılıyor, lütfen bekleyin." << endl;
    system("color 4");
    do {
        Sleep(1000);
        printf("%d - 5\n", x);
        x++;
    } while (x < 6);
    system("echo off");
    system("cls");
    cout << "Başarıyla korumadan geçtiniz, menüye yöneliyorsunuz." << endl;
    Sleep(500);
    yazi();
    Sleep(1000);
    system("cls");
    menu(); 
}
int main()
{
    turkceDil();    
    giris();
}
//==================================================\\
