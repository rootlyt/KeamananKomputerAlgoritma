String plaintext, ciphertext, key, keyBaru;//deklarasi variable string
int plaintextLength, no; //deklarasi variable integer

char polybiusSquare[5][5] = { //deklarasi variable char array 5x5
  {'A', 'B', 'C', 'D', 'E'},//inisialisasi data array
  {'F', 'G', 'H', 'I', 'K'},//inisialisasi data array
  {'L', 'M', 'N', 'O', 'P'},//inisialisasi data array
  {'Q', 'R', 'S', 'T', 'U'},//inisialisasi data array
  {'V', 'W', 'X', 'Y', 'Z'}//inisialisasi data array
};

String enkripsi(String plaintext, String key) {//deklarasi dan inisialisasi variable dengan variable string lain
  String ciphertext;//deklarasi variable string
  for (int i = 0, j = 0; i < plaintextLength; i++, j++) {//looping sebanyak
    if (isAlpha(plaintext[i])) {//seleksi kondisi dengan kondisi pada array
      ciphertext += char((((plaintext[i] + key[j]) % 26) + 'A'));//inisialisasi variable array dedngan array lainnya
    } else {//seleksi kondisi jika tak terpenuhi
      j--;//decrement variable j
    }
  }
  return ciphertext;//melakukan return value ciphertext
}

String dekripsi(String ciphertext, String key) {//deklarasi dan inisialisasi variable string dekripsi dengan return value variable lainnya
  String plaintext;//deklarasi variable string
  for (int i = 0, j = 0; i < plaintextLength; i++, j++) { //looping sebanyak panjang karakter pada plaintext
    if (isAlpha(ciphertext[i])) { //seleksi kondisi pada variable array
      if (ciphertext[i] - key[j] < 0) { //seleksi kondisi dengan syarat dua variable array
        plaintext += char((((ciphertext[i] - key[j]) % 26) + '['));//inisialisasi variable plaintext ditambahkan dengan character pada array
      } else {//seleksi kondisi saat tak terpenuhi
        plaintext += char((((ciphertext[i] - key[j]) % 26) + 'A'));//inisialisasi variable plaintext ditambahkan dengan character pada array
      }
    } else {//seleksi kondisi saat tak terpenuhi juga sebelumnya
      j--;//melakukan decrement pada variable j
    }
  }
  return plaintext;//melakukan return dengan value plaintext
}

String checkText() { //deklarasi dan inisialisasi variable
  String text;//deklarasi variable string
  delay(10000); //melakukan delay selama 10000ms
  while (true) {//jika kondisi benar
    if (Serial.available() > 0) {//seleksi kondisi saat terdeteksi input pada serial
      text = Serial.readString();//melakukan pembacaan string yang masuk pada serial dan menyimpan di variable text
      text.remove(text.length() - 1);//menghapus satu karakter pada variable text
      for (int i = 0; i < text.length(); i++) { //looping sebanyak karakter variable text
        if (text[i] >= 'a' && text[i] <= 'z') { //seleksi kondisi pada array saat A dan Z ada
          text[i] -= 32;//inisialisasi nilai pada array
        }
      }
      break;//keluar dari seleksi kondisi
    }
  }
  return text;//melakukan return dengan value text
}

String checkKey(String key) {//deklarasi dan inisialisasi variable
  String text;//deklarasi variable string
  while (true) {//jika kondisi benar
    if (key.length() != plaintextLength) {//seleksi kondisi jika panjang dari variable key tidak sama plaintext
      for (int i = 0, j = 0; i < plaintextLength; i++, j++) { //looping sebanyak plaintext character
        if (j == key.length()) {//jika J sama dengan panjang key
          j = 0; //inisialisasi nilai j jadi 0
        }
        text += key[j];//inisialisasi variable text dengan menambah array j
      }
    } else {//seleksi kondisi saat tak terpenuhi kondisi
      text = key;// inisialisasi nilai variable sama dengan key
    }
    break;//keluar dari selekso kondisi
  }
  return text;//melakukan return dengan value text
}

