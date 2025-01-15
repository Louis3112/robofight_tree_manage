#include<iostream>
using namespace std;

struct Tree{
    int Data;
    Tree *Left;
    Tree *Right;
};
Tree *Root;

void Create(Tree *Root);
void Clear(Tree *Root);
void IsEmpty(Tree *Root);
void Insert(Tree **Root, int NewData);
void PreOrder(Tree *Root);
void InOrder(Tree *Root);
void PostOrder(Tree *Root);
Tree *DeleteNode(Tree *Root, int DeleteData);
Tree *Find(Tree *Root, int FindData);
int Count(Tree *Root);
Tree *FindMin(Tree *Root);
Tree *FindMax(Tree *Root);
int Height(Tree *Root);
void FindLeaf(Tree*Root);

int main(){
    Create(Root);
    
    int Choice;
    
    char Login = 'y';
    while(Login == 'y'){
        system("cls");
        cout << "========== RoboFight App ==========\n\n";
        cout << "1. Enter your RoboFight card code\n";
        cout << "2. See all your RoboFight cards collection\n";
        cout << "3. Delete your RoboFight card code from your collection\n";
        cout << "4. Find your RoboFight card code\n";
        cout << "5. How many cards do you have?\n";
        cout << "6. What is your first and last card code card?\n";
        cout << "7. Exit\n";
        cout << "> ";
        cin >> Choice;

        switch (Choice){
        case 1:{
            int CardCode;
            cout << "Enter your RoboFight card code > ";
            cin >> CardCode;
            Insert(&Root,CardCode);

            cin.ignore();
            cout << "\nYour card code has been saved\n";
            cout << "Press Enter to Continue\n";
            cin.get();
        } 
        break;
        
        case 2:{
            int TraversalChoice;
            cout << "Select the method for seeing all your cards\n";
            cout << "1. Pre Order\n";
            cout << "2. In Order\n";
            cout << "3. Post Order\n";
            cout << "> ";
            cin >> TraversalChoice;

            cout << "List of your collection : \n";
            if(TraversalChoice == 1){
                PreOrder(Root);
            }
            else if(TraversalChoice == 2){
                InOrder(Root);
            }
            else if(TraversalChoice == 3){
                PostOrder(Root);
            }

            cin.ignore();
            cout << "\n\nPress Enter to Continue\n";
            cin.get(); 
        }
        break;

        case 3:{
            int DeleteCode;
            cout << "Enter the card code you wish to delete > ";
            cin >> DeleteCode;
            Root = DeleteNode(Root, DeleteCode);

            cout << "\nCard code with code " << DeleteCode << " has been deleted from your collection\n \n";
            cout << "\nList of your collection : \n";
            InOrder(Root);

            cin.ignore();
            cout << "\n\nPress Enter to Continue\n";
            cin.get();
        }  
        break;

        case 4:{
            int FindCode;
            cout << "Enter your RoboFight card code > ";
            cin >> FindCode;
            Tree *Result = Find(Root, FindCode);

            if(Result != nullptr){
                cout << "You have card with code " << FindCode << endl;
            }
            else{
                cout << "You do not have card with code " << FindCode << endl;
            }

            cin.ignore();
            cout << "\nPress Enter to Continue\n";
            cin.get();
        } 
        break;

        case 5:{
            int CardCount = Count(Root);
            cout << "You have " << CardCount << " cards in your collection\n";

            cin.ignore();
            cout << "\nPress Enter to Continue\n";
            cin.get();
        }
        break;

        case 6:{
            Tree *FirstCardCode = FindMin(Root);
            Tree *LastCardCode = FindMax(Root);

            cout << "Your first card code is " << FirstCardCode->Data << endl;
            cout << "Your last card code is " << LastCardCode->Data << endl;

            cin.ignore();
            cout << "\nPress Enter to Continue\n";
            cin.get();
        }
        break;

        case 7:{
            char Exit;
            cout << "Are you sure you to exit the application? (y/n)\n";
            cout << "> ";
            cin >> Exit;

            if(Exit == 'y' || Exit == 'Y'){
                Login = 'n';
            }
            else{
                Login = 'y';
            }
        }
        break;

        default:
            cout << "Invalid input\n";   
            cin.ignore();
            cout << "\nPress Enter to Continue\n";
            cin.get();
        break;
        }
    }
    return 0;
}

void Create(Tree *Root){
    Root = nullptr;
}

void Clear(Tree *Root){
    Root = nullptr;
}

