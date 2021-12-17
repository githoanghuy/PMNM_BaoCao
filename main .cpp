#include "Header.h"	
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>




int main()
{
	DanhSachAo ds;
	Ao a;
	DanhSachQuan dsq;
	Quan b;
	int so = 0;
	int n;
	int vt;
	int x = 0;
	const char* filename;
	char z[20];

	do
	{

		system("cls");
		cout << "-------------(^o^)-Chao Mung Ban Den Chuong Trinh Quan Ly Quan Ao-(^@^)---------------" << endl;
		cout << "=====MENU AO==== " << endl;
		cout << "  1.Nhap Xuat Ao" << endl;
		cout << "  2.Nhap Xuat Quan" << endl;
		cout << "  3.Tim theo ma ao" << endl;
		cout << "  4.Xoa Tai Vi Tri" << endl;
		cout << "  5.Them tai vi tri" << endl;
		cout << endl;
		cout << "=====MENU QUAN=====" << endl;
		cout << "  6.Tim theo ma quan" << endl;
		cout << "  7.Xoa Quan Tai Vi Tri " << endl;
		cout << "  8.Them quan tai vi tri" << endl;
		cout << endl;
		cout << "=====[LUU FILE AO]=====" << endl;
		cout << "  9.Luu file Ao " << endl;
		cout << "  10.Doc file Ao" << endl;
		cout << endl;
		cout << "=====[LUU FILE QUAN]=====" << endl;
		cout << "  11.Luu file Quan" << endl;
		cout << "  12.Doc file Quan" << endl;
		cout << endl;
		cout << "=====[SUA THONG TIN AO-QUAN]=====" << endl;
		cout << "  13.Sua Thong Tin Ao" << endl;
		cout << "  14.Sua Thong Tin Quan" << endl;
		cout << endl;
		cout << "--------------------" << endl;

		cout << "Moi ban chon chuong trinh : ";
		cin >> so;
		switch (so)
		{
		case 1:
			system("cls");
			cout << "Moi Ban Nhap Thong Tin Ao : " << endl;
			nhapDSA(ds);
			xuatDSA(ds);
			system("pause");
			break;
		case 2:
			system("cls");
			cout << " Moi ban nhap Thong Tin Quan !" << endl;
			nhapDSQ(dsq);
			xuatDSQ(dsq);
			system("pause");
			break;
		case 3:
		{
			system("cls");
			cout << "[TIM THEO MA]" << endl;
			if (timTheoMaAo(ds, n) == true)
			{
				xuatAo(ds.data[n]);
			}
			else
			{
				cout << "[MA KHONG TON TAI]";
			}
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			system("cls");
			xoa(ds, vt);
			xuatDSA(ds);
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			Ao z;
			nhapAo(z);
			them(ds, z, vt);
			xuatDSA(ds);
			system("pause");
			system("cls");
			break;
		}
		//======QUẦN====//
		case 6:
			system("cls");
			cout << "[TIM THEO MA]" << endl;
			if (timTheoMaQuan(dsq, n) == true)
			{
				xuatQuan(dsq.data[n]);
			}
			else
			{
				cout << "[MA KHONG TON TAI]";
			}
			system("pause");
			break;
		case 7:
		{
			system("cls");
			xoaQuan(dsq, vt);
			xuatDSQ(dsq);
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			Quan z;
			nhapQuan(z);
			themQuan(dsq, z, vt);
			xuatDSQ(dsq);
			system("pause");
			system("cls");
			break;
		}
		case 9:
		{
			system("cls");
			cin.ignore();
			cout << " Nhap ten file : ";
			cin.getline(z, 20);
			filename = (const char*)z;
			if (GhiDuLieuA(ds, filename))
				cout << "Ghi thanh cong!";
			else
			{
				cout << "Khong ghi duoc!";
			}
			system("pause");
			system("cls");
			break;
		}
		case 10:
		{
			system("cls");
			cin.ignore();
			cout << " Nhap ten file : ";
			cin.getline(z, 20);
			filename = (const char*)z;
			if (DocDuLieuA(ds, filename))
			{
				cout << "Doc thanh cong \n";
				xuatDSA(ds);
			}
			else
			{
				cout << "Khong co du lieu hoac ko tim thay!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 11:
		{
			system("cls");
			cin.ignore();
			cout << " Nhap ten file : ";
			cin.getline(z, 30);
			filename = (const char*)z;
			if (GhiDuLieuQ(dsq, filename))
				cout << "Ghi thanh cong!";
			else
			{
				cout << "Khong ghi duoc!";
			}
			system("pause");
			system("cls");
			break;
		}
		case 12:
		{
			system("cls");
			cin.ignore();
			cout << " Nhap ten file : ";
			cin.getline(z, 10);
			filename = (const char*)z;
			if (DocDuLieuQ(dsq, filename))
			{
				cout << "Doc thanh cong \n";
				xuatDSQ(dsq);
			}
			else
			{
				cout << "Khong co du lieu hoac ko tim thay!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 13:
		{
			system("cls");
			sua(ds, a, vt);
			xuatDSA(ds);
			system("pause");
			system("cls");
			break;
		}
		case 14:
		{
			system("cls");
			suaq(dsq, b, vt);
			xuatDSQ(dsq);
			system("pause");
			system("cls");
			break;
		}
		
		default:
			cout << "Vui long nhan chon tu 1 den 14" << endl;
			break;
		}
	} while (so != 20);
	system("pause");
	//system("cls");
}