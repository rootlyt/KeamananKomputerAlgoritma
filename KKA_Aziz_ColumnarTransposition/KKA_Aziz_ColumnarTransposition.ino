int i,j,k,x,y,z; //deklarasi variable integer
String keyword = ""; //deklarasi variable string
String plaintext = ""; //deklarasi variable string

void logiProses(){ //deklarasi method
  
  //Fungsi dibawah ini untuk menyusun tabel dari keyword
  int x; //deklarasi variable integer
  int y = keyword.length(); //deklarasi variable integer
  if(plaintext.length()%keyword.length()>0){ //seleksi kondisi dengan syarat panjang keyword
    x = 1+(plaintext.length()/keyword.length()); //deklarasi value variable
  } else { //seleksi kondisi saat kondisi sebelumnya tak terpebuhi
    x = plaintext.length()/keyword.length(); //deklarasi value variable
  }

  //Fungsi dibawah ini untuk insialisasi matriks Columnar
  char TABEL_COLUMNAR[x][y]; //deklarasi char array
  char SORTED_TABEL_COLUMNAR[x][y]; //deklarasi char array
  int k=0; //deklarasi integer
  for(int i=0; i<x; i++){ //looping sebanyak x
    for(int j=0; j<y; j++){ //loopinf sebanyak y
      if(k<plaintext.length()){ //seleksi kondisi pada panjang plaintext
        TABEL_COLUMNAR[i][j] = plaintext[k]; //seleksi pada nilai variable array
      } else { //saat kondisi lain tak terpenuhi
        TABEL_COLUMNAR[i][j] = 'x'; //deklarasi array
      }
      k++; //fungsi increment
    }
  }

  //Fungsi dibawah ini untuk pemrosesan sorted keyword
  char sorted_keyword[keyword.length()]; //deklarasi arary
  for(int i=0;i<keyword.length();i++){ //looping sebanyak karakter keyword
    sorted_keyword[i]=keyword[i];//inisialisasi nilai dengan value variable
  }
  //Fungsi dibawah ini untuk sorting keyword (menggunakan bubble sort)
  for(int i=0;i<keyword.length()-1;i++){ //looping dengan value
    for(int j=0;j<keyword.length()-1-i;j++){ //looping dengan value
      if(sorted_keyword[j]>sorted_keyword[j+1]){ //seleksi kondisi pada array
        k=sorted_keyword[j];//inisialisasi array
        sorted_keyword[j]=sorted_keyword[j+1]; //inisialisasi array
        sorted_keyword[j+1]=k; //inisialisasi array dan penambahan nilai
      }
    }
  }

  //Fungsi dibawah ini untuk pemrosesan keyword_index
  int keyword_index[keyword.length()]; // index keyword
  for(int i=0;i<keyword.length();i++){ //looping sebanyak karakter keyword
    for(int j=0;j<keyword.length();j++){ //looping sebanyak karakter keyword
      if(sorted_keyword[j]==keyword[i]){ //seleksi kondisi pada array
         keyword_index[i]=j; //inisialisasi array
         break;//keluar dari kondisi
      }
    }
  }

  int keyword_sorting_index[keyword.length()]; // deklarasi array integer untuk index key
  //Fungsi dibawah ini untuk pemrosesan keyword_sorting_index
  for(i=0;i<keyword.length();i++){ //looping sebanyak karakter keyword
    for(j=0;j<keyword.length();j++){ //looping sebanyak karakter keyword
      if(sorted_keyword[i]==keyword[j]){ //seleksi kondisi pada array
         keyword_sorting_index[i]=j; //inisialisasi array
         break; //keluar dari kondisi
      }
    }
  }

  //Fungsi dibawah ini untuk Mencetak penomoran keyword
  Serial.print("\nHasil Penomoran Keyword Terhadap Matriks:\n\t"); //melakukan serial print
  for(int i=0;i<keyword.length();i++){//looping sebanyak panjang keyword
    Serial.print(keyword_index[i]+1);//melakukan serial print dengan variable
    Serial.print(' ');//melakukan serial print
  }

  //Fungsi dibawah ini untuk Mencetak keyword asli
  Serial.print("\n\t");//melakukan serial print
  for(int i=0;i<keyword.length();i++){ //looping sebanyak karakter keyword
    Serial.print(keyword[i]);//melakukan serial print dengan variable
    Serial.print(' ');//melakukan serial print
  }
  
  //Fungsi dibawah ini untuk mencetak tabel / matriks columnar
  for(int i=0; i<x; i++){ //looping dengan kondisi sampai nilai x
    Serial.print("\n\t"); //melakukan serial print
    for(int j=0; j<y; j++){ //seleksi kondisi
      Serial.print(TABEL_COLUMNAR[i][j]); //melakukan serial print
      Serial.print(' '); //melakukan serial print
    }
  }


  //Fungsi dibawah ini untuk Sorted Keyword (Keyword yang sudah diurutkan)
  Serial.print("\n\nKeyword Yang Diurut:\n\t"); //melakukan serial print
  for(int i=0; i<keyword.length(); i++){//looping hingga panjang karakter keyword
    Serial.print(i+1);//melakukans serial print dengan variable dan penambahan nilai
    Serial.print(' '); //melakukan serial print
  }
  Serial.print("\n\t"); //melakukan serial print
  for(int i=0; i<keyword.length(); i++){ //looping hingga panjang karakter keyword
    Serial.print(sorted_keyword[i]); //melakukan serial print dengan variable 
    Serial.print(' ');//melakukan serial print
  }

  //Fungsi dibawah ini untuk memproses sorted key arr
  for(int i=0; i<keyword.length(); i++){ //looping sebanyak panjang karakter keyword
    for(int j=0; j<keyword.length(); j++){//looping sebanyak panjang karakter keyword
      SORTED_TABEL_COLUMNAR[i][j] = TABEL_COLUMNAR[i][keyword_sorting_index[j]];//inisialisasi array dengan variable lain
    }
  }

  
  //Fungsi dibawah ini untuk menampilkan sorted key arr
  for(int i=0; i<x; i++){ //seleksi kondisi dengan looping hingga nilai x
    Serial.print("\n\t");//melakukan serial print
    for(int j=0; j<y; j++){//looping hingga nilai y
      Serial.print(SORTED_TABEL_COLUMNAR[i][j]);//melakukan serial print dengan array
      Serial.print(' ');//melakukan serial print
    }
  }

  //Fungsi dibawah ini untuk Memproses ciphertext
  String ciphertext = ""; //deklarasi string
  for(int i=0; i<y; i++){//looping hingga nilai y
    for(int j=0; j<x; j++){ //looping hingga nilaix
      ciphertext += SORTED_TABEL_COLUMNAR[j][i]; //inisialisasi penambahan variable dengan array 
    }
  }

  //Fungsi dibawah ini untuk Mencetak Ciphertext
  Serial.println("\nHasil Ciphertext: "); //melakukan serial print
  for(int i=0; i<ciphertext.length(); i++){//looping sebanyak panjang karakter chipertext
    if(i>0 && i%x==0){ Serial.print(" "); }//seleksi kondisi dan melakukan serial print
    Serial.print(ciphertext[i]); //melakukans serial print dengan variable array
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //deklarasi dan inisialisasi komunikasi serial dengan baudrate
  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma Columnar Transposition\n_______"); //melakukan serial print
  //Fungsi dibawah ini untuk menginputkan keyword
  Serial.println("Masukkan Keyword Untuk dimasukkan ke Matriks : "); //melakukan serial print
  while(true){ //seleksi kondisi saat true
    if(Serial.available() > 0){ //saat terdeteksi serial input
      keyword = Serial.readString();//membaca input dan menyimpan pada variable
      keyword.remove(keyword.length() - 1);//menghapus karakter pada variable sebanyak 1
      //Fungsi dibawah ini untuk mengubah huruf kecil ke huruf kapital
      for (int i=0;i<keyword.length();i++){ if(keyword[i]>='a' && keyword[i]<='z'){ keyword[i]-=32;} } //seleksi kondisi dari karakter a sampai z
      Serial.println(keyword);//melakukan print variable
      break;//keluar dari seleksi kondisi
    }
  }

  //Fungsi dibawah ini untuk menginputkan plaintext
  Serial.println("Masukkan Plain Text Untuk dimasukkan ke Matriks : "); //melakukan serial print
  while(true){//seleksi kondisi saat true
    if(Serial.available() > 0){//saat terdeteksi serial input
      plaintext= Serial.readString();//membaca input dan menyimpan pada variable
      plaintext.remove(plaintext.length() - 1);//menghapus karakter pada variable sebanyak 1
      //Fungsi dibawah ini untuk mengubah huruf kecil ke huruf kapital
      for (int i=0;i<plaintext.length();i++){ if(plaintext[i]>='a' && plaintext[i]<='z'){ plaintext[i]-=32;} }//seleksi kondisi dari karakter a sampai z
      Serial.println(plaintext);//melakukan serial print dengan variable
      break;//keluar dari seleksi kondisi
    }
  }
  logiProses();//memanggil method logiProses
  Serial.println("\nProgram Selesai, silahkan reset Arduino jika ingin menggunakan lagi");//melakukan serial print
}

void loop() {//deklarasi method loop yang tidak dipakai
  // put your main code here, to run repeatedly:

}
