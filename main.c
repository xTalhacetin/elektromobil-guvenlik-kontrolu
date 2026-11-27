#include <stdio.h>

int main(void)
{
   
    float batarya_sicakligi; 
    int   sarj_yuzdesi;
    char  kapi_durumu;
    int   fren_pedali;

    printf("--- ELEKTROMOBİL GÜVENLİK KONTROLÜ ---\n");

    printf("Batarya Sıcaklığı (°C): ");
    scanf("%f", &batarya_sicakligi);

    printf("Şarj Yüzdesi (%%): ");
    scanf("%d", &sarj_yuzdesi);

    printf("Kapı Durumu (A/K): ");
    scanf("%c", &kapi_durumu);

    printf("Fren Pedalı (1:Basılı, 0:Değil): ");
    scanf("%d", &fren_pedali);


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