/*
* File Name: btquanlysv.cpp
* Author: THAI DOAN NHAT
* Date: 25/05/2023
* Description: This file to manage students
*/

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
//user-defined data type(kiểu dữ liệu do người dùng định nghĩa)
typedef enum{
    NAM,
    NU,
}GioiTinh;
//user-defined data type(kiểu dữ liệu do người dùng định nghĩa)
typedef enum{
    GIOI,
    KHA, 
    TRUNG_BINH,
    YEU
}HocLuc;
/*
*Create Class _sinh_vien
* Function:none
* Description: create class and scope of access of properties and methods are in class
* Input:none
* Output:none
*/
class _sinh_vien{
    private://access range
        uint8_t id;
        string ten;
        uint8_t tuoi;
        GioiTinh gioitinh;
        double diemToan;
        double diemLy;
        double diemHoa;
        double diemTrungBinh;
        HocLuc hocLuc;
    public://access range
        void setID(uint8_t id);
        uint8_t getID();
        void setTen(string ten);
        string getTen();
        void setGioiTinh(GioiTinh gioiTinh);
        GioiTinh getGioiTinh();
        void setTuoi(uint8_t tuoi);
        uint8_t getTuoi();
        void setDiemToan(double diemToan);
        double getDiemToan();
        void setDiemLy(double diemLy);
        double getDiemLy();
        void setDiemHoa(double diemHoa);
        double getDiemHoa();
        double getDiemTrungBinh();
        HocLuc getHocLuc();
};

/*
*Create Class _hien_thi
* Function:none
* Description: create class and scope of access of properties and methods are in class
* Input:none
* Output:none
*/
class _hien_thi
{
private:
    vector<_sinh_vien> sinhvien;// vector like array but the ability to auto-resize
    static uint8_t checkId;
public:
    //create access scope related functions
    void Giaodien();
    void themSinhVien();
    void capnhatSVtheoID();
    void xoaSVtheoID();
    void timkiemSVtheoTen();
    void sapxepSVtheoGPA();
    void sapxepSVtheoTen();
    void hienthiDanhSach();
    void hienthiDanhSachID();
};
/*
* Class: _sinh_vien
* Function: setID
* Description: This function use for setting ID of a Student
* Input: ID of Student
* Output:None
*/
void _sinh_vien::setID(uint8_t id){
    this->id = id;
}

/*
* Class: _sinh_vien
* Function: getID
* Description: This function use for getting id of student
* Input: None
* Output:Return ID of Student
*/
uint8_t _sinh_vien::getID(){
    return this->id;
}

/*
* Class: _sinh_vien
* Function: setTen
* Description: This function use for setting name of a Student
* Input:name(ten) of Student
* Output:None
*/
void _sinh_vien::setTen(string ten){
    this->ten = ten;
}

/*
* Class: _sinh_vien
* Function: getTen
* Description: This function use for getting name of student
* Input:none
* Output:return name of Student
*/
string _sinh_vien::getTen(){
    return this->ten;
}

/*
* Class: _sinh_vien
* Function: setTuoi
* Description: This function use for setting age of a Student
* Input:age(tuoi) of Student
* Output:None
*/
void _sinh_vien::setTuoi(uint8_t tuoi){
    this->tuoi = tuoi;
}

/*
* Class: _sinh_vien
* Function: getTuoi
* Description: This function use for getting age of student
* Input:none
* Output:return age of Student
*/
uint8_t _sinh_vien::getTuoi(){
    return this->tuoi;
}

/*
* Class: _sinh_vien
* Function: setGioiTinh
* Description: This function use for setting sex of a Student
* Input: sex(gioitinh) of Student
* Output:none
*/
void _sinh_vien::setGioiTinh(GioiTinh gioitinh){
    this->gioitinh = gioitinh;
}

/*
* Class: _sinh_vien
* Function: getGioiTinh
* Description: This function use for getting sex of student
* Input:nne
* Output:return sex of Student
*/
GioiTinh _sinh_vien::getGioiTinh(){
    return this->gioitinh;
}

