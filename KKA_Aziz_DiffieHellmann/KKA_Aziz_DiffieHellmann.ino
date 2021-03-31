void menu(){ //deklarasi method menu
  int p, g; //deklarasi variable integer
  Serial.print("Definisikan Nilai p : "); //melakukan serial print
  p = checkPrime(); //inisisalisasi nilai variable dengan nilai variable method lain
  Serial.println(p); //melakukan serial print dengan value variable
  Serial.print("Definisikan Nilai g : "); //melakukan serial print
  g = checkPrime(); //inisisalisasi nilai variable dengan nilai variable method lain
  Serial.println(g); //melakukan serial print dengan value variable
  handshake(p, g); //memanggil method variable dengan value variable 
}

int checkPrime(){ //deklarasi variable bermethod
  int p; //deklarasi variable intger
  delay(5000); //melakukan delay 5000ms
  while(true){ //seleksi kondisi saat true
    if(Serial.available() > 0){ //saat terdeteksi input pada serial
      p = Serial.parseInt(); //melakukan input dengan nilai serial ke variable
      if(p <= 1){ //jika nilai tak memenuni syarat
        Serial.println("\nIni Bukan Bilangan Prima"); //melakukan serial print
      }else{ //saat kondisi lain tak terpenuhi
        for(int i = 2; i < p; i++){ //melakukan seleksi kondisi
          if(p % i == 0){ //jika nilai P tidak samadengan syarat
            Serial.println("\nIni Bukan Bilangan Prima"); //melakukan serial print
          }
        }
      }
      break; //keluar dari seleksi kondisi
    }
  }
  return p; //melakukan return dengan nilai variable p
}

int loadPrivateKey(){ //deklarasi method variable
  int x; //deklarasi variable integer
  delay(5000); //melakukan delay 5000ms
  while(true){ //kondisi saat true
    if(Serial.available() > 0){ //saat terdeteksi input serial
      x = Serial.parseInt(); //melakukan input dengan nilai variable serial ke variable x
      break; //keluar dari seleksi kondisi 
    }
  }
  return x; //melakukan return dengan variable x
}

int computeSharedKey(int p, int g, int x){ //deklarasi method variable
  int y; //deklarasi variable integer
  long power = pow(g, x) + 0.5; //melakukan inisialisasi penambahan nilai variable dengan value variable lain 
  y = power % p; //melakukan inisialisasi value variable dengan nilai variable lain
  return y; //melakukan return dengan nilai variable y
}

void handshake(int p, int g){ //deklarasi method dengan return nilai variable lain
  int a, b, gA, gB, y; //deklarasi variable integer
  Serial.print("Definisikan Nilai Xa = "); //melakukan serial print
  a = loadPrivateKey(); //inisialisasi variable dengan nilai variable method lain
  Serial.println(a); //melakukan serial print dengan value variable
  Serial.print("Definisikan Nilai Xb = "); //melakukan serial print
  b = loadPrivateKey(); //inisialisasi variable dengan nilai variable method lain
  Serial.println(b); //melakukan serial print dengan value variable lain
  Serial.print("Hasil Operasi Untuk Nilai Ya = "); //melakukan serial print
  gB = computeSharedKey(p, g, a); //melakukan inisialisasi value variable dengan variable lain
  Serial.println(gB); //melakukan serial print dengan variable
  Serial.print("Hasil Operasi Untuk Nilai Yb = "); //melakukan serial print
  gA = computeSharedKey(p, g, b); //inisialisasi value variable dengan variable lain
  Serial.println(gA); //melakukan serial print dengan variable
  Serial.print("Hasil Operasi Menghasilkan Shared Key = "); //melakukan serial print
  y = computeSharedKey(p, gA, a); //inisialisasi value variable dengan variable lain
  Serial.println(y); //melakukan serial print

}

void setup() { //deklarasi method yang akan dijalankan sekali
  // put your setup code here, to run once:
  Serial.begin(115200); //deklarasi dan inisialisasi komunikasi serial dengan baudrate
  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Diffie Hellmann Key Exchamge\n_______"); //melakukan serial print
  menu(); //memanggil method menu
  Serial.println("\nProgram Selesai, silahkan reset Arduino jika ingin menggunakan lagi");//melakukan serial print

}

void loop() { //deklarasi method loop yang tidak digunakan
  // put your main code here, to run repeatedly:
}
