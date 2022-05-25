#include <stdio.h>
#include <stdlib.h>

FILE *Tambah;
FILE *Lihat;

struct{
    char nama[100];
    char nim[100];
    char ipk[100];
    char alamat[100];
    char tlp[100];
}mhs;


void TambahDat(){
    system("cls");
    printf("========== TAMBAH DATA MAHASISWA ==========\n");
    printf("-------------------------------------------\n");
    printf("Pesan : Tambahkan Underscore '_' sebagai \n        pengganti spasi\n\n");
    printf("Masukkan Nama Lengkap : "); scanf("%s", &mhs.nama); fflush(stdin);
    printf("Masukkan NIM          : "); scanf("%s", &mhs.nim); fflush(stdin);
    printf("Masukkan IPK          : "); scanf("%s", &mhs.ipk); fflush(stdin);
    printf("Masukkan Alamat       : "); scanf("%s", &mhs.alamat); fflush(stdin);
    printf("Masukkan No. Telepon  : "); scanf("%s", &mhs.tlp); fflush(stdin);
}

void SimpanDat(){
    Tambah = fopen("DataMhs.txt", "w");
    fprintf(Tambah, "================DATA_MAHASISWA================\n");
    fprintf(Tambah, "----------------------------------------------\n");
    fprintf(Tambah, "Nama:%s\n", mhs.nama);
    fprintf(Tambah, "NIM:%s\n", mhs.nim);
    fprintf(Tambah, "IPK:%s\n", mhs.ipk);
    fprintf(Tambah, "Alamat:%s\n", mhs.alamat);
    fprintf(Tambah, "No.Telepon:%s\n", mhs.tlp);
    fprintf(Tambah, "----------------------------------------------\n\n");
    printf("\nData Berhasil Ditambahkan\n");
    fclose(Tambah);
}

void SimpanDat2(){
    Tambah = fopen("DataMhs.txt", "a");
    fprintf(Tambah, "================DATA_MAHASISWA================\n");
    fprintf(Tambah, "----------------------------------------------\n");
    fprintf(Tambah, "Nama:%s\n", mhs.nama);
    fprintf(Tambah, "NIM:%s\n", mhs.nim);
    fprintf(Tambah, "IPK:%s\n", mhs.ipk);
    fprintf(Tambah, "Alamat:%s\n", mhs.alamat);
    fprintf(Tambah, "No.Telepon:%s\n", mhs.tlp);
    fprintf(Tambah, "----------------------------------------------\n\n");
    printf("\nData Berhasil Ditambahkan\n");
    fclose(Tambah);
}

void TampilDat(){
    system("cls");
    printf("============ LIHAT DATA MAHASISWA ============\n");
    printf("----------------------------------------------\n\n");
    Lihat = fopen("DataMhs.txt", "r");
    if(Lihat == NULL){
        printf("\nFile Tidak Tersedia!\n");
    }
    else{
        char buff[255];
        while(fscanf(Lihat, "%s", buff)==1) printf("%s\n", buff);
    }
    fclose(Lihat);

}

int main()
{
    int pilih;
    menu :
        system("cls");
        printf("========== PROGRAM DATA MAHASISWA ==========\n");
        printf("--------------------------------------------\n");
        printf("Menu :\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Tambah Data Mahasiswa lainnya\n");
        printf("3. Lihat Data Mahasiswa\n");
        printf("0. Keluar\n");
        printf("\n============================================\n");
        printf("Pilih Menu : ");
        scanf("%d", &pilih);
        switch(pilih)
        {
            case(1):
                TambahDat();
                SimpanDat();
                system("pause");
                goto menu;

            case(2):
                TambahDat();
                SimpanDat2();
                system("pause");
                goto menu;

            case(3):
                TampilDat();
                system("pause");
                goto menu;

            case(0):
                printf("\n========== TERIMAKASIH ==========\n");
                system("pause");
                break;

            default : printf("\nMenu Tidak Ada, Mohon Inputkan Ulang\n");
            system("pause");
            goto menu;
        }


    return 0;
}