/*
* Class: SinhVien
* Function: setDiemToan
* Description: This function use for setting mark of Math
* Input: diemtoan of Math
* Output:none
*/
void _sinh_vien::setDiemToan(double diemToan){
    this->diemToan = diemToan;
}

/*
* Class: _sinh_vien
* Function: getDiemToan
* Description: This function use for getting mark of Math
* Input:none
* Output:return mark of math
*/
double _sinh_vien::getDiemToan(){
    return this->diemToan;
}

/*
* Class: _sinh_vien
* Function: setDiemLy
* Description: This function use for setting mark of Physic
* Input:diemLy of Physic
* Output:none
*/
void _sinh_vien::setDiemLy(double diemLy){
    this->diemLy = diemLy;
}

/*
* Class: _sinh_vien
* Function: getDiemLy
* Description: This function use for getting mark of Physic
* Input:none
* Output:return mark of Physic
*/
double  _sinh_vien::getDiemLy(){
    return this->diemLy;
}

/*
* Class: _sinh_vien
* Function: setDiemHoa
* Description: This function use for setting mark of Chemistry
* Input:DiemHoa of Chemistry
* Output:none
*/
void _sinh_vien::setDiemHoa(double diemHoa){
    this->diemHoa = diemHoa;
}

/*
* Class: _sinh_vien
* Function: getDiemHoa
* Description: This function use for getting mark of Chemistry
* Input:none
* Output:return mark of Chemistry
*/
double  _sinh_vien::getDiemHoa(){
    return this->diemHoa;
}

/*
* Class: _sinh_vien
* Function: getDiemTrungBinh
* Description: This function use for getting diemtrungbinh
* Input:none
* Output:return diemtrungbinh
*/
double _sinh_vien::getDiemTrungBinh(){
    //Check to errors of subject scores
    if (this->diemToan < 0 || this->diemToan > 10){
        cout<<"error! nhap lai!\n"; 
        return 0;
    }
    if (this->diemLy < 0 || this->diemLy > 10){
        cout<<"error! nhap lai!\n"; 
        return 0;
    }
    if (this->diemHoa < 0 || this->diemHoa > 10){
        cout<<"error! nhap lai!\n"; 
        return 0;
    }
    return this->diemTrungBinh = (this->diemToan + this->diemLy + this->diemHoa) / 3;
}

/*
* Class: _sinh_vien
* Function: getHocLuc
* Description: This function use for getting ability of Student
* Input:none
* Output:return ability of Student
*/
HocLuc _sinh_vien::getHocLuc(){
    if (this->diemTrungBinh >= 8){
        return this->hocLuc = GIOI;
    }else if (this->diemTrungBinh >= 6.5)
    {
        return this->hocLuc = KHA;
    }else if (this->diemTrungBinh >= 5)
    {
        return this->hocLuc = TRUNG_BINH;
    }else return this->hocLuc = YEU;
}

/* static variable initialization */
uint8_t _hien_thi::checkId = 0;

/*
* Class: _hien_thi
* Function: Giaodien
* Description: This function is use to show list command
* Input:none
* Output:none
*/
void _hien_thi::Giaodien(){
    cout << "DANH SACH LENH: \n";
    cout << "1. THEM SINH VIEN\n";
    cout << "2. CAP NHAT THONG TIN SINH VIEN THEO ID\n";
    cout << "3. XOA SINH VIEN THEO ID\n";
    cout << "4. TIM KIEM SINH VIEN THEO TEN\n";
    cout << "5. SAP XEP SINH VIEN THEO GPA\n";
    cout << "6. SAP XEP SINH VIEN THEO TEN\n";
    cout << "7. HIEN THI DANH SACH SINH VIEN\n";
    cout << "NHAP 8 DE THOAT\n";
}

