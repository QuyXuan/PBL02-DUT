#pragma once
#include <iostream>
#include "Func_Support.h"
#include "Khunghienthi.h"
#include "Table.h"
#include "Ql_phong.h"
#include "Ql_khachhang.h"
#include "Ql_thue_tra.h"
using namespace std;

void Creat_main_guide(int& lua_chon){
	textcolor(WHITE);
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));
	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG KHACH SAN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "			 PBL02        " << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 15 / 2);
	cout << "	    GIAO DIEN CHINH" << endl;
	ThanhNgang(38, 11, 120, BLACK, WHITE, char(205));
	gotoxy(39, 11 + 20);
	cout << " CAC PHIM DIEU KHIEN, THAO TAC: ^, v, <, >, ENTER " << endl;
	string danhmuc[24] = {	" 1.  QUAN LY THUE/TRA             ",			//0
							" 2.  QUAN LY PHONG              ",				//1
							"  3.  QUAN LY KHACH HANG              ",		//2
							" 4.  THONG KE                    ",			//3
							" 5.  THOAT                       ",			//4
							" 1.1  THUE PHONG             ",				//5
							" 1.2  TRA PHONG               ",				//6
							" 1.3  TRO LAI                ",				//7
							" 2.1  TIM KIEM PHONG           ",				//8
							" 2.2  THEM PHONG              ",				//9
							" 2.3  SUA THONG TIN PHONG      ",				//10
							" 2.4  XOA PHONG                ",				//11
							"  2.5  DANH SACH PHONG                 ",		//12
							" 2.6  TRO LAI                 ",				//13
							" 3.1  TIM KIEM KHACH HANG        ",			//14
							" 3.2  THEM KHACH HANG            ",			//15
							" 3.3  SUA THONG TIN KHACH HANG   ",			//16
							" 3.4  XOA KHACH HANG             ",			//17
							"  3.5  DANH SACH KHACH HANG              ",		//18
							" 3.6  TRO LAI                 ",				//19
							" 4.1  DANH SACH PHONG QUA HAN    ",			//20
							"  4.2  DANH SACH KHACH HANG THUE QUA HAN ",		//21
							" 4.3  DANH SACH THUE/TRA           ",			//22
							" 4.4  TRO LAI                 ",				//23

	};

	Docfile(5, 80, "dog.txt");

	Show_point(FALSE);
	Khunghienthi ht_main[24];
	for (int i = 0; i < 5; i++){
		ht_main[i].SetToaDo(6 + i * 6, 13);
		ht_main[i].SetKichThuoc(6, 60);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
		ht_main[i].DrawKhunghienthi();
	}
	for (int i = 5; i < 8; i++){
		ht_main[i].SetToaDo(6 + (i - 5) * 4, 80);
		ht_main[i].SetKichThuoc(4, 45);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
	}
	for (int i = 8; i < 14; i++){
		ht_main[i].SetToaDo(6 + (i - 8) * 4, 80);
		ht_main[i].SetKichThuoc(4, 45);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
	}
	for (int i = 14; i < 20; i++){
		ht_main[i].SetToaDo(6 + (i - 14) * 4, 80);
		ht_main[i].SetKichThuoc(4, 45);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
	}
	for (int i = 20; i < 24; i++){
		ht_main[i].SetToaDo(6 + (i - 20) * 4, 80);
		ht_main[i].SetKichThuoc(4, 45);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
	}

	int vt_func0 = 4, vt_func1 = 0;
	int lop = 0;
	while (1) {
		gotoxy(7, 11);
		Sleep(50);
		char kk = _getch();
		if (kk == -32) {
			char cc = _getch();
			if (lop == 0)
				XoaMang(6, 75, 32, 52, 0);
			if (cc == 72){
				if (lop == 0){
					ht_main[vt_func0].Doinen(0);
					vt_func0--;
					if (vt_func0 < 0) vt_func0 = 4;
					ht_main[vt_func0].Doinen(1);
				}
				else{
					if (vt_func0 == 0){
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 5) vt_func1 = 7;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 1){
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 8) vt_func1 = 13;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 2){
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 14) vt_func1 = 19;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 3){
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 20) vt_func1 = 23;
						ht_main[vt_func1].Doinen(1);
					}
				}
			}

			if (cc == 80){
				if (lop == 0){
					ht_main[vt_func0].Doinen(0);
					vt_func0++;
					if (vt_func0 == 5) vt_func0 = 0;
					ht_main[vt_func0].Doinen(1);
				}
				else{
					if (vt_func0 == 0){
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 7) vt_func1 = 5;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 1){
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 13) vt_func1 = 8;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 2){
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 19) vt_func1 = 14;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 3){
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 23) vt_func1 = 20;
						ht_main[vt_func1].Doinen(1);
					}
				}
			}

			if (lop == 0){
				if (vt_func0 == 0){
					vt_func1 = 5;
					for (int i = 5; i < 8; i++){
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 1){
					vt_func1 = 8;
					for (int i = 8; i < 14; i++){
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 2){
					vt_func1 = 14;
					for (int i = 14; i < 20; i++){
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 3){
					vt_func1 = 20;
					for (int i = 20; i < 24; i++){
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 4){
					SetBGColor(0);
					Docfile(5, 80, "dog.txt");
				}
			}
		}

		if (kk == 13){
			if (lop == 0){
				lop = 1;
				if (vt_func0 == 4){
					lua_chon = 100;
					break;
				}
				else
					ht_main[vt_func1].Doinen(1);
			}
			else{
				lop = 0;
				if (vt_func1 == 7 || vt_func1 == 13 || vt_func1 == 19 || vt_func1 == 23){
					ht_main[vt_func1].Doinen(0);
				}
				else{
					gotoxy(0, 0);
					lua_chon = vt_func1;
					break;
				}
			}
		}
	}
}

int main(){
	int t_exit = 0;
	int lua_chon = 0;
	Show_point(false);
	Disable_maximize();

	while (1) {
		Creat_main_guide(lua_chon);
		SetBGColor(0);
		system("cls");
		switch (lua_chon)
		{
		case 5:                     //1.1 thue phong
			while (1){
				Khung_Ql_thue_phong();
				if (Xuly_Ql_thue_phong())

					break;
			}
			break;
		case 6:                     //1.2 Tra phong
			while (1){
				Khung_Ql_tra_phong();
				if (Xuly_Ql_tra_phong())

					break;
			}
			break;
		case 8:                     //2.1 Tim kiem phong
			Thucthi_Timkiem_phong();
			break;
		case 9:                    //2.2 Them phong
			while (1){
				Khung_Ql_phong_Them_phong();
				if (Xuly_Ql_phong_Them_phong())

					break;
			}
			break;
		case 10:                  //2.3 Sua thong tin phong
			Sua_thongtin_phong();
			break;
		case 11:                  //2.4 Xoa phong
			t_exit = 0;
			while (!t_exit){
				t_exit = Xoa_phong();
			}
			break;
		case 12:                  //2.5 Ds phong
			Hienthi_Ql_phong_ds();
			break;
		case 14:                  //3.1 Tim kiem khach hang
			Thucthi_Timkiem_khachhang();
			break;
		case 15:                 //3.2 Them khach hang
			while (1){
				Khung_Ql_phong_Them_khachhang();
				if (Xuly_Ql_phong_Them_khachhang())

					break;
			}
			break;
		case 16:                 //3.3 Sua thong tin khach hang
			Sua_thongtin_khachhang();
			break;
		case 17:                  //3.4 Xoa khach hang
			t_exit = 0;
			while (!t_exit){
				t_exit = Xoa_khachhang();
			}
			break;
		case 18:                 //3.5 Danh phong khach hang
			Hienthi_Ql_khachhang_ds();
			break;
		case 20:                 //4.1 Danh phong qua han
			Hienthi_ds_phong_quahan();
			break;
		case 21:                //4.2 Danh phong khach hang thue qua han
			Hienthi_ds_dg_quahan();
			break;
		case 22:                //4.3 Danh phong thue - tra
			Hienthi_ds_thuetra();
			break;
		case 100:
			Close_windows_console();
			break;
		}
		SetBGColor(0);
		system("cls");
	}
	return 0;
}


