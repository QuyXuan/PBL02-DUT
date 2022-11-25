#ifndef _DATA_HT_H_
#define _DATA_HT_H_
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<fstream>
#include "Func_Support.h"
using namespace std;

struct time_date{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct time_date v_date;

void Thoi_Gian_Thuc(v_date& x); // hàm lấy thời gian thực từ hệ thống máy tính
string Get_thoi_Gian_Thuc();
v_date Nhapdate();
v_date Suadate(string tt_date);
string Suadate2(char kq, string tt_date);
string Suadate3(char kq, string tt_date);
void Doc_File_Ngay_Thang_Nam(ifstream&, v_date&);
void Ghi_File_Ngay_Thang_Nam(ofstream&, v_date x);
bool Kiem_Tra_Tinh_Hop_Le(v_date);
bool Kiem_Tra_Tinh_Hop_Le_3(v_date x);
bool Kiem_Tra_Nam_Nhuan(int); // hàm kiểm tra năm nhuận
bool Kiem_quahan(v_date x);
v_date chuyen_str_to_date(string str_date);
string chuyen_date_to_str(v_date x);
#endif