int isEmpty(Tree *Root){
    if(Root == nullptr) return 1;
    else return 0;
}

void Insert(Tree **Root, int NewData){
    if((*Root) == nullptr){ //jika Root masih kosong
        Tree *NewNode; // maka membuat Root baru pertama
        NewNode = new Tree;
        NewNode->Data = NewData;
        NewNode->Left = nullptr;
        NewNode->Right = nullptr;
        (*Root) = NewNode; 
        (*Root)->Left = nullptr;
        (*Root)->Right = nullptr;
    }

    // jika sebelumnya sudah ada data di dalam binary tree, dilakukan pengecekan
    else if(NewData < (*Root)->Data){ // jika data yang baru lebih kecil dari Root
        Insert(&(*Root)->Left, NewData); // maka data diletakkan di child sebelah kiri
    }
    else if(NewData > (*Root)->Data){ // jika data yang baru lebih besar dari Root
        Insert(&(*Root)->Right, NewData);  // maka data diletakkan di child sebelah kanan
    }
    else if(NewData == (*Root)->Data){ // jika sebelumnya sudah menginputkan data yang sama 
        cout << "Data has been inputted\n"; // maka data tidak bisa diinputkan
    }
}

void PreOrder(Tree *Root){
    if(Root == nullptr){ 
        return;
    }
    cout << Root->Data << " "; // menampilkan data Root 
    PreOrder(Root->Left); // traverse ke kiri
    PreOrder(Root->Right); // traverse ke kanan
}

void InOrder(Tree *Root){
    if(Root == nullptr){ 
        return;
    }
    InOrder(Root->Left); // traverse ke kiri
    cout << Root->Data << " "; // menampilkan data Root 
    InOrder(Root->Right); // traverse ke kanan
} // sehingga menampilkan data secara terurut 

void PostOrder(Tree *Root){
    if(Root == nullptr){ 
        return;
    }
    PostOrder(Root->Left); // traverse ke kiri
    PostOrder(Root->Right);  // traverse ke kanan
    cout << Root->Data << " "; // menampilkan data Root 
}

Tree *DeleteNode(Tree *Root, int DeleteData){ // mencari data yang akan dihapus 
    if (Root == nullptr){ // jika Root kosong atau data yang dicari tidak ditemukan
        return nullptr; // maka akan mengembalikan nilai kosong
    }

    else if(DeleteData < Root->Data){ // jika data yang dicari lebih kecil dari Root
        Root->Left = DeleteNode(Root->Left, DeleteData); // maka mengakses subtree sebelah kiri
    }
    else if(DeleteData < Root->Data){  // jika data yang dicari lebih besar dari Root
        Root->Right = DeleteNode(Root->Right, DeleteData); // maka mengakses subtree sebelah kanan
    } // jika data memang sudah ditemukan 
    else{ // jika Root memiliki 1 child saja
        if(Root->Left == nullptr){ // jika Root tidak memiliki child di sebelah kiri 
            Tree *Temp = Root->Right; // maka Temp akan menyimpan child sebelah kanan
            delete Root; // menghapus data
            return Temp; // maka Temp disambungkan kembali terhadap binary tree
        }
        if(Root->Right == nullptr){ // jika Root tidak memiliki child di sebelah kanan 
            Tree *Temp = Root->Left; // maka Temp akan menyimpan child sebelah kiri
            delete Root; // menghapus data
            return Temp; // maka Temp disambungkan kembali terhadap binary tree
        }
        else{ //jika Root memiliki 2 child 
            Tree *Temp = FindMax(Root->Left); // maka data nilai digantikan dengan nilai terbesar dari left subtree
            Root->Data = Temp->Data; // data disimpan di Temp 
            Root->Left = DeleteNode(Root->Left,Temp->Data); // maka dilakukan penghapusan 
        }
    }
    return Root;
}

Tree *Find(Tree *Root, int FindData){
    if(Root == nullptr){ // jika Root kosong atau data tidak ditemukan
        return nullptr; // maka akan mengembalikan nilai kosong
    }
    else if(FindData < Root->Data) return Find(Root->Left,FindData); // jika data yang dicari lebih kecil dari Root, maka mencari ke child sebelah kiri
    else if(FindData > Root->Data) return Find(Root->Right,FindData); // jika data yang dicari lebih besar dari Root, maka mencari ke child sebelah kanan
    else return Root; // jika data sudah ditemukan, maka mengembalikan data yang dicari
}

