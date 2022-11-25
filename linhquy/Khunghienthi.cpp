#include "Khunghienthi.h"

Khunghienthi::Khunghienthi(){
	this->toado_0x = 0;
	this->toado_0y = 0;
	this->chieucao = 0;
	this->chieurong = 0;
	this->maubackgound = 0;
	this->modevien = 1;
	this->noidung = "";
}
Khunghienthi::Khunghienthi(int y, int x, int h, int w, int bg, int mode_vien){
	this->toado_0x = x;
	this->toado_0y = y;
	this->chieucao = h;
	this->chieurong = w;
	this->maubackgound = bg;
	this->modevien = mode_vien;
}
Khunghienthi::Khunghienthi(int y, int x, int h, int w, int bg){
	this->toado_0x = x;
	this->toado_0y = y;
	this->chieucao = h;
	this->chieurong = w;
	this->maubackgound = bg;
	this->modevien = 1;
}
void Khunghienthi::SetToaDo(int y, int x) {
	this->toado_0x = x;
	this->toado_0y = y;
}
void Khunghienthi::SetKichThuoc(int h, int w){
	this->chieucao = h;
	this->chieurong = w;
}
void Khunghienthi::SetBackground(int color){
	this->maubackgound = color;
}
void Khunghienthi::SetModeVien(int mode){
	this->modevien = mode;
}
void Khunghienthi::SetNoiDung(string t_noidung){
	this->noidung = t_noidung;
}
void Khunghienthi::DrawKhunghienthi(){
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;
	int mode = this->modevien;
	int trenphai = 218;
	int trentrai = 191;
	int trenngang = 196;
	int bendung = 179;
	int duoiphai = 192;
	int duoitrai = 217;
	int duoingang = 196;
	if (mode == 0)
	{
		trenphai = 201;
		trentrai = 187;
		trenngang = 205;
		bendung = 186;
		duoiphai = 200;
		duoitrai = 188;
		duoingang = 205;
	};
	gotoxy(y, x);
	Show_point(false);
	SetBGColor(this->maubackgound);
	for (int i = x; i < x + w; i++) {
		if (wherex() == x && wherey() == y){
			cout << char(trenphai);//'┌' 201
		}
		else if (wherex() == x + w - 1 && wherey() == y){
			cout << char(trentrai);//'┐' 187
		}
		else{
			cout << char(trenngang);      // '─'
		}
	}
	gotoxy(y + 1, x);
	for (int i = y + 1; i < y + h - 1; i++){
		gotoxy(i, x);
		cout << char(bendung);// '│'
		gotoxy(i, x + w - 1);
		cout << char(bendung);
	}
	gotoxy(y + h - 1, x);
	for (int i = x; i < x + w; i++){
		if (wherex() == x && wherey() == y + h - 1){
			cout << char(duoiphai);// '└'
		}
		else if (wherex() == x + w - 1 && wherey() == y + h - 1) {
			cout << char(duoitrai);      // '┘'
		}
		else{
			cout << char(duoingang);      // '─'
		}
	}
	XoaNoiDung(this->maubackgound);
	AddNoidung();
}
int Khunghienthi::Get0y(){
	int y = this->toado_0y;
	return y;
}
int Khunghienthi::Get0x(){
	int x = this->toado_0x;
	return x;
}
string Khunghienthi::GetNoiDung(){
	string str = this->noidung;
	return str;
}
void Khunghienthi::XoaNoiDung(int color){
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;
	SetBGColor(color);
	Show_point(false);
	for (int i = y + 1; i < y + h - 1; i++){
		gotoxy(i, x + 1);
		for (int j = x + 1; j < x + w - 1; j++){
			cout << " ";
		}
	}
}

void Khunghienthi::XoaAll(int color){
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;
	this->SetBackground(color);
	Show_point(false);
	if (h < 50 && w < 150){
		for (int i = y; i < y + h; i++){
			gotoxy(i, x);
			for (int j = x; j < x + w; j++){
				cout << " ";
			}
		}
	}
	else{
		cout << "Loi Doi Tuong" << endl;
	}
}
void Khunghienthi::AddNoidung(){
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;
	int l = this->noidung.length();
	gotoxy(y, x);
	if (l < w - 2){
		gotoxy(y + h / 2, x + w / 2 - l / 2);
		cout << this->noidung << endl;
	}
}
void Khunghienthi::Doinen(int color){
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;
	SetBackground(color);
	XoaAll(color);
	DrawKhunghienthi();
}