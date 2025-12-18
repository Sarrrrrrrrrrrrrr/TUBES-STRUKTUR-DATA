#include "bstNode.h"
#include "gameplay.h"

using namespace std;

address createNode(int objectX, int objectY, string namaObject, string pesanObject, bool statusDilewati) {
    address node = new Node;
    node->x = objectX;
    node->y = objectY;
    node->nama = namaObject;
    node->pesan = pesanObject;
    node->tembus = statusDilewati;
    node->left = node->right = NIL;
    return node;
}

address insert(address root, int x, int y, string namaObj, string pesanObj, bool statusDilewati){
    if (root == NIL) {
        root = createNode(x, y, namaObj, pesanObj, statusDilewati);
        return root;
    }

    // Prioritas X, lalu Y (sederhana)
    if (x < root->x) root->left = insert(root->left, x, y, namaObj, pesanObj, statusDilewati);
    else if (x > root->x) root->right = insert(root->right, x, y, namaObj, pesanObj, statusDilewati);
    else {
        if (y < root->y) root->left = insert(root->left, x, y, namaObj, pesanObj, statusDilewati);
        else root->right = insert(root->right, x, y, namaObj, pesanObj, statusDilewati);
    }
    return root;
}

// =========================================================
//              FUNGSI KHUSUS UNTUK INTERAKSI GAME
// =========================================================

address cariNode(address root, int x, int y) {
    if (root == NIL) return NIL;
    if (root->x == x && root->y == y) return root;

    if (x < root->x) return cariNode(root->left, x, y);
    else if(x > root->x) return cariNode(root->right, x, y);
    else {
        if (y < root->y) return cariNode(root->left, x, y);
        else return cariNode(root->right, x, y);
    }
}

int main () {
    address root = NIL;
    int pilihanMenu;
    int radiusPandang = 5;

    // Inisialisasi ruangan awal (Perpustakaan)
    pindahKeRuangan(root, /*playerX*/ *(new int(0)), /*playerY*/ *(new int(0)), 1);
    // NOTE: kita akan mengatur spawn pada mulaiBermain sehingga konstruktor di atas sekadar memastikan root terisi

    do {
        system("cls");
        cout << "=========================" << endl;
        cout << "      RENDERING GAME      " << endl;
        cout << "=========================" << endl;
        cout << "1. Mulai Bermain" << endl;
        cout << "2. Setting" << endl;
        cout << "3. Keluar" << endl;
        cout << "-------------------------" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihanMenu;
        switch (pilihanMenu)
        {
        case 1:
            mulaiBermain(root, radiusPandang);
            break;
        case 2:
            lihatSetting(root, radiusPandang);
            break;
        case 3:
            cout << "Terimakasih telah bermain!" << endl;
            break;
        default:
            break;
        }
    } while (pilihanMenu != 3);
    return 0;
}