int Count(Tree *Root){
    if(Root == nullptr) return 0; //jika Root kosong, maka mengembalikan nilai nol (karena tidak ada kartu) 
    return Count(Root->Left) + Count(Root->Right) + 1; // jika ada data, maka menghitung banyaknya node di left subtree dan right subtree, lalu ditambah 1 yang merupakan node root
}

Tree *FindMin(Tree *Root){ // mencari data paling kecil 
    if(Root == nullptr){ // jika Root kosong atau data tidak ditemukan
        return nullptr; // maka akan mengembalikan nilai kosong
    }
    else{
        if(Root->Left == nullptr) return Root; // jika subtree left kosong, berarti data tersebutlah yang paling kiri (yang paling kecil)
        else return FindMin(Root->Left); // jika memang belum kosong, maka mengakses subtree sebelah kiri
    }
}

Tree *FindMax(Tree *Root){ // mencari data paling kecil 
    if(Root == nullptr){ // jika Root kosong atau data tidak ditemukan 
        return nullptr; // maka akan mengembalikan nilai kosong
    }
    else{
        if(Root->Right == nullptr) return Root; // jika subtree right kosong, berarti data tersebutlah yang paling kanan (yang paling besar)
        else return FindMax(Root->Right);  // jika memang belum kosong, maka mengakses subtree sebelah kanan
    }
}

int Height(Tree *Root){
    if(Root == nullptr) return -1; // jika Root kosong, maka mengembalikan nilai -1 (karena tidak ada tinggi)
    int LeftHeight = Height(Root->Left); // dilakukan pembagian LeftHeight untuk menghitung kedalaman dari subtree sebelah kiri 
    int RightHeight = Height(Root->Right); // dilakukan pembagian RightHeight untuk menghitung kedalaman dari subtree sebelah kanan 
    if(LeftHeight > RightHeight) return LeftHeight + 1; // jika LeftHeight lebih besar, maka digunakan penghitungan LeftHeight + 1 (yg merupakan root utama)
    else return RightHeight + 1; // jika RightHeight lebih besar, maka digunakan penghitungan RightHeight + 1 (yg merupakan root utama)
}

void FindLeaf(Tree *Root){
    if(Root == nullptr){
        return;
    }
    if(Root->Left != nullptr) FindLeaf(Root->Left); // jika masih terdapat child di sebelah kiri, maka mengakses subtree sebelah kiri
    if(Root->Right != nullptr) FindLeaf(Root->Right); // jika masih terdapat child di sebelah kanan, maka mengakses subtree sebelah kanan
    else if(Root->Left == nullptr && Root->Right == nullptr){ // jika sudah tidak ada child di sebelah kiri atau kanan
        cout << "The leaf is " << Root->Data << endl; //maka leaf ditemukan
    }
}

/*

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 1
Enter your RoboFight card code > 413

Your card code has been saved
Press Enter to Continue

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 2
Select the method for seeing all your cards
1. Pre Order
2. In Order
3. Post Order
> 1

List of your collection:
134 131 413 351 194 180 174 164 256 281 274 261 323 291 315 341 409 380 418 504 473 582 541 

Press Enter to Continue


========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 2
Select the method for seeing all your cards
1. Pre Order
2. In Order
3. Post Order
> 2

List of your collection:
131 134 164 174 180 194 256 261 274 281 291 315 323 341 351 380 409 413 418 473 504 541 582 

Press Enter to Continue

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 2
Select the method for seeing all your cards
1. Pre Order
2. In Order
3. Post Order
> 3

List of your collection:
131 164 174 180 261 274 315 291 341 323 281 256 194 380 409 351 473 541 582 504 418 413 134 

Press Enter to Continue

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 3
Enter the card code you wish to delete > 261

Card code with code 261 has been deleted from your collection
 
List of your collection : 
131 164 174 180 194 256 274 281 291 315 323 341 351 380 409 413 418 473 504 541 582 

Press Enter to Continue

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 4
Enter your RoboFight card code > 274
You have card with code 274

Press Enter to Continue

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 4
Enter your RoboFight card code > 500
You do not have card with code 500

Press Enter to Continue

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 5
You have 22 cards in your collection

Press Enter to Continue

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 6
Your first card code is 131
Your last card code is 582

Press Enter to Continue

========== RoboFight App ==========

1. Enter your RoboFight card code
2. See all your RoboFight cards collection
3. Delete your RoboFight card code from your collection
4. Find your RoboFight card code
5. How many cards do you have?
6. What is your first and last card code card?
7. Exit
> 7
Are you sure you to exit the application? (y/n)
> y
*/