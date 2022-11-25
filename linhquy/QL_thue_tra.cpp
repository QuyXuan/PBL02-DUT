#include "Ql_thue_tra.h"


//thue phong
Khunghienthi mt_kht[50][50];
Khunghienthi mt_lcht1, mt_lcht2;
int mt_sh_m = 0, mt_sc_m = 0;
//Tra phong
Khunghienthi mt_kht_tra[50][50];
Khunghienthi mt_lcht1_tra, mt_lcht2_tra;
int mt_sh_t = 0, mt_sc_t = 0;
//thue tra
Khunghienthi kht2_mt[50][50];
int sh2_mt, sc2_mt;
//khach hang qua han
Khunghienthi kht3_mt[50][50];
int sh3_mt, sc3_mt;
//phong qua han
Khunghienthi kht4_mt[50][50];
int sh4_mt, sc4_mt;
/******************************************/
string mt_qls_file_name = "Ql_tt_phong_thue_tra.txt";
/************************************/
void Khung_Ql_thue_phong()
{
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi mt_htmain(0, 10, 41, 120, 0, 0);
	mt_htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 20 / 2);
	cout << "GIAO DIEN THUE PHONG" << endl;
	/**********************************************************/

	string danhmuc_hang[10] = { "MA SO PHONG: ",
									 "MA KHACH HANG: ",
									 "NGAY TRA: ",
									 "NGAY THUE: " };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20,45 };
	int vt_hang[10] = { 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(mt_kht, mt_sh_m, mt_sc_m);

	gotoxy(30, 35);
	cout << "BAN THUE, LUU VA THOAT?" << endl;

	mt_lcht1.SetToaDo(32, 35 - 12);
	mt_lcht1.SetKichThuoc(3, 20);
	mt_lcht1.SetBackground(0);
	mt_lcht1.SetNoiDung("LUU!");
	mt_lcht1.DrawKhunghienthi();

	mt_lcht2.SetToaDo(32, 35 + 12);
	mt_lcht2.SetKichThuoc(3, 20);
	mt_lcht2.SetBackground(0);
	mt_lcht2.SetNoiDung("HUY!");
	mt_lcht2.DrawKhunghienthi();

	gotoxy(35, 35);
	cout << "SU DUNG PHIM CTRL + S DE LUU!" << endl;
	gotoxy(36, 35);
	cout << "SU DUNG PHIM ESC DE THOAT!" << endl;
}

