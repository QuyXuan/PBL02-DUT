#ifndef _DT_khachhang_H_
#define _DT_khachhang_H_
#include "iostream"
#include "string"
#include "date_ht.h"

class DT_khachhang {
private:
	string Ma_khachhang;
	string Hoten;
	v_date Ngaysinh;
	string SDT;
	string Gioitinh;
	string Trangthai;
public:
	DT_khachhang();
	DT_khachhang(string t_ma_khach_hang, string t_Hoten, v_date t_Ngaysinh, string SDT, string t_Gioitinh, string t_Trangthai);
	void Set_ma_dg(string t_ma_khach_hang) {
		this->Ma_khachhang = t_ma_khach_hang;
	}
	void Set_hoten(string t_hoten_kh) {
		this->Hoten = t_hoten_kh;
	}
	void Set_sdt(string t_sdt) {
		this->SDT = t_sdt;
	}
	void Set_gioitinh(string t_gioitinh) {
		this->Gioitinh = t_gioitinh;
	}
	void Set_trangthai(string t_trangthai) {
		this->Trangthai = t_trangthai;
	}

	void Set_ngaysinh(v_date ngaysinh) {
		this->Ngaysinh = ngaysinh;
	}

	string Get_ma_dg() {
		return this->Ma_khachhang;
	}

	string Get_hoten()
	{
		return this->Hoten;
	}

	string Get_sdt()
	{
		return this->SDT;
	}

	string Get_gioitinh()
	{
		return this->Gioitinh;
	}

	string Get_trangthai()
	{
		return this->Trangthai;
	}

	v_date Get_ngaysinh()
	{
		return this->Ngaysinh;
	}

	bool operator == (const DT_khachhang& kh) {
		return (this->Ma_khachhang == kh.Ma_khachhang);
	}
};
#endif