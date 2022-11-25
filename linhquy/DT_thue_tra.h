#ifndef DT_thue_TRA_H_
#define DT_thue_TRA_H_
#include "iostream"
#include "string"
#include "Ql_khachhang.h"
#include "Ql_phong.h"
#include "date_ht.h"

class DT_thue_tra{
private:
	string ma_so_phong;
	string ma_so_khachhang;
	v_date ngay_thue;
	v_date ngay_tra;
public:
	DT_thue_tra();
	DT_thue_tra(string t_ma_so_phong, string t_ma_so_khachhang, v_date t_ngay_tra);
	void Set_ma_so_khachhang(string t_ma_so_kh){
		this->ma_so_khachhang = t_ma_so_kh;
	}
	void Set_ma_so_phong(string t_ma_so_phong){
		this->ma_so_phong = t_ma_so_phong;
	}
	void Set_ngay_thue(v_date t_ngay_thue){
		this->ngay_thue = t_ngay_thue;
	}
	void Set_ngay_tra(v_date t_ngay_tra){
		this->ngay_tra = t_ngay_tra;
	}
	string Get_ma_so_phong(){
		return this->ma_so_phong;
	}
	string Get_ma_so_dg(){
		return this->ma_so_khachhang;
	}
	v_date Get_ngay_thue(){
		return this->ngay_thue;
	}
	v_date Get_ngay_tra(){
		return this->ngay_tra;
	}
};
#endif