/*
* Class: _hien_thi
* Function: themSinhVien
* Description: This function is use to add student
* Input:none
* Output:none
*/
void _hien_thi::themSinhVien(){
    _sinh_vien sv;
    string ten;
    int gt;
    uint8_t tuoi;
    GioiTinh gioitinh;
    double diemToan, diemLy, diemHoa;
    cout << "THEM SINH VIEN \n";
    cout << "NHAP TEN: ";
    cin >> ten;
    sv.setTen(ten);
    cout << "NHAP TUOI: ";
    scanf("%d",&tuoi);
    sv.setTuoi(tuoi);
    fflush(stdin);
    cout << "GIOI TINH(0: NAM/1: NU): ";
    cin >> gt;
    if (gt == NAM){
        gioitinh = NAM; 
    }else if (gt == NU)
    {
        gioitinh = NU;
    }else cout << "ERROR !\n";
    sv.setGioiTinh(gioitinh);
    cout << "NHAP DIEM TOAN: ";
    cin >> diemToan;
    sv.setDiemToan(diemToan);
    cout << "NHAP DIEM LY: ";
    cin >> diemLy;
    sv.setDiemLy(diemLy);
    cout << "NHAP DIEM HOA: ";
    cin >> diemHoa;
    sv.setDiemHoa(diemHoa);
    this->checkId++;
    sv.setID(_hien_thi::checkId);
    _hien_thi::sinhvien.push_back(sv);
    cout << "SINH VIEN DA DUOC THEM\n\n";
}

/*
* Class: _hien_thi
* Function: capnhatSVtheoID
* Description: This function is use to update students by id 
* Input:none
* Output:none
*/
void _hien_thi::capnhatSVtheoID(){
    static _sinh_vien sv;
    uint8_t id = 0;
    uint8_t  index = 0, setid = 0;
    uint8_t tuoi = 0;
    GioiTinh gioitinh;
    string capnhatString;
    int capnhatInt;
    double diemToan = 0, diemLy = 0, diemHoa = 0;
    if(sinhvien.empty()){ 
        cout <<"KHONG CO DU LIEU TRONG DANH SACH\n";
        return;
    }
    while (true){
        if (setid == 0){
            cout << "NHAP ID: ";
            scanf("%d",&id);
            for (int i = 0; i < sinhvien.size(); i++){
                if (sinhvien[i].getID() == id){
                    sv = sinhvien[i];
                    index = i;
                    setid = 1;
                }
            }
        }
        if (setid == 1){
            cout<<"THONG TIN SINH VIEN MUON CAP NHAT"<<endl;
            cout<<"1. CAP NHAT TEN"<<endl;
            cout<<"2: CAP NHAT TUOI "<<endl;
            cout<<"3: CAP NHAT GIOI TINH"<<endl;
            cout<<"4: CAP NHAT DIEM TOAN"<<endl;
            cout<<"5: CAP NHAT DIEM LY"<<endl;
            cout<<"6: CAP NHAT DIEM HOA "<<endl;
            cout<<"7: TIEP TUC CAP NHAT ID TIEP THEO !"<<endl;
            cout<<"8: HOAN THANH CAP NHAT THONG TIN !\n";
            int nhap;
            cout<<"NHAP: ";
            cin >> nhap;
            switch (nhap){
            case 1:
                cout<<"TEN: ";
                cin >> capnhatString;
                this->sinhvien[index].setTen(capnhatString);
                break;
            case 2:
                cout<<"TUOI: ";
                cin >> capnhatInt;
                this->sinhvien[index].setTuoi(capnhatInt);
                break;
            case 3:
                cout<<"GIOI TINH (0: NAM/1: NU): ";
                cin >> capnhatInt;
                if (capnhatInt == NAM){
                    gioitinh = NAM; 
                }else if (capnhatInt == NU){
                    gioitinh = NU;
                }else cout << "ERROR !\n";
                this->sinhvien[index].setGioiTinh(gioitinh);
                break;   
            case 4:
                cout << "DIEM TOAN: ";
                cin >> diemToan;
                this->sinhvien[index].setDiemToan(diemToan);            
                break;
            case 5:
                cout << "NHAP DIEM LY: ";
                cin >> diemLy;
                this->sinhvien[index].setDiemLy(diemLy);
                break;
            case 6:
                cout << "NHAP DIEM HOA: ";
                cin >> diemHoa;
                this->sinhvien[index].setDiemHoa(diemHoa);
                break;
            case 7:
                printf("DA CAP NHAT THONG TIN CHO ID: %d !\n",sv.getID());
                setid = 0;
                break;
            case 8:
                printf("DA CAP NHAT THONG TIN CHO ID: %d!\n",sv.getID());                
                break;
            default:
                cout << "BAN DA NHAP SAI LENH !\n";
                break;
            }
            if (nhap == 8){
                break;}
        }
    }
}

