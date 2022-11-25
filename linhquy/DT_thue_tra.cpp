#include "DT_thue_tra.h"

DT_thue_tra::DT_thue_tra(){
	this->ma_so_phong = " ";
	this->ma_so_khachhang = " ";
	this->ngay_thue.Ngay = 1;
	Thoi_Gian_Thuc(this->ngay_thue);
	Thoi_Gian_Thuc(this->ngay_tra);
}

DT_thue_tra::DT_thue_tra(string t_ma_so_phong, string t_ma_so_khachhang, v_date t_ngay_tra){
	this->ma_so_phong = t_ma_so_phong;
	this->ma_so_khachhang = t_ma_so_khachhang;
	this->ngay_thue.Ngay = 1;
	Thoi_Gian_Thuc(this->ngay_thue);
	this->ngay_tra = t_ngay_tra;
}