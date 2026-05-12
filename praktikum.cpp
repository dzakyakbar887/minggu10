#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->nama = nama;
        this->email = email;
        id = generateId();
    }

    int generateId() {
        return ++globalId;
    }
};

int User::globalId = 0;

class Member : public User {
private:
    bool status;

public:
    Member(string nama, string email, bool status)
        : User(nama, email) {
        this->status = status;
    }

    void showProfile() {
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : "
             << (status ? "Aktif" : "Nonaktif")
             << endl;
    }

    void setStatus(bool status) {
        this->status = status;
    }
};

class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {}

    void showAllMember(vector<Member> members) {
        cout << "Daftar Member:" << endl;

        for (int i = 0; i < members.size(); i++) {
            members[i].showProfile();
            cout << "----------------" << endl;
        }
    }

    void toggleActivationMember(Member &m, bool status) {
        m.setStatus(status);
    }
};

int main() {

    Member m1("Budi", "budi@gmail.com", true);
    Member m2("Siti", "siti@gmail.com", false);

    Admin admin("Admin", "admin@gmail.com");

    vector<Member> daftarMember = {m1, m2};

    admin.showAllMember(daftarMember);

    admin.toggleActivationMember(m2, true);

    cout << "\nSetelah status diubah:\n";
    m2.showProfile();

    return 0;
}