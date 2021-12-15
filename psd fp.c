#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


time_t rawtime;
struct tm * timeinfo;

struct distribute
{
    char namabarang[100], tujuan[100], kodebarang[50];
    int no, jumlahbarang, hargabarang;
    struct distribute *prev;
    struct distribute *next;
};

struct distribute *head = NULL;

 
void TambahPesanan(int, char [], int, int, char[], char[]);
void LihatPesanan();
void KirimPesanan(int, char [], int , int , char [], char[]);
void displaymenu();
void main();


void main()
{
 system("cls");
    char namabarang[100], tujuan[100], kodebarang[50];
    int no, n, jumlahbarang, hargabarang, pilih;
     do
    {
    menu:
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    system("cls");
    system("color 0F");
    printf ("===============================  PROGRAM DISTIRBUSI  FROZEN FOOD   ===========================\n");
    printf ("================================  DARI PABRIK PT. ANUGRAH FROZEN  =============================\n");
    printf ("MENU :\n");
  			
    printf ("1. Daftar produk\n");
    printf ("2. Input Data Pendistribusian\n");
    printf ("3. Tampilkan Data Pendistribusian\n");
    printf ("4. Kirim Frozen Food\n");
    printf ("5. Keluar Program\n");
    printf ("\nMasukkan pilihan anda : ");
        scanf("%d", &pilih);
        switch(pilih)
        {
        case 1:
        	displaymenu();
		main();
	case 2:
	system ("cls");
    printf ("------------------------------------------------------------------------------------------------------\n");
    printf ("========================================     INPUT PESANAN     =======================================\n");
    printf ("------------------------------------------------------------------------------------------------------\n\n");
   
    printf ("1. Nomor Pesanan      : ");
    scanf  ("%d" , &no);
    fflush(stdin);
    printf ("2. Nama Frozen Food   : ");
   fflush(stdin);
   gets(namabarang);
   printf ("3. Jumlah Frozen Food : ");
   scanf  ("%d" , &jumlahbarang);
   printf ("4. Harga Frozen Food  : ");
   fflush(stdin);
   scanf  ("%d" , &hargabarang);
   fflush(stdin);
   printf ("5. Tujuan Distibusi   : ");
   fflush(stdin);
   gets(tujuan);
   printf ("6. Kode Frozen Food   : ");
   fflush(stdin);
   gets(kodebarang);
    fflush(stdin);  
   TambahPesanan(no, namabarang, jumlahbarang, hargabarang, tujuan, kodebarang);
            printf ("\n************  Tekan enter untuk melanjutkan  *************\n");
            getch();
     break;
        case 3 :
            if(head == NULL)
   {
    printf ("\n");
    printf ("******* Maaf, belum ada data distribusi frozen food!!*******\n");
    printf ("\n************  Tekan enter untuk melanjutkan  ************\n");
   }
   else
   {
    LihatPesanan();
    printf ("\n************  Tekan enter untuk melanjutkan  *************\n");
   }
   getch();
            break;
        case 4 :
   if(head == NULL)
   {
    printf ("\n");
    printf ("******* Maaf, belum ada data distribusi frozen food!!*******\n");
    printf ("\n************  Tekan enter untuk melanjutkan  ************\n");
   }
   else
   {
    KirimPesanan(no, namabarang, jumlahbarang, hargabarang, tujuan, kodebarang);
    printf ("\n************  Tekan enter untuk melanjutkan  *************\n");
   }
   getch();
            break; 
        case 5 :
   printf ("\n=====================  PENDISTRIBUSIAN FROZEN FOOD PT. ANUGRAH FROZEN TELAH SELESAI  ====================\n");
   exit(1);
   break;
  default :
   printf ("\n");
   printf ("*******  Maaf, pilihan yang anda masukan salah  *******\n");
   printf ("\n************  Tekan enter untuk mengulang  *************\n");
   getch();
   break;
        }
    }while(pilih != 5);
}

void TambahPesanan(int no, char namabarang[], int jumlahbarang, int hargabarang, char tujuan[], char kodebarang[])
{
    struct distribute *ptr,  *temp = head;
    ptr = (struct distribute *)malloc(sizeof(struct distribute));
    ptr->no = no;
    strcpy (ptr->namabarang , namabarang);
    ptr->jumlahbarang = jumlahbarang;
    ptr->hargabarang = hargabarang;
    strcpy (ptr->tujuan, tujuan);
    strcpy (ptr->kodebarang, kodebarang);
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        while (temp->next != NULL)
        temp = temp->next;
  		ptr->prev = temp;
  		temp->next = ptr;
    }
}

