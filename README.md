# 🏎 Elektromobil Araç Güvenlik Kontrol Sistemi (Start-Up Check)

Bir elektromobil aracın yarış öncesi güvenlik protokollerini simüle eden C programı.

## 📝 Açıklama

Elektromobil araç çalıştırılmadan önce bazı sensör verilerinin kontrol edilmesi gerekir.
Yarış kuralları gereği veriler güvenli aralıkta değilse motorun çalışmasına izin verilmez.
Bu program kullanıcıdan sensör verilerini alır, önce verilerin geçerli olup olmadığını,
ardından güvenlik koşullarını öncelik sırasına göre kontrol eder ve sonucu ekrana yazar.

### Girdiler

| Değişken            | Tip     | Açıklama                       |
|---------------------|---------|--------------------------------|
| `batarya_sicakligi` | `float` | Batarya sıcaklığı (°C)         |
| `sarj_yuzdesi`      | `int`   | Şarj yüzdesi (0 - 100)         |
| `kapi_durumu`       | `char`  | `A`: Açık, `K`: Kapalı         |
| `fren_pedali`       | `int`   | `1`: Basılı, `0`: Basılı Değil |

### Kontrol Sırası

1. **Sıcaklık** > 60°C → `KRİTİK HATA: Motor Aşırı Isındı! Sürüş Engellendi.`
2. **Şarj** < %10 → `UYARI: Batarya Kritik Seviyede! Sürüş Başlatılamaz.`
3. **Kapı** `A` → `HATA: Kapılar Açık! Lütfen Kapatınız.`
4. **Fren** `0` → `BİLGİ: Güvenlik için frene basarak tekrar deneyin.`
5. Hepsi uygunsa → `BAŞARILI: SİSTEM HAZIR. MOTOR BAŞLATILIYOR...`

### Hatalı Giriş Kontrolleri (Edge Cases)

- Sıcaklık -100°C'den küçük veya 200°C'den büyükse → mantıksız sıcaklık hatası
- Şarj %0'dan küçük veya %100'den büyükse → hatalı sensör verisi uyarısı
- Kapı durumu `A` / `K` dışında bir harfse → geçersiz karakter uyarısı (küçük harf de kabul edilir)
- Fren pedalı 0 veya 1 dışında bir değerse → uyarı
- Sayı beklenen yere harf girilirse → uyarı

Hatalı bir veri girildiği anda program uyarı verir ve sonraki soruları sormadan sonlanır.

## ⚙️ Kurulum ve Çalıştırma

GCC derleyicisi gereklidir.

```bash
# Derleme
gcc main.c -o check

# Çalıştırma (Linux / macOS)
./check

# Çalıştırma (Windows)
check.exe
```

## 🖥 Örnek Kullanım

**Başarılı başlatma**

```
--- ELEKTROMOBİL GÜVENLİK KONTROLÜ ---
Batarya Sıcaklığı (°C): 42.8
Şarj Yüzdesi (%): 85
Kapı Durumu (A/K): K
Fren Pedalı (1:Basılı, 0:Değil): 1

SONUÇ: BAŞARILI: SİSTEM HAZIR. MOTOR BAŞLATILIYOR...
```

**Kritik sıcaklık**

```
--- ELEKTROMOBİL GÜVENLİK KONTROLÜ ---
Batarya Sıcaklığı (°C): 65.0
Şarj Yüzdesi (%): 50
Kapı Durumu (A/K): K
Fren Pedalı (1:Basılı, 0:Değil): 1

SONUÇ: KRİTİK HATA: Motor Aşırı Isındı! Sürüş Engellendi.
```

**Hatalı giriş**

```
--- ELEKTROMOBİL GÜVENLİK KONTROLÜ ---
Batarya Sıcaklığı (°C): 25.0
Şarj Yüzdesi (%): 120

SONUÇ: HATA: İmkansız şarj seviyesi (%120). Hatalı sensör verisi, lütfen kontrol edin.
```