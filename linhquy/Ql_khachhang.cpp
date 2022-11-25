#include "Ql_khachhang.h"

//thêm khách hàng
Khunghienthi kht_dg[50][50];
Khunghienthi lcht1_dg, lcht2_dg;
int sh_dg = 0, sc_dg = 0;
//hiển thị danh sách
Khunghienthi kht2_dg[50][50];
int sh2_dg = 0, sc2_dg = 0;
//hiển thị danh sách
Khunghienthi kht3_dg[50][50];
int sh3_dg = 0, sc3_dg = 0;
string  qldg_file_name = "Ql_tt_khachhang.txt";
void Khung_Ql_phong_Them_khachhang(){
	textcolor(WHITE);
	SetBGColor(0);
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));
	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY ĐAT PHONG KHACH SAN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 22 / 2);
	cout << "GIAO DIEN THEM KHACH HANG" << endl;
	string danhmuc_hang[10] = { "MA SO: ", "HO TEN: ", "NGAY SINH: ", "GIOI TINH: ", "SDT: ", "TRANG THAI: " };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20,45 };
	int vt_hang[10] = { 5, 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht_dg, sh_dg, sc_dg);

	gotoxy(23, 90);
	cout << "BAN THUE, LUU VA THOAT?" << endl;

	lcht1_dg.SetToaDo(25, 80);
	lcht1_dg.SetKichThuoc(3, 20);
	lcht1_dg.SetBackground(0);
	lcht1_dg.SetNoiDung("LUU");
	lcht1_dg.DrawKhunghienthi();

	lcht2_dg.SetToaDo(25, 105);
	lcht2_dg.SetKichThuoc(3, 20);
	lcht2_dg.SetBackground(0);
	lcht2_dg.SetNoiDung("EXIT");
	lcht2_dg.DrawKhunghienthi();

	gotoxy(30, 90);
	cout << "SU DUNG PHIM CTRL + S DE LUU!" << endl;
	gotoxy(31, 90);
	cout << "SU DUNG PHIM ESC DE THOAT!" << endl;
}