void setup() {//deklarasi method yang akan dijalankan sekali
  // put your setup code here, to run once:
  Serial.begin(115200);//inisialisasi dan deklarasi pada serial dengan baudrate

  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Vigenere\nMasukkan Angka Menu\n_______");//melakukan serial print
  menu();//memanggil method menu
  Serial.println("Program Selesai, silahkan reset Arduino jika ingin menggunakan lagi");//melakukan serial print

}

void menu(){//deklarasi method menu
    Serial.println("1 - Encrypt\n2 - Decrypt");//melakukan serial print
  while (true) {//seleksi kondisi saat bernilai benar
    if (Serial.available() > 0) {//mendedteksi jika ada input pada serial input
      no = Serial.read();//akan membaca input dan menyimpan pada variable no
      break;//keluar dari seleksi kondisi
    }
  }
  switch (no) {//switch case dengan nilai variable no
    case 49://case satu
      Serial.println("_________________________");//melakukan serial print
      menuSatu();//memanggil method menu satu
      Serial.println("Auto Checker :");//melakukan serial print
      menuDua();//memanggil method menu dua
      break;// keluar dari case
    case 50://case dua
      Serial.println("_________________________");//melakukan serial print
      menuDua();//memanggil method menu dua
      Serial.println("Auto Checker :");//melakukan serial print
      menuSatu();//memanggil method menu satu
      break;//keluar dari switch case
    default://case untuk default jika tidak ada yang benar dipilih
      Serial.println("Pilihan Salah\nMasukkan Kembali");//melakukan serial print
      menu();//memanggil method menu
  }

}

void menuSatu(){// deklarasi method menu satu
      
      Serial.print("Plaintext: ");//melakukan serial print
      plaintext = checkText();//inisialisasi variable dengan value dari checkText
      plaintext.remove(0, 1);//menghilangkan 0, 1 pada array
      plaintextLength = plaintext.length();//inisialisasi nilai variable dengan nilai variable lain
      Serial.println(plaintext);//melakukan serial print
      Serial.print("Key: ");//melakukan serial print
      key = checkText();//inisialisasi nilai variable dengan nilai variable lain
      Serial.println(key);//melakukan serial print dengan variable lain
      Serial.print("Key Setelah Disesuaikan: ");//melakukan serial print
      keyBaru = checkKey(key);//inisialisasi nilai variable dengan nilai variable lain
      Serial.println(keyBaru);//melakukan serial print dengan variable 
      ciphertext = enkripsi(plaintext, keyBaru);//inisialisasi nilai variable dengan nilai variable lain
      Serial.print("Hasil ke Ciphertext: ");//melakukan serial print
      Serial.println(ciphertext);//melakukan serial print
      Serial.println("_________________________");//melakukan serial print
}

void menuDua(){//deklarasi method menu dua

      Serial.print("Ciphertext: ");//melakukan serial print
      ciphertext = checkText();//inisialisasi nilai variable dengan nilai variable lain
      ciphertext.remove(0, 1);//menghilangkan 0, 1 pada array
      plaintextLength = ciphertext.length();//inisialisasi nilai variable dengan nilai variable lain
      Serial.println(ciphertext);//melakukan serial print dengan variable
      Serial.print("Key: ");//melakukan serial print
      key = checkText();//inisialisasi nilai variable dengan nilai variable lain
      Serial.println(key);//melakukan serial print
      Serial.print("Key Setelah Disesuaikan: ");//melakukan serial print
      keyBaru = checkKey(key);//inisialisasi nilai variable dengan nilai variable lain
      Serial.println(keyBaru);//melakukan serial print
      plaintext = dekripsi(ciphertext, keyBaru);//inisialisasi nilai variable dengan nilai variable lain
      Serial.print("Hasil ke Plaintext: ");//melakukan serial print
      Serial.println(plaintext);//melakukan serial print dengan variable
      Serial.println("_________________________");//melakukan serial print
}

void loop() {//deklarasi method loop yang tidak digunakan
  // put your main code here, to run repeatedly:
  
}
