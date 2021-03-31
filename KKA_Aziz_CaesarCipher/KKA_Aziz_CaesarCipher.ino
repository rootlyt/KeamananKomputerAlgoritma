String plaintext, ciphertext; //deklarasi variable 
int geser, no; //deklarasi variable

void setup() { //deklarasi method setup yang akan dijalankan sekali
  // put your setup code here, to run once:
  Serial.begin(115200); //inisialisasi serial dengan baudrate

  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Caesar Cipher\nMasukkan Angka Menu\n_______"); //melakukan serial print
  menu(); //memanggil method menu
  Serial.println("Program Selesai, silahkan reset Arduino jika ingin menggunakan lagi"); //melakukan serial print
 // delay(300);
}

void menu(){ //deklarasi method menu
    Serial.println("1 - Encrypt\n2 - Decrypt"); //melakukan serial print
  while (true) { //seleksi kondisi saat bernilai true
    if (Serial.available() > 0) { //melakukan pengecekan pada serial apa ada input
      no = Serial.read(); //inisialisasi variable nomor dengan nilai input
      break; //keluar dari seleksi kondisi
    }
  }
  switch (no) { //membaca variable no dengan seleksi kondisi
    case 49: //pada case 1 
      menuSatu(); //memanggil method menu satu
      Serial.println("Auto Checker :"); //melakukan serial print
      menuDua(); //memanggil method dua
      break; //keluar dari seleksi kondisi
    case 50: //pada case 2
      menuDua(); //memanggil method menu dua
      Serial.println("Auto Checker :"); //melakukan serial print
      menuSatu(); //memanggil method menu satu
      break; //keluar dari seleksi kondisi
    default: //default saat pilihan tidak ada
      Serial.println("Pilihan Salah\nMasukkan Kembali Angka Pada Menu");
      menu(); //kembali memanggil method menu
  }
}

void menuSatu(){ //deklarasi method menu satu
      Serial.println("_________________________"); //melakukan serial print
      Serial.print("Masukkan Plaintext Dalam 10 Detik Dan Tunggu: "); //melakukan serial print
      plaintext = checkText(); //inisialisasi variable dengan value variable lain
      Serial.println(plaintext); //melakukan serial print dengan value plaintext
      geser = checkShift(); //inisialisasi variable dengan value variable lain
      Serial.println(geser); //melakukan serial print dengan value geser
      ciphertext = EnkripDekrip(plaintext, geser); //inisiallisasi variable dengan value variable lain
      Serial.print("Hasil Penggeseran Ciphertext: "); //melakukan serial print
      Serial.println(ciphertext); //melakukan serial print dengan value ciphertext
}

void menuDua(){ //deklarasi method menu dua
      Serial.println("_________________________"); //melakukan serial print
      Serial.print("Masukkan Ciphertext Dalam 10 Detik Dan Tunggu: "); //melakukan serial print
      ciphertext = checkText(); //inisialisasi variable dengan value variable lain
      Serial.println(ciphertext); //melakukan serial print dengan value ciphertext
      geser = checkShift(); //inisialisasi variable dengan value variable lain
      Serial.println(geser); //melakukan serial print dengan value geser
      plaintext = EnkripDekrip(ciphertext, geser); //inisiallisasi variable dengan value variable lain
      Serial.print("Plaintext: "); //melakukan serial print
      Serial.println(plaintext); //melakukan serial print dengan value ciphertext
}

String EnkripDekrip(String plaintext, int geser) { //deklarasi variable string untuk array dengan value variable lain
  String ciphertext; //deklarasi string variable
  for (int i = 0; i < plaintext.length(); i++) { //looping sebanyak jumlah plaintext
    if (!isAlpha(plaintext[i])) { //seleksi kondisi 
      ciphertext += plaintext[i]; //inisialisasi variable dengan value variable lain
    } else if (isAlpha(plaintext[i])) { //seleksi kondisi jika seleksi pertama tak terpenuhi
      ciphertext += char(int(plaintext[i] + geser - 'A') % 26 + 'A'); //inisialisasi variable dengan value variable lain
    }
  }
  return ciphertext; //melakukan return dengan value ciphertext
}

String checkText() { //deklarasi variable string dengan value variable checkText
  String text; //deklarasi variable string text
  delay(10000); //melakukan delay 
  while (true) { //seleksi kondisi jika bernilai true
    if (Serial.available() > 0) { //seleksi kondisi saat menerima input serial
      text = Serial.readString(); //inisialisasi variable text dengan nilai input dari serial
      for (int i = 0; i < text.length(); i++) { //loop sebanyak text length
        if (text[i] >= 'a' && text[i] <= 'z') { //seleksi kondisi untuk mengubah alphabet menjadi kapital
          text[i] -= 32; //inisialisasi nilai array i menjadi dikurang 32
        }
      }
      break; //keluar dari seleksi kondisi
    }
  }
  return text; //melakukan return dengan value text
}

int checkShift() { //deklarasi variable integer dengan value variable checkShift
  int geser; //deklarasi variable integer
  Serial.print("Geser: "); //melakukan serial print
  
  while (true) { //seleksi kondisi saat bernilai true
    if (Serial.available() > 0) { //seleksi kondisi saat menerima input serial
      geser = Serial.parseInt(); //inisialisasi variable geser dengan nilai integerparse
      if (geser < 0) { //seleksi kondisi jika geser <0
        geser += 26; //menambahkan nilai 26
      } else { //seleksi kondisi saat sebelumnya tak terpenuhi
        geser = geser % 26; //inisialisasi variable
      }
      break; //keluar dari seleksi kondisi
    }
  }
  return geser; //melakukan return dengan value geser
}

void loop() { //deklarasi method loop yang tidak digunakan
  // put your main code here, to run repeatedly:
  
}