void LihatPesanan()
{

 system("cls");
 struct distribute *temp = head;
 printf ("------------------------------------------------------------------------------------------------------\n");
 printf ("============================================     PESANAN     =========================================\n");
 printf ("------------------------------------------------------------------------------------------------------\n\n");
 
 while (temp!=NULL)
 {
  printf ("1. Nomor Pesanan      : %d\n" , temp->no);
  printf ("2. Nama Frozen Food   : %s\n" , temp->namabarang);
  printf ("3. Jumlah Frozen Food : %d pcs\n" , temp->jumlahbarang);
  printf ("4. Harga Frozen Food  : Rp.%d\n" , temp->hargabarang);
  printf ("5. Tujuan Distribusi  : %s\n" , temp->tujuan);
  printf ("6. Kode Frozen Food   : %s\n" , temp->kodebarang);
  printf ("7. Waktu Pembelian    : %s", asctime (timeinfo));
  printf ("\n");
        temp = temp->next;
 }
    printf ("---------------------------------------------------------------------------------");
}

void KirimPesanan(int no, char namabarang[], int jumlahbarang, int hargabarang, char tujuan[], char kodebarang[])
{
	FILE *pesanan;
 	struct distribute *temp, *p;                             
        temp = head;
        head = head->next;
        printf ("\n");
        printf ("Pesanan dengan data sebagai berikut berhasil didistribusikan!! \n");
  	printf ("1. Nomor Pesanan      : %d\n" , temp->no);
  	printf ("2. Nama Frozen Food   : %s\n" , temp->namabarang);
  	printf ("3. Jumlah Frozen Food : %d pcs\n" , temp->jumlahbarang);
  	printf ("4. Harga Frozen Food  : Rp.%d\n" , temp->hargabarang);
  	printf ("5. Tujuan Distribusi  : %s\n" , temp->tujuan);
  	printf ("6. Kode Frozen Food   : %s\n" , temp->kodebarang);
  	printf ("7. Waktu Pembelian    : %s", asctime (timeinfo));
  	printf ("\n");
	pesanan = fopen("HistoryPesanan.txt" , "a");
	fprintf (pesanan, "------------------------------------------\n");
	fprintf (pesanan, "1. Nomor Pesanan      : %d\n" , no);
	fprintf (pesanan, "2. Nama Frozen Food   : %s\n" , namabarang);
	fprintf (pesanan, "3. Jumlah Frozen Food : %d pcs\n" , jumlahbarang);
	fprintf (pesanan, "4. Harga Frozen Food  : Rp.%d\n" , hargabarang);
	fprintf (pesanan, "5. Tujuan Distribusi  : %s\n" , tujuan);
	fprintf (pesanan, "6. Kode Frozen Food   : %s\n" , kodebarang);
	fprintf(pesanan,  "7. Waktu Pembelian    : %s", asctime (timeinfo));
	fprintf (pesanan, "\n");
        free(temp);
}

void displaymenu()
{

	printf ("-------------------------------------------------------------------------------------------------------\n");
	printf ("=================================      DAFTAR FROZEN FOOD, KODE, DAN HARGA     ===============================\n");
	printf ("-------------------------------------------------------------------------------------------------------\n\n");
	printf ("\n1. Bakso Ayam / Ikan / Sapi \n");
	printf ("Kode Bakso Ayam: RTC1A \n");
	printf ("Kode Bakso Ikan: RTC1I \n");
	printf ("Kode Bakso Sapi: RTC1S \n");
	printf ("250 gr = Rp 20.000 \n");
	printf ("500 gr = Rp 35.000 \n");
	printf ("\n2. Nugget Ayam / Ikan \n"); 
	printf ("Kode Nugget Ayam: RTC2A \n");
	printf ("Kode Nugget Ikan: RTC2I \n");
	printf ("250 gr = Rp 25.000 \n");
	printf ("500 gr = Rp 45.000 \n");			   	
	printf ("\n3. Dumpling Ayam / Keju \n"); 
	printf ("Kode Dumpling Ayam: RTC3A \n");
	printf ("Kode Dumpling Keju: RTC3K \n");
	printf ("250 gr = Rp 22.000 \n");
	printf ("500 gr = Rp 38.000 \n");	
	printf ("\n4. Sosis Ayam / Sapi \n");
	printf ("Kode Sosis Ayam: RTC4A \n");
	printf ("Kode Sosis Sapi: RTC4S \n");
	printf ("250 gr = Rp 20.000\n");
	printf ("500 gr = Rp 35.000 \n");
	printf ("\n5. Siomay Ayam/Udang \n");
	printf ("Kode Siomay Ayam : RTC5A \n");
	printf ("Kode Siomay Udang: RTC5U \n");
	printf ("250 gr = Rp 17.000\n");
	printf ("500 gr = Rp 30.000\n");
	printf ("\n6. Kentang Goreng \n");
	printf ("500 gr  = Rp 22.000\n"); 
	printf ("1000 gr = Rp 38.000\n");
	printf ("\n7. Tempura Udang \n");
	printf ("500 gr = Rp 40.000\n");
	printf ("1000 gr = Rp 75.000\n");
	printf ("\n TEKAN ENTER UNTUK KEMBALI KE MENU ");
        getch();
	
}
