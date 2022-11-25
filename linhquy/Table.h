#pragma once
#include "iostream"
#include "Func_Support.h"
#include "Khunghienthi.h"

class Table{
private:
	int toado_0x;
	int toado_0y;
	int chieucao;
	int chieurong;
	int sohang;
	int socot;
	int dorongcot[50];
	int doronghang[50];
	int maubackgound;
	string tencot[50];
	string tenhang[50];
public:
	Table();
	Table(int y, int x, int* t_vthang, int* t_vtcot, int bg);
	void Set_danhmuc(string* dm_ten_hang, string* dm_ten_cot);
	void CreatTable(Khunghienthi kht[50][50], int& sh, int& sc);
	void CreatTable(Khunghienthi kht[50][50]);
};