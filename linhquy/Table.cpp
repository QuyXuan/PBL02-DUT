#include "Table.h"

Table::Table() {
	this->toado_0x = 0;
	this->toado_0y = 0;
	this->chieucao = 1;
	this->chieurong = 1;
	this->socot = 1;
	this->sohang = 1;
	this->maubackgound = 0;
	for (int i = 0; i < 50; i++) {
		this->dorongcot[i] = 0;
		this->doronghang[i] = 0;
		this->tencot[i] = "";
		this->tenhang[i] = "";
	}
}

Table::Table(int y, int x, int* t_temp_vthang, int* t_temp_vtcot, int bg) {
	int t_drc = 0, t_sh = 0, t_sc = 0, h = 0, w = 0;
	int* temp_vthang = t_temp_vthang;
	int* temp_vtcot = t_temp_vtcot;
	this->toado_0x = x;
	this->toado_0y = y;

	while (*temp_vthang > 0) {
		h += *temp_vthang;
		this->doronghang[t_sh] = *temp_vthang;
		t_sh++;
		temp_vthang++;
	}

	while (*temp_vtcot > 0) {
		w += *temp_vtcot;
		this->dorongcot[t_sc] = *temp_vtcot;
		t_sc++;
		temp_vtcot++;
	}

	this->socot = t_sc;
	this->sohang = t_sh;
	this->chieurong = w;
	this->chieucao = h;

	for (int i = 0; i < 50; i++) {
		this->tencot[i] = "";
		this->tenhang[i] = "";
	}
	this->maubackgound = bg;
}

void Table::Set_danhmuc(string* dm_ten_hang, string* dm_ten_cot) {
	for (int j = 0; j < this->socot; j++) {
		this->tencot[j] = dm_ten_cot[j];
	}

	for (int i = 0; i < this->sohang; i++) {
		this->tenhang[i] = dm_ten_hang[i];
	}
}

void Table::CreatTable(Khunghienthi kht[50][50], int& sh, int& sc) {
	int x = this->toado_0x;
	int y = this->toado_0y;

	sc = this->socot;
	sh = this->sohang;

	//Khunghienthi kht[50][50];
	Show_point(false);
	for (int j = 0; j < sh; j++) {
		for (int i = 0; i < sc; i++) {
			kht[j][i].SetToaDo(y, x);
			kht[j][i].SetKichThuoc(this->doronghang[j], this->dorongcot[i]);
			kht[j][i].SetBackground(this->maubackgound);
			kht[j][i].SetNoiDung("");
			if (j == 0) kht[j][i].SetNoiDung(this->tencot[i]);
			if (i == 0) kht[j][i].SetNoiDung(this->tenhang[j]);
			kht[j][i].DrawKhunghienthi();
			if (i > 0) {
				gotoxy(y, x);
				std::cout << char(194);
				gotoxy(y + this->doronghang[j] - 1, x);
				cout << char(193);
			}

			if (i == 0 && j > 0) {
				gotoxy(y, x);
				std::cout << char(195);
			}

			if (i == sc - 1 && j > 0) {
				gotoxy(y, x + dorongcot[i] - 1);
				std::cout << char(180);
			}

			if (j > 0 && i > 0) {
				gotoxy(y, x);
				std::cout << char(197);
			}
			x += this->dorongcot[i] - 1;
		}
		x = this->toado_0x;
		y += this->doronghang[j] - 1;

	}
}

void Table::CreatTable(Khunghienthi kht[50][50]){
	int x = this->toado_0x;
	int y = this->toado_0y;

	int sc = this->socot;
	int sh = this->sohang;

	//Khunghienthi kht[50][50];
	Show_point(false);
	for (int j = 0; j < sh; j++){
		for (int i = 0; i < sc; i++){
			kht[j][i].SetToaDo(y, x);
			kht[j][i].SetKichThuoc(this->doronghang[j], this->dorongcot[i]);
			kht[j][i].SetBackground(this->maubackgound);
			kht[j][i].SetNoiDung("");
			if (j == 0) kht[j][i].SetNoiDung(this->tencot[i]);
			if (i == 0) kht[j][i].SetNoiDung(this->tenhang[j]);
			kht[j][i].DrawKhunghienthi();
			if (i > 0){
				gotoxy(y, x);
				std::cout << char(194);
				gotoxy(y + this->doronghang[j] - 1, x);
				cout << char(193);
			}

			if (i == 0 && j > 0){
				gotoxy(y, x);
				std::cout << char(195);
			}

			if (i == sc - 1 && j > 0){
				gotoxy(y, x + dorongcot[i] - 1);
				std::cout << char(180);
			}

			if (j > 0 && i > 0){
				gotoxy(y, x);
				std::cout << char(197);
			}
			x += this->dorongcot[i] - 1;
		}
		x = this->toado_0x;
		y += this->doronghang[j] - 1;
	}
}
