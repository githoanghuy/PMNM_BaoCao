#include "Header.h"	
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
//--------------------------ÁO--------------------------//
void nhapAo(Ao &qa)
{
	cin.ignore();
	cout << "Nhap Ma Ao :";
	cin.getline(qa.maAo, 10);
	cout << "Nhap Hieu Ao:";
	cin.getline(qa.hieuAo, 20);
	cout << "Nhap Loai Ao :";
	cin.getline(qa.loaiAo, 10);
	cout << "Nhap size :";
	cin.getline(qa.size, 5);
	cout << "Nhap gia Ao:";
	cin >> qa.gtao;
}
void xuatAo(Ao qa)
{
	cout << "--------------" << endl;
	cout << "MA AO: " << qa.maAo << endl;
	cout << "LOAI AO:" << qa.loaiAo << endl;
	cout << "Hieu AO:" << qa.hieuAo << endl;
	cout << "SIZE:" << qa.size << endl;
	cout << "GIA TIEN AO:" << qa.gtao << endl;
	cout << "--------------" << endl;
}
void nhapDSA(DanhSachAo &ds)
{

	cout << "Nhap So Luong Ao : ";
	cin >> ds.a;
	cout << "-Thong Tin Ao-" << endl;
	for (int i = 0; i < ds.a; i++)
	{
		cout << "================================" << endl;
		cout << "Thong Tin Ao Thu " << i + 1 << endl;
		cout << "================================" << endl;
		nhapAo(ds.data[i]);
	}
}
void xuatDSA(DanhSachAo ds)
{
	cout << "-----------------------------------" << endl;
	cout << "-----------DANH SACH AO------------" << endl;
	for (int i = 0; i < ds.a; i++)
		xuatAo(ds.data[i]);
}
bool timTheoMaAo(DanhSachAo ds, int& vt)
{
	char tam[10];
	cout << " Nhap ma ao: ";
	cin >> tam;
	for (int i = 0; i < ds.a; i++)
	{
		if (strcmp(ds.data[i].maAo, tam) == 0)
		{
			vt = i;
			return true;
		}
	}
	return false;
}
void xoa(DanhSachAo &ds, int &viTri)
{
	
	cout << "Ban muon Xoa Tai Vi Tri Nao ?";
	cin >> viTri;
	for (int i = viTri; i < ds.a - 1; i++)
	{
		ds.data[i] = ds.data[i + 1];
	}
	ds.a = ds.a - 1;
}
void them(DanhSachAo &ds,Ao &a, int &viTri)
{
	cout << " Ban muon them tai vi tri nao ? ";
	cin >> viTri;
	for (int i = ds.a; i > viTri; i--)
	{
		ds.data[i] = ds.data[i - 1];
	}
	ds.data[viTri] = a;
	ds.a++;
}
////--------------------------Quần--------------------------//
void nhapQuan(Quan& quan)
{
	cin.ignore();
	cout << "Nhap Ma Quan:";
	cin.getline(quan.maQuan, 10);
	cout << "Nhap Hieu Quan:";
	cin.getline(quan.hieuQuan, 20);
	cout << "Nhap Loai Quan :";
	cin.getline(quan.loaiQuan, 10);
	cout << "Nhap size :";
	cin.getline(quan.size, 5);
	cout << "Nhap gia Quan:";
	cin >> quan.gtquan;
}
void xuatQuan(Quan quan)
{
	cout << "--------------" << endl;
	cout << "MA QUAN: " << quan.maQuan << endl;
	cout << "LOAI QUAN :" << quan.loaiQuan << endl;
	cout << "Hieu QUAN:" << quan.hieuQuan << endl;
	cout << "SIZE QUAN :" << quan.size << endl;
	cout << "GIA TIEN QUAN:" << quan.gtquan << endl;
	cout << "--------------" << endl;

}
void nhapDSQ(DanhSachQuan& dsq)
{
	cout << "Nhap So Luong Quan : ";
	cin >> dsq.b;
	cout << "-Thong Tin Quan-" << endl;
	for (int i = 0; i < dsq.b; i++)
	{
		cout << "================================" << endl;
		cout << "Thong Tin Quan Thu " << i + 1 << endl;
		cout << "================================" << endl;
		nhapQuan(dsq.data[i]);
	}
}
void xuatDSQ(DanhSachQuan dsq)
{
	cout << "-----------------------------------" << endl;
	cout << "-----------DANH SACH QUAN----------" << endl;
	for (int i = 0; i < dsq.b; i++)
		xuatQuan(dsq.data[i]);
}
bool timTheoMaQuan(DanhSachQuan dsq, int& vt)
{
	char tam[10];
	cout << " Nhap ma quan: ";
	cin >> tam;
	for (int i = 0; i < dsq.b; i++)
	{
		if (strcmp(dsq.data[i].maQuan, tam) == 0)
		{
			vt = i;
			return true;
		}
	}
	return false;
}
void xoaQuan(DanhSachQuan &ds, int &viTri)
{
	cout << "Ban muon Xoa Tai Vi Tri Nao ?";
	cin >> viTri;
	for (int i = viTri; i < ds.b- 1; i++)
	{
		ds.data[i] = ds.data[i + 1];
	}
	ds.b = ds.b - 1;
}
void themQuan(DanhSachQuan &ds, Quan &b, int &viTri)
{
	cout << " Ban muon them tai vi tri nao ? ";
	cin >> viTri;
	for (int i = ds.b; i > viTri; i--)
	{
		ds.data[i] = ds.data[i - 1];
	}
	ds.data[viTri] = b;
	ds.b++;
}
// =======[FILE AO]========//
int GhiDuLieuA(DanhSachAo ds, const char* fileName)
{
	FILE* f;
	fopen_s(&f, fileName, "w");
	if (f == NULL) return 0;
	fprintf(f, "%d\n", ds.a);
	for (int i = 0; i < ds.a; i++)
	{
		fprintf(f, "%s\n", ds.data[i].maAo);
		fprintf(f, "%s\n", ds.data[i].hieuAo);
		fprintf(f, "%s\n", ds.data[i].loaiAo);
		fprintf(f, "%s\n", ds.data[i].size);
		fprintf(f, "%d\n", ds.data[i].gtao);
	}
	fclose(f);
	return 1;
}
int DocDuLieuA(DanhSachAo& ds, const char* fileName)
{
	FILE* f;
	fopen_s(&f, fileName, "r+");
	if (f == NULL) return 0;
	else
	{
		fscanf_s(f, "%d\n", &ds.a);
		for (int i = 0; i < ds.a; i++)
		{
			fgets(ds.data[i].maAo, 10, f);
			ds.data[i].maAo[strlen(ds.data[i].maAo) - 1] = '\0';
			fgets(ds.data[i].hieuAo, 10, f);
			ds.data[i].hieuAo[strlen(ds.data[i].hieuAo) - 1] = '\0';
			fgets(ds.data[i].loaiAo, 10, f);
			ds.data[i].loaiAo[strlen(ds.data[i].loaiAo) - 1] = '\0';
			fgets(ds.data[i].size, 10, f);
			ds.data[i].size[strlen(ds.data[i].size) - 1] = '\0';
			fscanf_s(f, "%d\n", &ds.data[i].gtao);
		}
	}
	fclose(f);
	return 1;
}
//========================//=============================//
// =====[FILE QUAN]==== //
int GhiDuLieuQ(DanhSachQuan dsq, const char* fileName)
{
	FILE* f;
	fopen_s(&f, fileName, "w");
	if (f == NULL) return 0;
	fprintf(f, "%d\n", dsq.b);
	for (int i = 0; i < dsq.b; i++)
	{
		fprintf(f, "%s\n", dsq.data[i].maQuan);
		fprintf(f, "%s\n", dsq.data[i].hieuQuan);
		fprintf(f, "%s\n", dsq.data[i].loaiQuan);
		fprintf(f, "%s\n", dsq.data[i].size);
		fprintf(f, "%d\n", dsq.data[i].gtquan);
	}
	fclose(f);
	return 1;
}
int DocDuLieuQ(DanhSachQuan& dsq, const char* fileName)
{
	FILE* f;
	fopen_s(&f, fileName, "r+");
	if (f == NULL) return 0;
	else
	{
		fscanf_s(f, "%d\n", &dsq.b);
		for (int i = 0; i < dsq.b; i++)
		{
			fgets(dsq.data[i].maQuan, 10, f);
			dsq.data[i].maQuan[strlen(dsq.data[i].maQuan) - 1] = '\0';
			fgets(dsq.data[i].hieuQuan, 10, f);
			dsq.data[i].hieuQuan[strlen(dsq.data[i].hieuQuan) - 1] = '\0';
			fgets(dsq.data[i].loaiQuan, 10, f);
			dsq.data[i].loaiQuan[strlen(dsq.data[i].loaiQuan) - 1] = '\0';
			fgets(dsq.data[i].size, 10, f);
			dsq.data[i].size[strlen(dsq.data[i].size) - 1] = '\0';
			fscanf_s(f, "%d\n", &dsq.data[i].gtquan);
		}
	}
	fclose(f);
	return 1;
}
//=============================================================//
void sua(DanhSachAo& ds, Ao& tam, int& vt)
{
	nhapAo(tam);
	cout << " Nhap vi tri can sua : ";
	cin >> vt;
	ds.data[vt].gtao = tam.gtao;
	strcpy_s(ds.data[vt].hieuAo, tam.hieuAo);
	strcpy_s(ds.data[vt].loaiAo, tam.loaiAo);
	strcpy_s(ds.data[vt].size, tam.size);
	strcpy_s(ds.data[vt].maAo, tam.maAo);
}
void suaq(DanhSachQuan &dsq, Quan &tam1, int &vt)
{
	nhapQuan(tam1);
	cout << " Nhap vi tri can sua : ";
	cin >> vt;
	dsq.data[vt].gtquan = tam1.gtquan;
	strcpy_s(dsq.data[vt].hieuQuan, tam1.hieuQuan);
	strcpy_s(dsq.data[vt].loaiQuan, tam1.loaiQuan);
	strcpy_s(dsq.data[vt].size, tam1.size);
	strcpy_s(dsq.data[vt].maQuan, tam1.maQuan);
}
//=============================================================//