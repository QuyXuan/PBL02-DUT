
#include "Ql_phong.h"
#include "fstream"

/************ Them phong ***************/
Khunghienthi kht[50][50];
Khunghienthi lcht1, lcht2;
int sh = 0, sc = 0;
/*********** Hien thi ds **************/
Khunghienthi kht2[50][50];
int sh2 = 0, sc2 = 0;
int so_luong_phong = 0, value_count = 0;
/************* sua thong tin *********/
Khunghienthi kht3[50][50];
int stt_sh = 0, stt_sc = 0;
/*************************************/
string qls_file_name = "Ql_tt_phong.txt";
/************************************/
void Khung_Ql_phong_Them_phong() {
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 20 / 2);
	cout << "GIAO DIEN THEM PHONG" << endl;
	/**********************************************************/

	string danhmuc_hang[10] = { "MA PHONG: ",
								"TEN PHONG: ",
								"LOAI PHONG",
								"DON GIA",
								"NAM:",
								"TRANG THAI",
								"VI TRI" };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 15,50 };
	int vt_hang[10] = { 5, 5, 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht, sh, sc);

	gotoxy(23, 90);
	cout << "BAN THUE, LUU VA THOAT?" << endl;

	lcht1.SetToaDo(25, 80);
	lcht1.SetKichThuoc(3, 20);
	lcht1.SetBackground(0);
	lcht1.SetNoiDung("LUU!");
	lcht1.DrawKhunghienthi();

	lcht2.SetToaDo(25, 105);
	lcht2.SetKichThuoc(3, 20);
	lcht2.SetBackground(0);
	lcht2.SetNoiDung("HUY!");
	lcht2.DrawKhunghienthi();

	gotoxy(30, 90);
	cout << "SU DUNG PHIM CTRL + S DE LUU!" << endl;
	gotoxy(31, 90);
	cout << "SU DUNG PHIM ESC DE THOAT!" << endl;
}

