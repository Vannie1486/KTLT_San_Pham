#include <stdio.h>
#include <string.h>
struct SinhVien {
	char masv[10];
	char ten[15];
	int gt;
	float diem;
};
void NhapThongTin(SinhVien *sv, int i);
void InThongTin(SinhVien sv, int i);
int ChuCaiDau(SinhVien sv);
void DoiViTri(SinhVien *csv, int i, int j);
int main() {
	struct SinhVien cacSV[100];
	int n;
	printf("\nNhap so luong sinh vien can nhap: ");
	scanf("%d", &n);
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		NhapThongTin(&cacSV[i], i);
	}
	while (1) 
	{
		int luaChon;
		printf("\nChon cac chuc nang tiep theo de thuc hien (nhap 0 de ket thuc): ");
		printf("\n1.In danh sach sinh vien.\n2.Sap xep.\n3.Tim kiem.\n4.Thong ke.");
		printf("\n------------------------");
		scanf("%d", &luaChon);
		if (luaChon == 0) break;
		else if(luaChon == 1)
		{
			for (int i = 0; i < n; i++)
			{
				InThongTin(cacSV[i], i);
			}
		}
		else if (luaChon == 2)
		{
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i+1; j<n; j++)
				{
					if (ChuCaiDau(cacSV[i]) > ChuCaiDau(cacSV[j]))
					{
						DoiViTri(cacSV, i, j);
					}
				}	
			}
			printf("\nDa sap xep!");
		}
		else if (luaChon == 3)
		{
			char tim[10];
			printf("\nNhap ma sinh vien ban can tim: ");
			scanf("%s", &tim);
			for (int i =0; i<n; i++)
			{
				if (strcmp(cacSV[i].masv, tim) == 0)
				{
					printf("\nDa tim dc sinh vien!");
					printf("\nSinh vien can tim o vi tri thu %d.", i);
					printf("\n------------------------");
				}
				else 
				{
					printf("\nKhong tim thay sinh vien!!");
					printf("\n------------------------");
				}
			}
		}
		else if (luaChon == 4)
		{
			int lon = 0, be = 0;
			for (int i =0; i<n; i++)
			{
				if (cacSV[i].diem >= 5.5)
					lon += 1;
				else be += 1;
			}
			printf("\nSo sinh vien co diem so >= 5.5: %d", lon);
			printf("\nSo sinh vien co diem so < 5.5: %d", be);
		}
	}
	
}
void NhapThongTin(SinhVien *sv, int i) {
	printf("\nNhap thong tin sinh vien thu: %d", i+1);
	printf("\nNhap masv: ");
	scanf("%s", &sv->masv);
	fflush(stdin);
	printf("\nNhap ten: ");
	scanf("%s", &sv->ten);
	fflush(stdin);
	printf("\nNhap gioi tinh(1-nam, 0-nu): ");
	scanf("%d", &sv->gt);
	fflush(stdin);
	printf("\nNhap diem cua sinh vien: ");
	scanf("%f", &sv->diem);
	fflush(stdin);
	printf("\n------------------------");
}
void InThongTin(SinhVien sv, int i) {
	printf("\nThong tin sinh vien thu %d: ", i+1);
	printf("\nMaSV: %s", sv.masv);
	printf("\nTen cua sinh vien: %s", sv.ten);
	if (sv.gt==0) printf("\nGioi tinh cua sinh vien: nu");
	else printf("\nGioi tinh cua sinh vien: nam");
	printf("\nDiem cua sinh vien: %0.1f", sv.diem);
	printf("\n------------------------");
}
int ChuCaiDau(SinhVien sv) {
	int t = sv.ten[0];
	if ((t >= 97)&&(t <= 122))
		t -= 32;
	return t;
}
void DoiViTri(SinhVien *csv, int i, int j) {
	SinhVien dem;
	dem = csv[i];
	csv[i] = csv[j];
	csv[j] = dem;
}
