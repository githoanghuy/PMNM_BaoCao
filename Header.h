#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
const int MAX = 100;
const int MAX_List = 100;
struct Ao
{
	char maAo[10];
	char loaiAo[30];
	char hieuAo[10];
	char size[10];
	int n;
	int gtao;
};
struct Quan
{
	char maQuan[10];
	char loaiQuan[30];
	char hieuQuan[10];
	char size[10];
	int n;
	int gtquan;
};
struct DanhSachAo
{
	int a;// so luong ao
	Ao data[100]; // struct Ao chòng vào struct DanhSach Ao
	int arr[100]; 
};
struct DanhSachQuan
{
	int b;// so luong quan
	Quan data[100];
	int arr[100];
};
void nhapAo(Ao &qa);
void nhapQuan(Quan &quan);
void xuatAo(Ao qa);
void xuatQuan(Quan quan);
void nhapDSA(DanhSachAo &ds);
void nhapDSQ(DanhSachQuan &dsq);
void xuatDSA(DanhSachAo ds);
void xuatDSQ(DanhSachQuan dsq);
bool timTheoMaAo(DanhSachAo ds,int &vt);
void xoa(DanhSachAo &ds, int &viTri);
void them(DanhSachAo &ds, Ao &a, int &viTri);
void themQuan(DanhSachQuan &ds, Quan &b, int &viTri);
bool timTheoMaQuan(DanhSachQuan dsq, int &vt);
void xoaQuan(DanhSachQuan &ds, int &viTri); 
void sua(DanhSachAo &ds, Ao &tam, int &vt);
void suaq(DanhSachQuan &dsq, Quan &tam1, int &vt);
//GHI FILE
int GhiDuLieuA(DanhSachAo ds, const char* fileName);
int DocDuLieuA(DanhSachAo& ds, const char* fileName);
//Ghi File Quan//
int GhiDuLieuQ(DanhSachQuan dsq, const char* fileName);
int DocDuLieuQ(DanhSachQuan& dsq, const char* fileName);