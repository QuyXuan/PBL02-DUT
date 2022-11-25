#ifndef _DT_phong_
#define _DT_phong_
#include "iostream"
#include "string"
#include "cstdlib"
using namespace std;

class DT_phong{
private:
	string Ma_phong;
	string Ten_phong;
	string Kieu_phong;
	string Gia_phong;
	int Nam;
	string Trang_Thai;
	string Vi_Tri;
public:
	DT_phong();
	DT_phong(string t_ma_phong, string t_ten_phong, string t_kieu_phong,
		string t_gia_phong, int t_nam, string t_trang_thai, string t_vi_tri);
	void Set_ma_phong(string t_ma_phong){
		this->Ma_phong = t_ma_phong;
	}
	void Set_ten_phong(string t_ten_phong){
		this->Ten_phong = t_ten_phong;
	}
	void Set_kieu_phong(string t_kieu_phong){
		this->Kieu_phong = t_kieu_phong;
	}
	void Set_gia_phong(string t_gia_phong){
		this->Gia_phong = t_gia_phong;
	}
	void Set_trang_thai(string t_trang_thai){
		this->Trang_Thai = t_trang_thai;
	}
	void Set_vi_tri(string t_vi_tri){
		this->Vi_Tri = t_vi_tri;
	}
	void Set_nam(string t_nam){
		this->Nam = atoi(t_nam.c_str());
	}
	void Set_nam(int t_nam){
		this->Nam = t_nam;
	}
	string Get_ma_phong(){
		return this->Ma_phong;
	}
	string  Get_ten_phong(){
		return this->Ten_phong;
	}
	string  Get_kieu_phong(){
		return this->Kieu_phong;
	}
	string  Get_gia_phong(){
		return this->Gia_phong;
	}
	string  Get_trang_thai(){
		return this->Trang_Thai;
	}
	string  Get_vi_tri(){
		return this->Vi_Tri;
	}
	int Get_nam(){
		return this->Nam;
	}
	bool operator == (const DT_phong& phg) {
		return (this->Ma_phong == phg.Ma_phong);
	}
};
#endif

