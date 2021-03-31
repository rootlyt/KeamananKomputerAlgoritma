int i, j, k; //deklarasi variable
char TABEL_BIFID[5][5] = //deklarasi dan inisialisasi array
{
  {'A', 'B', 'C', 'D', 'E'}, //mengisi array
  {'F', 'G', 'H', 'I', 'J'}, //mengisi array
  {'K', 'L', 'M', 'N', 'O'}, //mengisi array
  {'P', 'Q', 'R', 'S', 'T'}, //mengisi array
  {'U', 'V', 'W', 'X', 'Y'} //mengisi array
};

void setup() { //deklarasi method setup yang akan dijalankan sekali
  // put your setup code here, to run once:
  Serial.begin(115200); //deklarasi untuk memulai serial dengan baudrate
  
  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma BIFID\n_______"); //melakukan serial print

  Serial.println("\t[1]\t[2]\t[3]\t[4]\t[5]"); //melakukan serial print
  String plaintext = ""; //deklarasi variable plaintext
  String ciphertext = ""; //deklarasi variable plaintext

  // fungsi dibawah untuk print tabel bifid
  for (int i = 0; i < 5; i++) { //looping hingga 5 kali dari 0
    Serial.print("["); //melakukan serial print
    Serial.print(i + 1); //melakukan serial print
    Serial.print("]\t "); //melakukan serial print
    for (int j = 0; j < 5; j++) { //looping lagi jika kondisi sebelumnya tak terpenuhi
      Serial.print(TABEL_BIFID[i][j]); //melakukan serial print array
      if (TABEL_BIFID[i][j] == 'Y') { //seleksi kondisi jika ada huruf Y
        Serial.print("/Z"); //melakukan serial print 
      }
      Serial.print("\t "); //melakukan serial print
    }
    Serial.println("|"); //melakukan serial print
  }

  //fungsi dibawah ini untuk input plaintext
  Serial.print("\nMasukkan Plaintext: "); //melakukan serial print
  while (true) { //seleksi kondisi saat nilai true
    if (Serial.available() > 0) { //seleksi kondisi jika serial menerima input
      plaintext = Serial.readString(); //melakukan input ke variable
      plaintext.remove(plaintext.length() - 1); //melakukan penghapusan sebanyak -1 karakter
      // fungsi dibawah ini untuk filter menjadi huruf kapital
      for (int i = 0; i < plaintext.length(); i++) { //looping 
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') { //seleksi kondisi jika pada huruf a hingga z
          plaintext[i] -= 32; //melakukan pengurangan array sebanyak 32
        }
      }
      Serial.println(plaintext); //melakukan serial print
      break; //keluar dari seleksi kondisi
    }
  }

  int PLAINTEXT_ARR[2][plaintext.length()]; //melakukan deklarasi dan inisialisasi array
  int PLAINTEXT_ARR2[plaintext.length() * 2]; //melakukan deklarasi dan inisialisasi array

  Serial.println("\nPlaintext:"); //melakukan serial print
  Serial.println("_____________"); //melakukan serial print
  for (k = 0; k < plaintext.length(); k++) { //looping saat plain text sepanjang k++
    Serial.print(plaintext[k]); //melakukan serial print
    Serial.print(" "); //melakukan serial print
    for (i = 0; i < 5; i++) { //looping yang diulang hingga 5 kali dari 0
      for (j = 0; j < 5; j++) { //looping dalam looping diulang 5 kali dari 0
        if (TABEL_BIFID[i][j] == plaintext[k]) { //seleksi kondisi untuk array
          PLAINTEXT_ARR[0][k] = i; //seleksi kondisi untuk array pada plain text
          PLAINTEXT_ARR[1][k] = j; //seleksi kondisi untuk array pada plain text
        }
      }
    }
  }


  //fungsi dibawah ini untuk mencetak angka kodrinat dari matriks array
  for (i = 0; i < 2; i++) { //looping sebanyak 2 kali dari 0
    Serial.print("\n"); //melakukan serial print
    for (j = 0; j < plaintext.length(); j++) { //melakukan looping sebanyak panjang plaintext
      Serial.print(PLAINTEXT_ARR[i][j] + 1); //melakukan serial print
      Serial.print(" "); //melakukan serial print
    }

  }
 
  //fungsi dibawah ini untuk mengubah array hasil tadi ke array satu dimensi
  k = 0; //deklarasi dan inisialisasi variable
  for (i = 0; i < 2; i++) { //melakukan looping hingga 2 kali dimulai dari 0
    for (j = 0; j < plaintext.length(); j++) { //melakukan looping sebanyak panjang plaintext
      PLAINTEXT_ARR2[k] = PLAINTEXT_ARR[i][j]; //inisialisasi array
      k++; //fungsi increment
    }
  }

  //fungsi dibawah ini untuk memroses cipher text
  for (j = 0; j < plaintext.length() * 2; j = j + 2, k++) { //looping sebanyak panjang plaintext
    int x = PLAINTEXT_ARR2[j]; //deklarasi dan inisialisasi variable dengan array
    int y = PLAINTEXT_ARR2[j + 1]; //deklarasi dan inisialisasi variable dengan array
    ciphertext += TABEL_BIFID[x][y]; //inisialisasi variable
  }

  //fungsi dibawah ini untuk mencetak ciphertext
  Serial.println("\n_____________"); //melakukan serial print
  Serial.println("\nCyphertext: "); //melakukan serial print
  Serial.println(ciphertext); //melakukan serial print dengan value variable
  Serial.println("Program Selesai, silahkan reset Arduino jika ingin menggunakan lagi"); //melakukan serial print
}

void loop() { //method loop yang tidak digunakan
  // put your main code here, to run repeatedly:
  
}
