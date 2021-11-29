#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct distribute
{
    char namabarang[100], tujuan[100];
    int no, jumlahbarang, hargabarang;
    struct distribute *prev;
    struct distribute *next;
};

struct distribute *head = NULL;

void TambahPesanan(int, char [], int, int, char[]);
void LihatPesanan();
void KirimPesanan(int, char namabarang[], int jumlahbarang, int hargabarang, char tujuan[]);
void displaymenu();
void main();


void main()
{
 system("cls");
    char namabarang[100], tujuan[100];
    int no, n, jumlahbarang, hargabarang, pilih;
     do
 {
 	 menu:
  system("cls");
        printf ("===============================================================================================\n");
  printf ("===============================  PROGRAM DISTIRBUSI  FROZEN FOOD   ============================\n");
  printf ("================================  DARI PABRIK PT. ANUGRAH FROZEN  =============================\n");
  printf ("===============================================================================================\n");
  printf ("MENU :\n");
  			
        printf ("1. Daftar produk\n");
        //mungkin kuubah pakai searching dan sorting 
        printf ("2. Input Data Pendistribusian\n");
        //isi fungsi file mungkin
        printf ("3. Tampilkan Data Pendistribusian\n");
        printf ("4. Kirim Frozen Food\n");
        //rute pendistribusian sc graph minggu lalu?
        //mungkin ada fixed route dn new route
        printf ("5. Keluar Program\n");
        printf ("\nMasukkan pilihan anda : ");
        scanf("%d", &pilih);
        switch(pilih)
        {
        case 1:
        	displaymenu();
		 case 2:
       
	system ("cls");
    printf ("------------------------------------------------------------------------------------------------------\n");
    printf ("============================ PESANAN ==============================\n");
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
   gets(tujuan);         
   TambahPesanan(no, namabarang, jumlahbarang, hargabarang, tujuan);
            printf ("\n************  Tekan enter untuk melanjutkan  *************\n");
            getch();
   break;
        case 3 :
            if(head == NULL)
   {
    printf ("\n");
    printf ("*******Maaf, belum ada data distribusi frozen food!!*******\n");
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
    printf ("*******Maaf, belum ada data distribusi frozen food!!*******\n");
    printf ("\n************  Tekan enter untuk melanjutkan  ************\n");
   }
   else
   {
    KirimPesanan(no, namabarang, jumlahbarang, hargabarang, tujuan);
    printf ("\n************  Tekan enter untuk melanjutkan  *************\n");
   }
   getch();
            break; 
        case 5 :
   printf ("\n=====================  PENDISTRIBUSIAN BERAS PT. ALAM SURYA TELAH SELESAI  ====================\n");
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

void TambahPesanan(int no, char namabarang[], int jumlahbarang, int hargabarang, char tujuan[])
{
    struct distribute *ptr,  *temp = head;
    ptr = (struct distribute *)malloc(sizeof(struct distribute));
    ptr->no = no;
    strcpy (ptr->namabarang , namabarang);
    ptr->jumlahbarang = jumlahbarang;
    ptr->hargabarang = hargabarang;
    strcpy (ptr->tujuan, tujuan);
   
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
 printf ("-------------------------------------------------------------------------------------------------\n");
 printf ("-------------------------------------------------------------------------------------------------\n\n");
 while (temp!=NULL)
 {
  printf ("1. Nomor Pesanan      : %d\n" , temp->no);
  printf ("2. Nama Frozen Food   : %s\n" , temp->namabarang);
  printf ("3. Jumlah Frozen Food : %d pcs\n" , temp->jumlahbarang);
  printf ("4. Harga Froxen Food  : Rp.%d\n" , temp->hargabarang);
  printf ("5. Tujuan Distribusi  : %s\n" , temp->tujuan);
  printf ("\n");
        temp = temp->next;
    }
    printf ("---------------------------------------------------------------------------------");
}

void KirimPesanan(int no, char namabarang[], int jumlahbarang, int hargabarang, char tujuan[])
{
 struct distribute *temp, *p;
    if (head-> no == no)
    {                               
        temp = head;
        head = head->next;
        printf ("\n");
        printf ("Pesanan dengan data sebagai berikut berhasil didistribusikan!! :)\n");
     printf ("1. Nomor Pesanan      : %d\n" , no);
  printf ("2. Nama Frozen Food   : %s\n" , namabarang);
  printf ("3. Jumlah Frozen Food : %d pcs\n" , jumlahbarang);
  printf ("4. Harga Froxen Food  : Rp.%d\n" , hargabarang);
  printf ("5. Tujuan Distribusi  : %s\n" , tujuan);
  printf ("\n");
        free(temp);
    }
    
}

void displaymenu()
{
int no, menu;
back:
system("cls");

printf ("------------------------------------------------------------------------------------------------------\n");
printf ("============================ DAFTAR FROZEN FOOD DAN HARGA ==============================\n");
printf ("------------------------------------------------------------------------------------------------------\n\n");
printf ("\n 1. Bakso Ayam / Ikan / Sapi \n");
printf ("\n 2. Nugget Ayam / Ikan \n "); 			   	
printf ("\n 3. Dumpling	Ayam / Keju \n ");    	
printf ("\n 4. Sosis  \n");    
printf ("\n 5. Siomay \n");	 
printf ("\n 6. Kentang \n");
printf ("\n 7. Kembali ke menu utama \n");	 			
printf("\n Masukkan nomor menu: ");
scanf("%d", &no);
switch(no)
{
	case 1:
		printf("\n 250 gr = Rp 20.000 \n 500 gr = Rp 35.000 \n");
		printf("Tekan ENTER untuk kembali ke menu ");
		getch();
		goto back;
	break;
	case 2:
		printf("\n 250 gr = Rp 25.000 \n 500 gr = Rp 45.000 \n");
		printf("Tekan ENTER untuk kembali ke menu  ");
		getch();
		goto back;
	break;
	case 3:
		printf("\n 250 gr = Rp 22.000 \n 500 gr = Rp 38.000 \n");
		printf("Tekan ENTER untuk kembali ke menu utama ");
		getch();
		goto back;
	break;
	case 4:
		printf("\n 250 gr = Rp 20.000 \n 500 gr = Rp 35.000 \n");
		printf("Tekan ENTER untuk kembali ke menu utama ");
		getch();
		goto back;
	break;
	case 5:
		printf("\n 250 gr = Rp 17.000 \n 500 gr = Rp 30.000 \n");
		printf("Tekan ENTER untuk kembali ke menu utama ");
		getch();
		goto back;
	break;
	case 6:
		printf("\n 500 gr = Rp 22.000 \n 1000 gr = Rp 38.000 \n");
		printf("Tekan ENTER untuk kembali ke menu utama ");
		getch();
		goto back;
	break;
	case 7:
		main();
	default:
		printf("\n Input salah, tekan ENTER untuk kembali ke menu  ");
		getch();
		goto back;
   }
}