int Xuly_Ql_thue_phong(){
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0;
	for (int i = 0; i < mt_sh_m; i++){
		dien_x[i] = mt_kht[i][1].Get0x() + 2;
		dien_y[i] = mt_kht[i][1].Get0y() + 5 / 2;
		str[i] = " ";
	}
	str[mt_sh_m - 1] = Get_thoi_Gian_Thuc();
	gotoxy(dien_y[mt_sh_m - 1], dien_x[mt_sh_m - 1]);
	cout << str[mt_sh_m - 1] << endl;

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
		mt_lcht1.Doinen(0);
		mt_lcht2.Doinen(0);
		gotoxy(38, 35);
		cout << "                           " << endl;

		if (kk == -32){
			char cc = _getch();
			if (cc == 80){
				tt_cnt++;
				if (tt_cnt > 2) tt_cnt = 0;
			}
			if (cc == 72){
				tt_cnt--;
				if (tt_cnt < 0) tt_cnt = 2;
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (30 < kk && kk < 122){
			if (tt_cnt != 2) {
				str[tt_cnt].push_back(kk);
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				cout << str[tt_cnt];
				Show_point(true);
			}
			else{
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				str[2] = Suadate3(kk, str[2]);
				tt_cnt++;
				if (tt_cnt > 2) tt_cnt = 0;
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
			if (tt_cnt > 2) tt_cnt = 0;
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

		}
		if (kk == 19){
			int vt_lcht = 0;
			mt_lcht1.Doinen(2);

			while (1){
				Show_point(false);
				char t_kk = _getch();
				if (t_kk == -32){
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77){
						if (vt_lcht == 0){
							vt_lcht = 1;
							mt_lcht1.Doinen(0);
							mt_lcht2.Doinen(2);
						}
						else{
							vt_lcht = 0;
							mt_lcht1.Doinen(2);
							mt_lcht2.Doinen(0);
						}
					}
				}
				if (t_kk == 13){
					if (vt_lcht == 0){
						DT_phong tdt_phong = Maphong_Timkiem_phong(str[0]);
						DT_khachhang tdt_khachhang = Madg_Timkiem_dg(str[1]);
						if (tdt_phong.Get_ma_phong() != " " && tdt_khachhang.Get_ma_dg() != " "){
							string kq = Get_trangthaiphong("Ql_tt_phong.txt", tdt_phong.Get_ma_phong());
							if (kq == "OK"){
								textcolor(WHITE);
								string tt_phong = "";
								for (int i = 0; i < mt_sh_m; i++){
									tt_phong += (str[i] + " ; ");
								}
								tt_phong += "\n";
								//them bien static so luong phong thue
								Ghifile(mt_qls_file_name, tt_phong);
								Suadoitrangthaiphong("Ql_tt_phong.txt", tdt_phong.Get_ma_phong(), "BUSY");
								gotoxy(38, 35);
								cout << "BAN DA LUU!" << endl;
								flag_exit = 1;
							}
							else{
								gotoxy(38, 35);
								cout << "PHONG KHONG SAN SANG THUE!" << endl;
								flag_exit = 0;
							}
						}
						else{
							gotoxy(38, 35);
							cout << "MA PHONG HOAC MA KHACH HANG SAI!" << endl;
							flag_exit = 0;
						}

					}
					if (vt_lcht == 1){
						gotoxy(38, 35);
						cout << "BAN DA HUY!" << endl;
						flag_exit = 0;
					}
					break;
				}
				if (t_kk == 27)
				{
					return 1;
				}
			}
			SetBGColor(0);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (kk == 27)
		{
			return 1;
		}
	}
	return 0;
}

/************************************/
void Khung_Ql_tra_phong(){
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi mt_htmain(0, 10, 41, 120, 0, 0);
	mt_htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 20 / 2);
	cout << "GIAO DIEN TRA PHONG" << endl;
	/**********************************************************/

	string danhmuc_hang[10] = { "MA SO PHONG: ",
									 "MA KHACH HANG: ",
									 "NGAY TRA: ",
									 "NGAY THUE: " };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20,45 };
	int vt_hang[10] = { 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(mt_kht_tra, mt_sh_t, mt_sc_t);

	gotoxy(30, 35);
	cout << "BAN THUE, LUU VA THOAT?" << endl;

	mt_lcht1_tra.SetToaDo(32, 35 - 12);
	mt_lcht1_tra.SetKichThuoc(3, 20);
	mt_lcht1_tra.SetBackground(0);
	mt_lcht1_tra.SetNoiDung("LUU!");
	mt_lcht1_tra.DrawKhunghienthi();

	mt_lcht2_tra.SetToaDo(32, 35 + 12);
	mt_lcht2_tra.SetKichThuoc(3, 20);
	mt_lcht2_tra.SetBackground(0);
	mt_lcht2_tra.SetNoiDung("HUY!");
	mt_lcht2_tra.DrawKhunghienthi();

	gotoxy(35, 35);
	cout << "SU DUNG PHIM CTRL + S DE LUU!" << endl;
	gotoxy(36, 35);
	cout << "SU DUNG PHIM ESC DE THOAT!" << endl;
}

int Xuly_Ql_tra_phong(){
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0;
	for (int i = 0; i < mt_sh_t; i++){
		dien_x[i] = mt_kht_tra[i][1].Get0x() + 2;
		dien_y[i] = mt_kht_tra[i][1].Get0y() + 5 / 2;
		str[i] = " ";
	}
	str[mt_sh_t - 1] = Get_thoi_Gian_Thuc();
	gotoxy(dien_y[mt_sh_t - 1], dien_x[mt_sh_t - 1]);
	cout << str[mt_sh_t - 1] << endl;

	str[2] = "  /  /    ";
	gotoxy(dien_y[2], dien_x[2]);
	cout << str[2];
	Show_point(true);
	gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

	while (!flag_exit){
		//Sleep(5);
		Show_point(true);
		char kk = _getch();
		//xoa thong bao
		mt_lcht1_tra.Doinen(0);
		mt_lcht2_tra.Doinen(0);
		gotoxy(38, 35);
		cout << "                                " << endl;
		gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		if (kk == -32){
			char t_cc = _getch();
			if (t_cc == 75 || t_cc == 77){}
		}
		if (30 < kk && kk < 122){
			str[tt_cnt].push_back(kk);
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
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
			DT_thue_tra dt_mt = Get_tt_thue_tra(str[tt_cnt]);
			if (dt_mt.Get_ma_so_phong() != " "){
				str[0] = dt_mt.Get_ma_so_phong();
				str[1] = dt_mt.Get_ma_so_dg();
				str[2] = chuyen_date_to_str(dt_mt.Get_ngay_tra());
				str[3] = chuyen_date_to_str(dt_mt.Get_ngay_thue());
				for (int i = 1; i < 4; i++){
					gotoxy(dien_y[i], dien_x[i]);
					cout << str[i];
				}
				gotoxy(38, 35);
				cout << "                   " << endl;
			}
			else{
				for (int i = 1; i < 4; i++){
					str[i] = " ";
					gotoxy(dien_y[i], dien_x[i]);
					cout << "                   ";
				}
				gotoxy(38, 35);
				cout << "MA PHONG SAI!" << endl;
			}

			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (kk == 19){
			int vt_lcht = 0;
			mt_lcht1_tra.Doinen(2);

			while (1){
				Show_point(false);
				char t_kk = _getch();
				if (t_kk == -32){
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77){
						if (vt_lcht == 0){
							vt_lcht = 1;
							mt_lcht1_tra.Doinen(0);
							mt_lcht2_tra.Doinen(2);
						}
						else{
							vt_lcht = 0;
							mt_lcht1_tra.Doinen(2);
							mt_lcht2_tra.Doinen(0);
						}
					}
				}
				if (t_kk == 13){
					if (vt_lcht == 0){
						if (str[1] != " "){
							DT_thue_tra dt_mt = Get_tt_thue_tra(str[0]);
							if (dt_mt.Get_ma_so_phong() != " "){
								Xoadoituongtrongfile(mt_qls_file_name, str[0]);
								Suadoitrangthaiphong("Ql_tt_phong.txt", str[0], "OK");
								gotoxy(38, 35);
								cout << "BAN DA LUU!" << endl;
								flag_exit = 1;
							}
							else{
								gotoxy(38, 35);
								cout << "KHONG TON TAI!" << endl;
								flag_exit = 0;
							}
						}

					}
					if (vt_lcht == 1){
						gotoxy(38, 35);
						cout << "BAN DA HUY!" << endl;
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

DT_thue_tra Get_tt_thue_tra(string t_ma_phong){
	DT_thue_tra dt_thuetra;
	fstream f;
	f.open(mt_qls_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	int count_line = 1, count_vtdt = 0;
	string str = Xoa_khoang_trang_thua(t_ma_phong);
	str = Chuyenchuhoathanhchuthuong(str);
	while (!f.eof()){
		getline(f, line);
		string t_line = Chuyenchuhoathanhchuthuong(line);
		int t_vt = t_line.find(str);
		if (t_vt >= 0){
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
				dt_thuetra.Set_ma_so_phong(str_dt[0]);
				dt_thuetra.Set_ma_so_khachhang(str_dt[1]);;
				dt_thuetra.Set_ngay_thue(chuyen_str_to_date(str_dt[3]));
				dt_thuetra.Set_ngay_tra(chuyen_str_to_date(str_dt[2]));
				break;
			}
		}
	}
	f.close();
	return dt_thuetra;
}


int value_count_mt;
void Hienthi_ds_thuetra(){
	value_count_mt = 0;
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 25 / 2);
	cout << "GIAO DIEN DANH SACH PHONG THUE TRA" << endl;
	gotoxy(0 + 5 / 2 + 2, 10 + 120 / 2 - 10 / 2);
	cout << Get_thoi_Gian_Thuc() << endl;
	/**********************************************************/
	int vt_trang = 1, sl_trang = 1;
	string danhmuc_hang[20] = { "STT", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "STT", "MA SO PHONG", "MA SO KHACH HANG", "NGAY TRA" ,"NGAY THUE" };
	int vt_cot[10] = { 8, 30, 30, 26, 26 };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 };

	int v_stt[100];
	string v_maso_phong[100], v_maso_dg[1000];
	v_date v_ngaythue[100], v_ngaytra[100];
	string data = Getfile(mt_qls_file_name);
	Table tb2(7, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht2_mt, sh2_mt, sc2_mt);

	gotoxy(38, 13 + 60 - 5);
	cout << "TRANG " << vt_trang << "/" << sl_trang << endl;
	/******************************** Xu ly data ******************************************************/

	char c;
	int cnt_hang = 0, cnt_cot = 0;
	string str_tt_mt = "", t_data;
	for (int i = 0; i < data.length(); i++){
		c = data.at(i);
		if (c == '\n'){
			value_count_mt++;
			cnt_hang++;
			kht2_mt[cnt_hang][0].SetNoiDung(to_string(value_count_mt));
			kht2_mt[cnt_hang][0].AddNoidung();
			cnt_cot = 1;
			str_tt_mt = " ";
			c = ' ';
		}
		if (c == ';'){
			t_data = Xoa_khoang_trang_thua(str_tt_mt);
			kht2_mt[cnt_hang][cnt_cot].SetNoiDung(t_data);
			kht2_mt[cnt_hang][cnt_cot].AddNoidung();
			cnt_cot++;
			str_tt_mt = " ";
		}
		else
			str_tt_mt += c;
	}

	kht2_mt[cnt_hang][0].SetNoiDung("     ");
	kht2_mt[cnt_hang][0].AddNoidung();
	gotoxy(39, 13);
	cout << "HUOGN DAN: " << cnt_hang << endl;
	while (1) {
		char kk = _getch();
		if (kk == 27)
		{
			break;
		}
	}
}

void Hienthi_ds_dg_quahan(){
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 36 / 2);
	cout << "GIAO DIEN DANH SACH PHONG, KHACH HANG QUA HAN" << endl;
	gotoxy(0 + 5 / 2 + 2, 10 + 120 / 2 - 16 / 2);
	cout << "NGAY: " << Get_thoi_Gian_Thuc() << endl;
	/**********************************************************/
	int vt_trang = 1, sl_trang = 1;
	string danhmuc_hang[20] = { "STT", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "STT", "MA SO", "HO TEN", "NGAY SINH", "GIOI TINH",
									"SDT", "TRANG THAI" };
	int vt_cot[10] = { 7, 20, 30, 15, 15, 20, 15 };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 };

	int v_stt[100];
	string v_madg, v_hoten, v_gioitinh, v_sdt, v_trangthai;
	v_date v_ngaysinh[100];

	Table tb2(7, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht3_mt, sh3_mt, sc3_mt);

	gotoxy(38, 13 + 60 - 5);
	cout << "TRANG " << vt_trang << "/" << sl_trang << endl;
	/******************************** Xu ly data *****************************************************/
	string data1[100], data2[100];
	int sl = 0, cnt_value = 0;
	Doituong_quahan(data1, data2, sl);
	for (int i = 0; i < sl; i++){
		int sl_qh = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (Xoa_khoang_trang_thua(Chuyenchuhoathanhchuthuong(data2[i])) == Xoa_khoang_trang_thua(Chuyenchuhoathanhchuthuong(data2[j]))) {
				sl_qh++;
			}
		}
		if (sl_qh == 2) {
			Suadoitrangthaikhachhang("Ql_tt_khachhang.txt", data2[i], "LOCK");
			for (int k = 1; k < cnt_value + 1; k++) {
				if (Xoa_khoang_trang_thua(Chuyenchuhoathanhchuthuong(data2[i])) == Xoa_khoang_trang_thua(Chuyenchuhoathanhchuthuong(kht3_mt[k][6].GetNoiDung()))) {
					DT_khachhang dt_dg_2 = Madg_Timkiem_dg(data2[i]);
					kht3_mt[k][6].SetNoiDung(dt_dg_2.Get_trangthai());
					kht3_mt[k][6].AddNoidung();
					break;
				}
			}
		}
		if (sl_qh == 0) {
			cnt_value++;
			DT_khachhang dt_dg = Madg_Timkiem_dg(data2[i]);
			kht3_mt[cnt_value][0].SetNoiDung(to_string(cnt_value));
			kht3_mt[cnt_value][0].AddNoidung();

			kht3_mt[cnt_value][1].SetNoiDung(dt_dg.Get_ma_dg());
			kht3_mt[cnt_value][1].AddNoidung();

			kht3_mt[cnt_value][2].SetNoiDung(dt_dg.Get_hoten());
			kht3_mt[cnt_value][2].AddNoidung();

			kht3_mt[cnt_value][3].SetNoiDung(chuyen_date_to_str(dt_dg.Get_ngaysinh()));
			kht3_mt[cnt_value][3].AddNoidung();

			kht3_mt[cnt_value][4].SetNoiDung(dt_dg.Get_gioitinh());
			kht3_mt[cnt_value][4].AddNoidung();

			kht3_mt[cnt_value][5].SetNoiDung(dt_dg.Get_sdt());
			kht3_mt[cnt_value][5].AddNoidung();

			kht3_mt[cnt_value][6].SetNoiDung(dt_dg.Get_trangthai());
			kht3_mt[cnt_value][6].AddNoidung();
		}
	}

	/************************************************************************************************/
	gotoxy(39, 13);
	cout << "HUONG DAN:" << sl - 1 << endl;
	while (1) {
		char kk = _getch();
		if (kk == 27){
			break;
		}
	}
}

void Hienthi_ds_phong_quahan()
{
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 32 / 2);
	cout << "GIAO DIEN DANH SACH PHONG QUA HAN" << endl;
	gotoxy(0 + 5 / 2 + 2, 10 + 120 / 2 - 16 / 2);
	cout << "NGAY: " << Get_thoi_Gian_Thuc() << endl;
	/**********************************************************/
	int vt_trang = 1, sl_trang = 1;
	string danhmuc_hang[20] = { "STT", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "STT", "MA PHONG", "TEN PHONG", "LOAI PHONG", "DON GIA",
									"NAM", "TRANG THAI", "VI TRI" };
	int vt_cot[10] = { 7, 12, 30, 20, 20, 10, 14, 10 };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 };

	int v_stt[100], v_nam_xb[100];
	string v_maphong, v_ten_phong, v_ten_tg, v_ten_nxb, v_trangthai, v_vitri;

	Table tb2(7, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht4_mt, sh4_mt, sc4_mt);

	gotoxy(38, 13 + 60 - 5);
	cout << "TRANG " << vt_trang << "/" << sl_trang << endl;
	/******************************** Xu ly data *****************************************************/
	string data1[100], data2[100];
	int sl, sl_dt = 1;
	Doituong_quahan(data1, data2, sl);
	char c;
	for (int i = 0; i < sl; i++){
		DT_phong dt_phong = Maphong_Timkiem_phong(data1[i]);
		if (dt_phong.Get_ma_phong() != " "){
			kht4_mt[sl_dt][0].SetNoiDung(to_string(sl_dt));
			kht4_mt[sl_dt][0].AddNoidung();

			kht4_mt[sl_dt][1].SetNoiDung(dt_phong.Get_ma_phong());
			kht4_mt[sl_dt][1].AddNoidung();

			kht4_mt[sl_dt][2].SetNoiDung(dt_phong.Get_ten_phong());
			kht4_mt[sl_dt][2].AddNoidung();

			kht4_mt[sl_dt][3].SetNoiDung(dt_phong.Get_kieu_phong());
			kht4_mt[sl_dt][3].AddNoidung();

			kht4_mt[sl_dt][4].SetNoiDung(dt_phong.Get_gia_phong());
			kht4_mt[sl_dt][4].AddNoidung();

			kht4_mt[sl_dt][5].SetNoiDung(to_string(dt_phong.Get_nam()));
			kht4_mt[sl_dt][5].AddNoidung();

			kht4_mt[sl_dt][6].SetNoiDung(dt_phong.Get_trang_thai());
			kht4_mt[sl_dt][6].AddNoidung();

			kht4_mt[sl_dt][7].SetNoiDung(dt_phong.Get_vi_tri());
			kht4_mt[sl_dt][7].AddNoidung();
			sl_dt++;
		}
	}


	/************************************************************************************************/
	gotoxy(39, 13);
	cout << "HUONG DAN:" << sl << endl;
	while (1) {
		char kk = _getch();
		if (kk == 27){
			break;
		}
	}
}

void Doituong_quahan(string* mss, string* msdg, int& sl_dt){
	sl_dt = 0;
	fstream f;
	f.open(mt_qls_file_name, ios::in);
	string line;
	string data;
	while (!f.eof()){
		getline(f, line);
		if (line.length() > 0){
			int doan[10];
			int cnt_phay = 0;
			for (int i = 0; i < line.length(); i++){
				if (line.at(i) == ';'){
					doan[cnt_phay] = i;
					cnt_phay++;
				}
			}
			data = line.substr(doan[1] + 2, doan[2] - doan[1] - 3);
			string t_data = " ";
			for (int i = 0; i < data.length(); i++){
				if (data.at(i) == ' ')
					t_data += "0";
				else
					t_data += data.at(i);
			}
			v_date tg_tra = chuyen_str_to_date(t_data);
			if (!Kiem_quahan(tg_tra)){
				mss[sl_dt] = Xoa_khoang_trang_thua(line.substr(1, doan[0] - 1));
				msdg[sl_dt] = Xoa_khoang_trang_thua(line.substr(doan[0] + 1, doan[1] - doan[0] - 1));
				sl_dt++;
			}
		}
	}
	f.close();
}