#pragma once
#include "fcntl.h"
#include "io.h"
#include "iostream"
#include "string"
#include "Khunghienthi.h"
#include "Func_Support.h"
#include "Table.h"
#include "date_ht.h"
#include "DT_khachhang.h"

void Khung_Ql_phong_Them_khachhang();
int Xuly_Ql_phong_Them_khachhang();
void Hienthi_Ql_khachhang_ds();
void Hien_thi_timkiem_khachhang();
void Thucthi_Timkiem_khachhang();
void Sua_thongtin_khachhang();
DT_khachhang Madg_Timkiem_dg(string t_madg);
int Xoa_khachhang();