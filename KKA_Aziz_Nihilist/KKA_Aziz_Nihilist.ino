String alfabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; //deklarasi variable string
String keyword = ""; //deklarasi variable string
String plaintext = ""; //deklarasi variable string
String key = ""; //deklarasi variable string
String key_baru = ""; //deklarasi variable string
String poly_plaintext = ""; //deklarasi variable string
String poly_key = ""; //deklarasi variable string
String ciphertext = ""; //deklarasi variable string

//fungsi dibawah ini untuk membuat tabel tanpa J
char TABEL_NIHILIST[5][5] = //deklarasi variable char array
{
  {'A', 'B', 'C', 'D', 'E'}, // inisialisasi variable array dengan value
  {'F', 'G', 'H', 'I', 'K'}, // inisialisasi variable array dengan value
  {'L', 'M', 'N', 'O', 'P'}, // inisialisasi variable array dengan value
  {'Q', 'R', 'S', 'T', 'U'}, // inisialisasi variable array dengan value
  {'V', 'W', 'X', 'Y', 'Z'} // inisialisasi variable array dengan value
};

void keyWord(){ //deklarasi method keyWord
  //fungsi dibawah ini untuk input keyword dan dimasukkan ke tabel baru
  Serial.print("Masukkan Keyword Untuk Tabel: "); //melakukan serial print
  while (true) { //seleksi kondisi saat bernilai true
    if (Serial.available() > 0) { //seleksi saat terdapat input serial
      keyword = Serial.readString(); //inisialisasi variable untuk mengambil nilai dari serial input
      keyword.remove(keyword.length() - 1); //inisialisasi untuk menghapus satu panjang karakter
      //fungsi dibawah ini untuk mengubah huruf kecil ke huruf kapital
      for (int i = 0; i < keyword.length(); i++) { //looping sepanjang length pada keyword
        if (keyword[i] >= 'a' && keyword[i] <= 'z') { //seleksi untuk a sampai z pada array 
          keyword[i] -= 32; //inisialisasi nilai pada keyword dikurang 32
        }
      }
      Serial.println(keyword); //melakukan serial print
      break; //keluar dari kondisi
    }
  }
}

void tabelBaru(){ //deklarasi method 
    //fungsi dibawah ini untuk membuat tabel baru
  for (int i = alfabet.length(); i >= 0; i--) { //looping hingga sepanjang variable alfabet
    for (int j = 0; j < keyword.length(); j++) { //looping 
      if (alfabet[i] == keyword[j]) { //seleksi jika array sama
        alfabet.remove(i, 1); //inisialisasi untuk menghapus karakter sebanyak 1
      }
    }
  }
  alfabet = keyword + alfabet; //inisialisasi variable alfabet dengan menambah value variable keyword
  for (int i = 0; i < 5; i++) { //looping sebanyak 5 dari 0
    for (int j = 0; j < 5; j++) { //looping sebanyak 5 dari 0
      TABEL_NIHILIST[i][j] = alfabet[0]; //inisialisasi array dengan array alfabet
      alfabet.remove(0, 1); //inisialisasi untuk menghapus karakter dari array alfabet di (0, 1)
    }
  }
}

void printTabelb(){ //deklarasi method printTabelb
    //fungsi di bawah ini untuk mencetak tabel
  Serial.println("\t[1]\t[2]\t[3]\t[4]\t[5]"); //melakukan serial print
  for (int i = 0; i < 5; i++) { //looping sebanyak 5 dari 0
    Serial.print("["); //melakukan serial print
    Serial.print(i + 1); //melakukan serial print dan menambah variable array
    Serial.print("]\t "); //melakukan serial print
    for (int j = 0; j < 5; j++) { //looping sebanyak 5 dari 0
      Serial.print(TABEL_NIHILIST[i][j]); //melakukan serial print
      Serial.print("\t "); //melakukan serial print
    }
    Serial.println(); //melakukan serial print kosong
  }
}

