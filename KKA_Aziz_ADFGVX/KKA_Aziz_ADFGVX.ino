int i,j,k,x,y,z;//deklarasi variable integer

char ADFGVX[6]={'A','D','F','G','V','X'};//deklarasi array char
char TABEL_ADFGVX[6][6]=//deklarasi array char
{
    {'8','P','3','D','1','N'},//inisialisasi value array
    {'L','T','4','O','A','H'},//inisialisasi value array
    {'7','K','B','C','5','Z'},//inisialisasi value array
    {'J','U','6','W','G','M'},//inisialisasi value array
    {'X','S','V','I','R','2'},//inisialisasi value array
    {'9','E','Y','0','F','Q'}//inisialisasi value array
};

void setup() {
  Serial.begin(115200);//deklarasi dan inisialisasi serial dengan baudrate
  Serial.println("175150307111020 M.Naufal Aziz\nAlgoritma ADFGVX\n_______"); //melakukan serial print
  Serial.println("\t[A]\t[D]\t[F]\t[G]\t[V]\t[X]");//melakukan serial print
  String plaintext = "";//deklarasi variable string
  String key = "";//deklarasi variable string
  String ciphertext = "";//deklarasi variable string
  
  //fungsi dibawah berguna untuk cetak tabel ADFGVX
  for(int i=0; i<6; i++){//looping sebanyak 6
    Serial.print("[");//melakukan serial print
    Serial.print(ADFGVX[i]);//melakukan serial print dengan array
    Serial.print("]\t ");//melakukan serial print
    for(int j=0; j<6; j++){//melakukan looping sebanyak 6
      Serial.print(TABEL_ADFGVX[i][j]);//melakukan serial print variable array
      Serial.print("\t ");//melakukan serial print
    }
    Serial.println();//melakukan serial print kosong untuk space
  }

  //fungsi dibawah berguna untuk menginputkan plaintext
  Serial.print("Masukkan Plain Text Untuk dimasukkan ke Matriks : ");//melakukan serial print
  while(true){//seleksi kondisi saat true
    if(Serial.available() > 0){//jika terdekteksi serial input
      plaintext = Serial.readString();//maka akan dibaca dan disimpan ke variable
      plaintext.remove(plaintext.length() - 1);//menghapus karakter sebanyak 1
      //fungsi dibawah berguna untuk mengubah plaintext huruf kecil ke huruf kapital
      for (int i=0;i<plaintext.length();i++){ if(plaintext[i]>='a' && plaintext[i]<='z'){ plaintext[i]-=32;} }//seleksi kondisi pada array untuk karakter a sampai z
      Serial.println(plaintext);//melakukan serial print
      break;//keluar dari seleksi kondisi
    }
  }

  //fungsi dibawah berguna untuk mendapatkan koordinat plaintext dari tabel ADFGVX
  char PLAINTEXT_ARR[plaintext.length()*2];//deklarasi dan inisialisasi array
  x=0;//inisialisasi variable
  for(k=0;k<plaintext.length();k++){//melakukan looping sebanyak karakter
    for(i=0;i<6;i++){//looping sebanyak 6 kali
      for(j=0;j<6;j++){//looping sebanuak 6 kali
        if(TABEL_ADFGVX[i][j]==plaintext[k]){//seleksi kondisi saat array dalam kondisi
           PLAINTEXT_ARR[x] = ADFGVX[i];//inisialisasi value array sama dengan value array lain
           PLAINTEXT_ARR[x+1] = ADFGVX[j];//inisialisasi value array sama dengan value array lain
           x=x+2;//inisialisasi penambahan pada variable
        }
      }
    }
  }

  //fungsi dibawah berguna untuk mencetak koordinat plaintext
  Serial.print("\nPlaintext:\t");//melakukan serial print
  for(i=0;i<plaintext.length();i++){//looping sebanyak karakter
    Serial.print("   ");//melakukan serial print
    Serial.print(plaintext[i]);//melakukan serial print dengan array
    Serial.print("   ");//melakukan serial print
  }
  Serial.print("\n\t\t");//melakukan serial print
  for(i=0;i<plaintext.length()*2;i=i+2){//looping sebanyak karakter
    Serial.print("[");//melakukan serial print
    Serial.print(PLAINTEXT_ARR[i]);//melakukan serial print dengan array
    Serial.print("][");//melakukan serial print
    Serial.print(PLAINTEXT_ARR[i+1]);//melakukan serial print dengan array
    Serial.print("] ");//melakukan serial print
  }

  //fungsi dibawah berguna untuk menginputkan key
  Serial.print("\n\nMasukkan Key: ");//melakukan serial print
  while(true){//seleksi kondisi saat true
    if(Serial.available() > 0){//mendteksi saat adanya input serial
      key = Serial.readString();//melakukan pembacaan dan menyimpan pada variable
      key.remove(key.length() - 1);//menghapus satu karakter pada variable
      //fungsi dibawah berguna untuk mengubah plaintext huruf kecil ke huruf kapital
      for (int i=0;i<key.length();i++){ if(key[i]>='a' && key[i]<='z'){ key[i]-=32;} }//seleksi kondisi pada array untuk karakter a sampai z
      Serial.println(key);//melakkukan serial print variable
      break;//keluar dari seleksi kondisi
    }
  }

  //fungsi dibawah berguna untuk menyusun matriks KEY
  int x;//deklarasi integer
  int y = key.length();//deklarasi integer dan inisialisasi dengan value variable lain
  if((plaintext.length()*2)%key.length()>0){ //seleksi kondisi saat variable dikali 2 karena ada koordinat x dan y
    x = 1+((plaintext.length()*2)/key.length());//melakukan inisialisasi antar variable
  } else {//jika kondisi tak terpenuhi
    x = plaintext.length()*2/key.length();//inisialisasi variable dengan nilai variable lain
  }

  //fungsi dibawah berguna untuk inisialisasi matriks key dgn panjang x*y
  char KEY_ARR[x][y];//deklarasi array char
  char SORTED_KEY_ARR[x][y];//deklarasi array char
  k=0;//inisialisasi nilai variable
  for(i=0;i<x;i++){//looping sebanyak x
    for(j=0;j<y;j++){//looping sebanyak y
      if(k<plaintext.length()*2){//seleksi kondisi dengan kondisi panjang karakter
        KEY_ARR[i][j] = PLAINTEXT_ARR[k];//inisialisasi value antar variable
      } else {//saat kondisi tak terpenuhi
        KEY_ARR[i][j] = 'x';//inisialisasi value array dengan x
      }
      k++;//melakukan increment
    }
  }

  //fungsi dibawah berguna untuk mencetak key
  Serial.print("\nKey:\t");//melakukan serial print
  for(i=0;i<key.length();i++){ //looping sebanyak karakter
    Serial.print(key[i]);//melakukan serial print dengan array
    Serial.print(' ');//melakukan serial print 
  }

  //fungsi dibawah berguna untuk pemrosesan sorted key
  char sorted_key[key.length()];//deklarasi dan inisialisasi variable dengan variable lain
  for(i=0;i<key.length();i++){//looping sebanyak karakter
    sorted_key[i]=key[i];//inisialisasi value antar variable
  }
  //fungsi dibawah berguna untuk pengurutan key (menggunakan bubble sort)
  for(i=0;i<key.length()-1;i++){//looping sampai panjang karakter -1
    for(j=0;j<key.length()-1-i;j++){//looping sampai panjang karakter -1
      if(sorted_key[j]>sorted_key[j+1]){//seleksi kondisi dengan kondisi array
        k=sorted_key[j];//inisialisasi variable dengan variable array
        sorted_key[j]=sorted_key[j+1];//melakukan inisialisasi antar variable
        sorted_key[j+1]=k;//inisialisasi variable dengan variable dengan variable array
      }
    }
  }

  //fungsi dibawah berguna untuk pemrosesan key_index
  int key_index[key.length()]; //deklarasi dan inisialisasi index key dengan array 
  
  for(i=0;i<key.length();i++){//looping sebanyak karakter
    for(j=0;j<key.length();j++){//looping sebanuak karakter
      if(sorted_key[j]==key[i]){//seleksi kondisi saat array sama
         key_index[i]=j;//inisialisasi array dengan value variable lain
         break;//keluar dari seleksi kondisi
      }
    }
  }

  int key_sorting_index[key.length()]; //deklarasi dan inisialisasi index key
  //fungsi dibawah berguna untuk pemrosesan key_sorting_index
  for(i=0;i<key.length();i++){//looping sebanyak karakter
    for(j=0;j<key.length();j++){//looping sebanyak karakter
      if(sorted_key[i]==key[j]){//seleksi kondisi dengan syarat array
         key_sorting_index[i]=j;//inisialisasi array dengan value variable lain
         break;//keluar dari seleksi kondisi
      }
    }
  }
  
  
  //fungsi dibawah berguna untuk Mencetak penomoran key
  Serial.print("\nHasil Penomoran Keyword Terhadap Matriks:\n\t");//melakukan serial print
  for(i=0;i<key.length();i++){//looping sebanyak karakter
    Serial.print(key_index[i]+1);//melakukan serial print dengan array
    Serial.print(' ');//melakukan serial print
  }
  
  //fungsi dibawah berguna untuk Mencetak key asli
  Serial.print("\n\t");//melakukan serial print
  for(i=0;i<key.length();i++){//looping sebanyak karakter
    Serial.print(key[i]);//melakukan serial print array
    Serial.print(' ');//melakukan serial print
  }

  //fungsi dibawah berguna untuk mencetak matriks KEY
  for(i=0;i<x;i++){//looping sebanyak x
    Serial.print("\n\t");//melakukan serial print
    for(j=0;j<key.length();j++){//looping sebanyak karakter
      Serial.print(KEY_ARR[i][j]);//melakukan serial print array
      Serial.print(' ');//melakukan serial print
    }
  }

  //fungsi dibawah berguna untuk Sorted Key (Key yang sudah diurutkan)
  Serial.print("\n\nKey Yang Diurut : \n\t");//melakukan serial print
  //fungsi dibawah berguna untuk menampilkan index key
  for(i=0; i<key.length(); i++){//looping sebanyak array
    Serial.print(i+1);//melakukan serial print variable 
    Serial.print(' ');//melakukan serial print 
  }
  //fungsi dibawah berguna untuk menampilkan sorted key
  Serial.print("\n\t");//melakukan serial print
  for(int i=0; i<key.length(); i++){//looping sebanyak karakter
    Serial.print(sorted_key[i])+1;//melakukan serial print dengan array
    Serial.print(' ');//melakukan serial print
  }

  //fungsi dibawah berguna untuk memproses sorted key arr
  for(int i=0; i<key.length(); i++){//looping sebanyak karakter
    for(int j=0; j<key.length(); j++){//looping sebanyak karakter
      SORTED_KEY_ARR[i][j] = KEY_ARR[i][key_sorting_index[j]];//inisialisasi antar variable
    }
  }

  
  //fungsi dibawah berguna untuk menampilkan sorted key arr
  for(int i=0; i<x; i++){//looping hingga x
    Serial.print("\n\t");//melakukan serial print
    for(int j=0; j<y; j++){//looping hingga y
      Serial.print(SORTED_KEY_ARR[i][j]);//melakukan serial print dengan array
      Serial.print(' ');//melakukan serial print
    }
  }
  
  //fungsi dibawah berguna untuk memproses ciphertext
  for(int i=0; i<y; i++){//looping sebanyak y
    for(int j=0; j<x; j++){//looping sebanyak x
      ciphertext += SORTED_KEY_ARR[j][i];//inisialisasi penambahan value variable dengan value array
    }
  }

  //fungsi dibawah berguna untuk mencetak ciphertext
  Serial.print("\n\nHasil Ciphertext: ");//melakukan serial print
  for(i=0;i<ciphertext.length();i++){//looping sebanyak karakter
    if(i>0 && i%x==0){ Serial.print(' '); }//seleksi kondisi dengan syarat
    Serial.print(ciphertext[i]);//melakukan serial print dengan array
  }
  
  Serial.println("\nProgram Selesai, silahkan reset Arduino jika ingin menggunakan lagi");//melakukan serial print

}

void loop() {//deklarasi method loop yang tidak digunakan
}
