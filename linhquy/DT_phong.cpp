#include "DT_phong.h"

DT_phong::DT_phong(){
	this->Ma_phong = " ";
	this->Ten_phong = " ";
	this->Nam = 0;
	this->Kieu_phong = " ";
	this->Gia_phong = " ";
	this->Trang_Thai = " ";
	this->Vi_Tri = " ";
}

DT_phong::DT_phong(string t_ma_phong, string t_ten_phong, string t_kieu_phong,
	string t_gia_phong, int t_nam, string t_trang_thai, string t_vi_tri){
	this->Ma_phong = t_ma_phong;
	this->Ten_phong = t_ten_phong;
	this->Nam = t_nam;
	this->Kieu_phong = t_kieu_phong;
	this->Gia_phong = t_gia_phong;
	this->Trang_Thai = t_trang_thai;
	this->Vi_Tri = t_vi_tri;
}