void plainText(){ //deklarasi method plainText
    //fungsi dibawah ini untuk input plaintext
  Serial.print("Masukkan Plaintext: "); //melakukan serial print
  while (true) { //seleksi kondisi saat true
    if (Serial.available() > 0) { //kondisi saat terdapat serial input
      plaintext = Serial.readString(); //akan membaca nilai serial input dan memasukkan ke variable plaintext
      plaintext.remove(plaintext.length() - 1); //inisialisasi variable untuk menghapus 1 karakter panjang variable 
      //fungsi dibawah ini untuk mengubah huruf kecil ke huruf kapital
      for (int i = 0; i < plaintext.length(); i++) { //looping sebanyak length variable
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') { //seleksi untuk value array alphabet a sampai z
          plaintext[i] -= 32;//inisialisasi mengurangi nilai dari variable array
        }
      }
      Serial.println(plaintext); //melakukan serial print dengan value plaintext
      break; //keluar dari seleksi kondisi
    }
  }
}

void kei(){ //deklarasi method
    //fungsi dibawah ini untuk melakukan input key
  Serial.print("Masukkan Key Untuk Diulang: "); //melakukan serial print
  while (true) { //seleksi kondisi saat benar
    if (Serial.available() > 0) { //kondisi saat terdapat input serial
      key = Serial.readString(); //inisialisasi variable key dengan value dari serial
      key.remove(key.length() - 1); //inisialisasi menghapus satu karakter 
      //fungsi dibawah ini untuk mengubah huruf kecil ke huruf kapital
      for (int i = 0; i < key.length(); i++) { //melakukan looping sebanyak panjang key
        if (key[i] >= 'a' && key[i] <= 'z') { //seleksi untuk value array alphabet a sampai z
          key[i] -= 32; //inisialisasi mengurangi nilai dari variable array
        }
      }
      Serial.println(key); //melakukan serial print
      break; //keluar dari seleksi kondisi
    }
  }
}

void cekKey(){ //deklarasi method
    //fungsi dibawah ini untuk melakukan pengecekan key
  if (key.length() != plaintext.length()) { //seleksi kondisi saat key panjangnya tak sama dengan plaintext
    for (int i = 0, j = 0; i < plaintext.length(); i++, j++) { //dilakukan looping sebanyak panjang dari plaintext
      if (j == key.length()) { //seleksi kondisi jika looping telah terpenuhi
        j = 0; //inisialisasi nilai j 0
      }
      key_baru += key[j]; //inisialisasi variable dengan menambahkan nilai array variable lain
    }
  } else { //seleksi kondisi saat semua tak terpenuhi
    key_baru = key; //inisialisasi variable dengan menambahkan nilai array variable lain
  }
}

void korTex(){ //deklarasi method
    //fungsi dibawah ini untuk mencetak koordinat plaintext dari tabel nihilist
  for (int k = 0; k < plaintext.length(); k++) { //looping sebanyak panjang plaintext
    for (int i = 0; i < 5; i++) { //looping sebanyak 5 dari 0
      for (int j = 0; j < 5; j++) {//looping sebanyak 5 dari 0
        if (plaintext[k] == 'J') { //seleksi kondisi jika pada array terdapat karakter J
          plaintext[k]--; //dilakukan penghapusan
        }
        if (TABEL_NIHILIST[i][j] == plaintext[k]) { //seleksi kondisi saat variable array sama
          poly_plaintext += char(i + '0' + 1); //inisialisasi nilai variable ditambah dengan variable lain
          poly_plaintext += char(j + '0' + 1); //inisialisasi nilai variable ditambah dengan variable lain
        }
      }
    }
  }
}

