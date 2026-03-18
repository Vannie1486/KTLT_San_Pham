#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
typedef struct
{
    int Id;
    char noidung[300];
    char pa1[150];
    char pa2[150];
    char pa3[150];
    char pa4[150];
    int dapan;
} CauHoi;
typedef struct
{
    char masv[10];
    char ten[15];
    char gt[10];
} SinhVien;
void InThongTin(SinhVien sv);
void NhapThongTin(SinhVien *sv);
void Doc(CauHoi *ch, int *n);
void InCauHoi(const CauHoi *ch, int i);
void CauNgauNhien(int n[], int sl);
void TongKet(SinhVien sv, int cDung);
int main()
{
    SinhVien Sv;
    CauHoi CacCH[100];
    int CacCau[10];
    int soC, LC, cDung = 0;
    Doc(CacCH, &soC);
    CauNgauNhien(CacCau, 10);
    NhapThongTin(&Sv);
    printf("\n------Nhap cau tra loi tu 1 den 4, nhap 0 de dung thi------\n");
    printf("------====================== Bat dau thi =====================------\n");
    for (int i = 0; i < 10; i++)
    {
        InCauHoi(CacCH, CacCau[i] - 1);
        while (1)
        {
            scanf("%d", &LC);
            if (LC == 0)
            {
                TongKet(Sv, cDung);
                return 0;
            }
            else if (LC < 1 || LC > 4 )
                printf("Lua chon khong hop le!!\nVui long nhap lai: ");
            else if (LC == CacCH[i].dapan)
            {
                printf("Dung!\n-----------------------------------\n");
                cDung++;
                break;
            }
            else
            {
                printf("Sai!\n-----------------------------------\n");
                break;
            }
        }
    }
    TongKet(Sv, cDung);
    return 0;
}
void InThongTin(SinhVien sv)
{
    printf("\nMaSV: %s", sv.masv);
    printf("\nTen cua sinh vien: %s", sv.ten);
    printf("\nGioi tinh: %s", sv.gt);
    printf("\n----------------------------------");
}
void NhapThongTin(SinhVien *sv)
{
    printf("\n------====== Nhap Thong tin ca nha ======------");
    printf("\nNhap masv: ");
    scanf("%s", &sv->masv);
    fflush(stdin);
    printf("\nNhap ten: ");
    scanf("%s", &sv->ten);
    fflush(stdin);
    int lc;
    printf("\nNhap gioi tinh:\n[0] nu\t[1] nam): ");
    scanf("%d", &lc);
    fflush(stdin);
    if (lc == 1)
    {
        strcpy(sv->gt, "Nam");
    }
    else
    {
        strcpy(sv->gt, "Nu");
    }
    printf("\n----------------------------------");
    printf("\n----------====== Thong tin vua nhap ======---------- ");
    InThongTin(*sv);
}

void Doc(CauHoi *ch, int *n)
{
    FILE *f;
    f = fopen("Cau_Hoi.txt", "r");
    if (f == NULL)
    {
        printf("Khong tim duoc file!\n");
        return;
    }
    int i = 0;
    for (; i < 50 && fscanf(f, "%d", &ch[i].Id) != EOF; i++)
    {
        fscanf(f, " %[^\n]", ch[i].noidung);
        fscanf(f, " %[^\n]", ch[i].pa1);
        fscanf(f, " %[^\n]", ch[i].pa2);
        fscanf(f, " %[^\n]", ch[i].pa3);
        fscanf(f, " %[^\n]", ch[i].pa4);
        fscanf(f, " %d", &ch[i].dapan);
    }
    *n = i;
    fclose(f);
}
void InCauHoi(const CauHoi *ch, int i)
{
    printf("Cau %d:\n", ch[i].Id);
    printf("  Noi dung : %s\n", ch[i].noidung);
    printf("  1) %s\n", ch[i].pa1);
    printf("  2) %s\n", ch[i].pa2);
    printf("  3) %s\n", ch[i].pa3);
    printf("  4) %s\n", ch[i].pa4);
    printf("  Lua chon (1-4): ");
}
void CauNgauNhien(int n[], int sl)
{
    int so;
    int trung;

    for (int i = 0; i < sl; i++)
    {
        do
        {
            so = 1 + rand() % 50;
            trung = 0;

            for (int j = 0; j < i; j++)
            {
                if (n[j] == so)
                {
                    trung = 1;
                    break;
                }
            }
        } while (trung == 1);

        n[i] = so;
    }
}
void TongKet(SinhVien sv, int cDung)
{
    printf("\n------=========== Ket qua thi ===========------");
    InThongTin(sv);
    printf("\nSo cau dung: %d/10 cau\n", cDung);
    if (cDung >= 8)
        printf("Xep loai: Gioi\n");
    else if (cDung >= 6)
        printf("Xep loai: Kha\n");
    else if (cDung >= 4)
        printf("Xep loai: Trung binh\n");
    else
        printf("Xep loai: Yeu\n");
}