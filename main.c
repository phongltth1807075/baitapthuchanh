#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char idsv[50];
    char namesv[50];
    char phonesv[50];

} sv;
sv dssv[50];

int count = 0;

int themsv() {
    int size;
    printf("Nhap so luong nhan vien ban can dien:\n");
    scanf("%d", &size);
    sv mysv[size];
    for (int i = 0; i < size; ++i) {
        printf("Nhap ma cua ban:\n");
        fgets(mysv[i].idsv, 50, stdin);
        if (!mysv[i].idsv, '\n') {
            while (fgetc(stdin) != '\n');
        }
        printf("Nhap ten cua ban: \n");
        fgets(mysv[i].namesv, 50, stdin);
        if (!mysv[i].namesv, '\n') {
            while (fgetc(stdin) != '\n');
        }
        printf("nhap so dien thoai cua ban: \n");
        fgets(mysv[i].phonesv, 50, stdin);
        if (!mysv[i].phonesv, '\n') {
            while (fgetc(stdin) != '\n');
        }
        count++;
    }
    return count;
}

void hienthidssv() {
    printf("%-10s%-20s%-10s%-20s%-10s%-20s", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int i = 0; i < count; ++i) {
        printf("%-10s%-20s%-10s%-20s%-10s%-20s\n", "", dssv[i].idsv, "|", dssv[i].namesv, "|",
               dssv[i].phonesv);
    }
}

void docdssv() {
    FILE *fp;
    fp = fopen("danhsachsinhvien.txt", "r");
    char buff[500];
    while (fgets(buff, 50, fp) != NULL) {
        printf("%s", buff);
    }
}

void ludssv() {
    FILE *fp;
    fp = fopen("danhsachsinhvien.txt", "w+");
    fprintf(fp, "%-10s%-20s%-10s%-20s%-10s%-20s", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int i = 0; i < count; ++i) {
        fprintf(fp, "%-10s%-20s%-10s%-20s%-10s%-20s\n", "", dssv[i].idsv, "|", dssv[i].namesv, "|",
                dssv[i].phonesv);
    }
    fclose(fp);

}


int main() {


    int choice;
    while (1 == 1) {
        printf("\n---------Quan ly sinh vien---------\n");
        printf("1.Them moi sinh vien\n");
        printf("2.Hien Thi sinh vien\n");
        printf("3.Luu danh sach sinh vien ra file\n");
        printf("4.Doc danh sach sinh vien tu file\n");
        printf("5.Thoat chuong trinh\n");
        printf("Moi ban nhap lua chon (1,2,3,4,5):\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("1.Them moi sinh vien\n");
                themsv();
                break;
            case 2:
                printf("2.Hien Thi sinh vien\n");
                hienthidssv();
                break;
            case 3:
                printf("3.Luu danh sach sinh vien ra file\n");
                ludssv();
                break;
            case 4:
                printf("4.Doc danh sach sinh vien tu file\n");
                docdssv();
                break;
            case 5:
                printf("ket thuc!");
                exit(1);
            default:
                break;
        }
    }

}