int i,j,k,x,y,z;//deklarasi integer

void setup() {//deklarasi method setup yang dijalankan sekali
  Serial.begin(115200);//deklarasi dan inisialisasi serial dengan baudrate

  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma MYSZKOWSKI\n_______"); //melakukan serial print
  String keyword = "";//deklarasi variable string
  String plaintext = "";//deklarasi variable string

  //fungsi dibawah untuk menginputkan keyword
  Serial.print("Masukkan Keyword Untuk dimasukkan ke Matriks : ");//melakukan serial print
  while(true){//seleksi kondisi saat true
    if(Serial.available() > 0){//saat mendeteksi serial input
      keyword = Serial.readString();//melakukan pembacaan dan menyimpan ke variable 
      keyword.remove(keyword.length() - 1);//menghapus karakter satu
      // mengubah huruf kecil ke huruf kapital
      for (int i=0;i<keyword.length();i++){ if(keyword[i]>='a' && keyword[i]<='z'){ keyword[i]-=32;} }//melakukan looping dan seleksi kondisi pada array
      Serial.println(keyword);//melakukan serial print
      break;//keluar dari seleksi kondisi
    }
  }

  //fungsi dibawah untuk menginputkan plaintext
  Serial.print("Masukkan Plain Text Untuk dimasukkan ke Matriks : ");//melakukan serial print
  while(true){//seleksi kondisi saat bernilai true
    if(Serial.available() > 0){//jika terdeteksi serial input
      plaintext= Serial.readString();//membaca serial input dan save ke variable
      plaintext.remove(plaintext.length() - 1);//menghapus satu karakter pada variable
      //fungsi dibawah untuk mengubah huruf kecil ke huruf kapital
      for (int i=0;i<plaintext.length();i++){ if(plaintext[i]>='a' && plaintext[i]<='z'){ plaintext[i]-=32;} }//melakukan looping dan seleksi kondisi pada array
      Serial.println(plaintext);//melakukan serial print dengan variable
      break;//keluar dari seleksi kondisi
    }
  }

  //fungsi dibawah untuk menyusun tabel dari keyword
  int x;//deklarasi integer
  int y = keyword.length();//deklarasi integer dan inisialisasi variable dengan nilai variable lain
  if(plaintext.length()%keyword.length()>0){//melakukan loop sebanyak karakter
    x = 1+(plaintext.length()/keyword.length());//inisialisasi variable array
  } else {//keluar dari seleksi kondisi
    x = plaintext.length()/keyword.length();//inisialisasi variable array
  }

  //fungsi dibawah untuk insialisasi matriks Myszkowski
  char TABEL_MYSZKOWSKI[x][y];//deklarasi array char
  char SORTED_TABEL_MYSZKOWSKI[x][y];//deklarasi array char
  int k=0;//deklarasi variable integer
  for(int i=0; i<x; i++){//looping sebanyak x
    for(int j=0; j<y; j++){//looping sebanyak y
      if(k<plaintext.length()){//seleksi kondisi dengan panjang karakter
        TABEL_MYSZKOWSKI[i][j] = plaintext[k];//inisialisasi array dengan variable array lain
      } else {//keluar dari seleksi kondisi
        TABEL_MYSZKOWSKI[i][j] = 'x';//inisialisasi nilai array
      }
      k++;//fungsi increment
    }
  }

  //fungsi dibawah untuk pemrosesan sorted keyword
  char sorted_keyword[keyword.length()];//deklarasi dan inisialisasi varaiable
  for(int i=0;i<keyword.length();i++){//looping sebanyak karakter
    sorted_keyword[i]=keyword[i];//inisialisasi array
  }
  //fungsi dibawah untuk pengurutan keyword (menggunakan bubble sort)
  for(int i=0;i<keyword.length()-1;i++){//looping sebanyak karakter
    for(int j=0;j<keyword.length()-1-i;j++){//looping sebanyak karakter
      if(sorted_keyword[j]>sorted_keyword[j+1]){//seleksi kondisi dengan array
        k = sorted_keyword[j];//inisialisasi variable dengan array 
        sorted_keyword[j] = sorted_keyword[j+1];//inisialisasi array
        sorted_keyword[j+1]=k;//inisialisasi array dengan variable
      }
    }
  }

  //fungsi dibawah untuk pemrosesan keyword_index
  int keyword_index[keyword.length()]; //deklarasi dan inisialisasi index keyword
  for(int i=0;i<keyword.length();i++){//looping sebanyak karakter
    for(int j=0;j<keyword.length();j++){//looping sebanyak karakter
      if(sorted_keyword[j]==keyword[i]){//seleksi kondisi saat array
         keyword_index[i]=j;//inisialisasi array dengan value variable
         break;//keluar dari seleksi kondisi
      }
    }
  }

  int keyword_sorting_index[keyword.length()]; //deklarasi dan inisialisasi index key
  //fungsi dibawah untuk pemrosesan keyword_sorting_index
  for(i=0;i<keyword.length();i++){//looping sebanyak karakter
    for(j=0;j<keyword.length();j++){//looping sebanyak karakter
      if(sorted_keyword[i]==keyword[j]){//inisialisasi variable array
         keyword_sorting_index[i]=j;//inisialisasi array dengan variable lain
         break;//keluar dari seleksi kondisi
      }
    }
  }

  //fungsi dibawah untuk Mencetak penomoran keyword
  Serial.print("\nHasil Penomoran Keyword Terhadap Matriks:\n\t");//melakukan serial print
  for(int i=0;i<keyword.length();i++){//looping sebanyak karakter
    Serial.print(keyword_index[i]+1);//melakukan serial print dengan array
    Serial.print(' ');//melakukan serial print
  }

  //fungsi dibawah untuk Mencetak keyword asli
  Serial.print("\n\t");//melakukan serial print
  for(int i=0;i<keyword.length();i++){//looping sebanyak karakter
    Serial.print(keyword[i]);//melakukan serial prtint dengan array
    Serial.print(' ');//melakukan serial print
  }
  
  //fungsi dibawah untuk mencetak tabel / matriks columnar
  for(int i=0; i<x; i++){//looping sebanyak x
    Serial.print("\n\t");//melakukan serial print
    for(int j=0; j<y; j++){//looping sebanyak y
      Serial.print(TABEL_MYSZKOWSKI[i][j]);//melakukan serial print dengan array
      Serial.print(' ');//melakukan serial print
    }
  }


  //fungsi dibawah untuk Sorted Keyword (Keyword yang sudah diurutkan)
  Serial.print("\n\nKeyword Yang Diurut:\n\t");//melakukan serial print
  for(int i=0; i<keyword.length(); i++){//looping sebanyak karakter
    Serial.print(i+1);//melakukan serial print dengan variable
    Serial.print(' ');//melakukan serial print
  }
  Serial.print("\n\t");//melakukan serial print
  for(int i=0; i<keyword.length(); i++){//looping sebanyak karakter
    Serial.print(sorted_keyword[i]);//melakukan serial print dengan array
    Serial.print(' ');//melakukan serial print
  }

  //fungsi dibawah untuk memproses sorted key arr
  for(int i=0; i<keyword.length(); i++){//looping sebanyak karakter
    for(int j=0; j<keyword.length(); j++){//looping sebanyak karakter
      SORTED_TABEL_MYSZKOWSKI[i][j] = TABEL_MYSZKOWSKI[i][keyword_sorting_index[j]];//inisialisasi variable array
    }
  }

  
  //fungsi dibawah untuk menampilkan sorted key arr
  for(int i=0; i<x; i++){//looping sebanyak x
    Serial.print("\n\t");//melakukan serial print
    for(int j=0; j<y; j++){//looping sebanyak y
      Serial.print(SORTED_TABEL_MYSZKOWSKI[i][j]);//melakukan serial print dengan array
      Serial.print(' ');//melakukan serial print
    }
  }

  //fungsi dibawah untuk Memproses ciphertext
  String ciphertext = "";//deklarasi variable string
  for(int i=0; i<y; i++){//looping sebanyak y
    for(int j=0; j<x; j++){?//looping sebanyak c
      ciphertext += SORTED_TABEL_MYSZKOWSKI[j][i];//inisialisasi variable array
    }
  }

  //fungsi dibawah untuk mencetak Ciphertext
  Serial.print("\n\nHasil Ciphertext: ");//melakukan serial print
  for(int i=0; i<ciphertext.length(); i++){//looping sebanyak karakter
    if(i>0 && i%x==0){ Serial.print(" "); }//melakukan serial print dan seleksi kondisi
    Serial.print(ciphertext[i]);//melakukan serial print dengan array
  }
   Serial.println("\nProgram Selesai, silahkan reset Arduino jika ingin menggunakan lagi");//melakukan serial print
}

void loop() {//deklarasi method loop yang tak digunakan 
}