/*
* Class: _hien_thi
* Function: xoaSVtheoID
* Description: This function is use to remove student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void _hien_thi::xoaSVtheoID(){
    _sinh_vien sv;
    uint8_t id, XoaID = 0, newID;
    if(sinhvien.empty()){ 
        cout <<"KHONG CO DU LIEU TRONG DANH SACH\n";
        return;
    }
    for (int i = 0; i < sinhvien.size(); i++){
        for (int j = i + 1; j < sinhvien.size(); j++){
            if (sinhvien[i].getID() > sinhvien[j].getID()){
                sv = sinhvien[i];
                sinhvien[i] = sv;
                sinhvien[i] = sinhvien[j];
                sinhvien[j] = sv;
            }
        }
    }
    cout<<"NHAP ID: ";
    scanf("%d",&id);
    for (int  i = 0; i < sinhvien.size(); i++){
        if (sinhvien[i].getID() == id){
            sinhvien.erase(sinhvien.begin() + i);
            checkId --;
            XoaID = 1;
            cout<<" DA XOA ID \n";
        }
        if (XoaID == 1){
            newID = sinhvien[i].getID() - 1;
            sinhvien[i].setID(newID);
        }
    }if (XoaID == 0){
        cout<<"KHONG CO ID NAY\n"<<endl;
    }
}

/*
* Class: _hien_thi
* Function: timkiemSVtheoTen
* Description: This function is use to search student by name
* Input:none
* Output:none
*/
void _hien_thi::timkiemSVtheoTen(){
    uint8_t timTen = 0;
    string ten;
    if(sinhvien.empty()){ 
        cout << "KHONG CO DU LIEU TRONG DANH SACH\n";
        return;
    }
    cout<<"NHAP TEN: ";
    cin >>ten;
    for (int i = 0; i < sinhvien.size(); i++){
        if (ten == sinhvien[i].getTen()){
            cout<<"ID\tTEN\tTUOI\tGIOITINH\tTOAN\tLY\tHOA\tGPA\tHOC_LUC\n";
            printf("%d\t",sinhvien[i].getID());
            cout<<sinhvien[i].getTen()<<"\t";
            printf("%d\t",sinhvien[i].getTuoi());  
            if(sinhvien[i].getGioiTinh() == NAM) cout<<"NAM"<<"\t\t"; else cout<<"NU"<<"\t\t"; cout<<sinhvien[i].getDiemToan()<<"\t"; cout<<sinhvien[i].getDiemLy()<<"\t"; cout<<sinhvien[i].getDiemHoa()<<"\t"; 
            cout<<sinhvien[i].getDiemTrungBinh()<<"\t"; if(sinhvien[i].getHocLuc() == GIOI) cout<<"GIOI"<<"\n"; else if(sinhvien[i].getHocLuc() == KHA) cout<<"KHA"<<"\n"; else if(sinhvien[i].getHocLuc() == TRUNG_BINH) cout<<"TRUNG_BINH"<<"\n"; else cout<<"YEU"<<"\n";
            timTen = 1;
        }
    }
    if (timTen == 0){
        cout<<"KHONG CO TEN NAY"<<endl;
    }
}

