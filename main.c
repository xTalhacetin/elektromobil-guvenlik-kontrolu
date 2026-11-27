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

    return 0;
}