int i, j, k, x, y, z;//deklarasi variable integer
String keywordPertama = "";//deklarasi variable string
String keywordKedua = "";//deklarasi variable string
String plaintext = "";//deklarasi variable string

void setup() { //deklarasi method setup yang akan dijalankan sekali
  Serial.begin(115200); //deklarasi dan inisialisasi komunikasi serial dengan baudrate
  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Double Columnar Transposition\n_______"); //melakukan serial print
 
  //Fungsi dibawah ini untuk input keyword 1
  Serial.print("Masukkan Keyword 1 Untuk dimasukkan ke Matriks : ");//melakukan serial print
  while (true) {//seleksi kondisi saat value true
    if (Serial.available() > 0) {//saat terdeteksi serial input
      keywordPertama = Serial.readString();//melakukan pembacaan dan memasukkan ke variable
      keywordPertama.remove(keywordPertama.length() - 1);//menghapus karakter pada variable
      //Fungsi dibawah ini untuk mengubah huruf kecil ke huruf kapital
      for (int i = 0; i < keywordPertama.length(); i++) {//seleksi kondisi pada variable
        if (keywordPertama[i] >= 'a' && keywordPertama[i] <= 'z') {//seleksi kondisi untuk array pada variable
          keywordPertama[i] -= 32;//inisialisasi nilai variable 
        }
      }
      Serial.println(keywordPertama);//melakukan serial print
      break;//keluar dari seleksi kondisi
    }
  }

  //Fungsi dibawah ini untuk input plaintext
  Serial.print("Masukkan Plain Text Untuk dimasukkan ke Matriks : ");//melakukan serial print
  while (true) {//seleksi kondisi saat nilai true
    if (Serial.available() > 0) {//saat terdeteksi serial input
      plaintext = Serial.readString();//membaca dan menyimpan nilai ke variable
      plaintext.remove(plaintext.length() - 1);//melakukan penghapusan karakter pada variable
      //Fungsi dibawah ini untuk mengubah huruf kecil ke huruf kapital
      for (int i = 0; i < plaintext.length(); i++) {//looping sebanyak panjang karakter
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {//seleksi kondisi untuk karakter dalam array variable
          plaintext[i] -= 32;//melakukan inisialisasi nilai variable
        }
      }
      Serial.println(plaintext);//melakukan serial print
      break;//keluar dari seleksi kondisi
    }
  }

  //Fungsi dibawah ini untuk menyusun tabel dari keyword 1
  int x;//deklarasi variable integer
  int y = keywordPertama.length();//deklarasi variable integer
  if (plaintext.length() % keywordPertama.length() > 0) {//looping sebanyak karakter
    x = 1 + (plaintext.length() / keywordPertama.length());//inisialisasi nilai variable saat kondisi tercapai
  } else {//seleksi kondisi saat kondisi sebelum tak tercapai
    x = plaintext.length() / keywordPertama.length();//inisialisasi nilai variable saat kondisi tercapai
  }

  //Fungsi dibawah ini untuk insialisasi matriks Columnar
  char TABEL_COLUMNAR[x][y];//inisialisasi variable char array
  char SORTED_TABEL_COLUMNAR[x][y];//inisialisasi variable char array
  int k = 0; //inisialisasi variable integer
  for (int i = 0; i < x; i++) {//looping sebanyak x
    for (int j = 0; j < y; j++) {//looping sebanyak y
      if (k < plaintext.length()) {//seleksi kondisi dengan panjang karakter
        TABEL_COLUMNAR[i][j] = plaintext[k];//inisialisai value array
      } else {//seleksi kondisi saat tak terpenuhi
        TABEL_COLUMNAR[i][j] = 'x';//inisialisasi nilai variable array dengan char x
      }
      k++;//fungsi increment
    }
  }

  //Fungsi dibawah ini untuk pemrosesan sorted keyword
  char sorted_keywordPertama[keywordPertama.length()];//iniisialisasi variable array dengan value variable lain
  for (int i = 0; i < keywordPertama.length(); i++) {//seleksi kondisi dan looping sebanyak keyword karakter
    sorted_keywordPertama[i] = keywordPertama[i];//inisialisasi value array dengan variable lain
  }
  //Fungsi dibawah ini untuk pengurutan keyword (menggunakan bubble sort)
  for (int i = 0; i < keywordPertama.length() - 1; i++) {////seleksi kondisi dan looping sebanyak keyword karakter
    for (int j = 0; j < keywordPertama.length() - 1 - i; j++) {//seleksi kondisi dan looping sebanyak keyword karakter
      if (sorted_keywordPertama[j] > sorted_keywordPertama[j + 1]) {//seleksi kondisi dengan syarat array
        k = sorted_keywordPertama[j];//inisialisasi variable array
        sorted_keywordPertama[j] = sorted_keywordPertama[j + 1];//inisialisasi variable array
        sorted_keywordPertama[j + 1] = k;//inisialisasi variable array
      }
    }
  }

  //Fungsi dibawah ini untuk pemrosesan keyword_index
  int keyword_index1[keywordPertama.length()]; //inisialisasi index keyword 1
  for (int i = 0; i < keywordPertama.length(); i++) {//looping sebanyak karakter keyword pertama
    for (int j = 0; j < keywordPertama.length(); j++) {//looping sebanyak karakter keyword pertama
      if (sorted_keywordPertama[j] == keywordPertama[i]) {//seleksi kondisi dengan array
        keyword_index1[i] = j;//inisialisasi array
        break;//keluar dari seleksi kondisi
      }
    }
  }

  int keyword_sorting_index1[keywordPertama.length()]; // index sorting keyword 1
  //Fungsi dibawah ini untuk pemrosesan keyword_sorting_index
  for (i = 0; i < keywordPertama.length(); i++) {//looping sebanyak karakter keyword pertama
    for (j = 0; j < keywordPertama.length(); j++) {//looping sebanyak karakter keyword pertama
      if (sorted_keywordPertama[i] == keywordPertama[j]) {//seleksi kondisi dengan array
        keyword_sorting_index1[i] = j;//inisialisasi array
        break;//keluar dari seleksi kondisi
      }
    }
  }

  //Fungsi dibawah ini untuk Mencetak penomoran keyword 1
  Serial.print("Hasil Penomoran Keyword 1:\n\t");//melakukan serial print
  for (int i = 0; i < keywordPertama.length(); i++) {//loping sebanyak karakter keyword pertama
    Serial.print(keyword_index1[i] + 1);//melakukan serial print dengan variable array
    Serial.print(' ');//melakukan serial print
  }

  //Fungsi dibawah ini untuk  Mencetak keyword 1 asli
  Serial.print("\n\t");//melakukan serial print
  for (int i = 0; i < keywordPertama.length(); i++) {//looping sebanyak karakter
    Serial.print(keywordPertama[i]);//melakukan serial print dengan variable array
    Serial.print(' ');//melakukan serial print
  }

  //Fungsi dibawah ini untuk mencetak tabel / matriks columnar
  for (int i = 0; i < x; i++) {//looping sebanyak x
    Serial.print("\n\t");//melakukan serial print
    for (int j = 0; j < y; j++) {//looping sebanyak y
      Serial.print(TABEL_COLUMNAR[i][j]);//melakukan serial print dengan array
      Serial.print(' ');//melakukan serial print
    }
  }

  //Fungsi dibawah ini untuk Sorted Keyword (Keyword 1 yang sudah diurutkan pada awal tadi )
  Serial.print("\nHasil Keyword 1 yang diurut:\n\t");//melakukan serial print
  for (int i = 0; i < keywordPertama.length(); i++) {//looping sebanyak karakter 
    Serial.print(i + 1);//melakukan serial print dengan variable
    Serial.print(' ');//melakukan serial print
  }
  Serial.print("\n\t");//melakukan serial print
  for (int i = 0; i < keywordPertama.length(); i++) {//looping sebanyak karakter
    Serial.print(sorted_keywordPertama[i]);//melakukan serial print dengan array
    Serial.print(' ');//melakkukans serial print 
  }

  //Fungsi dibawah ini untuk memproses sorted key arr 1
  for (int i = 0; i < keywordPertama.length(); i++) {//melakukan looping sebanyak karakter
    for (int j = 0; j < keywordPertama.length(); j++) {//melakukan looping sebanyak karakter
      SORTED_TABEL_COLUMNAR[i][j] = TABEL_COLUMNAR[i][keyword_sorting_index1[j]];//inisialisasi vairable array
    }
  }

  //Fungsi dibawah ini untuk menampilkan sorted key arr 1
  for (int i = 0; i < x; i++) {//looping sebanyak x
    Serial.print("\n\t");//melakukan serial print
    for (int j = 0; j < y; j++) {//looping sebanyak y
      Serial.print(SORTED_TABEL_COLUMNAR[i][j]);//melakukan serial print dengan array
      Serial.print(' ');//melakukan serial print
    }
  }

  //Fungsi dibawah ini untuk Memproses ciphertext 1
  String ciphertext1 = "";//deklarasi variable string
  for (int i = 0; i < y; i++) {//looping sebanyak y
    for (int j = 0; j < x; j++) {//looping sebanyak x
      ciphertext1 += SORTED_TABEL_COLUMNAR[j][i];//inisialsiasi variable array
    }
  }

  //Fungsi dibawah ini untuk Mencetak Ciphertext 1
  Serial.print("\n\nHasil Ciphertext 1: ");//melakukan serial print
  for (int i = 0; i < ciphertext1.length(); i++) {//looping sebanyak karakter
    if (i > 0 && i % x == 0) {//seleksi kondisi saat nilai i dan x
      Serial.print(" ");//melakukan serial print
    }
    Serial.print(ciphertext1[i]);//melakukan serial print dengan array 
  }

  //Fungsi dibawah ini untuk inputkan keyword 2
  Serial.print("\nMasukkan keyword 2: ");//melakukan serial print
  while (true) {//seleksi kondisi saat bernilai true
    if (Serial.available() > 0) {//saat terdeteksi serial print
      keywordKedua = Serial.readString();//menyimpan input ke variable
      keywordKedua.remove(keywordKedua.length() - 1);//menghapus karakter 
      //Fungsi dibawah ini untuk mengubah huruf kecil ke huruf kapital
      for (int i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
        if (keywordKedua[i] >= 'a' && keywordKedua[i] <= 'z') {//seleksi kondisi pada karakter a sampai z
          keywordKedua[i] -= 32;//inisialisasi array dengan value
        }
      }
      Serial.println(keywordKedua);//melakukan serial print dengan variable
      break;//keluar dari seleksi kondisi
    }
  }

  //Fungsi dibawah ini untuk menyusun tabel dari keyword 2
  y = keywordKedua.length();//inisialisasi variable dengan variable lain
  if (ciphertext1.length() % keywordKedua.length() > 0) {//seleksi kondisi antar variable
    x = 1 + (ciphertext1.length() / keywordKedua.length());//inisialisasi variable dengan variable lain
  } else {//saat kondisi belum terpenuhi
    x = ciphertext1.length() / keywordKedua.length();//inisialisasi variable dengan variable lain
  }

  //Fungsi dibawah ini untuk insialisasi matriks Columnar 2
  char TABEL_COLUMNAR2[x][y];//deklarasi array
  char SORTED_TABEL_COLUMNAR2[x][y];//deklarasi array
  k = 0;//inisialisasi nilai variable
  for (int i = 0; i < x; i++) {//looping hingga nilai x
    for (int j = 0; j < y; j++) {//looping hingga nilai y
      if (k < ciphertext1.length()) {//seleksi kondisi saat panjang karakter 
        TABEL_COLUMNAR2[i][j] = ciphertext1[k];//inisiaslisasi value array
      } else {//saat kondisi belum terpenuhi
        TABEL_COLUMNAR2[i][j] = 'x';//inisialisasi array
      }
      k++;//fungsi increment
    }
  }

  //Fungsi dibawah ini untuk pemrosesan sorted keyword 2
  char sorted_keywordKedua[keywordKedua.length()];//deklarasi dan inisialisasi variable array
  for (int i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
    sorted_keywordKedua[i] = keywordKedua[i];//inisialisasi variable
  }
  //Fungsi dibawah ini untuk pengurutan keywordKedua (menggunakan bubble sort)
  for (int i = 0; i < keywordKedua.length() - 1; i++) {//looping sebanyak karakter
    for (int j = 0; j < keywordKedua.length() - 1 - i; j++) {//looping sebanyak karakter
      if (sorted_keywordKedua[j] > sorted_keywordKedua[j + 1]) {//seleksi kondisi dengan array
        k = sorted_keywordKedua[j];//inisialisasi variable array
        sorted_keywordKedua[j] = sorted_keywordKedua[j + 1];//inisialisasi variable array
        sorted_keywordKedua[j + 1] = k;//inisialisasi variable array
      }
    }
  }

  //Fungsi dibawah ini untuk pemrosesan keyword_index 2
  int keyword_index2[keywordKedua.length()]; //deklarasi dan inisialsiasi index keyword 2
  for (int i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
    for (int j = 0; j < keywordKedua.length(); j++) {//looping sebanyak karakter
      if (sorted_keywordKedua[j] == keywordKedua[i]) {//seleksi kondisi dengan array
        keyword_index2[i] = j;//inisialisasi variable array
        break;//keluar dari seleksi kondisi
      }
    }
  }

  int keyword_sorting_index2[keywordKedua.length()]; //Fungsi dibawah ini untuk index sorting keyword 2
  //Fungsi dibawah ini untuk pemrosesan keyword_sorting_index
  for (i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
    for (j = 0; j < keywordKedua.length(); j++) {//looping sebanyak karakter
      if (sorted_keywordKedua[i] == keywordKedua[j]) {//seleksi kondisi dengan array
        keyword_sorting_index2[i] = j;//inisialisasi nilai array
        break;//keluar dari variable array
      }
    }
  }

  //Fungsi dibawah ini untuk mencetak penomoran keyword 2
  Serial.print("Hasil Penomoran Keyword Ke 2 thd Matriks:\n\t");//melakukan serial print
  for (int i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
    Serial.print(keyword_index2[i] + 1);//melakukan serial print dengan array
    Serial.print(' ');//melakukan serial print
  }

  //Fungsi dibawah ini untuk mencetak keyword 2
  Serial.print("\n\t");//melakukan serial print
  for (int i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
    Serial.print(keywordKedua[i]);//melakukan serial print dengan array
    Serial.print(' ');//melakukan serial print
  }

  //Fungsi dibawah ini untuk mencetak tabel / matriks columnar 2
  for (int i = 0; i < x; i++) {//looping sebanyak x
    Serial.print("\n\t");//melakukan serial print
    for (int j = 0; j < y; j++) {//looping sebanyak y
      Serial.print(TABEL_COLUMNAR2[i][j]);//melakukan serial print dengan array
      Serial.print(' ');//melakukan serial print
    }
  }

  //Fungsi dibawah ini untuk sorting Keyword 2 (Keyword 2 yang sudah diurutkan)
  Serial.print("\nKeyword ke 2 yang diurut:\n\t");//melakukan serial print
  for (int i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
    Serial.print(i + 1);//melakukan serial print dengan varaible
    Serial.print(' ');//melakukan serial print 
  }
  Serial.print("\n\t");//melakukan serial print
  for (int i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
    Serial.print(sorted_keywordKedua[i]);//melakukan serial print dengan array
    Serial.print(' ');//melakukan serial print
  }

  //Fungsi dibawah ini untuk memproses sorted key arr 2
  for (int i = 0; i < keywordKedua.length(); i++) {//looping sebanyak karakter
    for (int j = 0; j < keywordKedua.length(); j++) {//looping sebanyak karakter
      SORTED_TABEL_COLUMNAR2[i][j] = TABEL_COLUMNAR2[i][keyword_sorting_index2[j]];//inisialisasi array
    }
  }

  //Fungsi dibawah ini untuk menampilkan sorted key arr 2
  for (int i = 0; i < x; i++) {//looping sebanyak x
    Serial.print("\n\t");//melakukan serial print
    for (int j = 0; j < y; j++) {//looping sebanyak y
      Serial.print(SORTED_TABEL_COLUMNAR2[i][j]);//melakukan serial print dengan array
      Serial.print(' ');//melakukan serial print
    }
  }

  //Fungsi dibawah ini untuk memproses ciphertext2
  String ciphertext2 = "";//deklarasi string
  for (int i = 0; i < y; i++) {//looping hingga y
    for (int j = 0; j < x; j++) {//looping hingga x
      ciphertext2 += SORTED_TABEL_COLUMNAR2[j][i];//inisialisasi variable
    }
  }

  //Fungsi dibawah ini untuk mencetak Ciphertext 2
  Serial.print("\nHasil Ciphertext 2: ");//melakukan serial print
  for (int i = 0; i < ciphertext2.length(); i++) {//looping sebanyak karakter
    if (i > 0 && i % x == 0) {//seleksi kondisi saat x dan i
      Serial.print(" ");//melakukan serial print
    }
    Serial.print(ciphertext2[i]);//melakukan serial print dengan array
  }

 Serial.println("\nProgram Selesai, silahkan reset Arduino jika ingin menggunakan lagi");//melakukan serial print
}

void loop() {//deklarasi method loop yang tidak digunakan
  
}