int Xuly_Ql_phong_Them_khachhang(){
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0;
	v_date t_date;
	for (int i = 0; i < sh_dg; i++){
		dien_x[i] = kht_dg[i][1].Get0x() + 2;
		dien_y[i] = kht_dg[i][1].Get0y() + 5 / 2;
		str[i] = " ";
	}
	str[2] = "  /  /    ";
	gotoxy(dien_y[2], dien_x[2]);
	cout << str[2];
	Show_point(true);
	gotoxy(dien_y[0], dien_x[0]);
	while (!flag_exit){
		//Sleep(5);
		Show_point(true);
		char kk = _getch();
		//xoa thong bao
		lcht1_dg.Doinen(0);
		lcht2_dg.Doinen(0);
		gotoxy(33, 90);
		cout << "                           " << endl;
		if (kk == -32){
			char cc = _getch();
			if (cc == 80){
				tt_cnt++;
				if (tt_cnt > 5) tt_cnt = 0;
			}
			if (cc == 72){
				tt_cnt--;
				if (tt_cnt < 0) tt_cnt = 5;
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (30 < kk && kk < 122){
			if (tt_cnt != 2){
				str[tt_cnt].push_back(kk);
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				cout << str[tt_cnt];
				Show_point(true);
			}
			else{
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				str[2] = Suadate2(kk, str[2]);
				tt_cnt++;
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
		}
		if (kk == 8){
			if (!str[tt_cnt].empty()){
				str[tt_cnt].pop_back();
			}
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			for (int i = 0; i < str[tt_cnt].length() + 2; i++){
				cout << " ";
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}
		if (kk == 13){
			tt_cnt++;
			if (tt_cnt > 5) tt_cnt = 0;
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (kk == 19){
			int vt_lcht = 0;
			lcht1_dg.Doinen(2);
			while (1){
				Show_point(false);
				char t_kk = _getch();
				if (t_kk == -32){
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77){
						if (vt_lcht == 0){
							vt_lcht = 1;
							lcht1_dg.Doinen(0);
							lcht2_dg.Doinen(2);
						}
						else{
							vt_lcht = 0;
							lcht1_dg.Doinen(2);
							lcht2_dg.Doinen(0);
						}
					}
				}
				if (t_kk == 13){
					if (vt_lcht == 0){
						for (int i = 0; i < sh_dg; i++){
							kht_dg[i][1].SetNoiDung(str[i]);
						}
						textcolor(WHITE);
						string tt_khachhang = kht_dg[0][1].GetNoiDung() + " ; "
							+ kht_dg[1][1].GetNoiDung() + " ; "
							+ kht_dg[2][1].GetNoiDung() + " ; "
							+ kht_dg[3][1].GetNoiDung() + " ; "
							+ kht_dg[4][1].GetNoiDung() + " ; "
							+ kht_dg[5][1].GetNoiDung() + " ; \n";
						Ghifile(qldg_file_name, tt_khachhang);
						gotoxy(33, 90);
						cout << "BAN DA LUU" << endl;
						flag_exit = 1;
					}
					if (vt_lcht == 1)
					{
						gotoxy(33, 90);
						cout << "BAN DA HUY" << endl;
						flag_exit = 0;
					}
					break;
				}
				if (t_kk == 27){
					return 1;
				}
			}
			SetBGColor(0);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (kk == 27){
			return 1;
		}
	}
	return 0;
}
void Hienthi_Ql_khachhang_ds(){
	textcolor(WHITE);
	SetBGColor(0);
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));
	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY DAT PHONG KHACH SAN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 27 / 2);
	cout << "GIAO DIEN DANH SACH PHONG KHACH HANG" << endl;
	int vt_trang = 1, sl_trang = 1;
	string danhmuc_hang[20] = { "STT", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "STT", "MA SO", "HO TEN", "NGAY SINH", "GIOI TINH", "SDT", "TRANG THAI" };
	int vt_cot[10] = { 7, 20, 30, 15, 15, 20, 15 };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 };

	int v_stt[100];
	string v_madg[100], v_hoten[1000], v_gioitinh[100], v_sdt[100], v_trangthai[100];
	v_date v_ngaysinh[100];
	string data = Getfile("Ql_tt_khachhang.txt");

	Table tb2(7, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht2_dg, sh2_dg, sc2_dg);

	gotoxy(38, 13 + 60 - 5);
	cout << "TRANG " << vt_trang << "/" << sl_trang << endl;
	/******************************** Xu ly data *****************************************************/

	char c;
	int cnt_hang = 0, cnt_cot = 0;
	string str_tt_dg = "", t_data;
	int value_count_dg = 0;
	for (int i = 0; i < data.length(); i++){
		c = data.at(i);
		if (c == '\n'){
			value_count_dg++;
			cnt_hang++;

			kht2_dg[cnt_hang][0].SetNoiDung(to_string(value_count_dg));
			kht2_dg[cnt_hang][0].AddNoidung();

			cnt_cot = 1;
			str_tt_dg = "";
			c = ' ';
		}
		if (c == ';'){
			t_data = Xoa_khoang_trang_thua(str_tt_dg);
			kht2_dg[cnt_hang][cnt_cot].SetNoiDung(t_data);
			kht2_dg[cnt_hang][cnt_cot].AddNoidung();
			cnt_cot++;
			str_tt_dg = "";
		}
		else
			str_tt_dg += c;
	}

	kht2_dg[cnt_hang][0].SetNoiDung("    ");
	kht2_dg[cnt_hang][0].AddNoidung();

	gotoxy(39, 13);
	cout << "SO LUONG:" << cnt_hang - 1 << endl;
	while (1){
		char kk = _getch();
		if (kk == 27){
			break;
		}
	}
}

void Hien_thi_timkiem_khachhang(){
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY ĐAT PHONG KHACH SAN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "Xuan Quy - Hoang Linh" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 23 / 2);
	cout << "GIAO DIEN TIM KIEM KHACH HANG" << endl;
#define sl_tk 3
	int vt_trang = 1, sl_trang = 1;
	Khunghienthi tk_htlc[sl_tk];
	string danhmuc_tk_htlc[sl_tk] = { "TIM KIEM MA KHACH HANG", "TIM KIEM HO TEN", "TIM KIEM SDT" };
	for (int i = 0; i < sl_tk; i++){
		tk_htlc[i].SetToaDo(6, 13 + 114 * i / sl_tk);
		tk_htlc[i].SetKichThuoc(3, 114 / sl_tk);
		tk_htlc[i].SetBackground(0);
		tk_htlc[i].SetNoiDung(danhmuc_tk_htlc[i]);
		tk_htlc[i].DrawKhunghienthi();
	}

	textcolor(1);
	SetBGColor(WHITE);
	gotoxy(13, 13 + 60 - 7 / 2); cout << "KET QUA" << endl;
	SetBGColor(0);

	string danhmuc_hang[20] = { "STT", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "STT", "MA SO", "HO TEN", "NGAY SINH", "GIOI TINH", "SDT", "TRANG THAI" };
	int vt_cot[10] = { 7, 20, 30, 15, 15, 20, 15 };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3, 3 };

	Khunghienthi kht_tk[50][50];

	Table tb2(15, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht_tk);

	textcolor(WHITE);

	int luachon_tk = 0;
	tk_htlc[luachon_tk].Doinen(2);
	while (1){
		Show_point(false);
		char t_kk = _getch();
		if (t_kk == -32){
			char t_cc = _getch();
			if (t_cc == 75){
				tk_htlc[luachon_tk].Doinen(0);
				luachon_tk--;
				if (luachon_tk < 0) luachon_tk = sl_tk - 1;
				tk_htlc[luachon_tk].Doinen(2);
			}
			if (t_cc == 77){
				tk_htlc[luachon_tk].Doinen(0);
				luachon_tk++;
				if (luachon_tk == sl_tk) luachon_tk = 0;
				tk_htlc[luachon_tk].Doinen(2);
			}
		}
		if (t_kk == 13){
			break;
		}
	}

	Khunghienthi khtklc[2][50];
	int vt_cot_tklc[3] = { 114 / sl_tk, 114 - 114 / sl_tk + sl_tk - 2 };
	int vt_hang_tklc[1] = { 3 };
	string danhmuc_hang_tk[1] = { danhmuc_tk_htlc[luachon_tk] };
	string danhmuc_cot_tk[2] = { danhmuc_tk_htlc[luachon_tk], " " };
	Table tb_nhap_lc(9, 13, vt_hang_tklc, vt_cot_tklc, 0);
	tb_nhap_lc.Set_danhmuc(danhmuc_hang_tk, danhmuc_cot_tk);
	tb_nhap_lc.CreatTable(khtklc);

	Show_point(true);
	gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
	string str;
	while (1){
		//Show_point(false);
		char kk = _getch();
		Show_point(false);
		gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
		if (30 < kk && kk < 122) {
			str.push_back(kk);
			cout << str;
		}
		if (kk == 8){
			if (!str.empty()){
				str.pop_back();
			}
			for (int i = 0; i < str.length() + 2; i++){
				cout << " ";
			}
			gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
			cout << str;
		}

		Show_point(true);

		if (kk == 13){
			break;
		}
	}

	str = Xoa_khoang_trang_thua(str);
	str = Chuyenchuhoathanhchuthuong(str);

	gotoxy(38, 13 + 60 - 5);
	cout << "TRANG " << vt_trang << "/" << sl_trang << endl;
	/************************************************************************/
	Show_point(false);
	fstream f;
	f.open(qldg_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	int count_line = 1, count_vtdt = 0;
	while (!f.eof()){
		getline(f, line);
		if (line.length() > 1){
			tt_data = " ";
			count_vtdt = 0;
			for (int i = 0; i < line.length(); i++){
				if (line.at(i) == ';'){
					str_dt[count_vtdt] = Xoa_khoang_trang_thua(tt_data);
					count_vtdt++;
					tt_data = " ";
				}
				else tt_data += line.at(i);
			}
			string tt_str = " ";

			if (luachon_tk != 2)
				tt_str = Chuyenchuhoathanhchuthuong(str_dt[luachon_tk]);
			else
				tt_str = Chuyenchuhoathanhchuthuong(str_dt[4]);

			int x = tt_str.find(str);
			if (x >= 0){
				kht_tk[count_line][0].SetNoiDung(to_string(count_line));
				kht_tk[count_line][0].AddNoidung();
				for (int i = 0; i < 6; i++){
					kht_tk[count_line][i + 1].SetNoiDung(str_dt[i]);
					kht_tk[count_line][i + 1].AddNoidung();
				}
				count_line++;
			}
		}
	}
	f.close();
}

