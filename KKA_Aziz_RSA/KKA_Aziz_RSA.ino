//fungsi dibawah ini untuk melakukan pengecekan bilangan prima apa bukan
int checkPrime() {
  int p;
  delay(5000);
  while (true) {
    if (Serial.available() > 0) {
      p = Serial.parseInt();
      if (p <= 1) {
        Serial.println("\nBukan Bilangan Prima");
      } else {
        for (int i = 2; i < p; i++) {
          if (p % i == 0) {
            Serial.println("\nBukan Bilangan Prima");
          }
        }
      }
      break;
    }
  }
  return p;
}

//fungsi dibawah ini untuk melakukan operasi pencarian greatest common divisor
int gcd(int e, int Z) {
  int tmp;
  while (1) {
    tmp = e % Z;
    if (tmp == 0) {
      return Z;
    }
    e = Z;
    Z = tmp;
  }
}

//fungsi dibawah ini untuk melakukan operasi terhadap public key
int publicKey(int Z) {
  int e = 2;
  while (e < Z) {
    if (gcd(e, Z) == 1) {
      return e;
    } else {
      e++;
    }
  }
}

//fungsi dibawah ini untuk melakukan operasi terhadap private key
int privateKey(int e, int Z) {
  int d = 2;
  while (1) {
    if (((e * d) % Z) == 1) {
      return d;
    } else {
      d++;
    }
  }
}

//fungsi dibawah ini untuk melakukan operasi enkrip dan dekrip sesuai rumus modulo 
int encrypt(int m, int e, int n) {
  int c;
  long power = pow(m, e) + 1;
  c = power % n;
  return c;
}

//main method setup yang dijalanjkan sekali
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
    int p, q, n, Z, e, d, m, c;
  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Rivest Shamir Adleman\n_______"); //melakukan serial print
  
  //fungsi dibawah untuk melakukan pendefinisian nilai dan memanggil method diatas untuk melakukan operasi
  Serial.print("Definisikan Nilai (p) = ");
  p = checkPrime();
  Serial.println(p);
  Serial.print("Definisikan Nilai (q) = ");
  q = checkPrime();
  Serial.println(q);
  n = p * q;
  Z = (p - 1) * (q - 1);
  publicKey(Z);
  e = publicKey(Z);
  d = privateKey(e, Z);
  Serial.print("Definisikan Nilai Message Data (m) = ");
  delay(5000);
  while (true) {
    if (Serial.available() > 0) {
      m = Serial.parseInt();
      break;
    }
  }
  Serial.println(m);
  c = encrypt(m, e, n);
  Serial.println("_______");
  Serial.println("Hasil Sesuai Operasi Rumus C= m^e mod n");
  Serial.print("Hasil Proses Enkripsi = ");
  Serial.println(c);
  m = encrypt(c, d, n);
  Serial.println("\nHasil Sesuai Operasi Rumus m^1= c^d mod n");
  Serial.print("Hasil Proses Dekripsi = ");
  Serial.println(m);

}

void loop() {
  // put your main code here, to run repeatedly:

}
