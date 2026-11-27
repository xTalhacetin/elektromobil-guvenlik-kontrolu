#include <stdio.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

void tampon_temizle(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);
#endif

    float batarya_sicakligi; 
    int   sarj_yuzdesi;     
    char  kapi_durumu;
    int   fren_pedali;

    printf("--- ELEKTROMOBİL GÜVENLİK KONTROLÜ ---\n");

    printf("Batarya Sıcaklığı (°C): ");
    if (scanf("%f", &batarya_sicakligi) != 1) {
        printf("\nSONUÇ: HATA: Sıcaklık sayı olarak girilmelidir.\n");
        return 1;
    }
    if (batarya_sicakligi < -100.0f || batarya_sicakligi > 200.0f) {
        printf("\nSONUÇ: HATA: Mantıksız sıcaklık değeri (%.1f°C). "
               "Lütfen sensör verilerini kontrol edin.\n", batarya_sicakligi);
        return 1;
    }

    printf("Şarj Yüzdesi (%%): ");
    if (scanf("%d", &sarj_yuzdesi) != 1) {
        printf("\nSONUÇ: HATA: Şarj yüzdesi tam sayı olarak girilmelidir.\n");
        return 1;
    }
    if (sarj_yuzdesi < 0 || sarj_yuzdesi > 100) {
        printf("\nSONUÇ: HATA: İmkansız şarj seviyesi (%%%d). "
               "Hatalı sensör verisi, lütfen kontrol edin.\n", sarj_yuzdesi);
        return 1;
    }

    printf("Kapı Durumu (A/K): ");
    if (scanf(" %c", &kapi_durumu) != 1) {
        printf("\nSONUÇ: HATA: Kapı durumu okunamadı.\n");
        return 1;
    }
    kapi_durumu = (char)toupper((unsigned char)kapi_durumu);
    if (kapi_durumu != 'A' && kapi_durumu != 'K') {
        printf("\nSONUÇ: HATA: Geçersiz kapı durumu ('%c'). "
               "Sadece 'A' (Açık) veya 'K' (Kapalı) giriniz.\n", kapi_durumu);
        return 1;
    }
    tampon_temizle();

    printf("Fren Pedalı (1:Basılı, 0:Değil): ");
    if (scanf("%d", &fren_pedali) != 1 || (fren_pedali != 0 && fren_pedali != 1)) {
        printf("\nSONUÇ: HATA: Fren pedalı için sadece 1 veya 0 giriniz.\n");
        return 1;
    }

    printf("\n");

   
    if (batarya_sicakligi > 60.0f) {
        printf("SONUÇ: KRİTİK HATA: Motor Aşırı Isındı! Sürüş Engellendi.\n");
    } else if (sarj_yuzdesi < 10) {
        printf("SONUÇ: UYARI: Batarya Kritik Seviyede! Sürüş Başlatılamaz.\n");
    } else if (kapi_durumu == 'A') {
        printf("SONUÇ: HATA: Kapılar Açık! Lütfen Kapatınız.\n");
    } else if (fren_pedali == 0) {
        printf("SONUÇ: BİLGİ: Güvenlik için frene basarak tekrar deneyin.\n");
    } else {
        printf("SONUÇ: BAŞARILI: SİSTEM HAZIR. MOTOR BAŞLATILIYOR...\n");
    }

    return 0;
}