void Thucthi_Timkiem_khachhang(){
	char kk = 13;
	while (kk != 27){
		if (kk == 13)
			Hien_thi_timkiem_khachhang();
		kk = _getch();
	}
}

DT_khachhang Madg_Timkiem_dg(string t_madg){
	DT_khachhang dt_khachhang;
	fstream f;
	f.open(qldg_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	int count_line = 1, count_vtdt = 0;
	string str = Xoa_khoang_trang_thua(t_madg);
	str = Chuyenchuhoathanhchuthuong(str);
	while (!f.eof()){
		getline(f, line);
		if (line.length() > 1){
			tt_data = " ";
			count_vtdt = 0;
			for (int i = 0; i < line.length(); i++){
				if (line.at(i) == ';'){
					str_dt[count_vtdt] = Xoa_khoang_trang_thua(tt_data);
					count_vtdt++;
					tt_data = " ";
				}
				else tt_data += line.at(i);
			}
			string tt_str = " ";
			tt_str = Chuyenchuhoathanhchuthuong(str_dt[0]);

			if (tt_str == str){
				dt_khachhang.Set_ma_dg(str_dt[0]);
				dt_khachhang.Set_hoten(str_dt[1]);
				dt_khachhang.Set_gioitinh(str_dt[3]);
				dt_khachhang.Set_sdt(str_dt[4]);
				dt_khachhang.Set_trangthai(str_dt[5]);
				dt_khachhang.Set_ngaysinh(chuyen_str_to_date(str_dt[2]));
				break;
			}
		}
	}
	f.close();
	return dt_khachhang;
}

int Xoa_khachhang(){
	textcolor(WHITE);
	SetBGColor(0);
	DT_khachhang dt_khachhang;
	int flag_exit = 0;
	Khunghienthi xs_lcht1, xs_lcht2;
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY ĐAT PHONG KHACH SAN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 18 / 2);
	cout << "GIAO DIEN XOA KHACH HANG" << endl;
	Khunghienthi sx_kht[50][50];
	int sx_sh = 0, sx_sc = 0;
	string danhmuc_hang[10] = { "MA SO KHACH HANG:" };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20,45 };
	int vt_hang[10] = { 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(sx_kht, sx_sh, sx_sc);

	gotoxy(30, 35);

	xs_lcht1.SetToaDo(32, 35 - 12);
	xs_lcht1.SetKichThuoc(3, 20);
	xs_lcht1.SetBackground(0);
	xs_lcht1.SetNoiDung("XOA");
	xs_lcht1.DrawKhunghienthi();

	xs_lcht2.SetToaDo(32, 35 + 12);
	xs_lcht2.SetKichThuoc(3, 20);
	xs_lcht2.SetBackground(0);
	xs_lcht2.SetNoiDung("HUY");
	xs_lcht2.DrawKhunghienthi();

	gotoxy(35, 35);
	cout << "SU DUNG PHIM CTRL + S DE XOA!" << endl;
	gotoxy(36, 35);
	cout << "SU DUNG PHIM ESC DE THOAT!" << endl;

	gotoxy(14, 17);
	cout << "MA SO KHACH HANG: ";
	gotoxy(16, 17);
	cout << "HO TEN KHACH HANG: ";
	gotoxy(18, 17);
	cout << "NGAY SINH: ";
	gotoxy(20, 17);
	cout << "SDT: ";
	gotoxy(22, 17);
	cout << "GIOI TINH: ";
	gotoxy(24, 17);
	cout << "TRANG THAI: ";

	string str_ma_dg = " ";
	Show_point(true);
	gotoxy(38, 35);
	cout << "                    " << endl;
	gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
	while (!flag_exit){
		//Show_point(false);
		Show_point(true);
		char kk = _getch();
		xs_lcht1.Doinen(0);
		xs_lcht2.Doinen(0);
		gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
		if (30 < kk && kk < 122){
			str_ma_dg.push_back(kk);
			cout << str_ma_dg;
		}
		if (kk == 8) {
			if (!str_ma_dg.empty()){
				str_ma_dg.pop_back();
			}
			for (int i = 0; i < str_ma_dg.length() + 2; i++){
				cout << " ";
			}
			gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
			cout << str_ma_dg;
		}

		Show_point(false);

		if (kk == 13){
			str_ma_dg = Xoa_khoang_trang_thua(str_ma_dg);
			dt_khachhang = Madg_Timkiem_dg(str_ma_dg);
			if (dt_khachhang.Get_ma_dg() != " "){
				cout << dt_khachhang.Get_ma_dg();
				gotoxy(16, 17 + 17);
				cout << dt_khachhang.Get_hoten();
				gotoxy(18, 17 + 17);
				cout << chuyen_date_to_str(dt_khachhang.Get_ngaysinh());
				gotoxy(20, 17 + 17);
				cout << dt_khachhang.Get_sdt();
				gotoxy(22, 17 + 17);
				cout << dt_khachhang.Get_gioitinh();
				gotoxy(24, 17 + 17);
				cout << dt_khachhang.Get_trangthai();
			}
			else{
				gotoxy(14, 17 + 17);
				cout << "                      ";
				gotoxy(16, 17 + 17);
				cout << "                      ";
				gotoxy(18, 17 + 17);
				cout << "                      ";
				gotoxy(20, 17 + 17);
				cout << "                      ";
				gotoxy(22, 17 + 17);
				cout << "                      ";
				gotoxy(24, 17 + 17);
				cout << "                      ";
				gotoxy(26, 17 + 17);
				cout << "                      ";
				dt_khachhang.Set_ma_dg(" ");
			}
			gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
		}
		if (kk == 19){
			int vt_lcht = 0;
			xs_lcht1.Doinen(2);

			while (1){
				char t_kk = _getch();
				if (t_kk == -32){
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77){
						if (vt_lcht == 0){
							vt_lcht = 1;
							xs_lcht1.Doinen(0);
							xs_lcht2.Doinen(2);
						}
						else{
							vt_lcht = 0;
							xs_lcht1.Doinen(2);
							xs_lcht2.Doinen(0);
						}
					}
				}
				if (t_kk == 13){
					if (vt_lcht == 0){
						if (dt_khachhang.Get_ma_dg() != " "){
							Xoadoituongtrongfile(qldg_file_name, dt_khachhang.Get_ma_dg());
							gotoxy(38, 35);
							cout << "BAN DA LUU!" << endl;
							flag_exit = 1;
						}
					}
					if (vt_lcht == 1){
						gotoxy(38, 35);
						cout << "BAN DA HUY" << endl;
						flag_exit = 0;
					}
					break;
				}
				if (t_kk == 27){
					return 1;
				}
			}
			SetBGColor(0);
			gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
		}
		if (kk == 27){
			return 1;
		}
	}
	Show_point(false);
	return 0;
}