/*
* Class: _hien_thi
* Function: hienthiDanhSach
* Description: This function is use to display list of students
* Input:none
* Output:none
*/
void _hien_thi::hienthiDanhSach(){
    cout<<"ID\tTEN\tTUOI\tGIOITINH\tTOAN\tLY\tHOA\tGPA\tHOC_LUC\n";
    for (int i = 0; i < sinhvien.size(); i++){ 
        printf("%d\t",sinhvien[i].getID());  
        cout<<sinhvien[i].getTen()<<"\t"; 
        printf("%d\t",sinhvien[i].getTuoi());
        if(sinhvien[i].getGioiTinh() == NAM) cout<<"NAM"<<"\t\t"; 
        else cout<<"NU"<<"\t\t"; cout<<sinhvien[i].getDiemToan()<<"\t";
        cout<<sinhvien[i].getDiemLy()<<"\t"; cout<<sinhvien[i].getDiemHoa()<<"\t"; 
        cout<<sinhvien[i].getDiemTrungBinh()<<"\t"; if(sinhvien[i].getHocLuc() == GIOI) 
        cout<<"GIOI"<<"\n"; else if(sinhvien[i].getHocLuc() == KHA) cout<<"KHA"<<"\n"; 
        else if(sinhvien[i].getHocLuc() == TRUNG_BINH) cout<<"TRUNG_BINH"<<"\n"; else cout<<"YEU"<<"\n";
    }
}

/*
* Class: _hien_thi
* Function: sapxepSVtheoGPA
* Description: This function is use to sort students by GPA
* Input:none
* Output:none
*/
void _hien_thi::sapxepSVtheoGPA(){
    _sinh_vien sv;
    if(sinhvien.empty()){ 
        cout << "KHONG CO DU LIEU TRONG DANH SACH\n";
        return;
    }
    for (int i = 0; i < sinhvien.size(); i++){
        for (int j = i + 1; j < sinhvien.size(); j++){
            if (sinhvien[i].getDiemTrungBinh() > sinhvien[j].getDiemTrungBinh()){
                sv = sinhvien[i];
                sinhvien[i] = sv;
                sinhvien[i] = sinhvien[j];
                sinhvien[j] = sv;
            }
        }
    }
    _hien_thi::hienthiDanhSach();
}

/*
* Class: _hien_thi
* Function: sapxepSVtheoTen
* Description: This function is use to sort students by name
* Input:none
* Output:none
*/
void _hien_thi::sapxepSVtheoTen(){
    _sinh_vien sv;
    if(sinhvien.empty()){ 
        cout << "KHONG CO DU LIEU TRONG DANH SACH\n";
        return;
    }
    for (int i = 0; i < sinhvien.size(); i++){
        for (int j = i + 1; j < sinhvien.size(); j++){
            if (sinhvien[i].getTen() > sinhvien[j].getTen()){
                sv = sinhvien[i];
                sinhvien[i] = sv;
                sinhvien[i] = sinhvien[j];
                sinhvien[j] = sv;
            }
        }
    }
    _hien_thi::hienthiDanhSach();
}

/*
* Class: _hien_thi
* Function: showListStudent
* Description: This function use is use to display list of students by ID
* Input:none
* Output:none
*/
void _hien_thi::hienthiDanhSachID(){
    _sinh_vien sv;
    for (int i = 0; i < sinhvien.size(); i++){
        for (int j = i + 1; j < sinhvien.size(); j++){
            if (sinhvien[i].getID() > sinhvien[j].getID()){
                sv = sinhvien[i];
                sinhvien[i] = sv;
                sinhvien[i] = sinhvien[j];
                sinhvien[j] = sv;
            }
        }
    }
    _hien_thi::hienthiDanhSach();
}
int main(int argc, char const *argv[])
{
    _hien_thi HT;
    int nhap;
    while (true){
        HT.Giaodien();
        cout<<"VUI LONG NHAP: ";
        cin>>nhap;
        switch (nhap)
        {
        case 1:
            HT.themSinhVien();
            break;
        case 2:
            HT.capnhatSVtheoID();
            break;
        case 3:
            HT.xoaSVtheoID();
            break;
        case 4:
            HT.timkiemSVtheoTen();
            break;
        case 5:
            HT.sapxepSVtheoGPA();
            break;
        case 6:
            HT.sapxepSVtheoTen();
            break;
        case 7:
            HT.hienthiDanhSachID();
            break;
        case 8:
            break;
        default:
            break;
        }
        if (nhap == 8){
            break;}
    }
    return 0;
}