void korKey(){
    // mendapatkan koordinat key dari tabel nihilist
  for (int k = 0; k < key_baru.length(); k++) { //looping sebanyak panjang karakter key_baru
    for (int i = 0; i < 5; i++) { //looping sebanyak 5 dari 0
      for (int j = 0; j < 5; j++) { //looping sebanyak 5 dari 0
        if (key_baru[k] == 'J') { //kondisi saat value dari array = J
          key_baru[k]--; //menghapus satu karakter dari array
        }
        if (TABEL_NIHILIST[i][j] == key_baru[k]) { //seleksi saat kondisi 
          poly_key += char(i + '0' + 1); //inisialisasi variable dengan penambahan value
          poly_key += char(j + '0' + 1); //inisialisasi variable dengan penambahan value
        }
      }
    }
  }
}

void tambahTabl(){ //deklarasi method tambahTabl
    //fungsi dibawah ini untuk penjumlahan hasil tabel
  int nilai_cipher[plaintext.length()]; //deklarasi integer dengan array sebanyak jumlah karakter plaintext
  for (int i = 0; i < plaintext.length() * 2; i += 2) { //looping sebanyak jumlah karakter plaintext
    nilai_cipher[i / 2] = (((poly_plaintext[i] - '0') * 10) + (poly_plaintext[i + 1] - '0')) + (((poly_key[i] - '0') * 10) + (poly_key[i + 1] - '0')); //inisialisasi array dengan value variable
  }
  Serial.print("\nPlaintext:\t"); //melakukan serial print
  for (int i = 0; i < plaintext.length(); i++) { //looping sebanyak jumlah karakter plaintext
    if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') { //seleksi kondisi untuk alphabet a sampai z pada array 
      Serial.print(plaintext[i]); //melakukan serial print
      Serial.print("\t"); //melakukan serial print
    }
  }
  Serial.print("\n\t\t"); //melakukan serial print
  for (int i = 0; i < plaintext.length() * 2; i += 2) { //looping sebanyak jumlah karakter plaintext
    Serial.print(poly_plaintext[i]); //melakukan serial print dengan nilai variable array
    Serial.print(poly_plaintext[i + 1]);// melakukan serial print dengan variable array yang ditambah value nya satu
    Serial.print("\t");//melakukan serial print

  Serial.print("\n\nKey:\t\t"); //melakukan serial print
  for (int i = 0; i < key_baru.length(); i++) { //looping sebanyak jumlah karakter key baru
    if (key_baru[i] >= 'A' && key_baru[i] <= 'Z') { //seleksi kondisi untuk alphabet A sampai Z pada array
      Serial.print(key_baru[i]);//melakukan serial print dengan variable array
      Serial.print("\t");//melakukan serial print
    }
  }
  Serial.print("\n\t\t"); //melakukan serial print
  for (int i = 0; i < key_baru.length() * 2; i += 2) { ////looping sebanyak jumlah karakter key baru
    Serial.print(poly_key[i]); //melakukan serial print dengan variable array
    Serial.print(poly_key[i + 1]);//melakukan serial print dengan variable array
    Serial.print("\t"); //melakukan serial print
  }

  Serial.print("\n\nCiphertext:\t"); //melakukan serial print
  for (int i = 0; i < plaintext.length(); i++) { //looping sebanyak panjang karakter plaintext
    Serial.print(nilai_cipher[i]);//melakukan serial print dengan variable array
    Serial.print("\t");//melakukan serial print
  }
}


void setup() { //deklarasi method setup untuk dijalankan sekali
  // put your setup code here, to run once:
  Serial.begin(115200);// inisialisasi serial dengan baudrate
  
  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Nihilist\n_______"); //melakukan serial print
keyWord(); //memanggil method
tabelBaru();//memanggil method
printTabelb();//memanggil method
plainText();//memanggil method
kei();//memanggil method
cekKey();//memanggil method
korTex();//memanggil method
korKey();//memanggil method
tambahTabl();//memanggil method
  Serial.println("\nProgram Selesai, silahkan reset Arduino jika ingin menggunakan lagi");//melakukan serial print
}