void Sua_thongtin_khachhang(){
	textcolor(WHITE);
	SetBGColor(0);
	DT_khachhang dt_khachhang;
	int flag_exit = 0;
	Khunghienthi stt_lcht1, stt_lcht2;
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY ĐAT PHONG KHACH SAN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 32 / 2);
	cout << "GIAO DIEN SUA THONG TIN KHACH HANG" << endl;
	string danhmuc_hang[10] = { "MA SO: ", "HO TEN: ", "NGAY SINH: ", "GIOI TINH: ", "SDT: ", "TRANG THAI: " };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20,45 };
	int vt_hang[10] = { 5, 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht3_dg, sh3_dg, sc3_dg);

	gotoxy(23, 90);
	cout << "BAN THUE, LUU VA THOAT?" << endl;

	stt_lcht1.SetToaDo(25, 80);
	stt_lcht1.SetKichThuoc(3, 20);
	stt_lcht1.SetBackground(0);
	stt_lcht1.SetNoiDung("LUU!");
	stt_lcht1.DrawKhunghienthi();

	stt_lcht1.SetToaDo(25, 105);
	stt_lcht1.SetKichThuoc(3, 20);
	stt_lcht1.SetBackground(0);
	stt_lcht1.SetNoiDung("EXIT!");
	stt_lcht1.DrawKhunghienthi();

	gotoxy(30, 90);
	cout << "SU DUNG PHIM CTRL + S DE LUU!" << endl;
	gotoxy(31, 90);
	cout << "SU DUNG PHIM ESC DE THOAT!" << endl;
}