int Xuly_Ql_phong_Them_phong()
{
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0;

	for (int i = 0; i < sh; i++)
	{
		dien_x[i] = kht[i][1].Get0x() + 2;
		dien_y[i] = kht[i][1].Get0y() + 5 / 2;
		str[i] = " ";
	}
	Show_point(true);
	gotoxy(dien_y[0], dien_x[0]);

	while (!flag_exit)
	{
		//Sleep(5);
		Show_point(true);
		char kk = _getch();
		//xoa thong bao
		lcht1.Doinen(0);
		lcht2.Doinen(0);
		gotoxy(33, 90);
		cout << "                           " << endl;

		if (kk == -32)
		{
			char cc = _getch();
			if (cc == 80)
			{
				tt_cnt++;
				if (tt_cnt > 6) tt_cnt = 0;
			}
			if (cc == 72)
			{
				tt_cnt--;
				if (tt_cnt < 0) tt_cnt = 6;
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (30 < kk && kk < 122)
		{
			str[tt_cnt].push_back(kk);
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}

		if (kk == 8)
		{
			if (!str[tt_cnt].empty())
			{
				str[tt_cnt].pop_back();
			}
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			for (int i = 0; i < str[tt_cnt].length() + 2; i++)
			{
				cout << " ";
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}

		if (kk == 13)
		{
			tt_cnt++;
			if (tt_cnt > 6) tt_cnt = 0;
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

		}
		if (kk == 19)
		{
			int vt_lcht = 0;
			lcht1.Doinen(2);

			while (1)
			{
				Show_point(false);
				char t_kk = _getch();
				if (t_kk == -32)
				{
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77)
					{
						if (vt_lcht == 0)
						{
							vt_lcht = 1;
							lcht1.Doinen(0);
							lcht2.Doinen(2);
						}
						else
						{
							vt_lcht = 0;
							lcht1.Doinen(2);
							lcht2.Doinen(0);
						}
					}
				}
				if (t_kk == 13)
				{
					if (vt_lcht == 0)
					{
						for (int i = 0; i < sh; i++)
						{
							kht[i][1].SetNoiDung(str[i]);
						}
						textcolor(WHITE);
						string tt_phong = kht[0][1].GetNoiDung() + " ; "
							+ kht[1][1].GetNoiDung() + " ; "
							+ kht[2][1].GetNoiDung() + " ; "
							+ kht[3][1].GetNoiDung() + " ; "
							+ kht[4][1].GetNoiDung() + " ; "
							+ kht[5][1].GetNoiDung() + " ; "
							+ kht[6][1].GetNoiDung() + " ; \n ";
						//them bien static so luong phong
						Ghifile(qls_file_name, tt_phong);
						gotoxy(33, 90);
						cout << "BAN DA LUU!" << endl;
						flag_exit = 1;
					}
					if (vt_lcht == 1)
					{
						gotoxy(33, 90);
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

void Hienthi_Ql_phong_ds()
{
	value_count = 0;
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 20 / 2);
	cout << "GIAO DIEN DANH SACH PHONG" << endl;
	/**********************************************************/
	int vt_trang = 1, sl_trang = 1;
	string danhmuc_hang[20] = { "STT", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "STT", "MA PHONG", "TEN PHONG", "LOAI PHONG", "DON GIA",
									"NAM", "TRANG THAI", "VI TRI" };
	int vt_cot[10] = { 7, 12, 30, 20, 20, 10, 14, 10 };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 };

	int v_stt[100], v_nam_xb[100];
	string v_maphong[100], v_ten_phong[1000], v_ten_tg[100], v_ten_nxb[100], v_trangthai[100], v_vitri[100];

	string data = Getfile("Ql_tt_phong.txt");

	Table tb2(7, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht2, sh2, sc2);

	gotoxy(38, 13 + 60 - 5);
	cout << "TRANG " << vt_trang << "/" << sl_trang << endl;
	/******************************** Xu ly data *****************************************************/

	char c;
	int cnt_hang = 0, cnt_cot = 0;
	string str_tt_phong = "", t_data;
	for (int i = 0; i < data.length(); i++)
	{
		c = data.at(i);

		if (c == '\n')
		{
			so_luong_phong++;
			value_count++;
			cnt_hang++;

			kht2[cnt_hang][0].SetNoiDung(to_string(value_count));
			kht2[cnt_hang][0].AddNoidung();

			cnt_cot = 1;
			str_tt_phong = "";
			c = ' ';
		}

		if (c == ';')
		{
			t_data = Xoa_khoang_trang_thua(str_tt_phong);
			kht2[cnt_hang][cnt_cot].SetNoiDung(t_data);
			kht2[cnt_hang][cnt_cot].AddNoidung();
			cnt_cot++;
			str_tt_phong = "";
		}
		else
			str_tt_phong += c;
	}

	kht2[cnt_hang][0].SetNoiDung("   ");
	kht2[cnt_hang][0].AddNoidung();

	gotoxy(39, 13);
	cout << "SO LUONG:" << cnt_hang - 1 << endl;
	while (1) {
		char kk = _getch();
		if (kk == 27)
		{
			break;
		}
	}
}

void Hienthi_Timkiem_phong()
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
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 23 / 2);
	cout << "GIAO DIEN TIM KIEM PHONG" << endl;
	/**********************************************************/
#define sl_tk 3

	int vt_trang = 1, sl_trang = 1;
	Khunghienthi tk_htlc[sl_tk];
	string danhmuc_tk_htlc[sl_tk] = { "TIM KIEM MA PHONG",
										  "TIM KIEM TEN PHONG",
										  "TIM KIEM LOAI PHONG" };
	for (int i = 0; i < sl_tk; i++)
	{
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

	string danhmuc_hang[20] = { "STT", " ", " ", " ", " ", " ", " ", " ", " ", " "," " };
	string danhmuc_cot[10] = { "STT", "MA PHONG", "TEN PHONG", "LOAI PHONG", "DON GIA",
									"NAM", "TRANG THAI", "VI TRI" };
	int vt_cot[10] = { 7, 12, 30, 20, 20, 10, 14, 10 };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3,3 };

	Khunghienthi kht_tk[50][50];

	Table tb2(15, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht_tk);

	textcolor(WHITE);

	int luachon_tk = 0;
	tk_htlc[luachon_tk].Doinen(2);
	while (1)
	{
		Show_point(false);
		char t_kk = _getch();
		if (t_kk == -32)
		{
			char t_cc = _getch();
			if (t_cc == 75)
			{
				tk_htlc[luachon_tk].Doinen(0);
				luachon_tk--;
				if (luachon_tk < 0) luachon_tk = sl_tk - 1;
				tk_htlc[luachon_tk].Doinen(2);
			}
			if (t_cc == 77)
			{
				tk_htlc[luachon_tk].Doinen(0);
				luachon_tk++;
				if (luachon_tk == sl_tk) luachon_tk = 0;
				tk_htlc[luachon_tk].Doinen(2);
			}
		}
		if (t_kk == 13)
		{
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
	while (1)
	{
		//Show_point(false);
		char kk = _getch();
		Show_point(false);

		if (30 < kk && kk < 122)
		{
			str.push_back(kk);
			gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
			cout << str;
		}

		if (kk == 8)
		{
			if (!str.empty())
			{
				str.pop_back();
			}
			for (int i = 0; i < str.length() + 2; i++)
			{
				cout << " ";
			}
			gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
			cout << str;
		}

		Show_point(true);

		if (kk == 13)
		{
			break;
		}
	}

	str = Xoa_khoang_trang_thua(str);
	str = Chuyenchuhoathanhchuthuong(str);
	gotoxy(38, 13 + 60 - 5);
	cout << "TRANG " << vt_trang << "/" << sl_trang << endl;
	/*********************************************************************************************/
	Show_point(false);
	fstream f;
	f.open(qls_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	int count_line = 1, count_vtdt = 0;
	while (!f.eof())
	{
		getline(f, line);
		if (line.length() > 1)
		{
			tt_data = " ";
			count_vtdt = 0;
			for (int i = 0; i < line.length(); i++)
			{
				if (line.at(i) == ';')
				{
					str_dt[count_vtdt] = Xoa_khoang_trang_thua(tt_data);
					count_vtdt++;
					tt_data = " ";
				}
				else tt_data += line.at(i);
			}
			string tt_str = " ";
			tt_str = Chuyenchuhoathanhchuthuong(str_dt[luachon_tk]);

			int x = tt_str.find(str);
			if (x >= 0)
			{
				kht_tk[count_line][0].SetNoiDung(to_string(count_line));
				kht_tk[count_line][0].AddNoidung();
				for (int i = 0; i < 7; i++)
				{
					kht_tk[count_line][i + 1].SetNoiDung(str_dt[i]);
					kht_tk[count_line][i + 1].AddNoidung();
				}
				count_line++;
			}
		}
	}
	f.close();

}

void Thucthi_Timkiem_phong()
{
	char kk = 13;
	while (kk != 27)
	{
		if (kk == 13)
			Hienthi_Timkiem_phong();
		kk = _getch();
	}
}

DT_phong Maphong_Timkiem_phong(string t_maphong)
{
	DT_phong t_phong;
	fstream f;
	f.open(qls_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	int count_line = 1, count_vtdt = 0;
	string str = Xoa_khoang_trang_thua(t_maphong);
	str = Chuyenchuhoathanhchuthuong(str);
	while (!f.eof())
	{
		getline(f, line);
		if (line.length() > 1)
		{
			tt_data = " ";
			count_vtdt = 0;
			for (int i = 0; i < line.length(); i++)
			{
				if (line.at(i) == ';')
				{
					str_dt[count_vtdt] = Xoa_khoang_trang_thua(tt_data);
					count_vtdt++;
					tt_data = " ";
				}
				else tt_data += line.at(i);
			}
			string tt_str = " ";
			tt_str = Chuyenchuhoathanhchuthuong(str_dt[0]);

			if (tt_str == str)
			{
				t_phong.Set_ma_phong(str_dt[0]);
				t_phong.Set_ten_phong(str_dt[1]);
				t_phong.Set_kieu_phong(str_dt[2]);
				t_phong.Set_gia_phong(str_dt[3]);
				t_phong.Set_nam(str_dt[4]);
				t_phong.Set_trang_thai(str_dt[5]);
				t_phong.Set_vi_tri(str_dt[6]);
				break;
			}
		}
	}
	f.close();
	return t_phong;
}

int Xoa_phong()
{
	textcolor(WHITE);
	SetBGColor(0);
	DT_phong dt_phong;
	int flag_exit = 0;
	Khunghienthi xs_lcht1, xs_lcht2;
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 23 / 2);
	cout << "GIAO DIEN XOA PHONG" << endl;
	/**************************************************************************/
	Khunghienthi sx_kht[50][50];
	int sx_sh = 0, sx_sc = 0;
	string danhmuc_hang[10] = { "MA SO PHONG:" };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20,45 };
	int vt_hang[10] = { 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(sx_kht, sx_sh, sx_sc);

	gotoxy(30, 35);
	cout << "BAN THUE, XOA?" << endl;

	xs_lcht1.SetToaDo(32, 35 - 12);
	xs_lcht1.SetKichThuoc(3, 20);
	xs_lcht1.SetBackground(0);
	xs_lcht1.SetNoiDung("XOA!");
	xs_lcht1.DrawKhunghienthi();

	xs_lcht2.SetToaDo(32, 35 + 12);
	xs_lcht2.SetKichThuoc(3, 20);
	xs_lcht2.SetBackground(0);
	xs_lcht2.SetNoiDung("HUY!");
	xs_lcht2.DrawKhunghienthi();

	gotoxy(35, 35);
	cout << "SU DUNG PHIM CTRL + S DE XOA!" << endl;
	gotoxy(36, 35);
	cout << "SU DUNG PHIM ESC DE THOAT!" << endl;

	gotoxy(14, 17);
	cout << "MA SO PHONG: ";
	gotoxy(16, 17);
	cout << "TEN PHONG: ";
	gotoxy(18, 17);
	cout << "LOAI PHONG: ";
	gotoxy(20, 17);
	cout << "DON GIA: ";
	gotoxy(22, 17);
	cout << "NAM:";
	gotoxy(24, 17);
	cout << "TRANG THAI: ";
	gotoxy(26, 17);
	cout << "VI TRI: ";

	string str_ma_phong = " ";
	Show_point(true);
	gotoxy(38, 35);
	cout << "                    " << endl;
	gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
	while (!flag_exit)
	{
		//Show_point(false);
		Show_point(true);
		char kk = _getch();
		xs_lcht1.Doinen(0);
		xs_lcht2.Doinen(0);
		gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
		if (30 < kk && kk < 122)
		{
			str_ma_phong.push_back(kk);
			cout << str_ma_phong;
		}

		if (kk == 8)
		{
			if (!str_ma_phong.empty())
			{
				str_ma_phong.pop_back();
			}
			for (int i = 0; i < str_ma_phong.length() + 2; i++)
			{
				cout << " ";
			}
			gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
			cout << str_ma_phong;
		}

		Show_point(false);

		if (kk == 13)
		{
			str_ma_phong = Xoa_khoang_trang_thua(str_ma_phong);
			dt_phong = Maphong_Timkiem_phong(str_ma_phong);
			if (dt_phong.Get_ma_phong() != " ")
			{
				gotoxy(14, 17 + 17);
				cout << dt_phong.Get_ma_phong();
				gotoxy(16, 17 + 17);
				cout << dt_phong.Get_ten_phong();
				gotoxy(18, 17 + 17);
				cout << dt_phong.Get_kieu_phong();
				gotoxy(20, 17 + 17);
				cout << dt_phong.Get_gia_phong();
				gotoxy(22, 17 + 17);
				cout << dt_phong.Get_nam();
				gotoxy(24, 17 + 17);
				cout << dt_phong.Get_trang_thai();
				gotoxy(26, 17 + 17);
				cout << dt_phong.Get_vi_tri();
			}
			else
			{
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
				dt_phong.Set_ma_phong(" ");
			}
			gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
		}
		if (kk == 19)
		{
			int vt_lcht = 0;
			xs_lcht1.Doinen(2);

			while (1)
			{
				char t_kk = _getch();
				if (t_kk == -32)
				{
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77)
					{
						if (vt_lcht == 0)
						{
							vt_lcht = 1;
							xs_lcht1.Doinen(0);
							xs_lcht2.Doinen(2);
						}
						else
						{
							vt_lcht = 0;
							xs_lcht1.Doinen(2);
							xs_lcht2.Doinen(0);
						}
					}
				}
				if (t_kk == 13)
				{
					if (vt_lcht == 0)
					{
						if (dt_phong.Get_ma_phong() != " ")
						{
							Xoadoituongtrongfile(qls_file_name, dt_phong.Get_ma_phong());
							gotoxy(38, 35);
							cout << "BAN DA LUU!" << endl;
							flag_exit = 1;
						}

					}
					if (vt_lcht == 1)
					{
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
			gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
		}
		if (kk == 27)
		{
			return 1;
		}
	}
	Show_point(false);
	return 0;
}

void Sua_thongtin_phong()
{
	textcolor(WHITE);
	SetBGColor(0);
	DT_phong dt_phong;
	Khunghienthi stt_lcht1, stt_lcht2;
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "CHUONG TRINH QUAN LY THUE PHONG" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	cout << "XUAN QUY - HOANG LINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 29 / 2);
	cout << "GIAO DIEN SUA THONG TIN PHONG" << endl;
	/**********************************************************/

	string danhmuc_hang[10] = { "MA PHONG: ",
									"TEN PHONG: ",
									"LOAI PHONG: ",
									"DON GIA: ",
									"NAM: ",
									"TRANG THAI: ",
									"VI TRI: " };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 15,50 };
	int vt_hang[10] = { 5, 5, 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht3, stt_sh, stt_sc);

	gotoxy(23, 90);
	cout << "BAN THUE, LUU VA THOAT?" << endl;

	stt_lcht1.SetToaDo(25, 80);
	stt_lcht1.SetKichThuoc(3, 20);
	stt_lcht1.SetBackground(0);
	stt_lcht1.SetNoiDung("LUU!");
	stt_lcht1.DrawKhunghienthi();

	stt_lcht2.SetToaDo(25, 105);
	stt_lcht2.SetKichThuoc(3, 20);
	stt_lcht2.SetBackground(0);
	stt_lcht2.SetNoiDung("HUY!");
	stt_lcht2.DrawKhunghienthi();

	gotoxy(30, 90);
	cout << "SU DUNG PHIM CTRL + S DE LUU!" << endl;
	gotoxy(31, 90);
	cout << "SU DUNG PHIM ESC DE THOAT!" << endl;
	/*******************************************************/
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0, step = 0;

	for (int i = 0; i < stt_sh; i++)
	{
		dien_x[i] = kht3[i][1].Get0x() + 2;
		dien_y[i] = kht3[i][1].Get0y() + 5 / 2;
		str[i] = "";
	}
	Show_point(true);
	gotoxy(dien_y[0], dien_x[0]);
	while (!flag_exit)
	{
		Show_point(true);
		gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		cout << str[tt_cnt];

		char kk = _getch();
		//xoa thong bao
		stt_lcht1.Doinen(0);
		stt_lcht2.Doinen(0);
		gotoxy(33, 90);
		cout << "                           " << endl;

		if (kk == -32 && step != 0)
		{
			char cc = _getch();
			{
				if (cc == 80)
				{
					tt_cnt++;
					if (tt_cnt > 6) tt_cnt = 1;
				}
				if (cc == 72)
				{
					tt_cnt--;
					if (tt_cnt < 1) tt_cnt = 6;
				}
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
		}

		if (30 < kk && kk < 122)
		{
			str[tt_cnt].push_back(kk);
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}

		if (kk == 8)
		{
			if (!str[tt_cnt].empty())
			{
				str[tt_cnt].pop_back();
			}
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			for (int i = 0; i < str[tt_cnt].length() + 2; i++)
			{
				cout << " ";
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}

		if (kk == 13)
		{
			if (step == 0)
			{
				string str_ma_phong = Xoa_khoang_trang_thua(str[0]);
				dt_phong = Maphong_Timkiem_phong(str_ma_phong);
				if (dt_phong.Get_ma_phong() != " ")
				{
					str[0] = dt_phong.Get_ma_phong();
					str[1] = dt_phong.Get_ten_phong();
					str[2] = dt_phong.Get_kieu_phong();
					str[3] = dt_phong.Get_gia_phong();
					str[4] = to_string(dt_phong.Get_nam());
					str[5] = dt_phong.Get_trang_thai();
					str[6] = dt_phong.Get_vi_tri();

					for (tt_cnt = 1; tt_cnt < stt_sh; tt_cnt++)
					{
						gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
						cout << str[tt_cnt];
					}
					step = 1;
				}
			}
			else {
				tt_cnt++;
				if (tt_cnt > 6) tt_cnt = 1;
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
		}

		if (kk == 19 && step != 0)
		{
			int vt_lcht = 0;
			stt_lcht1.Doinen(2);

			while (1)
			{
				Show_point(false);
				char t_kk = _getch();
				string tt_phong = "";
				if (t_kk == -32)
				{
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77)
					{
						if (vt_lcht == 0)
						{
							vt_lcht = 1;
							stt_lcht1.Doinen(0);
							stt_lcht2.Doinen(2);
						}
						else
						{
							vt_lcht = 0;
							stt_lcht1.Doinen(2);
							stt_lcht2.Doinen(0);
						}
					}
				}

				if (t_kk == 13)
				{
					if (vt_lcht == 0)
					{
						for (int i = 0; i < stt_sh; i++)
						{
							tt_phong += (str[i] + " ; ");
						}
						tt_phong += "\n";
						textcolor(WHITE);
						Xoadoituongtrongfile(qls_file_name, dt_phong.Get_ma_phong());
						Ghifile(qls_file_name, tt_phong);
						gotoxy(33, 90);
						cout << "BAN DA LUU!" << endl;
						flag_exit = 1;
					}
					if (vt_lcht == 1)
					{
						gotoxy(33, 90);
						cout << "BAN DA HUY!" << endl;
						step = 0;
						for (tt_cnt = 6; tt_cnt > 0; tt_cnt--)
						{
							str[tt_cnt] = "";
							gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
							cout << "                                       ";
						}

						flag_exit = 0;
					}
					break;
				}

				if (t_kk == 27)
				{
					flag_exit = 1;
					break;
				}
				SetBGColor(0);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

			}
		}

		if (kk == 27)
		{
			flag_exit = 1;
			break;
		}
	}
}