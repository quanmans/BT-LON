#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struct luu tru thong tin nhan vien
struct NhanVien {
    int maNhanVien;
    string ten;
    string chucVu;
    double luong;
    double phucLoi;
    int chamCong;
    string danhGiaHieuQua;

    void hienThiThongTin() const {
        cout << "Ma nhan vien: " << maNhanVien << "\n";
        cout << "Ten: " << ten << "\n";
        cout << "Chuc vu: " << chucVu << "\n";
        cout << "Luong: " << luong << "\n";
        cout << "Phuc loi: " << phucLoi << "\n";
        cout << "Cham cong: " << chamCong << " ngay\n";
        cout << "Danh gia hieu qua: " << danhGiaHieuQua << "\n";
    }
};

// Class quan ly nhan su
class QuanLyNhanSu {
private:
    vector<NhanVien> danhSachNhanVien;

public:
    // Them nhan vien moi
    void themNhanVien(int maNhanVien, string ten, string chucVu, double luong, double phucLoi) {
        NhanVien nhanVienMoi = {maNhanVien, ten, chucVu, luong, phucLoi, 0, "Chua danh gia"};
        danhSachNhanVien.push_back(nhanVienMoi);
        cout << "Da them nhan vien thanh cong!\n";
    }

    // Them nhan vien thu cong
    void themNhanVienThuCong() {
        int maNhanVien;
        string ten;
        string chucVu;
        double luong;
        double phucLoi;

        cout << "Nhap ma nhan vien: ";
        cin >> maNhanVien;
        cin.ignore(); // Xoa ky tu xuong dong con lai
        cout << "Nhap ten nhan vien: ";
        getline(cin, ten);
        cout << "Nhap chuc vu: ";
        getline(cin, chucVu);
        cout << "Nhap luong: ";
        cin >> luong;
        cout << "Nhap phuc loi: ";
        cin >> phucLoi;

        themNhanVien(maNhanVien, ten, chucVu, luong, phucLoi);

        int soNgayChamCong;
        cout << "Nhap so ngay cham cong ban dau cho nhan vien " << ten << ": ";
        cin >> soNgayChamCong;
        capNhatChamCong(maNhanVien, soNgayChamCong);
    }

    // Them nhieu nhan vien thu cong
    void themNhieuNhanVien() {
        int soLuong;
        cout << "Ban muon them bao nhieu nhan vien? ";
        cin >> soLuong;
        for (int i = 0; i < soLuong; ++i) {
            cout << "\nNhap thong tin nhan vien " << (i + 1) << ":\n";
            themNhanVienThuCong();
        }
    }

    // Hien thi danh sach nhan vien
    void hienThiTatCaNhanVien() {
        for (const auto& nv : danhSachNhanVien) {
            nv.hienThiThongTin();
            cout << "-----------------------------\n";
        }
    }

    // Cap nhat cham cong
    void capNhatChamCong(int maNhanVien, int soNgay) {
        for (auto& nv : danhSachNhanVien) {
            if (nv.maNhanVien == maNhanVien) {
                nv.chamCong += soNgay;
                cout << "Da cap nhat cham cong thanh cong cho ma nhan vien: " << maNhanVien << "\n";
                return;
            }
        }
        cout << "Khong tim thay nhan vien voi ma: " << maNhanVien << "\n";
    }

    // Cap nhat danh gia hieu qua
    void capNhatDanhGiaHieuQua(int maNhanVien, string danhGia) {
        for (auto& nv : danhSachNhanVien) {
            if (nv.maNhanVien == maNhanVien) {
                nv.danhGiaHieuQua = danhGia;
                cout << "Da cap nhat danh gia thanh cong cho ma nhan vien: " << maNhanVien << "\n";
                return;
            }
        }
        cout << "Khong tim thay nhan vien voi ma: " << maNhanVien << "\n";
    }

    // Xoa nhan vien
    void xoaNhanVien(int maNhanVien) {
        for (auto it = danhSachNhanVien.begin(); it != danhSachNhanVien.end(); ++it) {
            if (it->maNhanVien == maNhanVien) {
                danhSachNhanVien.erase(it);
                cout << "Da xoa nhan vien voi ma: " << maNhanVien << " thanh cong.\n";
                return;
            }
        }
        cout << "Khong tim thay nhan vien voi ma: " << maNhanVien << "\n";
    }
};

int main() {
    QuanLyNhanSu qlns;
    int luaChon;

    do {
        cout << "\nQuan Ly Nhan Su:\n";
        cout << "1. Them nhieu nhan vien\n";
        cout << "2. Hien thi danh sach nhan vien\n";
        cout << "3. Cap nhat cham cong\n";
        cout << "4. Cap nhat danh gia \n";
        cout << "5. Xoa nhan vien\n";
        cout << "6. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            qlns.themNhieuNhanVien();
            break;
        case 2:
            qlns.hienThiTatCaNhanVien();
            break;
        case 3: {
            int maNV, soNgay;
            cout << "Nhap ma nhan vien can cap nhat cham cong: ";
            cin >> maNV;
            cout << "Nhap so ngay cham cong can them: ";
            cin >> soNgay;
            qlns.capNhatChamCong(maNV, soNgay);
            break;
        }
        case 4: {
            int maNV;
            string danhGia;
            cout << "Nhap ma nhan vien can danh gia: ";
            cin >> maNV;
            cin.ignore();
            cout << "Nhap danh gia hieu qua: ";
            getline(cin, danhGia);
            qlns.capNhatDanhGiaHieuQua(maNV, danhGia);
            break;
        }
        case 5: {
            int maNV;
            cout << "Nhap ma nhan vien can xoa: ";
            cin >> maNV;
            qlns.xoaNhanVien(maNV);
            break;
        }
        case 6:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (luaChon != 6);

    return 0;
}
