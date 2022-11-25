#include "DT_khachhang.h"

DT_khachhang::DT_khachhang(){
	this->Ma_khachhang = " ";
	this->Hoten = " ";
	this->Ngaysinh.Ngay = 1;
	this->Ngaysinh.Thang = 1;
	this->Ngaysinh.Nam = 1900;
	this->SDT = "000000000";
	this->Gioitinh = " ";
	this->Trangthai = " ";
}

DT_khachhang::DT_khachhang(string t_Ma_Khach_Hang, string t_Hoten, v_date t_Ngaysinh, string t_SDT, string t_Gioitinh, string t_Trangthai){
	this->Ma_khachhang = t_Ma_Khach_Hang;
	this->Hoten = t_Hoten;
	this->Ngaysinh.Ngay = t_Ngaysinh.Ngay;
	this->Ngaysinh.Thang = t_Ngaysinh.Thang;
	this->SDT = t_SDT;
	this->Gioitinh = t_Gioitinh;
	this->Trangthai = t_Trangthai;
}
