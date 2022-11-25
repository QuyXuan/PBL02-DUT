#pragma once
#include"list.h"
#include"DT_phong.h"
#include"DT_thue_tra.h"
#include"DT_khachhang.h"
class Hethong{
private:
	list<DT_khachhang>danhSachKhachHang;
	list<DT_phong>danhSachPhong;
	list<DT_thue_tra>danhSachPhongThueTra;
};