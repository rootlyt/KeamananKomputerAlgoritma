String plaintext, ciphertext;//deklarasi variable string
int no;//deklarasi variable integer
char polybiusSquare[5][5] = { //deklarasi array 5x5
  {'A', 'B', 'C', 'D', 'E'}, //inisialisasi pengisian array
  {'F', 'G', 'H', 'I', 'K'}, //inisialisasi pengisian array
  {'L', 'M', 'N', 'O', 'P'}, //inisialisasi pengisian array
  {'Q', 'R', 'S', 'T', 'U'}, //inisialisasi pengisian array
  {'V', 'W', 'X', 'Y', 'Z'} //inisialisasi pengisian array
};

String enkripsi(String plaintext) { //deklarasi dan inisialisasi variable enkripsi dengan value return plain text
  String ciphertext; //deklarasi variable string
  for (int i = 0; i < plaintext.length(); i++) { //loop sebanyak karakter plain text
    if (!isAlpha(plaintext[i])) { //seleksi kondisi dalam array plaintext
      ciphertext += plaintext[i]; //inisialisasi variable chipertext dengan array plaintext
    } else if (isAlpha(plaintext[i])) { //seleksi kondisi jika sebelumnya tidak terpenuhi
      for (int x = 0; x < 5; x++) { //looping sebanyak 5
        for (int y = 0; y < 5; y++) { //looping sebanyak 5
          if (plaintext[i] == 'J') { //seleksi kondisi saat terdapat J pada array
            plaintext[i]--; //decrement array
          }
          if (plaintext[i] == polybiusSquare[x][y]) { //inisialisasi array 
            ciphertext += char(x + '0' + 1); //inisialisasi variable dengan penambahan value
            ciphertext += char(y + '0' + 1); //inisialisasi variable dengan penambahan value
          }
        }
      }
    }
  }
  return ciphertext; //melakukan return value dengan variable ciphertext
  }

  String dekripsi(String ciphertext) { //deklarasi dan inisialisasi variable enkripsi dengan value return ciphertext
  String plaintext;//deklarasi variable string
  for (int i = 0; i < ciphertext.length(); i++) {//loop sebanyak karakter ciphertext
    if (!isDigit(ciphertext[i])) {//seleksi kondisi dalam array ciphertext
      plaintext += ciphertext[i]; //inisialisasi variable plaintext dengan array chipertext
    } else if (isDigit(ciphertext[i])) { //seleksi kondisi jika sebelumnya tidak terpenuhi
      for (int x = 1; x <= 5; x++) {//looping sebanyak 5
        for (int y = 1; y <= 5; y++) {//looping sebanyak 5
          if (ciphertext[i] == char(x + '0') && ciphertext[i + 1] == char(y + '0')) {//inisialisasi array 
            plaintext += polybiusSquare[x - 1][y - 1];//inisialisasi variable dengan penambahan value
          }
        }
      }
      i++; //fungsi increment
    }
  }
  return plaintext;//melakukan return value dengan variable plaintext
}

String checkText() { //deklarasi dan inisialisasi variable
  String text;//deklarasi variable string
  delay(8000); //melakukan delay selama 8000ms
  while (true) { //seleksi kondisi saat bernilai true
    if (Serial.available() > 0) { //jika terdeteksi serial input
      text = Serial.readString(); //melakukan pembacaan dan menyimpan pada variable text
      for (int i = 0; i < text.length(); i++) { //looping sebanyak karakter text
        if (text[i] >= 'a' && text[i] <= 'z') { //seleksi kondisi a dan z pada array
          text[i] -= 32; //inisialisasi array melakukan decrement sebanyak 32
        }
      }
      break;//keluar dari seleksi kondisi
    }
  }
  return text; //melakukan return dengan variable text
}
  
void setup() { //deklarasi method untuk dijalankan sekali
  // put your setup code here, to run once:
  Serial.begin(115200); //deklarasi serial baudrate

  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Polybius\nMasukkan Angka Menu\n_______");//melakukan serial print
  menu();//memanggil method menu
  Serial.println("Program Selesai, silahkan reset Arduino jika ingin menggunakan lagi");//melakukan serial print

}

void menu(){ //deklarasi method menu
    Serial.println("1 - Encrypt\n2 - Decrypt");//melakukan serial print
  while (true) { //seleksi kondisi saat bernilai benar
    if (Serial.available() > 0) { //jika terdeteksi input serial
      no = Serial.read();//melakukan pembacaan dan menyimpan pada variable text
      break;//keluar dari seleksi kondisi
    }
  }
  switch (no) { //saat switch case bernilai variable nomor
    case 49: //case satu 
      menuSatu();//memanggil method menu satu
      Serial.println("Auto Checker :");//melakukan serial print
      menuDua();///memanggil method menu dua
      break;//keluar dari case
    case 50: //case dua
      menuDua();//memanggil method menu dua
      Serial.println("Auto Checker :");//melakuakn serial print
      menuSatu();//memanggil menu satu 
      break;//keluar dari case
    default://case default
      Serial.println("Pilihan Salah\nMasukkan Kembali");//melakukan serial print
      menu();//memanggil method menu
  }

}

void menuSatu(){//deklarasi method menu satu
      Serial.println("_________________________");// melakukan serial print
      Serial.print("Plaintext: ");//melakukan serial print
      plaintext = checkText();//inisialisasi variable plain text bernilai check text
      Serial.println(plaintext);//melakukan printserial dengan variable plain text
      ciphertext = enkripsi(plaintext); //inisialisasi variable cipher text bernilai plain text
      Serial.print("Hasil Pengubahan ke Ciphertext: ");//melakukan serial print
      Serial.println(ciphertext);//melakkukan serial print dengan variable
}

void menuDua(){//deklarasi method menu dua
      Serial.println("_________________________");//melakukan serial print
      Serial.print("Ciphertext: ");//melakukan serial print
      ciphertext = checkText();//inisialisasi variable cipher text bernilai check text
      Serial.println(ciphertext);//melakukan serial print dengan variable
      plaintext = dekripsi(ciphertext);//inisialisasi variable plain text bernilai dekripsi dari ciphertext
      Serial.print("Hasil Pengubahan ke Plaintext: ");//melakukan serial print
      Serial.println(plaintext);//melakukan serial print dengan variable
}

void loop() {//method loop yang tidak digunakan
  // put your main code here, to run repeatedly:
  
}
