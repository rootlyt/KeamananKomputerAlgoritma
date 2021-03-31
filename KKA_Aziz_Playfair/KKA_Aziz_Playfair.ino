String alfabet = "ABCDEFGHIJKLMNOPRSTUVWXYZ";//deklarasi variable string
String keyword = "";//deklarasi variable string
String plaintext = "";//deklarasi variable string
String ciphertext = "";//deklarasi variable string

char TABEL_PLAYFAIR[5][5] =//deklarasi char array
{
  {'A', 'B', 'C', 'D', 'E'},//inisialisasi value array
  {'F', 'G', 'H', 'I', 'J'},//inisialisasi value array
  {'K', 'L', 'M', 'N', 'O'},//inisialisasi value array
  {'P', 'R', 'S', 'T', 'U'},//inisialisasi value array
  {'V', 'W', 'X', 'Y', 'Z'}//inisialisasi value array
}; //pada tabel huruf Q tak digunakan


void setup() {//deklarasi method setup untuk sekali dijalankan
  Serial.begin(115200);//deklarasi dan inisialisasi serial dengan baudrate
  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Playfair\n_______"); //melakukan serial print
  //fungsi dibawah untuk menginputkan keyword
  Serial.print("Masukkan Keyword Untuk dimasukkan ke Matriks : ");//melakukan serial print
  while (true) {//seleksi kondisi saat true
    if (Serial.available() > 0) {//jika terdeteksi serial input
      keyword = Serial.readString();//akan dibaca dan dimasukkan dalam variable
      keyword.remove(keyword.length() - 1);//menghapus satu karakter pada variable
      //fungsi dibawah untuk mengubah huruf kecil ke huruf kapital
      for (int i = 0; i < keyword.length(); i++) {//looping hingga panjang karakter
        if (keyword[i] >= 'a' && keyword[i] <= 'z') {//seleksi kondisi dalam array untuk karakter a sampai z
          keyword[i] -= 32;//inisialisasi value array
        }
      }
      Serial.println(keyword);//melakukan serial print dengan variable
      break;//keluar dari seleksi kondisi
    }
  }

  //fungsi dibawah untuk penyusunan matriks dari keyword dan alfabet
  for (int i = alfabet.length(); i >= 0; i--) {;//looping sepanjang alfabet
    for (int j = 0; j < keyword.length(); j++) {//looping sepanjang karakter
      if (alfabet[i] == keyword[j]) {//seleksi kondisi saat dua array sama
        alfabet.remove(i, 1);//menghapus karakter 
      }
    }
  }
  alfabet = keyword + alfabet;//inisialisasi variable dengan penambahan nilai antar variable
  for (int i = 0; i < 5; i++) {//looping sebanyak 5
    for (int j = 0; j < 5; j++) {//looping sebanyak 5
      TABEL_PLAYFAIR[i][j] = alfabet[0];//inisialisasi value array
      alfabet.remove(0, 1);//menghapus karakter
    }
  }

  //fungsi dibawah untuk Mencetak tabel
  Serial.println("\t[1]\t[2]\t[3]\t[4]\t[5]");//melakukan serial print
  for (int i = 0; i < 5; i++) {//looping sebanyak 5 kali
    Serial.print("[");//melakukan serial print
    Serial.print(i + 1);//melakukan serial print dengan variable
    Serial.print("]\t ");//melakukan serial print
    for (int j = 0; j < 5; j++) {//looping sebanyak 5 kali
      Serial.print(TABEL_PLAYFAIR[i][j]);//melakukan serial print dengan array
      Serial.print("\t ");//melakukan serial print
    }
    Serial.println();//melakukan serial print kosong untuk space
  }

  //fungsi dibawah untuk Menginputkan plaintext
  Serial.print("Masukkan Plain Text Untuk dimasukkan ke Matriks :  ");//melakukan serial print
  while (true) {//seleksi kondisi saat true
    if (Serial.available() > 0) {//jika terdeteksi serial input
      plaintext = Serial.readString();//maka akan dibaca dan disimpan pada variable
      plaintext.remove(plaintext.length() - 1);//menghapus karakter sebanyak satu dari variable
      //fungsi dibawah untuk mengubah huruf kecil ke huruf kapital
      for (int i = 0; i < plaintext.length(); i++) {//looping sebanyak karakter
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {//seleksi kondisi pada array untuk karakter a sampai z
          plaintext[i] -= 32;//inisialisasi array
        }
      }
      Serial.println(plaintext);//melakukan serial print
      break;//keluar dari seleksi kondisi
    }
  }

  //fungsi dibawah untuk apabila plaintext berjumlah ganjil maka diakhir ditambah huruf 'Z'
  if (plaintext.length() % 2 != 0) {//seleksi kondisi untuk variable plain text
    plaintext += 'Z';//inisialisasi variable dengan penambahan Z
  }

  Serial.print("Plaintext : ");//melakukan serial print
  for (int i = 0; i < plaintext.length(); i++) {//looping sebanyak karakter
    if (i > 0 && i % 2 == 0) {//seleksi kondisi 
      Serial.print(" ");//melakukan serial print
    }
    Serial.print(plaintext[i]);//melakukan serial print array
  }

  for (int i = 0; i < plaintext.length(); i += 2) {//looping sebanyak variable
    //fungsi dibawah untuk mendapatkan koordinat dari tiap pasangan
    char A = plaintext[i];//deklarasi dan inisialisasi variable dengan value array
    char B = plaintext[i + 1];//deklarasi dan inisialisasi variable dengan value array
    int Ax, Ay, Bx, By;//deklarasi variable intefer
    int swap;//deklarasi variable integer

    //fungsi dibawah untuk loop untuk mendapatkan koordinatnya
    for (int y = 0; y < 5; y++) {//looping sebanyak 5
      for (int x = 0; x < 5; x++) {//looping sebanyak 5
        if (TABEL_PLAYFAIR[y][x] == A) {//seleksi kondisi saat array sama dengan A
          Ax = x;//inisialisasi antar variable
          Ay = y;//inisialisasi antar variable
        }
        if (TABEL_PLAYFAIR[y][x] == B) {//seleksi kondisi saat array sama dengan b
          Bx = x;//inisialisasi antar variable
          By = y;//inisialisasi antar variable
        }
      }
    }

    //fungsi dibawah untuk aturan pertama, x & y tidak sama, maka x ditukar
    if (Ax != Bx && Ay != By) {//seleksi kondisidengan syarat
      swap = Ax;//inisialisasi antar variable
      Ax = Bx;//inisialisasi antar variable
      Bx = swap;//inisialisasi antar variable
    } else if (Ax == Bx && Ay != By) { //fungsi untuk aturan kedua x sama (vertikal), maka ambil dibawahnya
      Ay = (Ay + 1) % 5;//inisialisasi antar variable
      By = (By + 1) % 5;//inisialisasi antar variable
    } else if (Ax != Bx && Ay == By) { //fungsi untuk aturan ketiga y sama (horizontal), maka ambil disebelahnya
      Ax = (Ax + 1) % 5;//inisialisasi antar variable
      Bx = (Bx + 1) % 5;//inisialisasi antar variable
    }
    A = TABEL_PLAYFAIR[Ay][Ax];//inisialisasi antar variable
    B = TABEL_PLAYFAIR[By][Bx];//inisialisasi antar variable
    ciphertext += A;//inisialisasi antar variable
    ciphertext += B;//inisialisasi antar variable
  }

  Serial.print("\nHasil Ciphertext : ");//melakukan serial print
  for (int i = 0; i < ciphertext.length(); i++) {//looping sebanyak karakter
    if (i > 0 && i % 2 == 0) {//seleksi kondisi dengan syarat
      Serial.print(" ");//melakukan serial print
    }
    Serial.print(ciphertext[i]);//melakukan serial print dengan array
  }
}

void loop() {

}
