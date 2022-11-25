#pragma once
#include <stdio.h> 
#include <conio.h>
#include <tchar.h> 
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;

//key đặc biệt
#define BACKSPACE 8 //quay con trỏ về 1 đơn vị
#define ENTER 13 //ok
#define ESC  27 //thoát trực tiếp và về menu chính
#define KEY_UP 72 //di chuyển lên
#define KEY_DOWN 80 //di chuyển xuống
#define KEY_LEFT 75 //di chuyển sang trái
#define KEY_RIGHT 77 //di chuyển sang phải
#define KEY_F2 60 //lưu
#define KEY_F3 61 //xóa
#define KEY_F4 62 //hiệu chỉnh
#define KEY_F10 68 //lưu
#define PAGE_DOWN 81 //cuộn xuống dưới
#define PAGE_UP 73 //cuộn lên trên
#define SPACE  32 //khoảng trắng
#define KEY_F9 67 //tìm kiếm
#define TAB 9 //trở về

typedef unsigned int uint; //unsigned int -> uint

//mã màu
#define AQUA 3 //xanh dương
#define PURPLE 5 //tím
#define LIGHT_AQUA 11 //xanh dương sáng
#define LIGHT_YELLOW 14 //vàng sáng
#define LIGHT_GREEN 10 //xanh lá sáng
#define BLACK 0 //đen
#define WHITE 7 //trắng
#define GREEN 2	//xanh lá
#define BRIGHT_WHITE 15 //trắng ánh
#define BLUE 1 //xanh dương
#define LIGHT_RED 12 //đỏ sáng
#define LIGHT_ORANGE 78 //cam sáng

//kích cỡ màn hình
#define GWIDTH 120 //chiều rộng
#define GHEIGHT 36 //chiều cao

void Disable_maximize();
void Close_windows_console();
void gotoxy(short y, short x);
int wherex(void);
int wherey(void);
void textcolor(WORD color);
void SetBGColor(WORD color);
void setColor(int maunen, int mauchu);
void Show_point(bool value);

bool KiemTraTen(string);
void ThongBaoNhapNhay(string s, int maunen, int mauchu, int cot, int hang);
void BangThongBaoLoi(string);
void XoaBangThongBaoLoi();
void KhungHinh(int, int, int, int);
void XoaMang(int y, int x, int h, int w, int color);
bool KiemTraNhapSoNguyen(char a[], int& DuLieu);
void BangLuaChon(int y, int x, string noidung, bool& btn_Co);
void KhungNhapMakhachhang(int y, int x);
void ThanhTru(int y, int x, int maunen, int mauchu, int makitu);
void ThanhNgang(int y, int x, int w, int maunen, int mauchu, int makitu);
void KhungNho(int y, int x, int w, int h, string noidung, int bg);

void Ghifile(string name_file, string data);
void Docfile(int y, int x, string namefile);
string Getfile(string name_file);
void Xoadoituongtrongfile(string name_file, string tk);
void Suadoitrangthaiphong(string file_name, string t_maso, string t_trang_thai);
void Suadoitrangthaikhachhang(string file_name, string t_maso, string t_trang_thai);

string Get_trangthaiphong(string file_name, string t_maso);
string Get_trangthaikhachhang(string file_name, string t_maso);
string Xoa_khoang_trang_dau_cuoi(string data);
string Xoa_khoang_trang_giua(string data);
string Xoa_khoang_trang_thua(string t_data);
string Chuyenchuhoathanhchuthuong(string str);
